using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using System.Web;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using Microsoft.AspNet.Identity.Owin;
using Microsoft.Owin;
using Microsoft.Owin.Security;
using MainTain.Models;
using IdentityDB.Model.CustomModel;

namespace MainTain
{
	public class EmailService : IIdentityMessageService
	{
		public Task SendAsync(IdentityMessage message)
		{
			// Plug in your email service here to send an email.
			return Task.FromResult(0);
		}
	}

	public class SmsService : IIdentityMessageService
	{
		public Task SendAsync(IdentityMessage message)
		{
			// Plug in your SMS service here to send a text message.
			return Task.FromResult(0);
		}
	}
	public class ApplicationRoleManager : RoleManager<ApplicationRole>
	{
		public ApplicationRoleManager(IRoleStore<ApplicationRole, string> roleStore)
			: base(roleStore)
		{
		}

		// 创建用于管理 ApplicationRole 的 Manager 类, 
		// 同时将数据库上下文 ApplicationDbContext 传递进去
		// 内部使用这个上下文操作数据库
		public static ApplicationRoleManager Create(IdentityFactoryOptions<ApplicationRoleManager> options, IOwinContext context)
		{
			return new ApplicationRoleManager(new IdentityDB.RoleStore<ApplicationRole>());
		}

		/// <summary>
		/// 获取角色的权限列表
		/// </summary>
		/// <param name="roleId">角色ID</param>
		/// <returns>权限ID列表的IQueryable</returns>
		//public IEnumerable<ApplicationPermission> GetRolePermissions(string roleId)
		//{
		//	//取数据上下文, 代表数据库对象, 用于操作数据库
		//	//var context = HttpContext.Current.GetOwinContext().Get<ApplicationDbContext>();
		//	var roleManager = HttpContext.Current.GetOwinContext().Get<ApplicationRoleManager>();

		//	//取角色
		//	var role = roleManager.Roles.Include(r => r.Permissions).FirstOrDefault(t => t.Id == roleId);

		//	//取权限ID列表        
		//	var rolePermissionIds = role.Permissions.Select(t => t.PermissionId);

		//	//取权限列表
		//	var permissions = context.Permissions.Where(p => rolePermissionIds.Contains(p.Id)).ToList();
		//	return permissions;
		//}

		/// <summary>
		/// 取用户的权限列表
		/// </summary>
		/// <param name="filterContext"></param>
		/// <returns></returns>
		public IEnumerable<ApplicationPermission> GetUserPermissions(string username)
		{
			//用户权限集合
			var userPermissions = new List<ApplicationPermission>();
			//取数据上下文
			//var context = HttpContext.Current.GetOwinContext().Get<AppDBContext>();
			////取用户
			//var user = context.Users.Include(u => u.Roles)
			//				  .FirstOrDefault(t => t.UserName.ToUpper() == username.ToUpper());
			////取用户所属角色的所有权限
			//foreach (var item in user.Roles)
			//{
			//	//取角色权限
			//	var rolePermissions = GetRolePermissions(item.RoleId);
			//	//插入用户权限
			//	userPermissions.InsertRange(userPermissions.Count, rolePermissions);
			//}
			return userPermissions;
		}

	}
	// Configure the application user manager used in this application. UserManager is defined in ASP.NET Identity and is used by the application.
	public class ApplicationUserManager : UserManager<ApplicationUser>
	{
		public ApplicationUserManager(IUserStore<ApplicationUser> store)
			: base(store)
		{
		}

		#region 扩展基类 UserManager 的管理函数

		/// <summary>
		/// 基类有一个通过 userId 查询角色的函数, 存在冗余的数据库查询, 特此加一个函数
		/// </summary>
		/// <param name="user"></param>
		/// <returns></returns>
		public async Task<IList<string>> GetRolesAsync(ApplicationUser user)
		{
			var userRoleStore = Store as IUserRoleStore<ApplicationUser, string>;
			if (userRoleStore != null)
			{
				return await userRoleStore.GetRolesAsync(user);
			}
			else
				return new List<string>();
		}

		//public async Task<IdentityResult> AddToRoleAsync(string userId, string roleId)
		//{

		//}
		#endregion

