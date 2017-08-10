


public static T2 Accoumulate<T1, T2>(IEnumerable<T1> source, Func<T1,T2,T2> action)

/* Func<T1,.., Result>	// 最后一个总是表示返回类型!! 
Func<T1,T2,T2> action: 表示一个函数 
	T2 action(T1, T2)
	{
		T2 temp;
		....
		return temp;	// 必须返回 T2 类型数据
	}	
*/
















