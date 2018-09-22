using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WebApplication1.App_Start
{

	public class MyModule : IHttpModule
	{
		private static string[] domins = { "http://localhost:50464", "http://localhost:50465" };

		public void Dispose()
		{
			// throw new NotImplementedException();
		}

		// 事件响应顺序..
		public void Init(HttpApplication application)
		{
			application.BeginRequest += (sender, e) => {

				var http = application.Context;

				// 响应 options 请求，返回 202 表示允许，继而浏览器才能接着发起 post get 请求
				if (http.Request.HttpMethod == "OPTIONS")
				{
					if (http.Request.Headers["Origin"] != null && domins.Contains(http.Request.Headers["Origin"]))
					{
						http.Response.AddHeader("Access-Control-Allow-Origin", http.Request.Headers["Origin"]);        // 不能使用 *，需要使用 http://localhost:9101 格式，
					}

					//http.Response.AddHeader("Access-Control-Allow-Origin", "http://localhost:50464");
					//http.Response.AddHeader("Access-Control-Allow-Origin", "*");		// 如果 ajax 设置了 withCredentials=true，不能使用 * !!使用 * 好像 ajax 无法携带 cookie Request
					http.Response.AddHeader("Access-Control-Allow-Methods", "GET, HEAD, OPTIONS, POST, PUT");
					http.Response.AddHeader("Access-Control-Request-Methods", "GET, DELETE, OPTIONS, POST, PUT");
					http.Response.AddHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, __RequestVerificationToken");		// 对应 ajax 设置的请求头
					http.Response.AddHeader("Access-Control-Allow-Credentials", "true");        // 对应 ajax 的 withCredentials=true；貌似必须设置
					http.Response.StatusCode = 202;			// 响应 options 请求，使浏览器稍后发起 post 请求
				}
			};
		}
	}
}