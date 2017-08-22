using mvcIdentity.Areas.SuperAdmin.Model;
using mvcIdentity.Controllers;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Web.Mvc;
using WebApplication5.Model;

namespace mvcIdentity.Common
{
    public class ApplicationAssembly
    {
        public static IEnumerable<PermissionModel> GetAllActionByAssembly()
        {
            var result = new List<PermissionModel>();

            // 获取命名空间下所有的类型
            var types = Assembly.Load("mvcIdentity").GetTypes();
            //取控制器
            foreach (var type in types)
            {
                if (type.BaseType == typeof(BaseController))//如果是 BaseController 的子类           
                {
                    //反射控制器
                    var controller = new ReflectedControllerDescriptor(type);
                    //取控制器的Action,共有实例方法
                    var actions = controller.GetCanonicalActions();
                    //构建权限
                    foreach (var action in actions)
                    {
                        //创建权限
                        var ap = new PermissionModel()
                        {
                            Action = action.ActionName,
                            Controller = controller.ControllerName,
                            //Params = FormatParams(action),
                            Description = GetDescription(action)
                        };
                        result.Add(ap);
                    }
                }
            }
            return result;
        }

        public static string GetDescription(ICustomAttributeProvider action)
        {
            //取自定义特性数组
            var description = action.GetCustomAttributes(typeof(DescriptionAttribute), false);

            //取出Description，否则为空
            var result = description.Length > 0 ? (description[0] as DescriptionAttribute).Description : null;
            return result;
        }
    }
}