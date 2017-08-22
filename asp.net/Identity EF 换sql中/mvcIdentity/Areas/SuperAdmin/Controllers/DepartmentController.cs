using mvcIdentity.Areas.SuperAdmin.Model;
using mvcIdentity.Controllers;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebApplication5.Bll;

namespace mvcIdentity.Areas.SuperAdmin.Controllers
{
    public class DepartmentController : BaseController
    {
        // GET: Admin/Department
        [Description("部门列表")]
        public ActionResult Index()
        {
            CommonBLL bll = new CommonBLL();
            string sql = "select * from Departments";
            DataTable table = bll.ExecuteTable(sql);

            List<DepartmentViewModel> list = new List<DepartmentViewModel>();
            foreach(DataRow row in table.Rows)
            {
                DepartmentViewModel model = new DepartmentViewModel();
                model.Id = int.Parse(row["Id"].ToString());
                model.Name = row["Name"].ToString();

                list.Add(model);
            }

            return View(list);
        }
    }
}