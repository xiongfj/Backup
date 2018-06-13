using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;

/*
 * BlogProvider 是一个抽象数据工厂, 需要派生出各种数据子类, 实现提供不同数据的功能
 * BlogFileSystemPovider 也是一个抽象的数据工厂
 * 
 * 数据工厂派生的子类可以使用不同的方法获取数据, 例如一个子类从数据库获取数据,一个子类从 XML 文件获取数据
 * 
 * 
 * 
 * 
 */

namespace ProviderTest
{
    public partial class _default : System.Web.UI.Page
    {
        private static BlogProviderCollection _providers;

        /*这个就是对外的实例接口对象, 所有的操作都可以通过获得的这个对象操作*/
        private static BlogProvider _provider;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
                return;

            var section = (BlogProviderSection)WebConfigurationManager.GetSection("BlogEngine/blogProvider");

            _providers = new BlogProviderCollection();

            // 根据section内容填充 _providers; 会回调 BlogProviderCollection::Add(..) 函数
            ProvidersHelper.InstantiateProviders(section.Providers, _providers, typeof(BlogProvider));

            // 通过名称 获取某个子类的实例化对象
            _provider = _providers[section.DefaultProvider];

            // 调用的是对应子类的函数
            string str = _provider.TestFunc();

            Response.Write(str);
        }
    }
}