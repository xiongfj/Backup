#region 程序集 System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\System.dll
#endregion

using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;

namespace System.Collections.Generic
{
    //
    // 摘要:
    //     表示双重链接列表。
    //
    // 类型参数:
    //   T:
    //     指定链接列表的元素类型。
    [ComVisible(false)]
    [DebuggerDisplay("Count = {Count}")]
    [DebuggerTypeProxy(typeof(Generic.System_CollectionDebugView<>))]
    public class LinkedList<T> : ICollection<T>, IEnumerable<T>, ICollection, IEnumerable, ISerializable, IDeserializationCallback
    {
        //
        // 摘要:
        //     初始化为空的 System.Collections.Generic.LinkedList`1 类的新实例。
        public LinkedList();
        //
        // 摘要:
        //     初始化 System.Collections.Generic.LinkedList`1 类的新实例，该实例包含从指定的 System.Collections.IEnumerable
        //     中复制的元素并且其容量足以容纳所复制的元素数。
        //
        // 参数:
        //   collection:
        //     System.Collections.IEnumerable，它的元素被复制到新 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     collection 为 null。
        public LinkedList(IEnumerable<T> collection);
        //
        // 摘要:
        //     新实例初始化 System.Collections.Generic.LinkedList`1 是可序列化与指定的类 System.Runtime.Serialization.SerializationInfo
        //     和 System.Runtime.Serialization.StreamingContext。
        //
        // 参数:
        //   info:
        //     一个 System.Runtime.Serialization.SerializationInfo 对象包含序列化 System.Collections.Generic.LinkedList`1
        //     所需的信息。
        //
        //   context:
        //     一个 System.Runtime.Serialization.StreamingContext 对象包含与System.Collections.Generic.LinkedList`1
        //     关联的序列化流的源和目标。
        protected LinkedList(SerializationInfo info, StreamingContext context);

        //
        // 摘要:
        //     获取的最后一个节点 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     最后一个 System.Collections.Generic.LinkedListNode`1 的 System.Collections.Generic.LinkedList`1。
        public LinkedListNode<T> Last { get; }
        //
        // 摘要:
        //     获取的第一个节点 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     第一个 System.Collections.Generic.LinkedListNode`1 的 System.Collections.Generic.LinkedList`1。
        public LinkedListNode<T> First { get; }
        //
        // 摘要:
        //     获取中实际包含的节点数 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     中实际包含的节点数 System.Collections.Generic.LinkedList`1。
        public int Count { get; }

