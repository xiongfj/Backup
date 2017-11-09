using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace MainTain
{
	public class RouteConfig
	{
		public static void RegisterRoutes(RouteCollection routes)
		{
			routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

			routes.MapRoute(
				name: "Default",
				url: "{controller}/{action}/{id}",
				defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional },
				namespaces: new string[] { "Go.Controllers" }
			);

			routes.MapRoute(
				name: "target",
				url: "{id}",
				defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional },
				constraints: new { id = new MyRouteConstraint() },
				namespaces: new string[] { "Go.Controllers" }
			);
		}
	}

	/// <summary>
	/// 自定义路由验证约束
	/// </summary>
	public class MyRouteConstraint : IRouteConstraint
	{
		public bool Match(HttpContextBase httpContext, Route route, string parameterName, RouteValueDictionary values, RouteDirection routeDirection)
		{
			//获取id的值
			var id = values[parameterName];

			if (id.ToString().StartsWith("163"))
				return true;

			return false;
		}
	}
}
