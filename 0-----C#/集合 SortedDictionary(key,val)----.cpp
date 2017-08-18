#region 程序集 System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\System.dll
#endregion

using System.Diagnostics;
using System.Reflection;

namespace System.Collections.Generic
{
    //
    // 摘要:
    //     表示根据键进行排序的键/值对的集合。
    //
    // 类型参数:
    //   TKey:
    //     字典中的键的类型。
    //
    //   TValue:
    //     字典中的值的类型。
    [DebuggerDisplay("Count = {Count}")]
    [DebuggerTypeProxy(typeof(Generic.System_DictionaryDebugView<,>))]
    [DefaultMember("Item")]
    public class SortedDictionary<TKey, TValue> : IDictionary<TKey, TValue>, ICollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IDictionary, ICollection, IEnumerable
    {
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedDictionary`2 类的一个新实例，该实例为空并对键类型使用默认 System.Collections.Generic.IComparer`1
        //     实现。
        public SortedDictionary();
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedDictionary`2 类的新实例，该实例包含从指定的 System.Collections.Generic.IDictionary`2
        //     中复制的元素，并使用键类型的默认 System.Collections.Generic.IComparer`1 实现。
        //
        // 参数:
        //   dictionary:
        //     System.Collections.Generic.IDictionary`2，它的元素被复制到新 System.Collections.Generic.SortedDictionary`2。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     dictionary 为 null。
        //
        //   T:System.ArgumentException:
        //     dictionary 包含一个或多个重复键。
        public SortedDictionary(IDictionary<TKey, TValue> dictionary);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedDictionary`2 类的一个新实例，该实例为空并对比较键使用指定 System.Collections.Generic.IComparer`1
        //     实现。
        //
        // 参数:
        //   comparer:
        //     比较键时要使用的 System.Collections.Generic.IComparer`1 实现，或者为 null，以便为键类型使用默认的 System.Collections.Generic.Comparer`1。
        public SortedDictionary(IComparer<TKey> comparer);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedDictionary`2 类的新实例，该实例包含从指定的 System.Collections.Generic.IDictionary`2
        //     中复制的元素，并使用指定的 System.Collections.Generic.IComparer`1 实现来比较键。
        //
        // 参数:
        //   dictionary:
        //     System.Collections.Generic.IDictionary`2，它的元素被复制到新 System.Collections.Generic.SortedDictionary`2。
        //
        //   comparer:
        //     比较键时要使用的 System.Collections.Generic.IComparer`1 实现，或者为 null，以便为键类型使用默认的 System.Collections.Generic.Comparer`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     dictionary 为 null。
        //
        //   T:System.ArgumentException:
        //     dictionary 包含一个或多个重复键。
        public SortedDictionary(IDictionary<TKey, TValue> dictionary, IComparer<TKey> comparer);

        //
        // 摘要:
        //     获取或设置与指定的键关联的值。
        //
        // 参数:
        //   key:
        //     要获取或设置的值的键。
        //
        // 返回结果:
        //     与指定的键相关联的值。 如果指定键未找到，则 Get 操作引发 System.Collections.Generic.KeyNotFoundException，而
        //     Set 操作创建一个带指定键的新元素。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        //
        //   T:System.Collections.Generic.KeyNotFoundException:
        //     已检索该属性和 key 集合中不存在。
        public TValue this[TKey key] { get; set; }

        //
        // 摘要:
        //     获得一个包含 System.Collections.Generic.SortedDictionary`2 中的值的集合。
        //
        // 返回结果:
        //     一个 System.Collections.Generic.SortedDictionary`2.ValueCollection，包含 System.Collections.Generic.SortedDictionary`2
        //     中的值。
        public ValueCollection Values { get; }
        //
        // 摘要:
        //     获得一个包含 System.Collections.Generic.SortedDictionary`2 中的键的集合。
        //
        // 返回结果:
        //     一个 System.Collections.Generic.SortedDictionary`2.KeyCollection，包含 System.Collections.Generic.SortedDictionary`2
        //     中的键。
        public KeyCollection Keys { get; }
        //
        // 摘要:
        //     获取用于对 System.Collections.Generic.IComparer`1 的元素进行排序的 System.Collections.Generic.SortedDictionary`2。
        //
        // 返回结果:
        //     用于对 System.Collections.Generic.IComparer`1 的元素进行排序的 System.Collections.Generic.SortedDictionary`2。
        public IComparer<TKey> Comparer { get; }
        //
        // 摘要:
        //     获取包含在 System.Collections.Generic.SortedDictionary`2 中的键/值对的数目。
        //
        // 返回结果:
        //     包含在 System.Collections.Generic.SortedDictionary`2 中的键/值对的数目。
        public int Count { get; }