        //
        // 摘要:
        //     添加包含指定的值中指定的现有节点后的新节点 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     System.Collections.Generic.LinkedListNode`1 在其之后插入新 System.Collections.Generic.LinkedListNode`1
        //     包含 value。
        //
        //   value:
        //     要添加到值 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     新 System.Collections.Generic.LinkedListNode`1 包含 value。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 不在当前 System.Collections.Generic.LinkedList`1。
        public LinkedListNode<T> AddAfter(LinkedListNode<T> node, T value);
        //
        // 摘要:
        //     在中指定的现有节点之后添加指定的新节点 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     System.Collections.Generic.LinkedListNode`1 在其之后插入 newNode。
        //
        //   newNode:
        //     新 System.Collections.Generic.LinkedListNode`1 将添加到 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。- 或 -newNode 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 不在当前 System.Collections.Generic.LinkedList`1。- 或 -newNode 属于另一个 System.Collections.Generic.LinkedList`1。
        public void AddAfter(LinkedListNode<T> node, LinkedListNode<T> newNode);
        //
        // 摘要:
        //     添加包含在指定的现有节点前的指定的值的新节点 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     System.Collections.Generic.LinkedListNode`1 在其前面进行插入一个新 System.Collections.Generic.LinkedListNode`1
        //     包含 value。
        //
        //   value:
        //     要添加到值 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     新 System.Collections.Generic.LinkedListNode`1 包含 value。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 不在当前 System.Collections.Generic.LinkedList`1。
        public LinkedListNode<T> AddBefore(LinkedListNode<T> node, T value);
        //
        // 摘要:
        //     添加指定的新节点中指定的现有节点前 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     System.Collections.Generic.LinkedListNode`1 在其前面进行插入 newNode。
        //
        //   newNode:
        //     新 System.Collections.Generic.LinkedListNode`1 将添加到 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。- 或 -newNode 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 不在当前 System.Collections.Generic.LinkedList`1。- 或 -newNode 属于另一个 System.Collections.Generic.LinkedList`1。
        public void AddBefore(LinkedListNode<T> node, LinkedListNode<T> newNode);
        //
        // 摘要:
        //     添加包含指定的值的开头的新节点 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   value:
        //     要添加的开头处的值 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     新 System.Collections.Generic.LinkedListNode`1 包含 value。
        public LinkedListNode<T> AddFirst(T value);
        //
        // 摘要:
        //     将指定的新节点添加的开头 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     新 System.Collections.Generic.LinkedListNode`1 的开头添加 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 属于另一个 System.Collections.Generic.LinkedList`1。
        public void AddFirst(LinkedListNode<T> node);
        //
        // 摘要:
        //     添加包含指定的值的末尾的新节点 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   value:
        //     值的结尾处添加 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     新 System.Collections.Generic.LinkedListNode`1 包含 value。
        public LinkedListNode<T> AddLast(T value);
        //
        // 摘要:
        //     将指定的新节点添加的末尾 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     新 System.Collections.Generic.LinkedListNode`1 的末尾添加 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 属于另一个 System.Collections.Generic.LinkedList`1。
        public void AddLast(LinkedListNode<T> node);
        //
        // 摘要:
        //     删除所有节点从 System.Collections.Generic.LinkedList`1。
        public void Clear();
        //
        // 摘要:
        //     确定一个值是否在 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   value:
        //     要在 System.Collections.Generic.LinkedList`1 中定位的值。 对于引用类型，该值可以为 null。
        //
        // 返回结果:
        //     如果在 true 中找到 value，则为 System.Collections.Generic.LinkedList`1；否则为 false。
        public bool Contains(T value);
        //
        // 摘要:
        //     从目标数组的指定索引处开始将整个 System.Collections.Generic.LinkedList`1 复制到兼容的一维 System.Array。
        //
        // 参数:
        //   array:
        //     一维 System.Array，它是从 System.Collections.Generic.LinkedList`1 复制的元素的目标。System.Array
        //     必须具有从零开始的索引。
        //
        //   index:
        //     array 中从零开始的索引，从此处开始复制。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     array 为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     index 小于零。
        //
        //   T:System.ArgumentException:
        //     源中的元素数目 System.Collections.Generic.LinkedList`1 大于从的可用空间 index 目标从头到尾 array。
        public void CopyTo(T[] array, int index);
        //
        // 摘要:
        //     查找包含指定的值的第一个节点。
        //
        // 参数:
        //   value:
        //     要在 System.Collections.Generic.LinkedList`1 中定位的值。
        //
        // 返回结果:
        //     第一个 System.Collections.Generic.LinkedListNode`1 ，包含指定的值时，如果找到; 否则为 null。
        public LinkedListNode<T> Find(T value);
        //
        // 摘要:
        //     查找包含指定的值的最后一个节点。
        //
        // 参数:
        //   value:
        //     要在 System.Collections.Generic.LinkedList`1 中定位的值。
        //
        // 返回结果:
        //     最后一个 System.Collections.Generic.LinkedListNode`1 ，包含指定的值时，如果找到; 否则为 null。
        public LinkedListNode<T> FindLast(T value);
        //
        // 摘要:
        //     返回循环访问 System.Collections.Generic.LinkedList`1 的枚举数。
        //
        // 返回结果:
        //     用于 System.Collections.Generic.LinkedList`1.Enumerator 的 System.Collections.Generic.LinkedList`1。
        public Enumerator GetEnumerator();
        //
        // 摘要:
        //     实现 System.Runtime.Serialization.ISerializable 接口，并返回序列化 System.Collections.Generic.LinkedList`1
        //     实例所需的数据。
        //
        // 参数:
        //   info:
        //     System.Runtime.Serialization.SerializationInfo 对象，该对象包含序列化 System.Collections.Generic.LinkedList`1
        //     实例所需的信息。
        //
        //   context:
        //     System.Runtime.Serialization.StreamingContext 对象，该对象包含与 System.Collections.Generic.LinkedList`1
        //     实例关联的序列化流的源和目标。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     info 为 null。
        public virtual void GetObjectData(SerializationInfo info, StreamingContext context);
        //
        // 摘要:
        //     实现 System.Runtime.Serialization.ISerializable 接口，并在完成反序列化之后引发反序列化事件。
        //
        // 参数:
        //   sender:
        //     反序列化事件源。
        //
        // 异常:
        //   T:System.Runtime.Serialization.SerializationException:
        //     System.Runtime.Serialization.SerializationInfo 关联与当前对象 System.Collections.Generic.LinkedList`1
        //     实例无效。
        public virtual void OnDeserialization(object sender);
        //
        // 摘要:
        //     移除从指定的值的第一个匹配项 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   value:
        //     要移除的值 System.Collections.Generic.LinkedList`1。
        //
        // 返回结果:
        //     true 如果元素包含 value 成功删除; 否则为 false。 如果在原始 false 中没有找到 value，则此方法也会返回 System.Collections.Generic.LinkedList`1。
        public bool Remove(T value);
        //
        // 摘要:
        //     移除指定的节点从 System.Collections.Generic.LinkedList`1。
        //
        // 参数:
        //   node:
        //     要从 System.Collections.Generic.LinkedListNode`1 移除的 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     node 为 null。
        //
        //   T:System.InvalidOperationException:
        //     node 不在当前 System.Collections.Generic.LinkedList`1。
        public void Remove(LinkedListNode<T> node);
        //
        // 摘要:
        //     删除的开始处的节点 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     System.Collections.Generic.LinkedList`1 为空。
        public void RemoveFirst();
        //
        // 摘要:
        //     删除节点的末尾 System.Collections.Generic.LinkedList`1。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     System.Collections.Generic.LinkedList`1 为空。
        public void RemoveLast();

        //
        // 摘要:
        //     枚举 System.Collections.Generic.LinkedList`1 的元素。
        public struct Enumerator : IEnumerator<T>, IDisposable, IEnumerator, ISerializable, IDeserializationCallback
        {
            //
            // 摘要:
            //     获取枚举数当前位置的元素。
            //
            // 返回结果:
            //     System.Collections.Generic.LinkedList`1 中位于该枚举数当前位置的元素。
            public T Current { get; }

            //
            // 摘要:
            //     释放由 System.Collections.Generic.LinkedList`1.Enumerator 使用的所有资源。
            public void Dispose();
            //
            // 摘要:
            //     使枚举数前进到 System.Collections.Generic.LinkedList`1 的下一个元素。
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