using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace test.Module
{
    public class CompleteRequest : IHttpModule
    {
        public void Dispose() { }
        public void Init(HttpApplication application)
        {
            application.BeginRequest += new EventHandler(Application_BeginRequest);
            //下面两个是从剩下的近20个事件中随机选择的两个，可以发现这两个事件都不会触发，因为在BeginRequest中调用了CompleteRequest方法，导致直接跳到EndRequest事件。  
            application.PostResolveRequestCache += (sender, e) => { application.Context.Response.Write("Application_PostResolveRequestCache<br/>"); };
            application.PostMapRequestHandler += (sender, e) => { application.Context.Response.Write("Application_PostMapRequestHandler<br/>"); };
            //EndRequest事件会被执行，PreSendRequestHeaders与PreSendRequestContent因为在EndRequest之后，因此也会被执行  
            application.EndRequest += (sender, e) => { application.Context.Response.Write("Application_EndRequest<br/>"); };
            application.PreSendRequestHeaders += (sender, e) => { application.Context.Response.Write("Application_PreSendRequestHeaders<br/>"); };
            application.PreSendRequestContent += (sender, e) => { application.Context.Response.Write("Application_PreSendRequestContent<br/>"); };
        }
        public void Application_BeginRequest(object sender, EventArgs e)
        {
            HttpApplication application = sender as HttpApplication;
            application.CompleteRequest();
            
            //这句话的意思，是让浏览器用utf8来解析返回的数据  
            application.Context.Response.ContentType = "text/html;charset=UTF-8";
            application.Context.Response.Write("请求被终止<br/>");
        }
    }
}