        //
        // 摘要:
        //     将带有指定键和值的元素添加到 System.Collections.Generic.SortedDictionary`2 中。
        //
        // 参数:
        //   key:
        //     要添加的元素的键。
        //
        //   value:
        //     要添加的元素的值。 对于引用类型，该值可以为 null。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        //
        //   T:System.ArgumentException:
        //     System.Collections.Generic.SortedDictionary`2 中已存在具有相同键的元素。
        public void Add(TKey key, TValue value);
        //
        // 摘要:
        //     从 System.Collections.Generic.SortedDictionary`2 中移除所有元素。
        public void Clear();
        //
        // 摘要:
        //     确定是否 System.Collections.Generic.SortedDictionary`2 包含带有指定键的元素。
        //
        // 参数:
        //   key:
        //     要在 System.Collections.Generic.SortedDictionary`2 中定位的键。
        //
        // 返回结果:
        //     如果 true 包含具有指定键的元素，则为 System.Collections.Generic.SortedDictionary`2；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public bool ContainsKey(TKey key);
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedDictionary`2 是否包含具有指定值的元素。
        //
        // 参数:
        //   value:
        //     要在 System.Collections.Generic.SortedDictionary`2 中定位的值。 对于引用类型，该值可以为 null。
        //
        // 返回结果:
        //     如果 true 包含具有指定值的元素，则为 System.Collections.Generic.SortedDictionary`2；否则为 false。
        public bool ContainsValue(TValue value);
        //
        // 摘要:
        //     从指定的索引处开始，将 System.Collections.Generic.SortedDictionary`2 的元素复制到指定的 System.Collections.Generic.KeyValuePair`2
        //     结构的数组中。
        //
        // 参数:
        //   array:
        //     System.Collections.Generic.KeyValuePair`2 结构的一维数组，它是从当前 System.Collections.Generic.SortedDictionary`2
        //     中复制的元素的目标。该数组必须具有从零开始的索引。
        //
        //   index:
        //     array 中从零开始的索引，从此处开始复制。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     array 为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     index 小于 0。
        //
        //   T:System.ArgumentException:
        //     源中的元素数目 System.Collections.Generic.SortedDictionary`2 大于从的可用空间 index 目标从头到尾 array。
        public void CopyTo(KeyValuePair<TKey, TValue>[] array, int index);
        //
        // 摘要:
        //     返回循环访问 System.Collections.Generic.SortedDictionary`2 的枚举数。
        //
        // 返回结果:
        //     用于 System.Collections.Generic.SortedDictionary`2.Enumerator 的 System.Collections.Generic.SortedDictionary`2。
        public Enumerator GetEnumerator();
        //
        // 摘要:
        //     从 System.Collections.Generic.SortedDictionary`2 中移除带有指定键的元素。
        //
        // 参数:
        //   key:
        //     要移除的元素的键。
        //
        // 返回结果:
        //     如果该元素已成功移除，则为 true；否则为 false。 如果在 false 中没有找到 key，则此方法也会返回 System.Collections.Generic.SortedDictionary`2。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public bool Remove(TKey key);
        //
        // 摘要:
        //     获取与指定键关联的值。
        //
        // 参数:
        //   key:
        //     要获取的值的键。
        //
        //   value:
        //     当此方法返回时，如果找到指定键，则返回与该键相关联的值；否则，将返回 value 参数的类型的默认值。
        //
        // 返回结果:
        //     如果 true 包含具有指定键的元素，则为 System.Collections.Generic.SortedDictionary`2；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public bool TryGetValue(TKey key, out TValue value);

