using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ProviderTest
{
    public class XmlBlogProvider : BlogProvider
    {
        public override string TestFunc()
        {
            return "XmlBlogProvider .. ";
        }
    }
}