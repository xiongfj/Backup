using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;
using WebApplication1.App_Start;

namespace WebApplication1.Controllers
{
	[Token]
	public class HomeController : Controller
	{
		public ActionResult Index()
		{
			Session["uid"] = "admin";
			return View();
		}

		[HttpPost]
		public ActionResult Index(string name)
		{
			Session["name"] = name;
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



		// 跨域 form 表单 ValidateAntiForgeryToken 提交验证
		public ActionResult corsTest()
		{
			return View();
		}
		[HttpPost]
		[ValidateAntiForgeryToken]
		public ActionResult corsTest(string name)
		{
			ViewBag.name = name;
			return View();
		}


		// 跨域获取 session
		public ActionResult ajaxSessionTest()
		{
			return View();
		}
		[HttpPost]
		public string ajaxSessionTest(string data)
		{
			return Session["uid"].ToString();
		}



		// 自身 Antiforgery 验证
		public ActionResult ajaxTest()
		{
			return View();
		}
		[HttpPost]
		[AjaxValidateAntiForgeryToken]
		public ActionResult ajaxTest(string name)
		{
			ViewBag.name = name;
			return View();
		}




		// 跨域 Antiforgery 验证
		public ActionResult ajaxCorsAntiforgeryTest()
		{
			return View();
		}

		[HttpPost]
		[AjaxValidateAntiForgeryToken]
		public string ajaxCorsAntiforgeryTest(string obj)
		{
			return obj;
		}
	}

	public class Model
	{
		public string name { get; set; }
		public string age { get; set; }
	}
}