

public class Static Demo<T>
{
	public static int x;
}

---

// 各自拥有各自的静态数据
StaticDemo<String>.x = 1;
StaticDemo<int>.x = 120;

Console.WriteLine(StaticDemo<String>.x);		// 1








