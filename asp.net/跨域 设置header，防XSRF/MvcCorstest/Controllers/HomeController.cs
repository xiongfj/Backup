using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace MvcCorstest.Controllers
{
	public class HomeController : Controller
	{

		private static readonly string[] _purposes = new string[] { "System.Web.Helpers.AntiXsrf.AntiForgeryToken.v1" };
		public ActionResult Index()
		{
			byte[] sd = System.Text.Encoding.Default.GetBytes("a");
			sd = MachineKey.Protect(sd, _purposes);

			ViewBag.securet = HttpServerUtility.UrlTokenEncode(sd);

			byte[] rawProtectedBytes = HttpServerUtility.UrlTokenDecode("DgDfVEwUNeB-oQLsjtv9s2zMfDZv_ytAEQE0okbmQ5UwztkxmprpR1l1anBZw3cNAVRP7g2");
			try
			{
				byte[] ff = MachineKey.Unprotect(rawProtectedBytes, _purposes);
				ViewBag.result = System.Text.Encoding.Default.GetString(ff);
			}
			catch(Exception e){
				ViewBag.result = "error " + e.Message;
			}

			return View();
		}

		public ActionResult About()
		{
			ViewBag.Message = "Your application description page.";

			return View();
		}

		public ActionResult Contact()
		{
			ViewBag.Message = "Your contact page.";

			return View();
		}

		public ActionResult test()
		{
			return View();
		}
	}
}