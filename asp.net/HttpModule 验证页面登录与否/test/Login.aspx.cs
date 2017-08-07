using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace test
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Login_Button(object button, EventArgs e)
        {
            if (Request.QueryString["source"] != null)
            {
                string s = Request.QueryString["source"].ToLower().ToString();   //取出从哪个页面转来的
                Session["user"] = un.Text;
                Response.Redirect(s); //转到用户想去的页面
            }
            else
            {
               // Response.Redirect("main.aspx");    //默认转向main.aspx
            }
        }
    }
}