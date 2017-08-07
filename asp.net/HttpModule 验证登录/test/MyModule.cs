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
            application.PreRequestHandlerExecute += PreRequestHandlerExcute;
        }

        /* 页面跳转逻辑:
         * 某个用户请求 http://lcoalhost:22323/Default.aspx后, 在输出页面之前进入这个函数
         * 判断这个 url 不是登录页面并且用户没有登录
            -> 跳转到 Login.aspx 登录页面
            -> 在显示 Login.aspx 页面之前又进入这个函数, 判断是 Login.aspx 则不进行跳转, 最后显示 Login.aspx 
         * Login.aspx 点击登录按钮会进入这个函数, 该函数判断 Url 是 Login.aspx, 则不处理,
         * 接着响应用户的按钮点击事件, 登录后跳转页面又进入这个函数, 此时判断url不是 login.aspx, 但是用户已经登录,也不处理,
         * 最后页面跳转会 Default.aspx
         */
        public void PreRequestHandlerExcute(object sender, EventArgs e)
        {
            HttpApplication ha = (HttpApplication)sender;
            string path = ha.Context.Request.Url.ToString();
            int n = path.ToLower().IndexOf("login.aspx");

            // 如果该 url 不是 Login.aspx
            if (n == -1)
            {
                if (ha.Context.Session["user"] == null) //是否Session中有用户名，若是空的话，转向登录页。
                {
                    ha.Context.Response.Write("<script>alert('请登录..')</script>");
                    ha.Context.Server.Transfer("Login.aspx?source=" + path);
                }
            }
        }
    }
}