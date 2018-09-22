using System.Web;
using System.Web.Mvc;
using System.Web.WebPages;

namespace mvcLoginTest
{
	public class FilterConfig
	{
		public static void RegisterGlobalFilters(GlobalFilterCollection filters)
		{
			filters.Add(new HandleErrorAttribute());
		}
	}

	public class SelfOnlyAttribute : ActionFilterAttribute
	{
		public override void OnActionExecuting(ActionExecutingContext filterContext)
		{

			HttpResponseBase response = filterContext.HttpContext.Response;
			HttpRequestBase request = filterContext.HttpContext.Request;

			if (filterContext.HttpContext.User.Identity.IsAuthenticated)
			{
				//已经登录代码
			}
			else
			{
				if (!request.IsAjaxRequest())
				{
					string str = request.Url.AbsoluteUri.ToLower();
					string str2 = "/login";
					filterContext.Result = new RedirectResult(string.Format("{0}?returnUrl={1}", str2, str));
				}
				else
				{
					response.SetStatus(401);
				}
				filterContext.Result = new HttpUnauthorizedResult(); //这一行保证不再执行Action的代码
				response.End(); //必须加上这句，否则返回前台status始终是200
				return;

			}
		}

	}
}
