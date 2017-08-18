#region 程序集 System.Core, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\System.Core.dll
#endregion

using System.Collections;
using System.Collections.Generic;
using System.Reflection;

/*
该接口需要使用 IEnumerable<T> 的扩展方法实例化

ILookup<TKey, TSource> ToLookup<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector);
        
ILookup<TKey, TElement> ToLookup<TSource, TKey, TElement>(this IEnumerable<TSource> source,
						Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector);
		
ILookup<TKey, TElement> ToLookup<TSource, TKey, TElement>(this IEnumerable<TSource> source,
	Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector, IEqualityComparer<TKey> comparer);
        
		*/

namespace System.Linq
{
    [DefaultMember("Item")]
    public interface ILookup<TKey, TElement> : IEnumerable<IGrouping<TKey, TElement>>, IEnumerable
    {
        //     获取 System.Collections.Generic.IEnumerable`1 按指定的键索引值序列。
        IEnumerable<TElement> this[TKey key] { get; }

        //     获取对集合中的键/值数 System.Linq.ILookup`2。
        int Count { get; }

        //     确定指定的键是否存在于 System.Linq.ILookup`2。
        bool Contains(TKey key);
    }
}