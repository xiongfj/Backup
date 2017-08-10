
* 装箱\拆箱

var list = new ArrayList();
list.Add(33);		// 装箱

int i = (int)list[0];	// 拆箱

foreach( int i in list)
{
	Console.WriteLine(i);		// 拆箱; 如果循环次数较多的话, 效率低下
}

----- 使用泛型提高效率:

var list = new List<int>();		// 指定数据类型, 不需要装箱和拆箱,大大提高了效率
list.Add(33);		

int i = (int)list[0];	

foreach( int i in list)
{
	Console.WriteLine(i);	
}









