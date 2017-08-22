using mvcIdentity.Areas.SuperAdmin.Model;
using mvcIdentity.Controllers;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebApplication5.Bll;

namespace mvcIdentity.Areas.SuperAdmin.Controllers
{
    public class UserController : BaseController
    {
        // GET: SuperAdmin/User
        [Description("用户列表")]
        public ActionResult Index()
        {
            CommonBLL bll = new CommonBLL();
            string sql = "select * from AspNetUsers";
            DataTable table = bll.ExecuteTable(sql);

            List<UserViewModel> list = new List<UserViewModel>();
            foreach (DataRow row in table.Rows)
            {
                UserViewModel model = new UserViewModel();
                model.Id = row["Id"].ToString();
                model.UserName = row["UserName"].ToString();
                model.Email = row["Email"].ToString();

                list.Add(model);
            }

            return View(list);
        }

        public ActionResult Edit(string id)
        {
            CommonBLL bll = new CommonBLL();
            string sql = "select * from AspNetUsers where Id=@Id";
            SqlParameter param = new SqlParameter("@Id", id);
            param.SqlDbType = SqlDbType.NVarChar;

            DataTable table = bll.ExecuteTable(sql, param);
            UserViewModel model = new UserViewModel();
            if (table.Rows.Count == 1)
            {
                DataRow row = table.Rows[0];
                model.Id = row["Id"].ToString();
                model.UserName = row["UserName"].ToString();
                model.Email = row["Email"].ToString();
            }
            else
                return HttpNotFound();

            return View(model);
        }
    }
}