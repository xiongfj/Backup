using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(mvcLoginTest.Startup))]
namespace mvcLoginTest
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
