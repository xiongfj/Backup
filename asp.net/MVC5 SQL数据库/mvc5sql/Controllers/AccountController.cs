using mvc5sql.Bll;
using mvc5sql.Common;
using mvc5sql.Models;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvc5sql.Controllers
{
    public class AccountController : Controller
    {
        string errorInfo = string.Empty;

        // GET: Account
        public ActionResult Login()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Login(LoginViewModel model)
        {
            if (!ModelState.IsValid)
            {
                return View(model);
            }

            SYS_LOGIN_LOG sys_login_log = new SYS_LOGIN_LOG();

            //登录日志对象赋值
            sys_login_log.LOGIN_TIME = System.DateTime.Now;     // 登录时间
            sys_login_log.SYS_USER_ID = model.username.Trim();// userAccount.Value;      // 用户名
            sys_login_log.LOGINIP = Request.UserHostAddress;    // 用户 ip

            if (Session["CheckCode"] != null)
            {
                #region 验证录入项
                string code = Session["CheckCode"].ToString();

                string errMsg = "";
                if (!code.ToUpper().Equals(model.code.Trim().ToUpper()))//验证码错误
                {
                    errMsg += "验证码不正确！\\n";
                    errorInfo += "验证码不正确";
                    Response.Write("<script>alert('验证码不正确!')</script>");
                    return View(model);
                }
                #endregion

                #region 登录
                try
                {
                    string account = model.username.Trim();
                    StringHelper stringHelper = new StringHelper();
                    string pwd = stringHelper.ToMD5(model.password.Trim()); // 数据库存储的是加密过后的数据
                                                                            // Response.Write("<script>alert('"+ pwd + "')</script>");
                    string sql = "select * from USERINFO where username='" + account + "'";

                    CommonBLL combll = new CommonBLL();
                    DataTable dt = combll.ExecuteTable(sql);
                    if (dt.Rows.Count == 0)
                    {
                        Response.Write("<script>alert('用户不存在!!')</script>");
                        errorInfo += ". 用户不存在";
                        sys_login_log.IS_SUCCESS = "用户不存在";
                        LogM.SaveLoginLog(sys_login_log);
                        return Content("用户不存在");
                    }
                    if (dt.Rows[0]["password"].ToString() != pwd)
                    {
                        Response.Write("<script>alert('用户名或密码错误!')</script>");
                        errorInfo += ". 密码错误！";
                        sys_login_log.IS_SUCCESS = "密码错误";
                        LogM.SaveLoginLog(sys_login_log);
                        return Content("密码错误"); ;
                    }

                    sys_login_log.IS_SUCCESS = "登录成功";
                    LogM.SaveLoginLog(sys_login_log);

                    //登陆成功，跳转到主页
                    return Content("login success");
                    //RedirectToAction("Index");
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
            return Content("loginning");
        }
    }
}