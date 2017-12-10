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

        // 事件响应顺序..
        public void Init(HttpApplication application)
        {
            application.BeginRequest += (sender, e) => {
				application.Context.Response.Write("Application_BeginRequest<br/>");
            };

            application.AuthenticateRequest += (sender, e) => {
				application.Context.Response.Write("Application_AuthenticateRequest<br/>"); };
            application.PostAuthenticateRequest += (sender, e) => {
				application.Context.Response.Write("Application_PostAuthenticateRequest<br/>"); };
            application.AuthorizeRequest += (sender, e) => {
				application.Context.Response.Write("Application_AuthorizeRequest<br/>"); };
            application.PostAuthorizeRequest += (sender, e) => {
				application.Context.Response.Write("Application_PostAuthorizeRequest<br/>"); };
            application.ResolveRequestCache += (sender, e) => {
                application.Context.Response.Write("Application_ResolveRequestCache<br/>");
            };
            application.PostResolveRequestCache += (sender, e) => {
                application.Context.Response.Write("Application_PostResolveRequestCache<br/>"); };
            application.PostMapRequestHandler += (sender, e) => {
                application.Context.Response.Write("Application_PostMapRequestHandler<br/>"); };
            application.AcquireRequestState += (sender, e) => {
               // ((HttpApplication)sender).Session["d"] = "hello";
               // 还不能用 Session ?!?
                //var value = ((HttpApplication)sender).Session["d"];
				if (application.Context.Session != null )		// 会发生多次请求, Session 最后一次才生成
					application.Context.Response.Write("Application_AcquireRequestState<br/>"); };

            application.PostAcquireRequestState += (sender, e) => {
				application.Context.Response.Write("Application_PostAcquireRequestState<br/>"); };
            application.PreRequestHandlerExecute += (sender, e) => {
				application.Context.Response.Write("Application_PreRequestHandlerExecute<br/>"); };
            
            /*
            .....
            这里正在执行页面生命周期....
            .....
            */


            // 页面显示完后响应下面事件
            application.PostRequestHandlerExecute += (sender, e) => {
				application.Context.Response.Write("Application_PostRequestHandlerExecute<br/>"); };
            application.ReleaseRequestState += (sender, e) => {
				application.Context.Response.Write("Application_ReleaseRequestState<br/>"); };
            application.PostReleaseRequestState += (sender, e) => {
				application.Context.Response.Write("Application_PostReleaseRequestState<br/>"); };
            application.UpdateRequestCache += (sender, e) => {
				application.Context.Response.Write("Application_UpdateRequestCache<br/>"); };
            application.PostUpdateRequestCache += (sender, e) => {
				application.Context.Response.Write("Application_PostUpdateRequestCache <br/>"); };
            application.EndRequest += (sender, e) => {
				application.Context.Response.Write("Application_EndRequest<br/>"); };
            application.PreSendRequestHeaders += (sender, e) => {
				application.Context.Response.Write("Application_PreSendRequestHeaders<br/>"); };
            application.PreSendRequestContent += (sender, e) => {
				
				application.Context.Response.Write("Application_PreSendRequestContent<br/>"); };
        }
    }
}