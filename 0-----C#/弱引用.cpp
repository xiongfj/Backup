
* 弱引用数据在垃圾回收的时候会被系统回收, 有一定的风险,
* 所以在使用前需要判断是否已经被回收

public void func()
{
	WeakReference mathReference = new WeakReference(new xxClass() );
	xxClass obj;
	
	if (mathReference.IsAlive)
	{
		obj = mathReference.Target as xxClass;
		... 
	}
	else
	;// 对象已经被回收,无法使用.
	
	GC.Collect();				// 垃圾收回
	if (mathReference.IsAlive)	// 此时得到 false
	{
		// f
	}
}


















