using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace aspP
{
    public partial class CheckCode : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            localhost.WebService image = new localhost.WebService();

            // 不添加Web引用貌似也可以直接使用,不添加貌似只能在本地访问.. 需要访问服务器的函数还是需要添加服务器的web引用
           // WebService image = new WebService();
            int length = 4;
            string strKey = CheckingCode(length);

            // out 也是引用，传递的参数可以不初始化，申明和调用都必须带out
            // ref 表示引用传递参数，原来的值会在函数内被改变，ref这里可不写
            byte[] data = image.CheckCodeService(length, ref strKey);

            Response.Cache.SetNoStore();        // 不缓存该页面, 防止浏览器后退操作不刷新验证码
                                                // Response.Expires = 0;
                                                //Response.CacheControl = "no-cache";
            Response.OutputStream.Write(data, 0, data.Length);
        }
        public string CheckingCode(int length)
        {
            string strResult = "";
            // 采用的字符集，可以随即拓展，并可以控制字符出现的几率
            string strCode = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            Random rd = new Random();
            for (int i = 0; i < length; i++)
            {
                char c = strCode[rd.Next(strCode.Length)];
                // 随机获取字符
                strResult += c.ToString();
            }
            Session["CheckCode"] = strResult;
            return strResult;
        }
    }
}