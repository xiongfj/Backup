using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(MainTain.Startup))]
namespace MainTain
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
