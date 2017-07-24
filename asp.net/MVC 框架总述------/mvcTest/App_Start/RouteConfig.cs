using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

/***** url路由定义例子：
 * {controller}/{action}/{id}   一个匹配的url -> /Products/show/beverages
    1、Products是控制器的名称(类名？)， 
    2、show是控制器内的一个方法， 
    3、beverages 是一个 id 变量。

 * {table}/Details.aspx  一个匹配的url  ->  /Products/Details.aspx
   1、Products 此时是一个数据表名称
   2、Details.aspx 是一个常量

 * blog/{action}/{entry}  一个匹配的url  -> /blog/show//123
   1、blog 是一个常量，匹配url的时候照写即可。
   2、show 此时是摸个控制器的一个方法
   3、123 是一个 entry 变量

 ****** RouteTable 内的 static RouteCollection Routes 添加路由的两种方法:
 * 1. Routes.Add(sring name, RouteBase item)    // Routes.Add("default", new Route(new Route("Category/{action}/{categoryName}", new MvcRouteHandler())));     
 * 2. Routes.Add(new Route("Category/{action}/{categoryName}", new MvcRouteHandler())); // 调用的是泛型类Collection<RouteBase>的 Add(RouetBase)
 * 3. Routes.MapRoute(string name, string url, object defaults, object constraints, string[] namespace);
 ***/

namespace mvcTest
{
    public class RouteConfig
    {
        // 实现MVC应用程序的URL寻址功能
        // 如果要在程序单元测试的时候调用该函数，该函数必须是static的且含有RouteCollection参数
        // 参数路由一般存储在 System.Web.Routing.RouteTable.Routes 静态成员内.
        public static void RegisterRoutes(RouteCollection routes)
        {
            // 表示不需要处理这些路由
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");   // 定义了可以忽略的配置
            Route s;

            // 设置一个路由
            routes.MapRoute(
                name: "Default",        // 路由名称

                // {} 内是参数
                // '/' 和 '.' 作为分隔符，
                // 不在括号或方括号的信息被看作一个常量
                // 如果url请求不匹配这个url，也没偶定义默认url，那么路由将不处理这个请求，由asp.net解析
                url: "{controller}/{action}/{id}",  // 带参数的 url

                // 如果只请求 http://localhost:3313 实际上就是请求 http://localhost:3313/Home/Index/xxx
                defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional }//默认参数值
            );
            // 调用的是泛型模版内的函数
          //  routes.Add(new Route("Category/{action}/{categoryName}", new MvcRouteHandler()));
        }
    }
}

/****** 设置URL路由参数的默认值:
 *  routes.Add( new Route("Category/{action}/{categoryName}")
         {
            Defaults = new RouteValueDictionary{{"categoryName", "food"}, {"action", "show"} }
         }
        );
    1. 如果被请求的URL是: /Category    实际上请求的是 -> /Category/show/food
    2. 请求路由 /Category/add   实际上就是请求-> /Category/add/food
    3. 请求路由 /Category/add/beverages 是本身.
 */
