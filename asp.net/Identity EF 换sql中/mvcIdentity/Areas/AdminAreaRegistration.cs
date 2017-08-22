using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvcIdentity.Areas
{
    public class AdminAreaRegistration : AreaRegistration
    {
        public override string AreaName { get { return "SuperAdmin"; } }

        public override void RegisterArea(AreaRegistrationContext context)
        {
            context.MapRoute(
                "SuperAdmin_default",
                "SuperAdmin/{controller}/{action}/{id}",
                new { controller = "Department", action = "Index", id = UrlParameter.Optional },
                new string[] { "mvcIdentity.Areas.SuperAdmin.Controllers" }
            );
        }
    }
}