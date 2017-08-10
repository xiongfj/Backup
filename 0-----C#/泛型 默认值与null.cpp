
* 给泛型赋值 null 的方法

public class People<T>
{
	public T GetValue()
	{
		// 不能直接 T temp = null;	因为泛型不能
		T temp = default(T);	// 此时 temp 有两种值, null 或 0
		lock(this)
		{
			temp = ...;
		}
		
		return temp;
	}
};


	