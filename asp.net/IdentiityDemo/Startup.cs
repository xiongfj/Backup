using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(IdentiityDemo.Startup))]
namespace IdentiityDemo
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
