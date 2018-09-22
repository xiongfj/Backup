using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvcLoginTest.Controllers
{
	public class HomeController : Controller
	{
		public ActionResult Index()
		{
			Session.Timeout = 1;
			return View();
		}

		[Authorize]
		public ActionResult About()
		{
			ViewBag.Message = "Your application description page.";

			return View();
		}

		[SelfOnly]
		public ActionResult Contact()
		{
			ViewBag.Message = "Your contact page.";

			return View();
		}
	}
}