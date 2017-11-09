using System.Data.Entity;
using System.Security.Claims;
using System.Threading.Tasks;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System;
using System.Data.Entity.ModelConfiguration;

namespace MainTain.Models
{
    // You can add profile data for the user by adding more properties to your ApplicationUser class, please visit https://go.microsoft.com/fwlink/?LinkID=317594 to learn more.
 //   public class ApplicationUser : IdentityUser
	//{
	//	public ApplicationUser()
	//	{
	//		Urls = new List<Url>();
	//	}
	//	/// <summary>
	//	/// 明文密码
	//	/// </summary>        
	//	[Required]
	//	[Display(Name = "密码")]
	//	public string Password { get; set; }

	//	/// <summary>
	//	/// 一个用户有多个自定义 url
	//	/// </summary>
	//	public ICollection<Url> Urls { get; set; }

	//	public async Task<ClaimsIdentity> GenerateUserIdentityAsync(UserManager<ApplicationUser> manager)
 //       {
 //           // Note the authenticationType must match the one defined in CookieAuthenticationOptions.AuthenticationType
 //           var userIdentity = await manager.CreateIdentityAsync(this, DefaultAuthenticationTypes.ApplicationCookie);
 //           // Add custom user claims here
 //           return userIdentity;
 //       }
	//}

	//public class ApplicationRole : IdentityRole
	//{
	//	public ApplicationRole()
	//		: base()
	//	{
	//		Permissions = new List<ApplicationRolePermission>();
	//	}
	//	public ApplicationRole(string roleName)
	//		: this()
	//	{
	//		base.Name = roleName;
	//	}

	//	[Display(Name = "角色描述")]
	//	public string Description { get; set; }
	//	/// <summary>
	//	/// 权限列表
	//	/// </summary>
	//	public ICollection<ApplicationRolePermission> Permissions { get; set; }
	//}

	public class ApplicationPermission
	{
		public ApplicationPermission()
		{
			Id = Guid.NewGuid().ToString();
			Roles = new List<ApplicationRolePermission>();
		}
		/// <summary>
		/// 主键
		/// </summary>
		public string Id { get; set; }
		/// <summary>
		/// 控制器名
		/// </summary>
		public string Controller { get; set; }
		/// <summary>
		/// 方法名
		/// </summary>
		public string Action { get; set; }
		/// <summary>
		/// 参数字符串
		/// </summary>
		public string Params { get; set; }
		/// <summary>
		/// 功能描述
		/// </summary>
		public string Description { get; set; } // 用Action上面的[Description("...")] 赋值
		/// <summary>
		/// 角色列表
		/// </summary>
		public ICollection<ApplicationRolePermission> Roles { get; set; }
	}

	public class ApplicationPermissionEqualityComparer : IEqualityComparer<ApplicationPermission>
	{
		public bool Equals(ApplicationPermission x, ApplicationPermission y)
		{
			//先比较ID
			if (string.Compare(x.Id, y.Id, true) == 0)
			{
				return true;
			}
			//而后比较Controller,Action,Description和Params
			if (x.Controller == y.Controller || x.Action == y.Action || x.Description == y.Description)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		public int GetHashCode(ApplicationPermission obj)
		{
			var str = string.Format("{0}-{1}-{2}", obj.Controller, obj.Action, obj.Description);
			return str.GetHashCode();
		}
	}

	public class ApplicationRolePermission
	{
		public virtual string RoleId { get; set; }
		public virtual string PermissionId { get; set; }
	}

	/// <summary>
	/// 以 UrlKey 和 UserId 为双主键
	/// </summary>
	//public class Url
	//{
	//	//[Key]		// 指定为主键
	//	public string UrlKey { get; set; }		// 自定义 url 的key
	//	public string UrlValue { get; set; }	// key 对应的 url
	//	public string UserID { get; set; }		// 所属的 user
	//}

	//public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
	//   {
	//       public ApplicationDbContext()
	//           : base("DefaultConnection", throwIfV1Schema: false)
	//       {
	//		// 在第一次启动网站时初始化数据库添加管理员用户凭据和admin 角色到数据库
	//		Database.SetInitializer<ApplicationDbContext>(new ApplicationDbInitializer());
	//	}

	//       public static ApplicationDbContext Create()
	//       {
	//           return new ApplicationDbContext();
	//	}

	//	protected override void OnModelCreating(DbModelBuilder modelBuilder)
	//	{
	//		base.OnModelCreating(modelBuilder);

	//		// 一个权限可以被多个角色拥有
	//		//配置permission与rolePermission的1对多关系
	//		EntityTypeConfiguration<ApplicationPermission> configuration = modelBuilder.Entity<ApplicationPermission>().ToTable("ApplicationPermissions");
	//		configuration.HasMany<ApplicationRolePermission>(u => u.Roles).WithRequired().HasForeignKey(k => k.PermissionId);

	//		//
	//		//配置role与persmission的映射表RolePermission的键
	//		modelBuilder.Entity<ApplicationRolePermission>().HasKey(r => new { PermissionId = r.PermissionId, RoleId = r.RoleId }).ToTable("RolePermissions");

	//		// 一个角色可以拥有多个权限
	//		//配置role与RolePermission的1对多关系
	//		EntityTypeConfiguration<ApplicationRole> configuration2 = modelBuilder.Entity<ApplicationRole>();
	//		configuration2.HasMany<ApplicationRolePermission>(r => r.Permissions).WithRequired().HasForeignKey(k => k.RoleId);

	//		// Url 表的双主键
	//		modelBuilder.Entity<Url>().HasKey(t => new { t.UrlKey, t.UserID });

	//		// 将 ApplicationUser 的主键与 Url 表的 UserID 绑定成复健
	//		EntityTypeConfiguration<ApplicationUser> configUrl = modelBuilder.Entity<ApplicationUser>();
	//		configUrl.HasMany<Url>(u => u.Urls).WithRequired().HasForeignKey(k => k.UserID);
	//	}

	//	public DbSet<Url> Urls { get; set; }
	//	public new IDbSet<ApplicationRole> Roles { get; set; }
	//	public virtual IDbSet<ApplicationPermission> Permissions { get; set; }
	//}
}