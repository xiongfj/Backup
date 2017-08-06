using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace test.Handler
{
    public class MyHandlerFactory : IHttpHandlerFactory
    {
        #region IHttpHandlerFactory 成员

        // 假设请求的是 http://localhost:2329/xx/Handler_1.asd
        public IHttpHandler GetHandler(HttpContext context, string requestType, string url, string pathTranslated)
        {
            // url 是 ../xx/Handler_1.asd 之类的
            // pathTranslated 是 web.config 内指定 <add .. path="*.asd" /> asd后缀的文件路径: F:/xx/xx/xx..
            // requestType = 'GET" 或者 POST
            string fname = url.Substring(url.IndexOf('/') + 1);     // fname 截取后= xx/Handler_1.asd 之类的

            // 如果fname内还有 '/', 则从 '/' + 1处索引开始截取到字符串末尾,赋值给 fname, 依次再检测
            while (fname.IndexOf('/') != -1)
                fname = fname.Substring(fname.IndexOf('/') + 1);

            string cname = fname.Substring(0, fname.IndexOf('.'));  // 截取 Handler_1.asd 中的 Handler_1
            string className = "test.Handler." + cname;

            object h = null;

            try
            {
                // 采用动态反射机制创建相应的IHttpHandler实现类。
                h = Activator.CreateInstance(Type.GetType(className));
            }
            catch (Exception e)
            {
                throw new HttpException("工厂不能为类型" + cname + "创建实例。", e);
            }

            return (IHttpHandler)h;
        }

        public void ReleaseHandler(IHttpHandler handler)
        {
        }

        #endregion
    }

    // url= http://localhost:2312/../Handler_1.asd 访问的是此类
    public class Handler_1 : IHttpHandler, IRequiresSessionState
    {
        #region IHttpHandler 成员

        public bool IsReusable
        {
            get { return true; }
        }

        public void ProcessRequest(HttpContext context)
        {
            context.Response.Write("<h1><b>Hello HttpHandler_1</b></h1>");
            context.Session["Test"] = "MyHandler_1";
            context.Response.Write(context.Session["Test"]);
        }

        #endregion
    }

    // url= http://localhost:2312/../Handler_2.asd 访问的是此类
    public class Handler_2 : IHttpHandler, IRequiresSessionState
    {
        #region IHttpHandler 成员

        public bool IsReusable
        {
            get { return true; }
        }

        public void ProcessRequest(HttpContext context)
        {
            context.Response.Write("<h1><b>Hello HttpHandler_2</b></h1>");
            context.Session["Test2"] = "MyHandler_222222222";
            context.Response.Write(context.Session["Test2"]);
        }

        #endregion
    }
}