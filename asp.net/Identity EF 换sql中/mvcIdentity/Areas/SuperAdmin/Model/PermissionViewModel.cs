using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace mvcIdentity.Areas.SuperAdmin.Model
{
    public class PermissionViewModel
    {
        /// <summary>
        /// 控制器名
        /// </summary>
        [Required(AllowEmptyStrings = false)]
        [Display(Name = "控制器名")]
        public string Controller { get; set; }

        /// <summary>
        /// 方法名
        /// </summary>
        [Required(AllowEmptyStrings = false)]
        [Display(Name = "方法名")]
        public string Action { get; set; }

        /// <summary>
        /// 功能描述
        /// </summary>
        [Required(AllowEmptyStrings = true)]
        [Display(Name = "功能描述")]
        public string Description { get; set; }

        /*[Display(Name = "选择")]
        public bool Selected { get; set; }

        [Display(Name = "角色ID")]
        public string RoleId { get; set; }

        [Display(Name = "角色名")]
        public string RoleName { get; set; }*/
    }
}