        //
        // 摘要:
        //     枚举 System.Collections.Generic.SortedDictionary`2 的元素。
        public struct Enumerator : IEnumerator<KeyValuePair<TKey, TValue>>, IDisposable, IDictionaryEnumerator, IEnumerator
        {
            //
            // 摘要:
            //     获取枚举数当前位置的元素。
            //
            // 返回结果:
            //     System.Collections.Generic.SortedDictionary`2 中位于该枚举数当前位置的元素。
            public KeyValuePair<TKey, TValue> Current { get; }

            //
            // 摘要:
            //     释放由 System.Collections.Generic.SortedDictionary`2.Enumerator 使用的所有资源。
            public void Dispose();
            //
            // 摘要:
            //     使枚举数前进到 System.Collections.Generic.SortedDictionary`2 的下一个元素。
            //
            // 返回结果:
            //     如果枚举数已成功地推进到下一个元素，则为 true；如果枚举数传递到集合的末尾，则为 false。
            //
            // 异常:
            //   T:System.InvalidOperationException:
            //     创建枚举器后，已修改该集合。
            public bool MoveNext();
        }

        //
        // 摘要:
        //     表示 System.Collections.Generic.SortedDictionary`2 中密钥的集合。 此类不能被继承。
        [DebuggerDisplay("Count = {Count}")]
        [DebuggerTypeProxy(typeof(Generic.System_DictionaryKeyCollectionDebugView<,>))]
        public sealed class KeyCollection : ICollection<TKey>, IEnumerable<TKey>, ICollection, IEnumerable
        {
            //
            // 摘要:
            //     新实例初始化 System.Collections.Generic.SortedDictionary`2.KeyCollection 类来反映中指定的键
            //     System.Collections.Generic.SortedDictionary`2。
            //
            // 参数:
            //   dictionary:
            //     System.Collections.Generic.SortedDictionary`2 其键反映在新 System.Collections.Generic.SortedDictionary`2.KeyCollection。
            //
            // 异常:
            //   T:System.ArgumentNullException:
            //     dictionary 为 null。
            public KeyCollection(SortedDictionary<TKey, TValue> dictionary);

            //
            // 摘要:
            //     获取 System.Collections.Generic.SortedDictionary`2.KeyCollection 中包含的元素数。
            //
            // 返回结果:
            //     System.Collections.Generic.SortedDictionary`2.KeyCollection 中包含的元素数。
            public int Count { get; }

            //
            // 摘要:
            //     副本 System.Collections.Generic.SortedDictionary`2.KeyCollection 到现有一维数组，从指定的数组索引处开始的元素。
            //
            // 参数:
            //   array:
            //     一维数组，它是从 System.Collections.Generic.SortedDictionary`2.KeyCollection 中复制的元素的目标。
            //     该数组的索引必须从零开始。
            //
            //   index:
            //     array 中从零开始的索引，从此处开始复制。
            //
            // 异常:
            //   T:System.ArgumentNullException:
            //     array 为 null。
            //
            //   T:System.ArgumentOutOfRangeException:
            //     index 小于 0。
            //
            //   T:System.ArgumentException:
            //     源中的元素数目 System.Collections.Generic.SortedDictionary`2.KeyCollection 大于从的可用空间
            //     index 目标从头到尾 array。
            public void CopyTo(TKey[] array, int index);
            //
            // 摘要:
            //     返回循环访问 System.Collections.Generic.SortedDictionary`2.KeyCollection 的枚举数。
            //
            // 返回结果:
            //     用于 System.Collections.Generic.SortedDictionary`2.KeyCollection 的 System.Collections.Generic.SortedDictionary`2.KeyCollection.Enumerator
            //     结构。
            public Enumerator GetEnumerator();

            //
            // 摘要:
            //     枚举 System.Collections.Generic.SortedDictionary`2.KeyCollection 的元素。
            public struct Enumerator : IEnumerator<TKey>, IDisposable, IEnumerator
            {
                //
                // 摘要:
                //     获取枚举数当前位置的元素。
                //
                // 返回结果:
                //     System.Collections.Generic.SortedDictionary`2.KeyCollection 中位于该枚举数当前位置的元素。
                public TKey Current { get; }

