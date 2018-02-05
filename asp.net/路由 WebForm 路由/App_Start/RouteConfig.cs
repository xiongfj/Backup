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
			settings.AutoRedirectMode = RedirectMode.Off;
			routes.EnableFriendlyUrls(settings);

			routes.MapPageRoute("", "", "~/Default.aspx");

			// 更改url 映射到不同的页面
			// action 和 id 都会传递到 channel/view.aspx 内
			// channel 是一个文件夹, view.aspx 在该文件夹下面
			// 然后就可以使用 url: .../samples/
			// 项目根目录下不能有 samples 文件夹. 不然会访问文件夹而不会匹配路由. 导致页面无法显示
			//routes.MapPageRoute("view", "samples/{action}/{id}", "~/channel/view.aspx", false, new RouteValueDictionary { { "action", "default" }, { "id", "" } });

			// 这样写可以保持原来的 xx.aspx?id=12&catelog=xxx ... 获取参数的形式
			routes.MapPageRoute("test", "{channel}", "~/channel/view.aspx", false, new RouteValueDictionary { }, new RouteValueDictionary { { "channel", @"test|test.aspx" } });

			// 貌似一次只能指定一个物理页面文件??!
			//routes.MapPageRoute("list", "samples/list/{id}", "~/channel/list.aspx", false, new RouteValueDictionary {{ "id", "" } });

			//routes.MapPageRoute("show", "Show/{action}", "~/show.aspx", false, new RouteValueDictionary { { "action", "all" } });

			// 设置正则过滤
			//routes.MapPageRoute("edit", "Edit/{id}", "~/edit.aspx", false, new RouteValueDictionary { { "id", "1" } }, new RouteValueDictionary { { "id", @"\d+" } });
			//routes.MapPageRoute("view", "{channel}/{action}/{id}", "~/channel/view.aspx", false,
			//	new RouteValueDictionary { { "action", "default" }, { "id", "" } },
			//	new RouteValueDictionary { { "channel",@"downloads|news|samples|skills"}, { "action", @"view|view.aspx" } });


		}
	}
}
