using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Web;
using System.Web.Http;

namespace Implicit.Controllers
{
    public class CodesController : ApiController
    {
		[HttpGet]   // 跨域需要; 同时 WebApiConfig.cs 内添加 config.EnableCors(new EnableCorsAttribute("*", "*", "*")); using System.Web.Http.Cors;
		[Route("api/access_token")]
		public HttpResponseMessage GetToken()
		{
			var url = Request.RequestUri;

			// 会自动回调 url 并加上 access_token, state, 之类的
			// 然后在 响应 url 的网站 js 中获取 hash, 不能在后台获取, 应为是 # 开头, 会被浏览器过滤掉
			return new HttpResponseMessage()
			{
				Content = new StringContent("", Encoding.UTF8, "text/plain")
			};
		}
	}
}
