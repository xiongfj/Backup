using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace mvcIdentity.Areas.SuperAdmin.Model
{
    public class DepartmentViewModel
    {
        /// <summary>
        /// 机构编号
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// 机构名称
        /// </summary>
        [Required]
        [Display(Name = "机构名称")]
        public string Name { get; set; }
    }
}