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

			// ����url ӳ�䵽��ͬ��ҳ��
			// action �� id ���ᴫ�ݵ� channel/view.aspx ��
			// channel ��һ���ļ���, view.aspx �ڸ��ļ�������
			// Ȼ��Ϳ���ʹ�� url: .../samples/
			// ��Ŀ��Ŀ¼�²����� samples �ļ���. ��Ȼ������ļ��ж�����ƥ��·��. ����ҳ���޷���ʾ
			//routes.MapPageRoute("view", "samples/{action}/{id}", "~/channel/view.aspx", false, new RouteValueDictionary { { "action", "default" }, { "id", "" } });

			// ����д���Ա���ԭ���� xx.aspx?id=12&catelog=xxx ... ��ȡ��������ʽ
			routes.MapPageRoute("test", "{channel}", "~/channel/view.aspx", false, new RouteValueDictionary { }, new RouteValueDictionary { { "channel", @"test|test.aspx" } });

			// ò��һ��ֻ��ָ��һ������ҳ���ļ�??!
			//routes.MapPageRoute("list", "samples/list/{id}", "~/channel/list.aspx", false, new RouteValueDictionary {{ "id", "" } });

			//routes.MapPageRoute("show", "Show/{action}", "~/show.aspx", false, new RouteValueDictionary { { "action", "all" } });

			// �����������
			//routes.MapPageRoute("edit", "Edit/{id}", "~/edit.aspx", false, new RouteValueDictionary { { "id", "1" } }, new RouteValueDictionary { { "id", @"\d+" } });
			//routes.MapPageRoute("view", "{channel}/{action}/{id}", "~/channel/view.aspx", false,
			//	new RouteValueDictionary { { "action", "default" }, { "id", "" } },
			//	new RouteValueDictionary { { "channel",@"downloads|news|samples|skills"}, { "action", @"view|view.aspx" } });


		}
	}
}
