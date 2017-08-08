using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace test.Module
{
    public class ErrorModule : IHttpModule
    {
        public void Dispose()
        { }  //这里没有什么要释放的资源，所以这里为空  
        public void Init(HttpApplication application)
        {
            application.Error += new EventHandler(application_Error);
            application.BeginRequest += new EventHandler(application_BeginRequest);
        }
        private void application_BeginRequest(object sender, EventArgs e)
        {
            throw new Exception("这里故意抛出一个异常，用于测试！"); //Application在运行时可能会出现异常，但是这是小概率事件，所以这里主动抛出异常以便进行测试  
        }
        private void application_Error(object sender, EventArgs e)
        {
            HttpApplication application = (HttpApplication)sender;

            //这里可以设置断点进行监视  
            // LastError 的内容就是 "这里故意抛出一个异常，用于测试！"
            Exception LastError = application.Context.Server.GetLastError();    //这里获取异常信息  
            //这里利用LastError，添加任意代码进行错误处理，一般操作是记录错误日志，以便后续查错修正  
        }
    }
}