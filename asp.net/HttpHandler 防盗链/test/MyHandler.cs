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
            //站点的域名
            string myDomain = "localhost";

            if (context.Request.UrlReferrer == null ||
                context.Request.UrlReferrer.Host.ToLower().IndexOf(myDomain) < 0)
            {
                //如果是通过浏览器直接访问或者是通过其他站点访问过来的，则显示“资源不存在”图片
                context.Response.ContentType = "image/JPEG";
                context.Response.WriteFile(context.Request.PhysicalApplicationPath + "no.jpg");
            }
            else
            {
                //如果是通过站内访问的，这正常显示图片
                context.Response.ContentType = "image/JPEG";
                context.Response.WriteFile(context.Request.PhysicalPath);
            }
        }

        #endregion
    }
}