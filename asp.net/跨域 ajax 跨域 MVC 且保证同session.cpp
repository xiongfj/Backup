
* ��������վ http://localhost:9101 �� http://localhost:8001
* �ȴ� 9101������ͬһ���������ǩ�� 8001
* ��ʱ 8001 ͨ�� ajax ��ȡ�� session �� 9101 ��session��ͬ



1��//�������Թ��˱�ǩ
{



public class AllowCorsAttribute : ActionFilterAttribute
{
	private string[] _domains;
	public AllowCorsAttribute()
	{
		//���[AllowCors]���Ա�ǩû�д���������ô�ʹ������ļ��ж�ȡ������ʵ�������Ȼ��������_domains
		//_domains = ����Ӧ���Ǵ������ļ��ж�����������������ɵ�����
		_domains = new string[] { "", "" };
	}

	// ��Ӧ���Ա�ǩ [AllowCors("localhost", "ip2", ...)]
	public AllowCorsAttribute(params string[] domain)
	{
		_domains = domain;
	}
	public override void OnActionExecuting(ActionExecutingContext filterContext)
	{
		var context = filterContext.RequestContext.HttpContext;
		var host = context.Request.UrlReferrer?.Host;
		var hostAddress = context.Request.UrlReferrer?.Scheme + Uri.SchemeDelimiter + context.Request.UrlReferrer?.Authority;
		if (host != null && _domains.Contains(host))
		{
			// ʹ�� * ���ܱ�֤ͬ session
			// Access-Control-Allow-Credentials Ϊ true ʱ����ֵ������ *
			filterContext.RequestContext.HttpContext.Response.AddHeader("Access-Control-Allow-Origin", hostAddress);		// ����ʹ�� *����Ҫʹ�� http://localhost:9101 ��ʽ��
		}
		filterContext.HttpContext.Response.AddHeader("Access-Control-Max-Age", "0");	// ���������������Ч
		filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Methods", "GET, HEAD, OPTIONS, POST, PUT");
		filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Headers", "Access-Control-Allow-Headers, Origin, No-Cache, Accept, X-Requested-With, If-Modified-Since, Pragma, Last-Modified, Cache-Control, Expires, Content-Type, X-E4M-With,userId,token, Access-Control-Request-Method, Access-Control-Request-Headers");
		filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Credentials","true");
		filterContext.HttpContext.Response.AddHeader("XDomainRequestAllowed", "1");
		base.OnActionExecuting(filterContext);
	}
}



}

2��///�� mvc ��򷽷�����ӱ�ǩ 
{
	// �ٶ�����վ�� http://localhost:9102
	....
	[AllowCors("localhost")]
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
			Session["name"] = "admin";
            return View();
        }

		// ���Ե�¼����ת��ԭ����ҳ��
		public ActionResult TestPage()
		{
			return View();
		}
		
		[HttpPost]
		public string TestCors()
		{
			return Session["name"] + " --- " + Session.SessionID;
		}
    }
	...
}

3�� //������һ����վ http://localhost:8001/defaule.aspx �з��ʣ�������ͬ�������ͬ��ǩ�����ܵõ���ǰ�û��� session ֵ
{
$.ajax({
	type: 'post',
	xhrFields: {
			 withCredentials:true
		   },
	url: 'http://localhost:9102/Home/TestCors',
	success: function (data) {
		alert(data);
	},
	error: function (e) {
		console.log(e.data);
	}
});
				
}

/* ����� HttpClient,��ҪЯ����Ӧ�� sessionId ���ܻ�ȡͬ���� Session

				var ss = Request.Cookies["ASP.NET_SessionID"]?.Value.ToString();
				CookieContainer sd = new CookieContainer();
				Cookie c = new Cookie("ASP.NET_SessionId", ss);
				c.Domain = "localhost";
				sd.Add(c);
				HttpClientHandler handler = new HttpClientHandler
				{
					//UseDefaultCredentials = true,
					//UseCookies = true,
					CookieContainer = sd
				};


				HttpClient _httpClient = new HttpClient(handler);
				_httpClient.BaseAddress = new Uri("https://www.codeabc.cn");
				HttpResponseMessage response = _httpClient.PostAsync("/Home/TestCors", null).Result;
				response.EnsureSuccessStatusCode();
				string oauthTokenResponse = response.Content.ReadAsStringAsync().Result;
				Response.Write(oauthTokenResponse);
*/