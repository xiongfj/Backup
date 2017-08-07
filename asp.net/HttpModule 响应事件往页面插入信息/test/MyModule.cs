using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace test.Module
{
    public class MyModule : IHttpModule
    {
        public void Dispose()
        {
            // throw new NotImplementedException();
        }

        public void Init(HttpApplication context)
        {
            context.EndRequest += new EventHandler(context_EndRequest);
        }

        void context_EndRequest(object sender, EventArgs e)
        {
            HttpApplication ha = (HttpApplication)sender;

            // 三个都是同一个 Response
/*            HttpResponse respone = ha.Response;
            HttpResponse re = ha.Context.Response;
            HttpResponse rs = HttpContext.Current.Response;
            */

            ha.Response.Write("<!-- 我是 Module 插入页面的内容 -->");

        }
    }
}