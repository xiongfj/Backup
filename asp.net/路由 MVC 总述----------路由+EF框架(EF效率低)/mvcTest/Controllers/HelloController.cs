using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

/*
 * ViewBag 是属于方法和其对应页面的
    即使是同名的方法, 它们return View 同一个View, ViewBag 也是无法共用的
 
   */

namespace mvcTest.Controllers
{
    public class HelloController : Controller
    {
        public ActionResult Index()
        {
            // 将对应的 Views/Hello/Index.cshtml 内容输出到浏览器
            return View();
        }

        public ActionResult Welcome(string name, int id = 1)
        {
            // ViewBag 是该控制器的对台容器元素, 可以添加任何属性并赋值,
            // 在对应的 .cshtml 文件内通过 ViewBag 获取数据; 使用 @ViewBag.Message 嵌入到标签内
            ViewBag.Message = "Hello: " + name + "先生";
            ViewBag.times = id;
            return View();
        }

        /// http://localhost:3313/hello 默认访问的是 Index 函数, 在RouteConfig.cs 内配置默认值
        /// 要指定调用哪个函数需要 http://localhost:3313/hello/Welcome
        public string Index2()
        {
            // 这里一般返回一个 View, 而不是直接返回 字符窜 或 html
            return "hello world!";
        }

        /// <summary>
        /// http://localhost:3313/hello/Welcome?name=Mack&age=19

        /// 或添加路由格式
        /* 
         * routes.MapRoute(
            name: "Default", 
            url: "{controller}/{action}/{name}/{id}", 
            defaults: new { controller = "Home", action = "Index", name="default-name", id = UrlParameter.Optional }//默认参数值
       
        * 例如请求 localhost:3343/hello/welcome/Jack/23 与localhost:3343/hello/welcome?name=Jack&age=10 相同
        * 此时还可以 localhost:3342/hello/welcome 访问, 因为设置了默认值 defaults:
        */
        /// </summary>
        /// <param name="name"></param>
        /// <param name="age">默认值, 如果不传 age 默认=22</param>
        /// <returns></returns>
        public string WelcomeJack(string name, int age = 22)
        {
            return HttpUtility.HtmlEncode("welcome: " + name + ", age " + age);
        } 
    }
}