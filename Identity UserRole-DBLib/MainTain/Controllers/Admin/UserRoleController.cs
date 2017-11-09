using AutoMapper;
using IdentityDB.Model.CustomModel;
using MainTain.Controllers;
using MainTain.Models;
using Microsoft.AspNet.Identity.EntityFramework;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Threading.Tasks;
using System.Web;
using System.Web.Mvc;
using Webdiyer.WebControls.Mvc;

namespace MainTain.Controllers
{
	[Description("用户-角色维护")]
	public class UserRoleController : BaseController
    {
        // GET: SuperAdmin/UserRole
        public ActionResult Index(int id = 1)
        {
			return AjaxSearchPost(id);
		}

		public ActionResult AjaxSearchPost(int id = 1)
		{
			var views = Mapper.Map<IList<EditUserRoleViewModel>>(_userManager.Users);
			var models = views.ToPagedList(id, 5);
			if (Request.IsAjaxRequest())
				return PartialView("_AjaxSearchPost", models);

			return View(models);
		}

		/// <summary>
		/// 用户提交搜索后, 服务器搜索,返回到视图 AjaxSearchPost.cshtml
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Email"></param>
		/// <param name="id"></param>
		/// <returns></returns>
		[HttpPost]
		public ActionResult AjaxSearchPost(string Name, string Email, int id = 1)
		{
			return ajaxSearchPostResult(Name, Email, id);
		}
		private ActionResult ajaxSearchPostResult(string Name, string Email, int id = 1)
		{
			var qry = _userManager.Users;
			if (!string.IsNullOrWhiteSpace(Name))
				qry = qry.Where(a => a.UserName.ToLower().Contains(Name.ToLower()));
			if (!string.IsNullOrWhiteSpace(Email))
				qry = qry.Where(a => a.Email.ToLower().Contains(Email.ToLower()));

			var model = Mapper.Map<IList<EditUserRoleViewModel>>(qry).ToPagedList(id, 5);
			if (Request.IsAjaxRequest())
				return PartialView("_AjaxSearchPost", model);
			return View(model);
		}

		public ActionResult IndexSearch(int index = 1, string str = "")
		{
			var users = _userManager.Users;

			if (String.IsNullOrWhiteSpace(str))
			{
				var views = Mapper.Map<IList<EditUserRoleViewModel>>(users);
				return PartialView(views.ToPagedList(index, 5));
			}
			else
			{
				var result = users.Where(u => u.UserName.ToLower().Contains(str.ToLower()));
				var views = Mapper.Map<IList<EditUserRoleViewModel>>(result);
				return PartialView(views.ToPagedList(index, 5));
			}
		}

		//
		//异步读取用户详情
		//GET: /Users/Details/5
		[Description("用户-角色详情")]
		public async Task<ActionResult> Details(string id)
		{
			//用户为空时返回400错误
			if (id == null)
			{
				return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
			}
			//按Id查找用户
			var user = await _userManager.FindByIdAsync(id);
			var view = Mapper.Map<EditUserRoleViewModel>(user);
			//var view = new EditUserRoleViewModel
			//{
			//	UserName = user.UserName,
			//	Email = user.Email
			//};
			ViewBag.RoleNames = await _userManager.GetRolesAsync(user.Id);

			return View(view);
		}

