using Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvcTest.Controllers
{
	[Localization]
	public class LangTestController : Controller
	{
		// GET: LangTest
		public ActionResult Index()
		{
			ViewBag.Title = Globale.Name;
			ViewBag.Name = Globale.Name;
			ViewBag.Password = Resources.Globale.Password;
			return View();
		}
	}
}