#region 程序集 System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\System.dll
#endregion

using System.Diagnostics;
using System.Runtime.Serialization;
using System.Security;

namespace System.Collections.Generic
{
    //
    // 摘要:
    //     表示按排序顺序维护的对象的集合。
    //
    // 类型参数:
    //   T:
    //     集内元素的类型。
    [DebuggerDisplay("Count = {Count}")]
    [DebuggerTypeProxy(typeof(Generic.SortedSetDebugView<>))]
    public class SortedSet<T> : ISet<T>, ICollection<T>, IEnumerable<T>, ICollection, IEnumerable, ISerializable, IDeserializationCallback
    {
        //
        // 摘要:
        //     初始化 System.Collections.Generic.SortedSet`1 类的新实例。
        public SortedSet();
        //
        // 摘要:
        //     新实例初始化 System.Collections.Generic.SortedSet`1 类，该类使用指定的比较器。
        //
        // 参数:
        //   comparer:
        //     要用来进行比较的对象的默认比较器。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     comparer 为 null。
        public SortedSet(IComparer<T> comparer);
        //
        // 摘要:
        //     新实例初始化 System.Collections.Generic.SortedSet`1 类，其中包含的元素复制从指定的可枚举集合。
        //
        // 参数:
        //   collection:
        //     要复制的可枚举集合。
        public SortedSet(IEnumerable<T> collection);
        //
        // 摘要:
        //     新实例初始化 System.Collections.Generic.SortedSet`1 类，其中包含的元素复制从指定的可枚举集合，并使用指定的比较器。
        //
        // 参数:
        //   collection:
        //     要复制的可枚举集合。
        //
        //   comparer:
        //     要用来进行比较的对象的默认比较器。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     collection 为 null。
        public SortedSet(IEnumerable<T> collection, IComparer<T> comparer);
        //
        // 摘要:
        //     新实例初始化 System.Collections.Generic.SortedSet`1 类，其中包含序列化数据。
        //
        // 参数:
        //   info:
        //     包含序列化所需的信息的对象 System.Collections.Generic.SortedSet`1 对象。
        //
        //   context:
        //     包含的源和目标与相关联的序列化流的结构 System.Collections.Generic.SortedSet`1 对象。
        protected SortedSet(SerializationInfo info, StreamingContext context);

        //
        // 摘要:
        //     获取用于为 System.Collections.Generic.SortedSet`1 中的值排序的 System.Collections.Generic.IComparer`1
        //     对象。
        //
        // 返回结果:
        //     用于为 System.Collections.Generic.SortedSet`1 中的值排序的比较器。
        public IComparer<T> Comparer { get; }
        //
        // 摘要:
        //     获取中的元素数 System.Collections.Generic.SortedSet`1。
        //
        // 返回结果:
        //     System.Collections.Generic.SortedSet`1 中的元素的数量。
        public int Count { get; }
        //
        // 摘要:
        //     获取最大值 System.Collections.Generic.SortedSet`1, ，如比较器的定义。
        //
        // 返回结果:
        //     集内的最大值。
        public T Max { get; }
        //
        // 摘要:
        //     获取最小值 System.Collections.Generic.SortedSet`1, ，如比较器的定义。
        //
        // 返回结果:
        //     集内的最小值。
        public T Min { get; }

