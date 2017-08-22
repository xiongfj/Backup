using mvcIdentity.Areas.SuperAdmin.Model;
using mvcIdentity.Controllers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Web.Mvc;
using WebApplication5.Bll;

namespace mvcIdentity.Areas.SuperAdmin.Controllers
{
    public class RoleController : BaseController
    {
        // GET: SuperAdmin/Role
        [Description("角色列表")]
        public ActionResult Index()
        {
            CommonBLL bll = new CommonBLL();
            string sql = "select * from AspNetRoles";
            DataTable table = bll.ExecuteTable(sql);

            List<RoleViewModel> list = new List<RoleViewModel>();
            foreach (DataRow row in table.Rows)
            {
                RoleViewModel model = new RoleViewModel();
                model.Name = row["Name"].ToString();
                model.Description = row["Description"].ToString();

                list.Add(model);
            }

            return View(list);
        }
    }
}