using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(mvcIdentity.Startup))]
namespace mvcIdentity
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
