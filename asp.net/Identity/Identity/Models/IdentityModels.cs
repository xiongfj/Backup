using System.Data.Entity;
using System.Security.Claims;
using System.Threading.Tasks;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using System.ComponentModel.DataAnnotations;
using System.Collections.Generic;

namespace Identity.Models
{
    // You can add profile data for the user by adding more properties to your ApplicationUser class, please visit https://go.microsoft.com/fwlink/?LinkID=317594 to learn more.


    public class ApplicationUser : IdentityUser
    {
        public async Task<ClaimsIdentity> GenerateUserIdentityAsync(UserManager<ApplicationUser> manager)
        {
            // 请注意，authenticationType 必须与 CookieAuthenticationOptions.AuthenticationType 中定义的相应项匹配
            var userIdentity = await manager.CreateIdentityAsync(this, DefaultAuthenticationTypes.ApplicationCookie);

           // IdentityRole fh;
           // Microsoft.AspNet.Identity.EntityFramework.RoleStore fsf;

            // 在此处添加自定义用户声明
            return userIdentity;
        }
    }

    /*public class ApplicationRole : IdentityRole
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

    public class ApplicationRolePermission
    {
        public virtual string RoleId { get; set; }
        public virtual string PermissionId { get; set; }
    }*/



    public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
    {
       // DbContext gh;
        public ApplicationDbContext()
            : base("DefaultConnection", throwIfV1Schema: false)
        {
        }

        public static ApplicationDbContext Create()
        {
            return new ApplicationDbContext();
        }
    }
}