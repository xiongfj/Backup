using System;
using System.Collections.Generic;
using System.Linq;
using System.Web.Http;

namespace WebApplication9
{
	public static class WebApiConfig
	{
		public static void Register(HttpConfiguration config)
		{
			// Web API configuration and services

			//string origins = "*";
			//EnableCorsAttribute cors = new EnableCorsAttribute(origins, "*", "*");
			//config.EnableCors(cors);

			// Web API routes
			config.MapHttpAttributeRoutes();

			config.Routes.MapHttpRoute(
				name: "DefaultApi",
				routeTemplate: "api/{controller}/{id}",
				//routeTemplate: "api/{controller}/{action}/{id}", 这样可以与 mvc 那样写 url，可以指定某个 post 函数，可以有多个同样method的函数
				defaults: new { id = RouteParameter.Optional }
			);
			
			// 可以同时匹配两种路由,action 可以写或不写
		//	config.Routes.MapHttpRoute("DefaultApiWithActionAndId", "api/{controller}/{action}/{id}"/*, new { id = RouteParameter.Optional } 不可使用！*/);
		}
	}
}
