
* 可以将查询结果转换成 C# 数据:	
// (from .. in .. select).toList() 
// ToDictionary(); ToArray(); ToLookup()


* 任何是 IEnumerable<T> 类型的对象都可以调用该类的函数进行筛选数据

public static class Enumerable
{
	public static TSource Aggregate<TSource>(this IEnumerable<TSource> source, Func<TSource, TSource, TSource> func);
	public static TAccumulate Aggregate<TSource, TAccumulate>(this IEnumerable<TSource> source, TAccumulate seed, Func<TAccumulate, TSource, TAccumulate> func);
	public static TResult Aggregate<TSource, TAccumulate, TResult>(this IEnumerable<TSource> source, TAccumulate seed, Func<TAccumulate, TSource, TAccumulate> func, Func<TAccumulate, TResult> resultSelector);
	/*
		 确定是否对序列中的所有元素都满足条件。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 ，其中包含要应用谓词的元素。
	
	   predicate:
		 用于测试每个元素是否满足条件的函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 true 如果源序列中的每个元素通过与指定谓词中的测试，或者如果序列为空，则为否则为 false。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static bool All<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	/*
		 确定序列是否包含任何元素。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 以检查是否为空。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 true 如果源序列中不包含任何元素，则否则为 false。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	*/
	public static bool Any<TSource>(this IEnumerable<TSource> source);
	/*
		 确定是否序列中的任何元素都满足条件。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 其应用谓词的元素。
	
	   predicate:
		 用于测试每个元素是否满足条件的函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 true 如果源序列中的任何元素中指定的谓词; 通过的测试否则为 false。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static bool Any<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	/*
		 返回输入类型化为 System.Collections.Generic.IEnumerable`1。
	
	 参数:
	   source:
		 序列以键入 System.Collections.Generic.IEnumerable`1。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 在输入的序列类型化为 System.Collections.Generic.IEnumerable`1。
	*/
	public static IEnumerable<TSource> AsEnumerable<TSource>(this IEnumerable<TSource> source);
	/*
		 可以为 null 的序列的平均值，计算 System.Decimal 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 要计算的平均值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 值序列的平均值或 null 如果源序列为空或仅包含值的 null。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Decimal.MaxValue。
	*/
	public static decimal? Average<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal?> selector);
	/*
		 计算序列的平均值 System.Decimal 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 用于计算平均值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Decimal.MaxValue。
	*/
	public static decimal Average<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal> selector);
	/*
		 计算序列的平均值 System.Int32 值。
	
	 参数:
	   source:
		 一系列 System.Int32 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static double Average(this IEnumerable<int> source);
	/*
		 可以为 null 的序列的平均值，计算 System.Int32 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Int32 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值或 null 如果源序列为空或仅包含值的 null。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Int64.MaxValue。
	*/
	public static double? Average(this IEnumerable<int?> source);
	/*
		 计算序列的平均值 System.Int64 值。
	
	 参数:
	   source:
		 一系列 System.Int64 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static double Average(this IEnumerable<long> source);
	/*
		 可以为 null 的序列的平均值，计算 System.Int64 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Int64 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值或 null 如果源序列为空或仅包含值的 null。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Int64.MaxValue。
	*/
	public static double? Average(this IEnumerable<long?> source);
	/*
		 计算序列的平均值 System.Single 值。
	
	 参数:
	   source:
		 一系列 System.Single 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static float Average(this IEnumerable<float> source);
	/*
		 计算序列的平均值 System.Double 值。
	
	 参数:
	   source:
		 一系列 System.Double 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static double Average(this IEnumerable<double> source);
	/*
		 可以为 null 的序列的平均值，计算 System.Double 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Double 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值或 null 如果源序列为空或仅包含值的 null。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	*/
	public static double? Average(this IEnumerable<double?> source);
	/*
		 计算序列的平均值 System.Decimal 值。
	
	 参数:
	   source:
		 一系列 System.Decimal 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static decimal Average(this IEnumerable<decimal> source);
	/*
		 可以为 null 的序列的平均值，计算 System.Decimal 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Decimal 要计算平均值的值。
	
	 返回结果:
		 值序列的平均值或 null 如果源序列为空或仅包含值的 null。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Decimal.MaxValue。
	*/
	public static decimal? Average(this IEnumerable<decimal?> source);
	/*
		 计算序列的平均值 System.Int32 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 要计算的平均值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 值序列的平均值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Int64.MaxValue。
	*/
	public static double Average<TSource>(this IEnumerable<TSource> source, Func<TSource, int> selector);
	/*
		 可以为 null 的序列的平均值，计算 System.Int32 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 要计算的平均值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 值序列的平均值或 null 如果源序列为空或仅包含值的 null。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 在序列中元素的总和大于 System.Int64.MaxValue。
	*/
	public static double? Average<TSource>(this IEnumerable<TSource> source, Func<TSource, int?> selector);
	public static double Average<TSource>(this IEnumerable<TSource> source, Func<TSource, long> selector);
	public static double? Average<TSource>(this IEnumerable<TSource> source, Func<TSource, long?> selector);
	public static float Average<TSource>(this IEnumerable<TSource> source, Func<TSource, float> selector);
	public static float? Average<TSource>(this IEnumerable<TSource> source, Func<TSource, float?> selector);
	public static double Average<TSource>(this IEnumerable<TSource> source, Func<TSource, double> selector);
	public static double? Average<TSource>(this IEnumerable<TSource> source, Func<TSource, double?> selector);
	public static float? Average(this IEnumerable<float?> source);
	
	/* 将非类型化集合转换成类型化集合
	* 比如: ArrayList list = ["wer","we","234","fds","ads"];
		此时不能使用 foreach( var i in list )		// 因为 list 内的不是对象类型
	* IEnumerable<TResult> objs = list.Cast<TResult>();
		foreach(var item in objs)
		{
			...// 此时可以
		}
	*/
	public static IEnumerable<TResult> Cast<TResult>(this IEnumerable source);
	public static IEnumerable<TSource> Concat<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second);
	public static bool Contains<TSource>(this IEnumerable<TSource> source, TSource value);
	public static bool Contains<TSource>(this IEnumerable<TSource> source, TSource value, IEqualityComparer<TSource> comparer);
	public static int Count<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	public static int Count<TSource>(this IEnumerable<TSource> source);
	public static IEnumerable<TSource> DefaultIfEmpty<TSource>(this IEnumerable<TSource> source);
	public static IEnumerable<TSource> DefaultIfEmpty<TSource>(this IEnumerable<TSource> source, TSource defaultValue);
	
	// 返回两个集合不相同的部分
	public static IEnumerable<TSource> Distinct<TSource>(this IEnumerable<TSource> source, IEqualityComparer<TSource> comparer);
	public static IEnumerable<TSource> Distinct<TSource>(this IEnumerable<TSource> source);
	
	public static TSource ElementAt<TSource>(this IEnumerable<TSource> source, int index);
	public static TSource ElementAtOrDefault<TSource>(this IEnumerable<TSource> source, int index);
	public static IEnumerable<TResult> Empty<TResult>();
	
	// 获取两个集合的差集
	public static IEnumerable<TSource> Except<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second);
	public static IEnumerable<TSource> Except<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second, IEqualityComparer<TSource> comparer);
	
	public static TSource First<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	public static TSource First<TSource>(this IEnumerable<TSource> source);
	
	public static TSource FirstOrDefault<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	public static TSource FirstOrDefault<TSource>(this IEnumerable<TSource> source);
	
	public static IEnumerable<IGrouping<TKey, TSource>> GroupBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector);
	
	public static IEnumerable<IGrouping<TKey, TSource>> GroupBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, IEqualityComparer<TKey> comparer);
	
	public static IEnumerable<TResult> GroupBy<TSource, TKey, TResult>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TKey, IEnumerable<TSource>, TResult> resultSelector);
	
	public static IEnumerable<TResult> GroupBy<TSource, TKey, TElement, TResult>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector, Func<TKey, IEnumerable<TElement>, TResult> resultSelector);
	
	public static IEnumerable<TResult> GroupBy<TSource, TKey, TResult>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TKey, IEnumerable<TSource>, TResult> resultSelector, IEqualityComparer<TKey> comparer);
	
	public static IEnumerable<TResult> GroupBy<TSource, TKey, TElement, TResult>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector, Func<TKey, IEnumerable<TElement>, TResult> resultSelector, IEqualityComparer<TKey> comparer);
	
	public static IEnumerable<IGrouping<TKey, TElement>> GroupBy<TSource, TKey, TElement>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector, IEqualityComparer<TKey> comparer);
	
	public static IEnumerable<IGrouping<TKey, TElement>> GroupBy<TSource, TKey, TElement>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector);
	
	public static IEnumerable<TResult> GroupJoin<TOuter, TInner, TKey, TResult>(this IEnumerable<TOuter> outer, IEnumerable<TInner> inner, Func<TOuter, TKey> outerKeySelector, Func<TInner, TKey> innerKeySelector, Func<TOuter, IEnumerable<TInner>, TResult> resultSelector);
	
	public static IEnumerable<TResult> GroupJoin<TOuter, TInner, TKey, TResult>(this IEnumerable<TOuter> outer, IEnumerable<TInner> inner, Func<TOuter, TKey> outerKeySelector, Func<TInner, TKey> innerKeySelector, Func<TOuter, IEnumerable<TInner>, TResult> resultSelector, IEqualityComparer<TKey> comparer);
	
	// 获取两个集合的交集
	public static IEnumerable<TSource> Intersect<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second);
	public static IEnumerable<TSource> Intersect<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second, IEqualityComparer<TSource> comparer);
	
	public static IEnumerable<TResult> Join<TOuter, TInner, TKey, TResult>(this IEnumerable<TOuter> outer,
		IEnumerable<TInner> inner, 
		Func<TOuter, TKey> outerKeySelector, 
		Func<TInner, TKey> innerKeySelector, 
		Func<TOuter, TInner, TResult> resultSelector);
		
	public static IEnumerable<TResult> Join<TOuter, TInner, TKey, TResult>(this IEnumerable<TOuter> outer, 
	IEnumerable<TInner> inner, 
	Func<TOuter, TKey> outerKeySelector, 
	Func<TInner, TKey> innerKeySelector, 
	Func<TOuter, TInner, TResult> resultSelector, 
	IEqualityComparer<TKey> comparer);
	
	public static TSource Last<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	public static TSource Last<TSource>(this IEnumerable<TSource> source);
	
	public static TSource LastOrDefault<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	public static TSource LastOrDefault<TSource>(this IEnumerable<TSource> source);
	
	public static long LongCount<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	public static long LongCount<TSource>(this IEnumerable<TSource> source);
	
	public static double Max(this IEnumerable<double> source);
	
	public static decimal Max(this IEnumerable<decimal> source);
	
	public static decimal? Max(this IEnumerable<decimal?> source);
	
	public static decimal Max<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal> selector);
	
	public static double? Max<TSource>(this IEnumerable<TSource> source, Func<TSource, double?> selector);
	
	public static TSource Max<TSource>(this IEnumerable<TSource> source);
	
	public static int Max(this IEnumerable<int> source);
	
	public static double Max<TSource>(this IEnumerable<TSource> source, Func<TSource, double> selector);
	
	public static float? Max<TSource>(this IEnumerable<TSource> source, Func<TSource, float?> selector);
	
	public static int? Max(this IEnumerable<int?> source);
	
	public static long Max(this IEnumerable<long> source);
	
	public static float Max<TSource>(this IEnumerable<TSource> source, Func<TSource, float> selector);
	
	public static long? Max<TSource>(this IEnumerable<TSource> source, Func<TSource, long?> selector);
	
	public static long Max<TSource>(this IEnumerable<TSource> source, Func<TSource, long> selector);
	
	public static int? Max<TSource>(this IEnumerable<TSource> source, Func<TSource, int?> selector);
	
	public static int Max<TSource>(this IEnumerable<TSource> source, Func<TSource, int> selector);
	public static float? Max(this IEnumerable<float?> source);
	
	public static double? Max(this IEnumerable<double?> source);
	
	public static long? Max(this IEnumerable<long?> source);
	
	public static float Max(this IEnumerable<float> source);
	
	public static TResult Max<TSource, TResult>(this IEnumerable<TSource> source, Func<TSource, TResult> selector);
	
	public static decimal? Max<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal?> selector);
	
	public static int? Min(this IEnumerable<int?> source);
	
	public static long Min(this IEnumerable<long> source);
	
	public static long? Min(this IEnumerable<long?> source);
	
	public static float Min(this IEnumerable<float> source);
	
	public static float? Min(this IEnumerable<float?> source);
	
	public static double Min(this IEnumerable<double> source);
	
	public static double? Min(this IEnumerable<double?> source);
	
	public static decimal Min(this IEnumerable<decimal> source);
	
	public static decimal? Min(this IEnumerable<decimal?> source);
	
	public static TSource Min<TSource>(this IEnumerable<TSource> source);
	
	public static int Min<TSource>(this IEnumerable<TSource> source, Func<TSource, int> selector);
	
	public static int? Min<TSource>(this IEnumerable<TSource> source, Func<TSource, int?> selector);
	
	public static long Min<TSource>(this IEnumerable<TSource> source, Func<TSource, long> selector);
	
	/*
		 调用转换函数对序列的每个元素，并返回最小值可以为 null System.Int64 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 类型的值 Nullable<Int64> 在 C# 或 Nullable(Of Int64) 中 Visual Basic 对应于序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static long? Min<TSource>(this IEnumerable<TSource> source, Func<TSource, long?> selector);
	
	/*
		 调用转换函数对序列的每个元素，并返回所需的最低 System.Single 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static float Min<TSource>(this IEnumerable<TSource> source, Func<TSource, float> selector);
	
	/*
		 调用转换函数对序列的每个元素，并返回最小值可以为 null System.Single 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 类型的值 Nullable<Single> 在 C# 或 Nullable(Of Single) 中 Visual Basic 对应于序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static float? Min<TSource>(this IEnumerable<TSource> source, Func<TSource, float?> selector);
	
	/*
		 调用转换函数对序列的每个元素，并返回所需的最低 System.Double 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static double Min<TSource>(this IEnumerable<TSource> source, Func<TSource, double> selector);
	
	/*
		 调用转换函数对序列的每个元素，并返回最小值可以为 null System.Double 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 类型的值 Nullable<Double> 在 C# 或 Nullable(Of Double) 中 Visual Basic 对应于序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static double? Min<TSource>(this IEnumerable<TSource> source, Func<TSource, double?> selector);
	
	/*
		 调用转换函数对序列的每个元素，并返回所需的最低 System.Decimal 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static decimal Min<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal> selector);
	
	/*
		 返回序列中的最小值 System.Int32 值。
	
	 参数:
	   source:
		 一系列 System.Int32 值来确定的最小值。
	
	 返回结果:
		 序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 source 不包含任何元素。
	*/
	public static int Min(this IEnumerable<int> source);
	
	/*
		 调用转换函数对序列的每个元素，并返回最小值可以为 null System.Decimal 值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 类型的值 Nullable<Decimal> 在 C# 或 Nullable(Of Decimal) 中 Visual Basic 对应于序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static decimal? Min<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal?> selector);
	
	/*
		 调用泛型序列的每个元素的转换函数，并返回最小的结果值。
	
	 参数:
	   source:
		 要确定其最小值的值序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	   TResult:
		 返回的值的类型 selector。
	
	 返回结果:
		 序列中的最小值。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static TResult Min<TSource, TResult>(this IEnumerable<TSource> source, Func<TSource, TResult> selector);
	
	/* 假如数据集合 lists 是 IPeople 类型的,
	* 而集合内部包含的是 Man, Women 两个继承 IPeople 的数据
	* 此时就可以使用: IEnumerable<Women> result = lists.OfType<Women>(); 筛选只是 Women 的数据
	*/
	public static IEnumerable<TResult> OfType<TResult>(this IEnumerable source);
	
	/*
	* 按照返回值 TKey 排序(升序)
	*/
	public static IOrderedEnumerable<TSource> OrderBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, IComparer<TKey> comparer);
	public static IOrderedEnumerable<TSource> OrderBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector);
	
	/*
	* 按照 Func 的返回值 TKey 降序排序
	*/
	public static IOrderedEnumerable<TSource> OrderByDescending<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, IComparer<TKey> comparer);
	public static IOrderedEnumerable<TSource> OrderByDescending<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector);
	
	/*
		 生成指定范围内的整数序列。
		 [start, start+1, start+2, .. start + count -1 ]
	*/
	public static IEnumerable<int> Range(int start, int count);
	
	/*
		 将生成一个序列，其中包含一个重复的值。
	
	 参数:
	   element:
		 要重复的值。
	
	   count:
		 在生成序列中重复该值的次数。
	
	 类型参数:
	   TResult:
		 要在结果序列中重复的值的类型。
	
	 返回结果:
		 System.Collections.Generic.IEnumerable`1 包含重复的值。
	
	 异常:
	   T:System.ArgumentOutOfRangeException:
		 count 小于 0。
	*/
	public static IEnumerable<TResult> Repeat<TResult>(TResult element, int count);
	
	// 反转序列中元素的顺序。
	public static IEnumerable<TSource> Reverse<TSource>(this IEnumerable<TSource> source);
	
	/*
		例如 Select(r => r) 等效与 select r
		或 Select( r => r.name) 与 select r.name 等效
	* 是从 TSource 到 TResult 的过滤而已
	*/
	public static IEnumerable<TResult> Select<TSource, TResult>(this IEnumerable<TSource> source, Func<TSource, TResult> selector);
	public static IEnumerable<TResult> Select<TSource, TResult>(this IEnumerable<TSource> source, Func<TSource, int, TResult> selector);
	
	/*
	* 等效与 Linq 的 select new { Upper = w.ToUpper(), Lower = w.ToLower() }; 
	* 返回一组自己组装的对象集合
	* 用户可以把参数 TSource 内的数据拆分, 封装成自己的 selector;
	* 例如: TSource => new List<dynamic>(){ new {a=TSource.age, b=TSource.name}, new {a=TSource.age + 1, b=TSource.name}}
	* 
	*/
	public static IEnumerable<TResult> SelectMany<TSource, TResult>(this IEnumerable<TSource> source, 
					Func<TSource, IEnumerable<TResult>> selector);
	
	// collectionSelector 是TSource 内的某个子集合 TSource=>TSource.lists
	// resultSelector 的 Collection 是collectionSelector子集合内一一个 item
	// 用于查询集合内还有集合的数据
	public static IEnumerable<TResult> SelectMany<TSource, TCollection, TResult>(this IEnumerable<TSource> source, 
		Func<TSource, IEnumerable<TCollection>> collectionSelector, 
		Func<TSource, TCollection, TResult> resultSelector);
		
	public static IEnumerable<TResult> SelectMany<TSource, TCollection, TResult>(this IEnumerable<TSource> source, 
		Func<TSource, int, IEnumerable<TCollection>> collectionSelector, 
		Func<TSource, TCollection, TResult> resultSelector);
		
	public static IEnumerable<TResult> SelectMany<TSource, TResult>(this IEnumerable<TSource> source, 
		Func<TSource, int, IEnumerable<TResult>> selector);
	
	/*
		 确定两个序列是否通过使用指定的比较它们的元素相等 System.Collections.Generic.IEqualityComparer`1。
	
	 参数:
	   first:
		 System.Collections.Generic.IEnumerable`1 要与 second。
	
	   second:
		 System.Collections.Generic.IEnumerable`1 要与第一个序列进行比较。
	
	   comparer:
		 System.Collections.Generic.IEqualityComparer`1 要用来比较元素。
	
	 类型参数:
	   TSource:
		 输入序列中的元素的类型。
	
	 返回结果:
		 true 如果两个源序列的长度相等，并且其相应元素的比较结果相等根据 comparer; 否则为 false。
	
	 异常:
	   T:System.ArgumentNullException:
		 first 或 second 为 null。
	*/
	public static bool SequenceEqual<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second, IEqualityComparer<TSource> comparer);
	
	/*
		 确定两个序列是否相等的元素进行比较通过使用相应类型的默认相等比较器。
	
	 参数:
	   first:
		 System.Collections.Generic.IEnumerable`1 要与 second。
	
	   second:
		 System.Collections.Generic.IEnumerable`1 要与第一个序列进行比较。
	
	 类型参数:
	   TSource:
		 输入序列中的元素的类型。
	
	 返回结果:
		 true 如果两个源序列的长度相等，且其相应元素相等根据它们的类型; 的默认相等比较器否则为 false。
	
	 异常:
	   T:System.ArgumentNullException:
		 first 或 second 为 null。
	*/
	public static bool SequenceEqual<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second);
	
	/*
		 返回序列中满足指定条件的唯一元素；如果有多个这样的元素存在，则会引发异常。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 以返回从的单个元素。
	
	   predicate:
		 用于测试元素是否满足条件的函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 输入序列中满足条件的单个元素。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	
	   T:System.InvalidOperationException:
		 没有元素满足该条件在 predicate。- 或 -多个元素满足该条件在 predicate。- 或 -源序列为空。
	*/
	public static TSource Single<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	/*
		 返回序列的唯一元素；如果该序列并非恰好包含一个元素，则会引发异常。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 要返回的单个元素。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 输入序列的单个元素。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 输入的序列包含多个元素。- 或 -输入的序列为空。
	*/
	public static TSource Single<TSource>(this IEnumerable<TSource> source);
	
	/*
		 返回一个序列，或默认值的唯一元素，如果序列为空，则为如果序列中存在多个元素，则此方法将引发异常。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 要返回的单个元素。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 在输入序列的单个元素或 default(TSource) 如果序列不包含任何元素。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.InvalidOperationException:
		 输入的序列包含多个元素。
	*/
	public static TSource SingleOrDefault<TSource>(this IEnumerable<TSource> source);
	
	/*
		 返回序列中满足指定条件的唯一元素；如果这类元素不存在，则返回默认值；如果有多个元素满足该条件，此方法将引发异常。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 以返回从的单个元素。
	
	   predicate:
		 用于测试元素是否满足条件的函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 输入序列中满足该条件的单个元素或 default(TSource) 如果找到这样的元素。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static TSource SingleOrDefault<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	/*
	* 用于翻页: 跳过 page * PageSize 条数据, 然后就可以实现翻页了
	* (from .. in .. select).Skip(page * pageSize).Take(pageSize);
	*/
	public static IEnumerable<TSource> Skip<TSource>(this IEnumerable<TSource> source, int count);
	
	/*
		 只要指定的条件为 true，然后返回剩余元素，跳过序列中的元素。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 返回中的元素。
	
	   predicate:
		 用于测试每个元素是否满足条件的函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 System.Collections.Generic.IEnumerable`1 ，其中包含从输入序列不将传递通过指定的测试的线性系列中的第一个元素开始的元素
		 predicate。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static IEnumerable<TSource> SkipWhile<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	/*
		 只要指定的条件为 true，然后返回剩余元素，跳过序列中的元素。 将在谓词函数的逻辑中使用元素的索引。
	
	 参数:
	   source:
		 System.Collections.Generic.IEnumerable`1 返回中的元素。
	
	   predicate:
		 用于测试每个源元素是否满足条件的函数；该函数的第二个参数表示源元素的索引。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 System.Collections.Generic.IEnumerable`1 ，其中包含从输入序列不将传递通过指定的测试的线性系列中的第一个元素开始的元素
		 predicate。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static IEnumerable<TSource> SkipWhile<TSource>(this IEnumerable<TSource> source, Func<TSource, int, bool> predicate);
	
	/*
		 计算可以为 null 的序列的和 System.Int32 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int32.MaxValue。
	*/
	public static int? Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, int?> selector);
	
	/*
		 计算的序列的和 System.Decimal 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Decimal.MaxValue。
	*/
	public static decimal Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal> selector);
	
	/*
		 计算可以为 null 的序列的和 System.Decimal 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Decimal.MaxValue。
	*/
	public static decimal? Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, decimal?> selector);
	
	/*
		 计算的一系列总和 System.Int32 值。
	
	 参数:
	   source:
		 一系列 System.Int32 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int32.MaxValue。
	*/
	public static int Sum(this IEnumerable<int> source);
	
	/*
		 计算可以为 null 的序列的和 System.Int32 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Int32 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int32.MaxValue。
	*/
	public static int? Sum(this IEnumerable<int?> source);
	
	/*
		 计算的一系列总和 System.Int64 值。
	
	 参数:
	   source:
		 一系列 System.Int64 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int64.MaxValue。
	*/
	public static long Sum(this IEnumerable<long> source);
	
	/*
		 计算可以为 null 的序列的和 System.Int64 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Int64 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int64.MaxValue。
	*/
	public static long? Sum(this IEnumerable<long?> source);
	
	/*
		 计算的一系列总和 System.Single 值。
	
	 参数:
	   source:
		 一系列 System.Single 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	*/
	public static float Sum(this IEnumerable<float> source);
	
	/*
		 计算可以为 null 的序列的和 System.Single 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Single 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	*/
	public static float? Sum(this IEnumerable<float?> source);
	
	/*
		 计算可以为 null 的序列的和 System.Double 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Double 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	*/
	public static double? Sum(this IEnumerable<double?> source);
	
	/*
		 计算的一系列总和 System.Double 值。
	
	 参数:
	   source:
		 一系列 System.Double 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	*/
	public static double Sum(this IEnumerable<double> source);
	
	/*
		 计算可以为 null 的序列的和 System.Decimal 值。
	
	 参数:
	   source:
		 可以为 null 的序列 System.Decimal 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Decimal.MaxValue。
	*/
	public static decimal? Sum(this IEnumerable<decimal?> source);
	
	/*
		 计算的序列的和 System.Int32 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int32.MaxValue。
	*/
	public static int Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, int> selector);
	
	/*
		 计算的序列的和 System.Int64 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int64.MaxValue。
	*/
	public static long Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, long> selector);
	
	/*
		 计算可以为 null 的序列的和 System.Int64 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Int64.MaxValue。
	*/
	public static long? Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, long?> selector);
	
	/*
		 计算的序列的和 System.Single 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static float Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, float> selector);
	
	/*
		 计算可以为 null 的序列的和 System.Single 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static float? Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, float?> selector);
	
	/*
		 计算的序列的和 System.Double 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static double Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, double> selector);
	
	/*
		 计算可以为 null 的序列的和 System.Double 通过调用对输入序列中的每个元素的转换函数获得的值。
	
	 参数:
	   source:
		 使用要计算的总和的值的序列。
	
	   selector:
		 应用于每个元素的转换函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 投影值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 selector 为 null。
	*/
	public static double? Sum<TSource>(this IEnumerable<TSource> source, Func<TSource, double?> selector);
	
	/*
		 计算的一系列总和 System.Decimal 值。
	
	 参数:
	   source:
		 一系列 System.Decimal 要对其求和的值。
	
	 返回结果:
		 在序列中值的总和。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 为 null。
	
	   T:System.OverflowException:
		 之和大于 System.Decimal.MaxValue。
	*/
	public static decimal Sum(this IEnumerable<decimal> source);
	
	/* 只显示前 count 条数据
	*/
	public static IEnumerable<TSource> Take<TSource>(this IEnumerable<TSource> source, int count);
	
	/*
		 返回序列中的元素，只要指定的条件为真。
	
	 参数:
	   source:
		 要返回元素的序列。
	
	   predicate:
		 用于测试每个元素是否满足条件的函数。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 System.Collections.Generic.IEnumerable`1 ，其中包含输入序列中出现测试不再能够通过在元素之前的元素。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static IEnumerable<TSource> TakeWhile<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	/*
		 返回序列中的元素，只要指定的条件为真。 将在谓词函数的逻辑中使用元素的索引。
	
	 参数:
	   source:
		 要从其返回元素的序列。
	
	   predicate:
		 用于测试每个源元素是否满足条件的函数；该函数的第二个参数表示源元素的索引。
	
	 类型参数:
	   TSource:
		 中的元素的类型 source。
	
	 返回结果:
		 System.Collections.Generic.IEnumerable`1 ，其中包含输入序列中出现测试不再能够通过在元素之前的元素。
	
	 异常:
	   T:System.ArgumentNullException:
		 source 或 predicate 为 null。
	*/
	public static IEnumerable<TSource> TakeWhile<TSource>(this IEnumerable<TSource> source, Func<TSource, int, bool> predicate);
	
	/*
	* 进行二次升序排序, 一般是 OrderBy().ThenBy()...ThenBy().. 可以无数次排序
	*/
	public static IOrderedEnumerable<TSource> ThenBy<TSource, TKey>(this IOrderedEnumerable<TSource> source, Func<TSource, TKey> keySelector);
	public static IOrderedEnumerable<TSource> ThenBy<TSource, TKey>(this IOrderedEnumerable<TSource> source, Func<TSource, TKey> keySelector, IComparer<TKey> comparer);
	
	/*
	* 进行二次降序排序
	*/
	public static IOrderedEnumerable<TSource> ThenByDescending<TSource, TKey>(this IOrderedEnumerable<TSource> source, Func<TSource, TKey> keySelector);
	public static IOrderedEnumerable<TSource> ThenByDescending<TSource, TKey>(this IOrderedEnumerable<TSource> source, Func<TSource, TKey> keySelector, IComparer<TKey> comparer);
	
	public static TSource[] ToArray<TSource>(this IEnumerable<TSource> source);
	public static Dictionary<TKey, TElement> ToDictionary<TSource, TKey, TElement>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector, IEqualityComparer<TKey> comparer);
	public static Dictionary<TKey, TElement> ToDictionary<TSource, TKey, TElement>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector);
	public static Dictionary<TKey, TSource> ToDictionary<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, IEqualityComparer<TKey> comparer);
	public static Dictionary<TKey, TSource> ToDictionary<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector);
	public static List<TSource> ToList<TSource>(this IEnumerable<TSource> source);
	
	/*
	* 从查询结果 TSource 中选择某个类型数据作为键 TKey, 组成 <TKey, TSource> 的数据形式返回
	*/
	public static ILookup<TKey, TSource> ToLookup<TSource, TKey>(this IEnumerable<TSource> source,
		Func<TSource, TKey> keySelector);
		
	// 去结果集中的某个元素作为 key, 再取某个元素作为 Value; 组成<TKey, TElement> 键值对返回
	public static ILookup<TKey, TElement> ToLookup<TSource, TKey, TElement>(this IEnumerable<TSource> source,
		Func<TSource, TKey> keySelector,
		Func<TSource, TElement> elementSelector);
	
	public static ILookup<TKey, TElement> ToLookup<TSource, TKey, TElement>(this IEnumerable<TSource> source,
		Func<TSource, TKey> keySelector, 
		Func<TSource, TElement> elementSelector, 
		IEqualityComparer<TKey> comparer);
	
	public static ILookup<TKey, TSource> ToLookup<TSource, TKey>(this IEnumerable<TSource> source, 
		Func<TSource, TKey> keySelector,
		IEqualityComparer<TKey> comparer);
	
	// 使用指定的生成两个序列的并集
	public static IEnumerable<TSource> Union<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second, IEqualityComparer<TSource> comparer);
	public static IEnumerable<TSource> Union<TSource>(this IEnumerable<TSource> first, IEnumerable<TSource> second);
	
	/*
		筛选符合 where 的数据
		Func 返回 bool 值
		Func<TSource, int index, bool> 中 int 参数是<原数据集>中每个元素的下标索引.可以筛选偶数的结果: return xxx && idnex % 2 == 0
	*/
	public static IEnumerable<TSource> Where<TSource>(this IEnumerable<TSource> source, Func<TSource, int, bool> predicate);
	public static IEnumerable<TSource> Where<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate);
	
	// 两个集合进行列合并, 新集合的列数 = TFirst + TSecond 的列数之和
	public static IEnumerable<TResult> Zip<TFirst, TSecond, TResult>(this IEnumerable<TFirst> first, 
		IEnumerable<TSecond> second, 
		Func<TFirst, TSecond, TResult> resultSelector);
}
}











