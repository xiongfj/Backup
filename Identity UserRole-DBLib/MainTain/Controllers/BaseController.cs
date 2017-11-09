using IdentityDB.Model.CustomModel;
using MainTain.App_Start;
using MainTain.Models;
using Microsoft.AspNet.Identity.Owin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MainTain.Controllers
{
	[IdentityAuthorize(Roles = "管理员")]
	public abstract class BaseController : Controller
	{
		public BaseController()
		{
		}
		public BaseController(ApplicationUserManager userManager, ApplicationRoleManager roleManager)
		{
			_userManager = userManager;
			_roleManager = roleManager;
		}

		private ApplicationUserManager userManager;
		protected ApplicationUserManager _userManager
		{
			get
			{
				return userManager ?? HttpContext.GetOwinContext().GetUserManager<ApplicationUserManager>();
			}
			private set
			{
				userManager = value;
			}
		}

		private ApplicationRoleManager roleManager;
		protected ApplicationRoleManager _roleManager
		{
			get
			{
				return roleManager ?? HttpContext.GetOwinContext().Get<ApplicationRoleManager>();
			}
			private set
			{
				roleManager = value;
			}
		}

		//private ApplicationDbContext db;
		//protected ApplicationDbContext _db
		//{
		//	get
		//	{
		//		return db ?? HttpContext.GetOwinContext().Get<ApplicationDbContext>();
		//	}
		//	private set
		//	{
		//		db = value;
		//	}
		//}

		private AppDBContext mDB;
		protected AppDBContext _mDB
		{
			get
			{
				return mDB ?? HttpContext.GetOwinContext().Get<AppDBContext>();
			}
			private set
			{
				mDB = value;
			}
		}
	}
}