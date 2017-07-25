using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(mvcTest.Startup))]
namespace mvcTest
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
