#region 程序集 System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\System.dll
#endregion

using System.Diagnostics;
using System.Runtime.InteropServices;

namespace System.Collections.Generic
{
    //
    // 摘要:
    //     表示可变大小的后进先出 (LIFO) 集合（对于相同指定类型的实例）。
    //
    // 类型参数:
    //   T:
    //     指定堆栈中元素的类型。
    [ComVisible(false)]
    [DebuggerDisplay("Count = {Count}")]
    [DebuggerTypeProxy(typeof(Generic.System_StackDebugView<>))]
    public class Stack<T> : IEnumerable<T>, ICollection, IEnumerable
    {
        //
        // 摘要:
        //     初始化 System.Collections.Generic.Stack`1 类的新实例，该实例为空并且具有默认初始容量。
        public Stack();
        //
        // 摘要:
        //     新实例初始化 System.Collections.Generic.Stack`1 ，该类为空并具有指定的初始容量或默认的初始容量，则两者中较大。
        //
        // 参数:
        //   capacity:
        //     System.Collections.Generic.Stack`1 可包含的初始元素数。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     capacity 小于零。
        public Stack(int capacity);
        //
        // 摘要:
        //     初始化 System.Collections.Generic.Stack`1 类的新实例，该实例包含从指定集合复制的元素并且具有足够的容量来容纳所复制的元素。
        //
        // 参数:
        //   collection:
        //     从中复制元素的集合。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     collection 为 null。
        public Stack(IEnumerable<T> collection);

        //
        // 摘要:
        //     获取 System.Collections.Generic.Stack`1 中包含的元素数。
        //
        // 返回结果:
        //     System.Collections.Generic.Stack`1 中包含的元素数。
        public int Count { get; }

        //
        // 摘要:
        //     从 System.Collections.Generic.Stack`1 中移除所有对象。
        public void Clear();
        //
        // 摘要:
        //     确定某元素是否在 System.Collections.Generic.Stack`1 中。
        //
        // 参数:
        //   item:
        //     要在 System.Collections.Generic.Stack`1 中定位的对象。 对于引用类型，该值可以为 null。
        //
        // 返回结果:
        //     如果在 true 中找到 item，则为 System.Collections.Generic.Stack`1；否则为 false。
        public bool Contains(T item);
        //
        // 摘要:
        //     副本 System.Collections.Generic.Stack`1 到现有一维 System.Array, 指定的数组索引处开始。
        //
        // 参数:
        //   array:
        //     一维 System.Array，它是从 System.Collections.Generic.Stack`1 复制的元素的目标。System.Array
        //     必须具有从零开始的索引。
        //
        //   arrayIndex:
        //     array 中从零开始的索引，从此处开始复制。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     array 为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     arrayIndex 小于零。
        //
        //   T:System.ArgumentException:
        //     源中的元素数目 System.Collections.Generic.Stack`1 大于从的可用空间 arrayIndex 目标从头到尾 array。
        public void CopyTo(T[] array, int arrayIndex);
        //
        // 摘要:
        //     返回的枚举数 System.Collections.Generic.Stack`1。
        //
        // 返回结果:
        //     用于 System.Collections.Generic.Stack`1.Enumerator 的 System.Collections.Generic.Stack`1。
        public Enumerator GetEnumerator();
        //
        // 摘要:
        //     返回的对象顶部的 System.Collections.Generic.Stack`1 而不删除它。
        //
        // 返回结果:
        //     在顶部的对象 System.Collections.Generic.Stack`1。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     System.Collections.Generic.Stack`1 为空。
        public T Peek();
        //
        // 摘要:
        //     移除并返回位于顶部的对象 System.Collections.Generic.Stack`1。
        //
        // 返回结果:
        //     从顶部删除的对象 System.Collections.Generic.Stack`1。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     System.Collections.Generic.Stack`1 为空。
        public T Pop();
        //
        // 摘要:
        //     在 System.Collections.Generic.Stack`1 的顶部插入一个对象。
        //
        // 参数:
        //   item:
        //     要推入到 System.Collections.Generic.Stack`1 中的对象。 对于引用类型，该值可以为 null。
        public void Push(T item);
        //
        // 摘要:
        //     副本 System.Collections.Generic.Stack`1 到新数组。
        //
        // 返回结果:
        //     新数组包含元素的副本 System.Collections.Generic.Stack`1。
        public T[] ToArray();
        //
        // 摘要:
        //     如果元素数小于当前容量的 90%，将容量设置为 System.Collections.Generic.Stack`1 中的实际元素数。
        public void TrimExcess();

        //
        // 摘要:
        //     枚举 System.Collections.Generic.Stack`1 的元素。
        public struct Enumerator : IEnumerator<T>, IDisposable, IEnumerator
        {
            //
            // 摘要:
            //     获取枚举数当前位置的元素。
            //
            // 返回结果:
            //     System.Collections.Generic.Stack`1 中位于该枚举数当前位置的元素。
            //
            // 异常:
            //   T:System.InvalidOperationException:
            //     枚举数定位在集合或最后一个元素之后的第一个元素之前。
            public T Current { get; }

            //
            // 摘要:
            //     释放由 System.Collections.Generic.Stack`1.Enumerator 使用的所有资源。
            public void Dispose();
            //
            // 摘要:
            //     使枚举数前进到 System.Collections.Generic.Stack`1 的下一个元素。
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