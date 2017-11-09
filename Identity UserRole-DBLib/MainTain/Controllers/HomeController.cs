using AutoMapper;
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
	[AllowAnonymous]
	public class HomeController : Controller
	{
		//private ApplicationDbContext db = null;
		//private ApplicationDbContext _db
		//{
		//	get
		//	{
		//		return db ?? HttpContext.GetOwinContext().Get<ApplicationDbContext>();
		//	}
		//	set
		//	{
		//		db = value;
		//	}
		//}
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

		public ActionResult Search(string searchString)
		{
			var users = HttpContext.GetOwinContext().GetUserManager<ApplicationUserManager>().Users.Where(u => u.UserName.Contains(searchString)).ToListAsync().Result;
			List<EditUserRoleViewModel> views = new List<EditUserRoleViewModel>();

			foreach (var u in users)
			{
				var view = new EditUserRoleViewModel
				{
					Id = u.Id,
					UserName = u.UserName,
					Email = u.Email
				};
				views.Add(view);
			}

			return PartialView(views);
		}
	}
}