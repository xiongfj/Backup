using mvcIdentity.Areas.SuperAdmin.Model;
using mvcIdentity.Common;
using mvcIdentity.Controllers;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvcIdentity.Areas.SuperAdmin.Controllers
{
    public class PermissionController : BaseController
    {
        // GET: SuperAdmin/Permission
        [Description("权限列表")]
        public ActionResult Index()
        {
            List<PermissionViewModel> list = new List<PermissionViewModel>();
            var permissionList = ApplicationAssembly.GetAllActionByAssembly();

            foreach (var model in permissionList)
            {
                PermissionViewModel m = new PermissionViewModel();
                m.Controller = model.Controller;
                m.Action = model.Action;
                m.Description = model.Description;

                list.Add(m);
            }

            return View(list);
        }
    }
}