                //
                // 摘要:
                //     释放由 System.Collections.Generic.SortedDictionary`2.KeyCollection.Enumerator 使用的所有资源。
                public void Dispose();
                //
                // 摘要:
                //     使枚举数前进到 System.Collections.Generic.SortedDictionary`2.KeyCollection 的下一个元素。
                //
                // 返回结果:
                //     如果枚举数已成功地推进到下一个元素，则为 true；如果枚举数传递到集合的末尾，则为 false。
                //
                // 异常:
                //   T:System.InvalidOperationException:
                //     创建枚举器后，已修改该集合。
                public bool MoveNext();
            }
        }
        //
        // 摘要:
        //     表示 System.Collections.Generic.SortedDictionary`2 中值的集合。 无法继承此类
        [DebuggerDisplay("Count = {Count}")]
        [DebuggerTypeProxy(typeof(Generic.System_DictionaryValueCollectionDebugView<,>))]
        public sealed class ValueCollection : ICollection<TValue>, IEnumerable<TValue>, ICollection, IEnumerable
        {
            //
            // 摘要:
            //     新实例初始化 System.Collections.Generic.SortedDictionary`2.ValueCollection 类来反映中指定的值
            //     System.Collections.Generic.SortedDictionary`2。
            //
            // 参数:
            //   dictionary:
            //     System.Collections.Generic.SortedDictionary`2 其值反映在新 System.Collections.Generic.SortedDictionary`2.ValueCollection。
            //
            // 异常:
            //   T:System.ArgumentNullException:
            //     dictionary 为 null。
            public ValueCollection(SortedDictionary<TKey, TValue> dictionary);

            //
            // 摘要:
            //     获取 System.Collections.Generic.SortedDictionary`2.ValueCollection 中包含的元素数。
            //
            // 返回结果:
            //     System.Collections.Generic.SortedDictionary`2.ValueCollection 中包含的元素数。
            public int Count { get; }

            //
            // 摘要:
            //     副本 System.Collections.Generic.SortedDictionary`2.ValueCollection 到现有一维数组，从指定的数组索引处开始的元素。
            //
            // 参数:
            //   array:
            //     一维数组，它是从 System.Collections.Generic.SortedDictionary`2.ValueCollection 中复制的元素的目标。
            //     该数组的索引必须从零开始。
            //
            //   index:
            //     array 中从零开始的索引，从此处开始复制。
            //
            // 异常:
            //   T:System.ArgumentNullException:
            //     array 为 null。
            //
            //   T:System.ArgumentOutOfRangeException:
            //     index 小于 0。
            //
            //   T:System.ArgumentException:
            //     源中的元素数目 System.Collections.Generic.SortedDictionary`2.ValueCollection 大于从的可用空间
            //     index 目标从头到尾 array。
            public void CopyTo(TValue[] array, int index);
            //
            // 摘要:
            //     返回循环访问 System.Collections.Generic.SortedDictionary`2.ValueCollection 的枚举数。
            //
            // 返回结果:
            //     用于 System.Collections.Generic.SortedDictionary`2.ValueCollection 的 System.Collections.Generic.SortedDictionary`2.ValueCollection.Enumerator
            //     结构。
            public Enumerator GetEnumerator();

            //
            // 摘要:
            //     枚举 System.Collections.Generic.SortedDictionary`2.ValueCollection 的元素。
            public struct Enumerator : IEnumerator<TValue>, IDisposable, IEnumerator
            {
                //
                // 摘要:
                //     获取枚举数当前位置的元素。
                //
                // 返回结果:
                //     System.Collections.Generic.SortedDictionary`2.ValueCollection 中位于该枚举数当前位置的元素。
                public TValue Current { get; }

                //
                // 摘要:
                //     释放由 System.Collections.Generic.SortedDictionary`2.ValueCollection.Enumerator
                //     使用的所有资源。
                public void Dispose();
                //
                // 摘要:
                //     使枚举数前进到 System.Collections.Generic.SortedDictionary`2.ValueCollection 的下一个元素。
                //
                // 返回结果:
                //     如果枚举数已成功地推进到下一个元素，则为 true；如果枚举数传递到集合的末尾，则为 false。
                //
                // 异常:
                //   T:System.InvalidOperationException:
                //     创建枚举器后，已修改该集合。
                public bool MoveNext();
            }
        }
    }
}