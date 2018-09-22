using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web;
using System.Web.Helpers;
using System.Web.Mvc;

namespace WebApplication1.App_Start
{
	public class TokenAttribute : ActionFilterAttribute
	{
		private string[] _domains;
		public TokenAttribute()
		{
			//如果[AllowCors]特性标签没有带域名，那么就从配置文件中读取允许访问的域名，然后将它赋给_domains
			//_domains = 这里应该是从配置文件中读出来的所有域名组成的数组
			_domains = new string[] { "", "" };
		}

		// 对应属性标签 [AllowCors("localhost", "ip2", ...)]
		public TokenAttribute(params string[] domain)
		{
			_domains = domain;
		}
		public override void OnActionExecuting(ActionExecutingContext filterContext)
		{
			var context = filterContext.RequestContext.HttpContext;
			var host = context.Request.UrlReferrer?.Host;
			var hostAddress = context.Request.UrlReferrer?.Scheme + Uri.SchemeDelimiter + context.Request.UrlReferrer?.Authority;
			if (host != null)
			{
				Log.WriteLog("* OnActionExecuting " + hostAddress);
				filterContext.RequestContext.HttpContext.Response.AddHeader("Access-Control-Allow-Origin", hostAddress);        // 不能使用 *，需要使用 http://localhost:9101 格式，
			}

			filterContext.HttpContext.Response.AddHeader("Access-Control-Max-Age", "0");
			filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Methods", "GET, HEAD, OPTIONS, POST, PUT");
			filterContext.HttpContext.Response.AddHeader("Access-Control-Request-Methods", "GET, DELETE, OPTIONS, POST, PUT");
			filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Headers", "Access-Control-Allow-Headers, Origin, No-Cache, Accept, X-Requested-With, If-Modified-Since, Pragma, Last-Modified, Cache-Control, Expires, Content-Type, X-E4M-With,userId,token, Access-Control-Request-Method, Access-Control-Request-Headers, __RequestVerificationToken");
			filterContext.HttpContext.Response.AddHeader("Access-Control-Allow-Credentials", "true");
			filterContext.HttpContext.Response.AddHeader("XDomainRequestAllowed", "1");
			base.OnActionExecuting(filterContext);
		}
	}

	[AttributeUsage(AttributeTargets.Class | AttributeTargets.Method)]
	public class AjaxValidateAntiForgeryTokenAttribute : FilterAttribute, IAuthorizationFilter
	{
		public void OnAuthorization(AuthorizationContext filterContext)
		{
			//Log.WriteLog("* AjaxValidateAntiForgeryToken ");

			if (filterContext == null)
			{
				throw new ArgumentNullException("filterContext");
			}

			var request = filterContext.HttpContext.Request;

			var antiForgeryCookie = request.Cookies[AntiForgeryConfig.CookieName];
			var cookieValue = antiForgeryCookie != null ? antiForgeryCookie.Value : null;

			//Log.WriteLog("* AjaxValidateAntiForgeryToken -> " + cookieValue);

			var formToken = request.Headers["__RequestVerificationToken"];
			AntiForgery.Validate(cookieValue, formToken);
		}
	}
}