

* Qeuryable<T>

* Expression<T>

* IEnumerator		// 遍历器

* IEnumerable		// 只有一个函数, 返回实现这个接口的类的遍历器, 可以

* IComparable<T> 	// 实现这个接口的类的对象, 可以调用系统的排序比较等..函数对该对象进行操作

* Cs:IFormattable		// 提供一个 toString() 方法而已, 
// 实现这个接口的类可以直接用 Console.Write("{0}", obj) 输出, 或格式化 String.Format(..., obj);
// 在 Console.Write("{0:Format}", cs/*是Cs对象*/) 时,会把 format 作为参数传递给 cs.toString(format,.. )
// 然后可以根据自定义格式化字符串

* ICollection<T>






