using System.Security.Claims;
using System.Web.Mvc;

namespace AspNetIdentity2Permission.Mvc.Controllers
{
    [AllowAnonymous]
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            ClaimsIdentity claimsIdentity = HttpContext.User.Identity as ClaimsIdentity;
           // System.Security.Claims.ClaimTypes sd;
            if (claimsIdentity == null)
            {
                return View("Error", new string[] { "未找到声明" });
            }
            else
            {
                var v = claimsIdentity.Claims;
                return View(v);
            }
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}