        //
        // 摘要:
        //     返回 System.Collections.IEqualityComparer 可用来创建包含各个集的集合的对象。
        //
        // 返回结果:
        //     用于创建集的集合的比较器。
        public static IEqualityComparer<SortedSet<T>> CreateSetComparer();
        //
        // 摘要:
        //     返回 System.Collections.IEqualityComparer 对象根据指定的比较器，用于创建包含各个集的集合。
        //
        // 参数:
        //   memberEqualityComparer:
        //     用于创建返回的比较器的比较器。
        //
        // 返回结果:
        //     用于创建集的集合的比较器。
        public static IEqualityComparer<SortedSet<T>> CreateSetComparer(IEqualityComparer<T> memberEqualityComparer);
        //
        // 摘要:
        //     向集内添加元素，并返回一个指示是否已成功添加元素的值。
        //
        // 参数:
        //   item:
        //     要添加到集中的元素。
        //
        // 返回结果:
        //     true 如果 item 添加到集; 否则为 false。
        public bool Add(T item);
        //
        // 摘要:
        //     从集内移除所有元素。
        public virtual void Clear();
        //
        // 摘要:
        //     确定集是否包含特定元素。
        //
        // 参数:
        //   item:
        //     要在集内定位的元素。
        //
        // 返回结果:
        //     true 如果该集包含 item; 否则为 false。
        public virtual bool Contains(T item);
        //
        // 摘要:
        //     将复制的完整 System.Collections.Generic.SortedSet`1 到兼容的一维数组，从目标数组的开头。
        //
        // 参数:
        //   array:
        //     一维数组，它是从复制的元素的目标 System.Collections.Generic.SortedSet`1。
        //
        // 异常:
        //   T:System.ArgumentException:
        //     源中的元素数目 System.Collections.Generic.SortedSet`1 超过目标数组可包含的元素数。
        //
        //   T:System.ArgumentNullException:
        //     array 为 null。
        public void CopyTo(T[] array);
        //
        // 摘要:
        //     将复制的完整 System.Collections.Generic.SortedSet`1 到兼容的一维数组，从指定的数组索引处开始。
        //
        // 参数:
        //   array:
        //     一维数组，它是从复制的元素的目标 System.Collections.Generic.SortedSet`1。 该数组的索引必须从零开始。
        //
        //   index:
        //     array 中从零开始的索引，从此处开始复制。
        //
        // 异常:
        //   T:System.ArgumentException:
        //     源数组中的元素数大于从的可用空间 index 到目标数组的末尾。
        //
        //   T:System.ArgumentNullException:
        //     array 为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     index 小于零。
        public void CopyTo(T[] array, int index);
        //
        // 摘要:
        //     将指定的数目的元素从复制 System.Collections.Generic.SortedSet`1 到兼容的一维数组，从指定的数组索引处开始。
        //
        // 参数:
        //   array:
        //     一维数组，它是从复制的元素的目标 System.Collections.Generic.SortedSet`1。 该数组的索引必须从零开始。
        //
        //   index:
        //     array 中从零开始的索引，从此处开始复制。
        //
        //   count:
        //     要复制的元素数。
        //
        // 异常:
        //   T:System.ArgumentException:
        //     源数组中的元素数大于从的可用空间 index 到目标数组的末尾。
        //
        //   T:System.ArgumentNullException:
        //     array 为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     index 小于零。- 或 -count 小于零。
        public void CopyTo(T[] array, int index, int count);
        //
        // 摘要:
        //     移除从当前的指定集合中的所有元素 System.Collections.Generic.SortedSet`1 对象。
        //
        // 参数:
        //   other:
        //     要从 System.Collections.Generic.SortedSet`1 对象中移除的项的集合。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        public void ExceptWith(IEnumerable<T> other);
        //
        // 摘要:
        //     返回循环访问 System.Collections.Generic.SortedSet`1 的枚举数。
        //
        // 返回结果:
        //     返回一个按排序顺序循环访问 System.Collections.Generic.SortedSet`1 的枚举数。
        public Enumerator GetEnumerator();
        //
        // 摘要:
        //     返回的视图中一小部分 System.Collections.Generic.SortedSet`1。
        //
        // 参数:
        //   lowerValue:
        //     视图中所需的最小值。
        //
        //   upperValue:
        //     视图中所需的最大值。
        //
        // 返回结果:
        //     仅包含指定范围内的值的子集视图。
        //
        // 异常:
        //   T:System.ArgumentException:
        //     lowerValue 是多个 upperValue 根据比较器。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     在视图上尝试的操作指定的范围超出了 lowerValue 和 upperValue。
        public virtual SortedSet<T> GetViewBetween(T lowerValue, T upperValue);
        //
        // 摘要:
        //     修改当前 System.Collections.Generic.SortedSet`1 对象，因此该变量包含也存在在指定集合中的唯一元素。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        public virtual void IntersectWith(IEnumerable<T> other);
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedSet`1 对象是否为指定集合的真子集。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 返回结果:
        //     如果 System.Collections.Generic.SortedSet`1 对象是 other 的真子集，则为 true；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        [SecuritySafeCritical]
        public bool IsProperSubsetOf(IEnumerable<T> other);
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedSet`1 对象是否为指定集合的真超集。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 返回结果:
        //     如果 System.Collections.Generic.SortedSet`1 对象是 other 的真超集，则为 true；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        [SecuritySafeCritical]
        public bool IsProperSupersetOf(IEnumerable<T> other);
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedSet`1 对象是否为指定集合的子集。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 返回结果:
        //     true 如果当前 System.Collections.Generic.SortedSet`1 对象是子集 other; 否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        [SecuritySafeCritical]
        public bool IsSubsetOf(IEnumerable<T> other);
        //
        // 摘要:
        //     确定 System.Collections.Generic.SortedSet`1 对象是否为指定集合的超集。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 返回结果:
        //     如果 System.Collections.Generic.SortedSet`1 对象是 other 的超集，则为 true；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        public bool IsSupersetOf(IEnumerable<T> other);
        //
        // 摘要:
        //     确定是否当前的 System.Collections.Generic.SortedSet`1 对象和指定的集合共享通用元素。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 返回结果:
        //     如果 System.Collections.Generic.SortedSet`1 对象和 other 共享至少一个公共元素，则为 true；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        public bool Overlaps(IEnumerable<T> other);
        //
        // 摘要:
        //     移除指定的项从 System.Collections.Generic.SortedSet`1。
        //
        // 参数:
        //   item:
        //     要移除的元素。
        //
        // 返回结果:
        //     true 如果找到并成功移除，则该元素否则为 false。
        public bool Remove(T item);
        //
        // 摘要:
        //     移除与从指定的谓词所定义的条件匹配的所有元素 System.Collections.Generic.SortedSet`1。
        //
        // 参数:
        //   match:
        //     用于定义要移除的元素应满足的条件的委托。
        //
        // 返回结果:
        //     已删除的元素数目 System.Collections.Generic.SortedSet`1 集合...
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     match 为 null。
        public int RemoveWhere(Predicate<T> match);
        //
        // 摘要:
        //     返回 System.Collections.Generic.IEnumerable`1 ，它循环访问 System.Collections.Generic.SortedSet`1
        //     按相反的顺序。
        //
        // 返回结果:
        //     枚举数循环访问 System.Collections.Generic.SortedSet`1 按相反的顺序。
        public IEnumerable<T> Reverse();
        //
        // 摘要:
        //     确定是否当前 System.Collections.Generic.SortedSet`1 对象和指定的集合包含相同的元素。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 返回结果:
        //     true 如果当前 System.Collections.Generic.SortedSet`1 对象是否等于 other; 否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        [SecuritySafeCritical]
        public bool SetEquals(IEnumerable<T> other);
        //
        // 摘要:
        //     修改当前 System.Collections.Generic.SortedSet`1 对象以使其包含存在的元素显示在当前对象或指定的集合中，但不要同时使用两者。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        public void SymmetricExceptWith(IEnumerable<T> other);
        //
        // 摘要:
        //     修改当前 System.Collections.Generic.SortedSet`1 对象以使其包含在当前对象或指定的集合中存在的所有元素。
        //
        // 参数:
        //   other:
        //     要与当前的 System.Collections.Generic.SortedSet`1 对象进行比较的集合。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     other 为 null。
        public void UnionWith(IEnumerable<T> other);
        //
        // 摘要:
        //     实现 System.Runtime.Serialization.ISerializable 接口，并返回必须要序列化的数据 System.Collections.Generic.SortedSet`1
        //     对象。
        //
        // 参数:
        //   info:
        //     一个 System.Runtime.Serialization.SerializationInfo 对象，它包含序列化所需的信息 System.Collections.Generic.SortedSet`1
        //     对象。
        //
        //   context:
        //     System.Runtime.Serialization.StreamingContext 结构，其中包含与 System.Collections.Generic.SortedSet`1
        //     对象关联的序列化流的源和目标。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     info 为 null。
        protected virtual void GetObjectData(SerializationInfo info, StreamingContext context);
        //
        // 摘要:
        //     实现 System.Runtime.Serialization.ISerializable 接口，并反序列化时引发事件已完成反序列化。
        //
        // 参数:
        //   sender:
        //     反序列化事件源。
        //
        // 异常:
        //   T:System.Runtime.Serialization.SerializationException:
        //     System.Runtime.Serialization.SerializationInfo 关联与当前对象 System.Collections.Generic.SortedSet`1
        //     对象无效。
        protected virtual void OnDeserialization(object sender);

        //
        // 摘要:
        //     枚举 System.Collections.Generic.SortedSet`1 对象的元素。
        public struct Enumerator : IEnumerator<T>, IDisposable, IEnumerator, ISerializable, IDeserializationCallback
        {
            //
            // 摘要:
            //     获取枚举数当前位置的元素。
            //
            // 返回结果:
            //     集合中位于枚举数当前位置的元素。
            public T Current { get; }

            //
            // 摘要:
            //     释放由 System.Collections.Generic.SortedSet`1.Enumerator 使用的所有资源。
            public void Dispose();
            //
            // 摘要:
            //     将枚举数推进到下一个元素 System.Collections.Generic.SortedSet`1 集合。
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