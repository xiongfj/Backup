using System;
using System.Collections.Generic;
using System.Configuration.Provider;
using System.Linq;
using System.Web;

namespace ProviderTest.FileSystemProvider
{
    public class BlogFileSystemProviderCollection : ProviderCollection
    {
        /// <param name="name">The name of the provider.</param>
        public new BlogFileSystemProvider this[string name]
        {
            get
            {
                return (BlogFileSystemProvider)base[name];
            }
        }

        /// <summary>
        /// Add a provider to the collection.
        /// </summary>
        /// <param name="provider">
        /// The provider.
        /// </param>
        public override void Add(ProviderBase provider)
        {
            if (provider == null)
            {
                throw new ArgumentNullException(nameof(provider));
            }

            if (!(provider is BlogFileSystemProvider))
            {
                throw new ArgumentException("Invalid provider type", nameof(provider));
            }

            base.Add(provider);
        }
    }
}