using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(mvc5sql.Startup))]
namespace mvc5sql
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
