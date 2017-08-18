#region 程序集 System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\System.dll
#endregion

using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;

namespace System.Collections.Generic
{
    //
    // 摘要:
    //     表示基于相关的 System.Collections.Generic.IComparer`1 实现按键进行排序的键/值对的集合。
    //
    // 类型参数:
    //   TKey:
    //     集合中的键的类型。
    //
    //   TValue:
    //     集合中值的类型。
    [ComVisible(false)]
    [DebuggerDisplay("Count = {Count}")]
    [DebuggerTypeProxy(typeof(Generic.System_DictionaryDebugView<,>))]
    [DefaultMember("Item")]
    public class SortedList<TKey, TValue> : IDictionary<TKey, TValue>, ICollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IDictionary, ICollection, IEnumerable
    {
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedList`2 类的新实例，该示例为空且具有默认的初始容量，并使用默认的 System.Collections.Generic.IComparer`1。
        public SortedList();
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedList`2 类的新实例，该示例为空且具有指定的初始容量，并使用默认的 System.Collections.Generic.IComparer`1。
        //
        // 参数:
        //   capacity:
        //     System.Collections.Generic.SortedList`2 可包含的初始元素数。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     capacity 小于零。
        public SortedList(int capacity);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedList`2 类的新实例，该实例为空，具有默认的初始容量并使用指定的 System.Collections.Generic.IComparer`1。
        //
        // 参数:
        //   comparer:
        //     在对键进行比较时使用的 System.Collections.Generic.IComparer`1 实现。- 或 -为这类键使用默认的 null，则为
        //     System.Collections.Generic.Comparer`1。
        public SortedList(IComparer<TKey> comparer);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedList`2 类的新实例，该实例包含从指定的 System.Collections.Generic.IDictionary`2
        //     中复制的元素，其容量足以容纳所复制的元素数并使用默认的 System.Collections.Generic.IComparer`1。
        //
        // 参数:
        //   dictionary:
        //     System.Collections.Generic.IDictionary`2，它的元素被复制到新 System.Collections.Generic.SortedList`2。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     dictionary 为 null。
        //
        //   T:System.ArgumentException:
        //     dictionary 包含一个或多个重复键。
        public SortedList(IDictionary<TKey, TValue> dictionary);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedList`2 类的新实例，该实例为空，具有指定的初始容量并使用指定的 System.Collections.Generic.IComparer`1。
        //
        // 参数:
        //   capacity:
        //     System.Collections.Generic.SortedList`2 可包含的初始元素数。
        //
        //   comparer:
        //     在对键进行比较时使用的 System.Collections.Generic.IComparer`1 实现。- 或 -为这类键使用默认的 null，则为
        //     System.Collections.Generic.Comparer`1。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     capacity 小于零。
        public SortedList(int capacity, IComparer<TKey> comparer);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedList`2 类的新实例，该实例包含从指定的 System.Collections.Generic.IDictionary`2
        //     中复制的元素，其容量足以容纳所复制的元素数并使用指定的 System.Collections.Generic.IComparer`1。
        //
        // 参数:
        //   dictionary:
        //     System.Collections.Generic.IDictionary`2，它的元素被复制到新 System.Collections.Generic.SortedList`2。
        //
        //   comparer:
        //     在对键进行比较时使用的 System.Collections.Generic.IComparer`1 实现。- 或 -为这类键使用默认的 null，则为
        //     System.Collections.Generic.Comparer`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     dictionary 为 null。
        //
        //   T:System.ArgumentException:
        //     dictionary 包含一个或多个重复键。
        public SortedList(IDictionary<TKey, TValue> dictionary, IComparer<TKey> comparer);

        //
        // 摘要:
        //     获取或设置与指定的键关联的值。
        //
        // 参数:
        //   key:
        //     要获取或设置其值的键。
        //
        // 返回结果:
        //     与指定的键相关联的值。 如果找不到指定的键，则 get 操作会引发一个 System.Collections.Generic.KeyNotFoundException，而
        //     set 操作会创建一个使用指定键的新元素。
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
        //     获得一个包含 System.Collections.Generic.SortedList`2 中的值的集合。
        //
        // 返回结果:
        //     一个 System.Collections.Generic.IList`1，包含 System.Collections.Generic.SortedList`2
        //     中的值。
        public IList<TValue> Values { get; }
        //
        // 摘要:
        //     获取或设置 System.Collections.Generic.SortedList`2 可包含的元素数。
        //
        // 返回结果:
        //     System.Collections.Generic.SortedList`2 可包含的元素数。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     System.Collections.Generic.SortedList`2.Capacity 设置为一个值，该值小于 System.Collections.Generic.SortedList`2.Count。
        //
        //   T:System.OutOfMemoryException:
        //     系统上没有足够的可用内存。
        public int Capacity { get; set; }
        //
        // 摘要:
        //     获取该排序列表的 System.Collections.Generic.IComparer`1。
        //
        // 返回结果:
        //     当前 System.IComparable`1 的 System.Collections.Generic.SortedList`2。
        public IComparer<TKey> Comparer { get; }
        //
        // 摘要:
        //     获取包含在 System.Collections.Generic.SortedList`2 中的键/值对的数目。
        //
        // 返回结果:
        //     包含在 System.Collections.Generic.SortedList`2 中的键/值对的数目。
        public int Count { get; }
        //
        // 摘要:
        //     获取一个按排序顺序包含 System.Collections.Generic.SortedList`2 中的键的集合。
        //
        // 返回结果:
        //     一个 System.Collections.Generic.IList`1，包含 System.Collections.Generic.SortedList`2
        //     中的键。
        public IList<TKey> Keys { get; }

