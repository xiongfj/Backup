using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ProviderTest
{
    public class DbBlogProvider : BlogProvider
    {
        public override string TestFunc()
        {
            return "DBBlogProvider -- ";
        }
    }
}