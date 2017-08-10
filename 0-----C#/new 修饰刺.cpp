


public class Animal
{
	public void speak();
};


public class Dog : Animal
{
	public new void speak();		// new 说明该函数是覆盖基类的函数
	
	// public void speak();		// 如果这样写会发出警告, 也是覆盖基类函数
};