        //
        // 摘要:
        //     将带有指定键和值的元素添加到 System.Collections.Generic.SortedList`2 中。
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
        //     System.Collections.Generic.SortedList`2 中已存在具有相同键的元素。
        public void Add(TKey key, TValue value);
        //
        // 摘要:
        //     从 System.Collections.Generic.SortedList`2 中移除所有元素。
        public void Clear();
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedList`2 是否包含特定键。
        //
        // 参数:
        //   key:
        //     要在 System.Collections.Generic.SortedList`2 中定位的键。
        //
        // 返回结果:
        //     如果 true 包含具有指定键的元素，则为 System.Collections.Generic.SortedList`2；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public bool ContainsKey(TKey key);
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedList`2 是否包含特定值。
        //
        // 参数:
        //   value:
        //     要在 System.Collections.Generic.SortedList`2 中定位的值。 对于引用类型，该值可以为 null。
        //
        // 返回结果:
        //     如果 true 包含具有指定值的元素，则为 System.Collections.Generic.SortedList`2；否则为 false。
        public bool ContainsValue(TValue value);
        //
        // 摘要:
        //     返回循环访问 System.Collections.Generic.SortedList`2 的枚举数。
        //
        // 返回结果:
        //     System.Collections.Generic.IEnumerator`1 的类型 System.Collections.Generic.KeyValuePair`2
        //     的 System.Collections.Generic.SortedList`2。
        public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator();
        //
        // 摘要:
        //     在整个 System.Collections.Generic.SortedList`2 中搜索指定键并返回从零开始的索引。
        //
        // 参数:
        //   key:
        //     要在 System.Collections.Generic.SortedList`2 中定位的键。
        //
        // 返回结果:
        //     如果找到，则为整个 key 中 System.Collections.Generic.SortedList`2 的从零开始的索引；否则为 -1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public int IndexOfKey(TKey key);
        //
        // 摘要:
        //     在整个 System.Collections.Generic.SortedList`2 中搜索指定的值，并返回第一个匹配项的从零开始的索引。
        //
        // 参数:
        //   value:
        //     要在 System.Collections.Generic.SortedList`2 中定位的值。 对于引用类型，该值可以为 null。
        //
        // 返回结果:
        //     如果找到，则为整个 value 中 System.Collections.Generic.SortedList`2 第一个匹配项的从零开始的索引；否则为
        //     -1。
        public int IndexOfValue(TValue value);
        //
        // 摘要:
        //     从 System.Collections.Generic.SortedList`2 中移除带有指定键的元素。
        //
        // 参数:
        //   key:
        //     要移除的元素的键。
        //
        // 返回结果:
        //     如果该元素已成功移除，则为 true；否则为 false。 如果在原始 false 中没有找到 key，则此方法也会返回 System.Collections.Generic.SortedList`2。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public bool Remove(TKey key);
        //
        // 摘要:
        //     移除 System.Collections.Generic.SortedList`2 的指定索引处的元素。
        //
        // 参数:
        //   index:
        //     要移除的元素的从零开始的索引。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     index 小于零。- 或 -index 等于或大于 System.Collections.Generic.SortedList`2.Count。
        public void RemoveAt(int index);
        //
        // 摘要:
        //     如果元素数小于当前容量的 90%，将容量设置为 System.Collections.Generic.SortedList`2 中的实际元素数。
        public void TrimExcess();
        //
        // 摘要:
        //     获取与指定键关联的值。
        //
        // 参数:
        //   key:
        //     要获取其值的键。
        //
        //   value:
        //     当此方法返回时，如果找到指定键，则返回与该键相关联的值；否则，将返回 value 参数的类型的默认值。 此参数未经初始化即被传递。
        //
        // 返回结果:
        //     如果 true 包含具有指定键的元素，则为 System.Collections.Generic.SortedList`2；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     key 为 null。
        public bool TryGetValue(TKey key, out TValue value);
    }
}