using System;
using System.Collections.Generic;
using System.Configuration.Provider;
using System.Linq;
using System.Web;

namespace ProviderTest
{
    /* 该类只定义函数接口, 不能做具体实现, 提供一个对外统一的接口
     * 子类按照这个统一的接口实现函数, 从而实现不同的功能
     */
    public abstract class BlogProvider : ProviderBase
    {
        public abstract string TestFunc();

        // public abstract void SaveData();
        // public abstract void DeleteData();
        // public abstract void InsertData();
        // public abstract void UpdateSql();
    }
}