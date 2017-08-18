﻿using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data.Entity;
using System.Data.Entity.ModelConfiguration;
using System.Security.Claims;
using System.Threading.Tasks;

namespace AspNetIdentity2Permission.Mvc.Models
{
    // 可以通过向 ApplicationUser 类添加更多属性来为用户添加配置文件数据。若要了解详细信息，请访问 http://go.microsoft.com/fwlink/?LinkID=317594。
    public class ApplicationUser : IdentityUser
    {
        public ApplicationUser() : base() { this.Departments = new List<UserDepartment>(); }
        public ApplicationUser(string userName) : base(userName) { }
        /// <summary>
        /// 所属部门
        /// </summary>
        public virtual ICollection<UserDepartment> Departments { get; set; }
        /// <summary>
        /// 明文密码
        /// </summary>        
        [Required]
        [Display(Name = "密码")]
        public string Password { get; set; }

        public async Task<ClaimsIdentity> GenerateUserIdentityAsync(ApplicationUserManager manager)
        {
            // 请注意，authenticationType 必须与 CookieAuthenticationOptions.AuthenticationType 中定义的相应项匹配
            var userIdentity = await manager.CreateIdentityAsync(this, DefaultAuthenticationTypes.ApplicationCookie);
            // 在此处添加自定义用户声明
            return userIdentity;
        }
    }

    public class ApplicationRole : IdentityRole
    {
        public ApplicationRole()
            : base()
        {
            Permissions = new List<ApplicationRolePermission>();
        }
        public ApplicationRole(string roleName)
            : this()
        {
            base.Name = roleName;
        }

        [Display(Name = "角色描述")]
        public string Description { get; set; }
        /// <summary>
        /// 权限列表
        /// </summary>
        public ICollection<ApplicationRolePermission> Permissions { get; set; }
    }

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
    /// 机构
    /// </summary>
    public class Department
    {
        public Department()
        {
            this.Users = new List<UserDepartment>();
        }
        /// <summary>
        /// 机构编号
        /// </summary>
        public int Id { get; set; }
        /// <summary>
        /// 机构名称
        /// </summary>
        public string Name { get; set; }
        /// <summary>
        /// 下辖用户列表
        /// </summary>
        public virtual ICollection<UserDepartment> Users { get; set; }
    }

    public class UserDepartment
    {
        public int DepartmentId { get; set; }
        public string ApplicationUserId { get; set; }
    }

    public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
    {
        public ApplicationDbContext()
            : base("DefaultConnection")
        {
            // 在第一次启动网站时初始化数据库添加管理员用户凭据和admin 角色到数据库
            Database.SetInitializer<ApplicationDbContext>(new ApplicationDbInitializer());
        }

        // 数据库创建的时候会调用这个函数?!
        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            if (modelBuilder == null)
            {
                throw new ArgumentNullException("modelBuilder");
            }
            
            base.OnModelCreating(modelBuilder);

            // 一个权限可以被多个角色拥有
            //配置permission与rolePermission的1对多关系
            EntityTypeConfiguration<ApplicationPermission> configuration = modelBuilder.Entity<ApplicationPermission>().ToTable("ApplicationPermissions");
            configuration.HasMany<ApplicationRolePermission>(u => u.Roles).WithRequired().HasForeignKey(k => k.PermissionId);
           
            //
            //配置role与persmission的映射表RolePermission的键
            modelBuilder.Entity<ApplicationRolePermission>().HasKey(r => new { PermissionId = r.PermissionId, RoleId = r.RoleId }).ToTable("RolePermissions");
            
            // 一个角色可以拥有多个权限
            //配置role与RolePermission的1对多关系
            EntityTypeConfiguration<ApplicationRole> configuration2 = modelBuilder.Entity<ApplicationRole>();
            configuration2.HasMany<ApplicationRolePermission>(r => r.Permissions).WithRequired().HasForeignKey(k => k.RoleId);

            //配置Department与applicationUser的多对多关系
            modelBuilder.Entity<UserDepartment>().HasKey(u => new { u.ApplicationUserId, u.DepartmentId })
                            .ToTable("UserDepartment").Property(t=>t.ApplicationUserId).HasColumnName("UserId");

            EntityTypeConfiguration<Department> configuration3 = modelBuilder.Entity<Department>();
            configuration3.HasMany(d => d.Users).WithRequired().HasForeignKey(k => k.DepartmentId);

            EntityTypeConfiguration<ApplicationUser> configuration4 = modelBuilder.Entity<ApplicationUser>();
            configuration4.HasMany(d => d.Departments).WithOptional().HasForeignKey(k => k.ApplicationUserId);
            
        }

        public static ApplicationDbContext Create()
        {
            return new ApplicationDbContext();
        }

        // 这些集合时刻与数据库保持同步!!
        // 覆盖基类的 Roles, 因为 ApplicationRole 内添加了自定义的属性等..
        public new IDbSet<ApplicationRole> Roles { get; set; }
        public virtual IDbSet<ApplicationPermission> Permissions { get; set; }
        public virtual DbSet<Department> Departments { get; set; }

    }
}