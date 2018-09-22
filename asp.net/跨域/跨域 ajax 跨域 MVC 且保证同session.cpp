
* 有两个网站 http://localhost:9101 和 http://localhost:8001
* 先打开 9101，再在同一个浏览器标签打开 8001
* 此时 8001 通过 ajax 获取的 session 与 9101 的session相同



1、//定义属性过滤标签
{



public class AllowCorsAttribute : ActionFilterAttribute
{
	private string[] _domains;
	public AllowCorsAttribute()
	{
		//如果[AllowCors]特性标签没有带域名，那么就从配置文件中读取允许访问的域名，然后将它赋给_domains
		//_domains = 这里应该是从配置文件中读出来的所有域名组成的数组
		_domains = new string[] { "", "" };
	}

	// 对应属性标签 [AllowCors("localhost", "ip2", ...)]
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
			// 使用 * 不能保证同 session
			// Access-Control-Allow-Credentials 为 true 时，该值不能是 *
			filterContext.RequestContext.HttpContext.Response.AddHeader("Access-Control-Allow-Origin", hostAddress);		// 不能使用 *，需要使用 http://localhost:9101 格式，
		}
		filterContext.HttpContext.Response.AddHeader("Access-Control-Max-Age", "0");	// 该请求多少秒内有效
		filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Methods", "GET, HEAD, OPTIONS, POST, PUT");
		filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Headers", "Access-Control-Allow-Headers, Origin, No-Cache, Accept, X-Requested-With, If-Modified-Since, Pragma, Last-Modified, Cache-Control, Expires, Content-Type, X-E4M-With,userId,token, Access-Control-Request-Method, Access-Control-Request-Headers");
		filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Credentials","true");
		filterContext.HttpContext.Response.AddHeader("XDomainRequestAllowed", "1");
		base.OnActionExecuting(filterContext);
	}
}



}

2、///在 mvc 类或方法上添加标签 
{
	// 假定该网站是 http://localhost:9102
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

		// 测试登录后跳转会原来的页面
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

3、 //在另外一个网站 http://localhost:8001/defaule.aspx 中访问，必须是同浏览器不同标签，才能得到当前用户的 session 值
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

/* 如果是 HttpClient,需要携带对应的 sessionId 才能获取同样的 Session

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