		public static ApplicationUserManager Create(IdentityFactoryOptions<ApplicationUserManager> options, IOwinContext context)
		{
			var manager = new ApplicationUserManager(new IdentityDB.UserStore<ApplicationUser>());
			// Configure validation logic for usernames
			manager.UserValidator = new UserValidator<ApplicationUser>(manager)
			{
				AllowOnlyAlphanumericUserNames = false,
				RequireUniqueEmail = true
			};

			// Configure validation logic for passwords
			manager.PasswordValidator = new PasswordValidator
			{
				RequiredLength = 6,
				RequireNonLetterOrDigit = true,
				RequireDigit = true,
				RequireLowercase = true,
				RequireUppercase = true,
			};

			// Configure user lockout defaults
			manager.UserLockoutEnabledByDefault = true;
			manager.DefaultAccountLockoutTimeSpan = TimeSpan.FromMinutes(5);
			manager.MaxFailedAccessAttemptsBeforeLockout = 5;

			// Register two factor authentication providers. This application uses Phone and Emails as a step of receiving a code for verifying the user
			// You can write your own provider and plug it in here.
			manager.RegisterTwoFactorProvider("Phone Code", new PhoneNumberTokenProvider<ApplicationUser>
			{
				MessageFormat = "Your security code is {0}"
			});
			manager.RegisterTwoFactorProvider("Email Code", new EmailTokenProvider<ApplicationUser>
			{
				Subject = "Security Code",
				BodyFormat = "Your security code is {0}"
			});
			manager.EmailService = new EmailService();
			manager.SmsService = new SmsService();
			var dataProtectionProvider = options.DataProtectionProvider;
			if (dataProtectionProvider != null)
			{
				manager.UserTokenProvider =
					new DataProtectorTokenProvider<IdentityDB.Model.CustomModel.ApplicationUser>(dataProtectionProvider.Create("ASP.NET Identity"));
			}
			return manager;
		}
	}

	// Configure the application sign-in manager which is used in this application.
	public class ApplicationSignInManager : SignInManager<IdentityDB.Model.CustomModel.ApplicationUser, string>
	{
		public ApplicationSignInManager(ApplicationUserManager userManager, IAuthenticationManager authenticationManager)
			: base(userManager, authenticationManager)
		{
		}

		public override Task<ClaimsIdentity> CreateUserIdentityAsync(IdentityDB.Model.CustomModel.ApplicationUser user)
		{
			return user.GenerateUserIdentityAsync((ApplicationUserManager)UserManager);
		}

		public static ApplicationSignInManager Create(IdentityFactoryOptions<ApplicationSignInManager> options, IOwinContext context)
		{
			return new ApplicationSignInManager(context.GetUserManager<ApplicationUserManager>(), context.Authentication);
		}
	}

	/// <summary>
	/// 初始化时,对数据库的操作,
	/// 一：数据库不存在时重新创建数据库 Database.SetInitializer<testContext>(new CreateDatabaseIfNotExists<testContext>());
	/// 二：每次启动应用程序时创建数据库 Database.SetInitializer<testContext>(new DropCreateDatabaseAlways<testContext>());
	/// 三：模型更改时重新创建数据库 Database.SetInitializer<testContext>(new DropCreateDatabaseIfModelChanges<testContext>());
	/// 四：从不创建数据库 Database.SetInitializer<testContext>(null);
	///* 在IdentityModels 内的 ApplicationDbContext :  IdentityDbContext<ApplicationUser> 设置
	/// </summary>
	//public class ApplicationDbInitializer : CreateDatabaseIfNotExists<ApplicationDbContext>
	//{
	//	protected override void Seed(ApplicationDbContext context)
	//	{
	//		InitializeIdentityForEF(context);
	//		base.Seed(context);
	//	}

	//	//创建用户名为admin@123.com，密码为“Admin@123456”并把该用户添加到角色组"Admin"中
	//	public static void InitializeIdentityForEF(ApplicationDbContext db)
	//	{
			//var userManager = HttpContext.Current.GetOwinContext().Get<ApplicationUserManager>();
			//var roleManager = HttpContext.Current.GetOwinContext().Get<ApplicationRoleManager>();
			
