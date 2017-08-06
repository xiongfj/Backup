using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace test.Handler
{
    public class MyHandler : IHttpHandler, IRequiresSessionState
    {
        #region IHttpHandler 成员

        public bool IsReusable
        {
            get { return true; }
        }

        public void ProcessRequest(HttpContext context)
        {
            // PhySicalPath = "F:\\vs2017----\\test\\test\\test.xl" 之类的
            if ( File.Exists(context.Request.PhysicalPath) )
            {
                context.Response.Write("<h1><b>Hello HttpHandler_1</b></h1>");
                context.Session["Test"] = "MyHandler_1";
                context.Response.Write(context.Session["Test"]);
            }
            else
                context.Response.Write("请求的文件不存在!");
        }

        #endregion
    }
}