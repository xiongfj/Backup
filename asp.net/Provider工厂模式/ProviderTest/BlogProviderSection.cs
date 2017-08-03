using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;

namespace ProviderTest
{
    /*
     * 该类对象对应节点; <blogProvider defaultProvider="DbBlogProvider" fileStoreProvider="XmlBlogProvider"> 
     */
    public class BlogProviderSection : ConfigurationSection
    {
        #region Properties

        /// <summary>
        // 这个属性对应节点属性 'defaultProvider'
        /// </summary>
        [StringValidator(MinLength = 1)]
        [ConfigurationProperty("defaultProvider", DefaultValue = "XmlBlogProvider")] // 如果节点没有这个属性,使用这个默认值返回
        public string DefaultProvider
        {
            get
            {
                // 获取节点内 <blogProvider ..> 属性 defaultProvider="DbBlogProvider" 的值
                return (string)base["defaultProvider"];
            }

            set
            {
                base["defaultProvider"] = value;
            }
        }

        /// <summary>
        /// Gets or sets the name of the file storage provider, defaults to the XmlBlogProvider if one is not specified
        /// </summary>
        /// <remarks>
        /// This  attribute is not required, however allows for specifying different providers for various operations
        /// </remarks>
        [StringValidator(MinLength = 0)]
        [ConfigurationProperty("fileStoreProvider", IsRequired = false, DefaultValue = "XmlBlogProvider")]
        public string FileStoreProvider
        {
            get
            {
                return (string)base["fileStoreProvider"];
            }

            set
            {
                base["fileStoreProvider"] = value;
            }
        }

        /// <summary>
        // 调用 var section = (BlogProviderSection)WebConfigurationManager.GetSection("BlogEngine/blogProvider");
        // 的时候会填充这个 Collection
        /// </summary>
        [ConfigurationProperty("providers")]
        public ProviderSettingsCollection Providers
        {
            get
            {
                return (ProviderSettingsCollection)base["providers"];
            }
        }

        #endregion
    }
}