			//#region 创建用户
			//const string name1 = "Admin";//用户名
			//const string email1 = "admin@123.com";//邮箱
			//const string password1 = "Admin@123456";//密码
			//const string name2 = "user";//用户名
			//const string email2 = "user@123.com";//邮箱
			//const string password2 = "User@123456";//密码
			//const string name3 = "super";//用户名
			//const string email3 = "super@123.com";//邮箱
			//const string password3 = "Super@123456";//密码

			//var user1 = userManager.FindByName(name1);
			//if (user1 == null)
			//{
			//	user1 = new ApplicationUser
			//	{
			//		UserName = name1,
			//		Email = email1,
			//		Password = password1,
			//	};
			//	var result = userManager.Create(user1, password1);
			//	result = userManager.SetLockoutEnabled(user1.Id, false);
			//}

			//var user2 = userManager.FindByName(name2);
			//if (user2 == null)
			//{
			//	user2 = new ApplicationUser
			//	{
			//		UserName = name2,
			//		Email = email2,
			//		Password = password2,
			//	};
			//	var result = userManager.Create(user2, password2);
			//	result = userManager.SetLockoutEnabled(user2.Id, false);
			//}

			//var user3 = userManager.FindByName(name3);
			//if (user3 == null)
			//{
			//	user3 = new ApplicationUser
			//	{
			//		UserName = name3,
			//		Email = email3,
			//		Password = password3,
			//	};
			//	var result = userManager.Create(user3, password3);
			//	result = userManager.SetLockoutEnabled(user3.Id, false);
			//}
			//#endregion

			//#region 创建角色
			//const string roleName1 = "管理员";
			//const string roleName2 = "普通用户";
			//const string roleName3 = "超级管理员";		// 可以添加账户,添加管理员

			//var role1 = roleManager.FindByName(roleName1);
			//if (role1 == null)
			//{
			//	role1 = new ApplicationRole() { Name = roleName1, Description = roleName1 };
			//	var roleresult = roleManager.Create(role1);
			//}
			//var role2 = roleManager.FindByName(roleName2);
			//if (role2 == null)
			//{
			//	role2 = new ApplicationRole() { Name = roleName2, Description = roleName2 };
			//	var roleresult = roleManager.Create(role2);
			//}
			//var role3 = roleManager.FindByName(roleName2);
			//if (role3 == null)
			//{
			//	role3 = new ApplicationRole() { Name = roleName3, Description = roleName3 };
			//	var roleresult = roleManager.Create(role3);
			//}
			//#endregion

			//#region 将用户添加进角色
			//var rolesForUser1 = userManager.GetRoles(user1.Id);
			//if (!rolesForUser1.Contains(role1.Name))
			//{
			//	var result = userManager.AddToRole(user1.Id, role1.Name);
			//}
			//var rolesForUser2 = userManager.GetRoles(user2.Id);
			//if (!rolesForUser2.Contains(role2.Name))
			//{
			//	var result = userManager.AddToRole(user2.Id, role2.Name);
			//}
			//var rolesForUser3 = userManager.GetRoles(user3.Id);
			//if (!rolesForUser3.Contains(role3.Name))
			//{
			//	var result = userManager.AddToRole(user3.Id, role3.Name);
			//}
			//#endregion

			//#region Urls 表添加数据

			//Url u0 = new Url { UrlKey = "bd", UrlValue = "http://www.baidu.com", UserID = user1.Id };
			//Url u1 = new Url { UrlKey = "ex", UrlValue = "http://www.easyx.cn", UserID = user1.Id };
			//Url u2 = new Url { UrlKey = "163", UrlValue = "http://mail.163.com", UserID = user1.Id };
			//Url u3 = new Url { UrlKey = "qq", UrlValue = "mail.qq123.com", UserID = user1.Id };
			//Url u4 = new Url { UrlKey = "qun", UrlValue = "http://qgc.qq.com/117253/t/85", UserID = user1.Id };
			//db.Urls.Add(u0);
			//db.Urls.Add(u1);
			//db.Urls.Add(u2);
			//db.Urls.Add(u3);
			//db.Urls.Add(u4);

			//db.SaveChanges();
			//#endregion
		//}
	//}
}
