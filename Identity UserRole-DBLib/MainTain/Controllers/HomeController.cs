using AutoMapper;
using IdentityDB.Model.CustomModel;
using MainTain.Models;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.Owin;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using System.Web;
using System.Web.Mvc;

namespace MainTain.Controllers
{
	[Authorize]
	public class HomeController : BaseController
	{
		public ActionResult Index(string id = "")
		{
			return View();
			//ClaimsIdentity claimsIdentity = HttpContext.User.Identity as ClaimsIdentity;
			//if (claimsIdentity == null)
			//{
			//	return View("Error", new string[] { "未找到声明" });
			//}
			//else
			//{
			//	var v = claimsIdentity.Claims;
			//	return View(v);
			//}
		}

		#region Url 设置部分
		public ActionResult UrlIndex()
		{
			string userid = User.Identity.GetUserId();
			return View(_mDB.Urls.ToList());
		}
		//
		// GET: /Admin/Create
		public ActionResult UrlCreate()
		{
			return View();
		}

		//
		// POST: /Admin/Create

		[HttpPost]
		[ValidateAntiForgeryToken]
		public ActionResult UrlCreate(UrlEditViewModel u)
		{
			if (ModelState.IsValid)
			{
				var model = Mapper.Map<Url>(u);
				_mDB.Insert(model);
				return RedirectToAction("UrlIndex");
			}

			return View(u);
		}

		//
		// GET: /Admin/Edit/5
		public ActionResult UrlEdit(string key = "")
		{
			if (key.Length > 0)
			{
				Url u = _mDB.Urls.Find(m => m.UrlKey == key);
				var model = Mapper.Map<UrlEditViewModel>(u);
				if (model != null)
					return View(model);
			}

			return HttpNotFound();
		}

		//
		// POST: /Admin/Edit/5
		[HttpPost]
		[ValidateAntiForgeryToken]
		public ActionResult UrlEdit(UrlEditViewModel u)
		{
			if (ModelState.IsValid)
			{
				var model = Mapper.Map<Url>(u);
				_mDB.Update(model);
				return RedirectToAction("UrlIndex");
			}

			return View(u);
		}

		//
		// GET: /Admin/Delete/5

		public ActionResult UrlDelete(string key = "")
		{
			if (key.Length > 0)
			{
				Url u = _mDB.Urls.Find(m => m.UrlKey == key);
				if (u != null)
				{
					_mDB.Delete(u);
					return RedirectToAction("UrlIndex");
				}
			}

			return HttpNotFound();
		}
		#endregion
	}
}