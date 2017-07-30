using AspNetIdentity2Permission.Mvc.Models;
using AspNetIdentity2Permission.Mvc.Services;
using Microsoft.AspNet.Identity.Owin;
using System.Collections.Generic;
using System.Web;
using System.Web.Mvc;

/*
 * 派生 6 个子类, 实现各自管理
 * DepartmentController
 * PermissionsAdminController
 * RolePermissionsController
 * RolesAdminController
 * UserDepartmentController
 * UserRoleController
 * 
 * 管理流程:
 * 1.用户在页面上点击某个的管理链接, 会调用对应子类 xxController 的构造函数,
 * 2.同时会调用 BaseController 的构造函数,
 * 3.然后调用验证类的 OnAuthorization() 函数, 实行验证, 
 * 4.验证通过后会调用 xxController 的 Index() action ,然后显示对应的页面
 */

namespace AspNetIdentity2Permission.Mvc.Controllers
{
    /// <summary>
    /// 基础类, 所有的派生类都会进过这个类验证
    /// 属性标签 [IdentityAuthorize] 说明会调用 App_Start/IdentityAuthorizeAttribute.cs 内的验证类 
    /// 并把 当前页面的 HttpContext 传递过去
    /// </summary>
    [IdentityAuthorize(Roles="管理员")]
    public abstract class BaseController : Controller
    {
        public BaseController()
        {
            //HttpContextBase httpC = HttpContext;
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
              //  HttpContextBase fg = this.HttpContext;
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
                //HttpContextBase fg = this.HttpContext;
                return roleManager ?? HttpContext.GetOwinContext().Get<ApplicationRoleManager>();
            }
            private set
            {
                roleManager = value;
            }
        }

        private ApplicationDbContext db;
        protected ApplicationDbContext _db
        {
            get
            {
                return db ?? HttpContext.GetOwinContext().Get<ApplicationDbContext>();
            }
            private set
            {
                db = value;
            }
        }
        /// <summary>
        /// 缓存key
        /// </summary>
        const string _permissionKey = "PermissionsOfAssembly";
        /// <summary>
        /// 程序集中权限集合
        /// </summary>
        protected IEnumerable<ApplicationPermission> _permissionsOfAssembly
        {
            get
            {
                // 等效 Application[_permissionKey] = ""; ...
                var permissions = HttpContext.Application.Get(_permissionKey) as IEnumerable<ApplicationPermission>;
                if (permissions == null)
                {
                    //取程序集中全部权限
                    permissions = ActionPermissionService.GetAllActionByAssembly();
                    //添加到缓存
                    HttpContext.Application.Add(_permissionKey, permissions);
                }
                return permissions;
            }
        }
    }
}