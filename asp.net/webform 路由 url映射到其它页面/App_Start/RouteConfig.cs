using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Web;
using System.Web.Routing;
using Microsoft.AspNet.FriendlyUrls;

namespace Webf
{
    public static class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            var settings = new FriendlyUrlSettings();
            settings.AutoRedirectMode = RedirectMode.Permanent;
            routes.EnableFriendlyUrls(settings);

			routes.MapPageRoute("", "", "~/Default.aspx");

			// 更改url 映射到不同的页面
			// action 和 id 都会传递到 channel/view.aspx 内
			routes.MapPageRoute("list", "samples/{action}/{id}", "~/channel/view.aspx", false, new RouteValueDictionary { { "action", "default" }, { "id", "" } });


			//routes.MapPageRoute("show", "Show/{action}", "~/show.aspx", false, new RouteValueDictionary { { "action", "all" } });

			//routes.MapPageRoute("edit", "Edit/{id}", "~/edit.aspx", false, new RouteValueDictionary { { "id", "1" } }, new RouteValueDictionary { { "id", @"\d+" } });


		}
	}
}
