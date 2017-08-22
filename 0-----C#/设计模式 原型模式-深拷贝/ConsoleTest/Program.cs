using System;

class ShallowCopy : ICloneable
{
    public int[] v = { 1,2,3};

    public ShallowCopy() { }

    public ShallowCopy(int[] v)
    {
        this.v = (int[])v.Clone();      // 调用的是 int[] 的 Clone 函数
    }

    // 实现接口函数, 要不要继承接口貌似都一样, 多此一举.可以自定义这个函数,不一定非要接口来指定?!?
    public object Clone()
    {
        return new ShallowCopy(this.v);
    }

    public void Display()
    {
        foreach(int i in v)
        {
            Console.Write(i + " - ");
        }
        Console.WriteLine();
    }
}

/*
* 每个类都是一个产品; 扩展就是增加一个新类; 类与类之间相互独立
* 允许动态增减产品类,
* 具有给一个应用软件动态加载新功能的能力.
* 不需要任何实现确定的等级结构
*/
class Client
{
    public static void Main()
    {
        ShallowCopy sc1 = new ShallowCopy();
        ShallowCopy sc2 = (ShallowCopy)sc1.Clone();

        sc2.Display();
        sc1.v[0] = 100;
        sc2.Display();      // 不共用内存; 只是内存的数据一样   
    }
}