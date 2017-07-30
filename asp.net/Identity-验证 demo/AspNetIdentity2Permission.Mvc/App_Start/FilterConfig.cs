using System.Web;
using System.Web.Mvc;

namespace AspNetIdentity2Permission.Mvc
{
    /*跨站请求过滤器*/
    public class FilterConfig
    {
        public static void RegisterGlobalFilters(GlobalFilterCollection filters)
        {
            filters.Add(new HandleErrorAttribute());
            filters.Add(new AuthorizeAttribute());
        }
    }
}
