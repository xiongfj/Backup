using System;
using System.Collections.Generic;
using System.Configuration.Provider;
using System.Linq;
using System.Web;

namespace ProviderTest.FileSystemProvider
{
    /*
     *  类似 BlogProvider 
     */
    public abstract class BlogFileSystemProvider : ProviderBase
    {
        public abstract string func();
    }
}