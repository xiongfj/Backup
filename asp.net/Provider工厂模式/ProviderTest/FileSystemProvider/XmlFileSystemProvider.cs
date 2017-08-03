using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ProviderTest.FileSystemProvider
{
    public class XmlFileSystemProvider : BlogFileSystemProvider
    {
        public override string func()
        {
            return "XmlFileSystemProvider ;;";
        }
    }
}