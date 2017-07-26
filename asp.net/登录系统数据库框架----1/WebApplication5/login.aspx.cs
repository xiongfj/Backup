using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication5.Bll;
using WebApplication5.Common;
using WebApplication5.Model;

namespace WebApplication5
{
    public partial class login : System.Web.UI.Page
    {
        string errorInfo = string.Empty;

        protected void Page_Load(object sender, EventArgs e)
        {
        }
        protected void btnLogin_Click(object sender, EventArgs e)
        {
            //登录日志对象
            Model.SYS_LOGIN_LOG sys_login_log = new Model.SYS_LOGIN_LOG();

            //登录日志对象赋值
            sys_login_log.LOGIN_TIME = System.DateTime.Now;     // 登录时间
            sys_login_log.SYS_USER_ID = userAccount.Value.Trim();      // 用户名
            sys_login_log.LOGINIP = Request.UserHostAddress;    // 用户 ip

            if (Session["CheckCode"] != null)
            {
                #region 验证录入项
                string code = Session["CheckCode"].ToString();

                string errMsg = "";
                if (!code.ToUpper().Equals(checkcode.Value.Trim().ToUpper()))//验证码错误
                {
                    errMsg += "验证码不正确！\\n";
                    errorInfo += "验证码不正确";
                    Response.Write("<script>alert('验证码不正确!')</script>");
                    return;
                }
                #endregion

                #region 登录
                try
                {
                    string account = userAccount.Value.Trim();
                    StringHelper stringHelper = new StringHelper();
                    string pwd = stringHelper.ToMD5(password.Value.Trim()); // 数据库存储的是加密过后的数据
                   // Response.Write("<script>alert('"+ pwd + "')</script>");
                    string sql = "select * from USERINFO where username='" + account+"'";

                    CommonBLL combll = new CommonBLL();
                    DataTable dt = combll.ExecuteTable(sql);
                    if (dt.Rows.Count == 0)
                    {
                        Response.Write("<script>alert('用户不存在!!')</script>");
                        errorInfo += ". 用户不存在";
                        sys_login_log.IS_SUCCESS = "用户不存在";
                        LogM.SaveLoginLog(sys_login_log);
                        return;
                    }
                    if (dt.Rows[0]["password"].ToString() != pwd)
                    {
                        Response.Write("<script>alert('用户名或密码错误!')</script>");
                        errorInfo += ". 密码错误！";
                        sys_login_log.IS_SUCCESS = "密码错误";
                        LogM.SaveLoginLog(sys_login_log);
                        return;
                    }

                        sys_login_log.IS_SUCCESS = "登录成功";
                        LogM.SaveLoginLog(sys_login_log);

                    //登陆成功，跳转到主页
                     Response.Redirect("MainPage.aspx", false); // 如果设置 true,下面catch会出现异常!!
                }
                catch (Exception e1)
                {
                    try
                    {
                        /*登录失败：记录登录失败日志*/
                        errorInfo += ". 服务器数据库异常->";
                        errorInfo += e1.Message;
                        sys_login_log.IS_SUCCESS = errorInfo;
                        LogM.SaveLoginLog(sys_login_log);
                    }
                    catch { }
                }
                #endregion
            }
        }
    }
}