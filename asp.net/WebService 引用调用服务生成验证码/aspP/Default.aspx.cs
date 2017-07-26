using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace aspP
{
    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            if (Session["CheckCode"].ToString() == this.txtCode.Text.Trim())    // Trim() 移除首位空格
            {
                Response.Write("<script>alert('验证码正确！')</script>");
            }
            else
            {
                Response.Write("<script>alert('验证码错误！')</script>");
            }
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            this.txtCode.Text = "";
            this.txtPwd.Text = "";
            this.txtUid.Text = "";
        }
    }
}