		/// <summary>
		/// 异步读取用户创建
		/// </summary>
		/// <returns></returns>
		[Description("新建用户")]
		public async Task<ActionResult> Create()
		{
			//读取角色列表
			ViewBag.RoleId = new SelectList(_roleManager.Roles/*.ToListAsync()*/, "Name", "Name");
			return View();
		}
		/// <summary>
		/// 异步写入用户创建
		/// </summary>
		/// <param name="userViewModel"></param>
		/// <param name="selectedRoles"></param>
		// POST: /Users/Create
		[Description("新建用户，保存")]
		[HttpPost]
		[ValidateAntiForgeryToken]
		public async Task<ActionResult> Create(RegisterViewModel userViewModel, params string[] selectedRoles)
		{
			if (ModelState.IsValid)
			{
				var user = Mapper.Map<ApplicationUser>(userViewModel);
				//var user = new ApplicationUser {
				//	UserName = userViewModel.Username,
				//	Email = userViewModel.Email,
				//	Password = userViewModel.Password
				//};
				var adminResult = await _userManager.CreateAsync(user, userViewModel.Password);

				//
				if (adminResult.Succeeded)
				{
					if (selectedRoles != null)
					{
						var result = await _userManager.AddToRolesAsync(user.Id, selectedRoles);
						if (!result.Succeeded)
						{
							ModelState.AddModelError("", result.Errors.First());
							ViewBag.RoleId = new SelectList(await _roleManager.Roles.ToListAsync(), "Name", "Name");
							return View();
						}
					}
				}
				else
				{
					ModelState.AddModelError("", adminResult.Errors.First());
					ViewBag.RoleId = new SelectList(_roleManager.Roles, "Name", "Name");
					return View();
				}
				return RedirectToAction("Index");
			}
			ViewBag.RoleId = new SelectList(_roleManager.Roles, "Name", "Name");
			return View();
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		[Description("编辑用户-角色")]
		public async Task<ActionResult> Edit(string id)
		{
			if (id == null)
			{
				return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
			}
			var user = await _userManager.FindByIdAsync(id);
			if (user == null)
			{
				return HttpNotFound();
			}
			var userRoles = await _userManager.GetRolesAsync(user.Id);
			var view = Mapper.Map<EditUserRoleViewModel>(user);
			//var view = new EditUserRoleViewModel { Id = user.Id, UserName = user.UserName, Email=user.Email };
			view.RolesList = _roleManager.Roles.ToList().Select(x => new SelectListItem()
			{
				Selected = userRoles.Contains(x.Name),		// 该用户是那个/些角色
				Text = x.Name,
				Value = x.Id
			});
			return View(view);
		}
		//
		//写入用户编辑
		// POST: /Users/Edit/5
		[Description("编辑用户-角色，保存")]
		[HttpPost]
		[ValidateAntiForgeryToken]
		public async Task<ActionResult> Edit([Bind(Include = "UserName,Email,Id")]EditUserRoleViewModel editUser, params string[] selectedRole)
		{
			if (ModelState.IsValid)
			{
				var user = await _userManager.FindByIdAsync(editUser.Id);
				if (user == null)
				{
					return HttpNotFound();
				}
				//不允许修改用户名
				user.Email = editUser.Email;
				//更新用户信息
				var result = await _userManager.UpdateAsync(user);
				if (!result.Succeeded)
				{
					ModelState.AddModelError("", result.Errors.First());
					return View();
				}
				//更新角色
				//删除现有角色
				//var userRoles = user.Roles.ToList();
				//userRoles.ForEach(t => _db.Set<IdentityUserRole>().Remove(t));

				// 清楚该用户的所有角色
				IList<string> roles = await _userManager.GetRolesAsync(user);
				foreach(string roleName in roles)
					await _userManager.RemoveFromRolesAsync(user.Id, roleName);

				//添加所选角色
				selectedRole = selectedRole ?? new string[] { };
				foreach(string roleName in selectedRole)
				{
					//var userRole = new IdentityUserRole { RoleId = roleId, UserId = user.Id };
					//_db.Set<IdentityUserRole>().Add(userRole);
					await _userManager.AddToRoleAsync(user.Id, roleName);
				}
				//_db.SaveChanges();
				return RedirectToAction("Index");
			}
			ModelState.AddModelError("", "操作失败。");
			return View();
		}

		//
		//读取用户删除
		// GET: /Users/Delete/5
		[Description("删除用户")]
		public async Task<ActionResult> Delete(string id)
		{
			if (id == null)
			{
				return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
			}
			var user = await _userManager.FindByIdAsync(id);
			if (user == null)
			{
				return HttpNotFound();
			}
			var result = await _userManager.DeleteAsync(user);
			if (!result.Succeeded)
			{
				ModelState.AddModelError("", result.Errors.First());
				return View();
			}
			return RedirectToAction("Index");
		}
	}
}