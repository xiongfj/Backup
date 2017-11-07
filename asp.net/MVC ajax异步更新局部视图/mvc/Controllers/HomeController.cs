using mvc.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvc.Controllers
{
	public class HomeController : Controller
	{
		public ActionResult Index()
		{
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

		/// <summary>
		/// 必须有对应的 GetData.cshtml 视图
		/// <div id="data">
		///		@{Html.RenderAction("GetData");}		// 对应该 Action
		/// </div>
		/// </summary>
		/// <param name="str"></param>
		/// <returns></returns>
		public ActionResult GetData(string str)
		{
			List<AspUser> list = new List<AspUser>();
			list.Add(new AspUser("111"+ str));
			list.Add(new AspUser("222" + str));
			list.Add(new AspUser("3333" + str));
			list.Add(new AspUser("44444" + str));
			return PartialView(list);		// 不能返回 View
		}
	}
}