using mvc.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Webdiyer.WebControls.Mvc;

/**
 * 必须使用 jquery1.8.2以上的版本才能正常运行!!
 * **/

namespace mvc.Controllers
{
	public class HomeController : Controller
	{
		public ActionResult Index(int index = 1)
		{
			return AjaxSearchPost(index);
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
		/// 
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		public ActionResult AjaxSearchPost(int index = 1)
		{
				var model = AspUser.Users.ToPagedList(index, 5);
				if (Request.IsAjaxRequest())
					return PartialView("_AjaxSearchPost", model);
				return View(model);
		}

		/// <summary>
		/// 用户提交搜索后通过该函数筛选数据, 然后显示在 AjaxSearchPost.cshtml 视图上.
		/// 该视图可以说是一个筛选Model过的 Index 视图
		/// 给用户提供一个查询的接口
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Addr"></param>
		/// <param name="Email"></param>
		/// <param name="index"></param>
		/// <returns></returns>
		[HttpPost]
		public ActionResult AjaxSearchPost(string Name, string Addr, string Email, int index = 1)
		{
			return ajaxSearchPostResult(Name, Addr, Email, index);
		}
		private ActionResult ajaxSearchPostResult(string Name, string Addr, string Email, int index = 1)
		{
				var qry = AspUser.Users.AsQueryable();
				if (!string.IsNullOrWhiteSpace(Name))
					qry = qry.Where(a => a.Name.ToLower().Contains(Name.ToLower()));
				if (!string.IsNullOrWhiteSpace(Addr))
					qry = qry.Where(a => a.addr.ToLower().Contains(Addr.ToLower()));
				if (!string.IsNullOrWhiteSpace(Email))
					qry = qry.Where(a => a.email.ToLower().Contains(Email.ToLower()));

				var model = qry.ToPagedList(index, 5);
				if (Request.IsAjaxRequest())
					return PartialView("_AjaxSearchPost", model);
				return View(model);
		}
	}
}