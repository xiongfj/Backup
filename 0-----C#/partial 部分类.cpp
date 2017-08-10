

* partial 关键词可以用在 class struct interface 前面.
* 允许把类\结构\方法\接口放在多个文件中.

* 所有部分类前面的修饰词必须相同!!

* 每个部分类继承的最终会合并在一起
* 每个部分类的标签\属性\方法都会合并在一起

a.cs:
public class Man
{
	public void fun()
	{
	...
	}
}

b.cs:
public class Man
{
	public void func2(){ .. };
}

------------- 可以调用两个部分类的函数

Man m;
m.func();
m.func2();











