using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI;

namespace WebApplication5.Common
{
    public class BasePage : Page
    {
        #region 页面通用对象

        public class LoginUserInfo
        {
            /// <summary>
            /// 用户ID
            /// </summary>            
            public string UserID;

            /// <summary>
            /// 用户登录名
            /// </summary>
            public string LoginName;

            /// <summary>
            /// 用户名称
            /// </summary>
            public string UserName;

            /// <summary>
            /// 登录IP
            /// </summary>
            public string IP;

            /// <summary>
            /// 用户角色ID
            /// </summary>
            public string RoleID;

            /// <summary>
            /// 用户角色名称
            /// </summary>
            public string RoleName;

            /// <summary>
            /// 用户角色父ID
            /// </summary>
            public int ParentID;

            /// <summary>
            /// 用户组织机构ID
            /// </summary>
            public string OrgID;

            /// <summary>
            /// 用户组织机构名称
            /// </summary>
            public string OrgName;

            /// <summary>
            /// 用户组织机构类别
            /// </summary>
            public int OrgType;

            /// <summary>
            /// 用户类别
            /// </summary>
            public int UserType;

            //行政区划ID
            //public int DivisionID;

            //行政区划编码
            //public int DivisionNumber;

            //行政区划名称
            //public string DivisionName;

            //用户组织机构父ID
            //public int OrgParentID;

            /// <summary>
            /// 岗位名称
            /// </summary>
            public string Station;

            /// <summary>
            /// 岗位名称ID
            /// </summary>
            public int StationID;
        }

        #endregion
    }
}
