using System;

/** 浅拷贝 **/
class ShallowCopy : ICloneable
{
    public int[] v = { 1,2,3};

    // 实现接口函数, 要不要继承接口貌似都一样, 多此一举.可以自定义这个函数,不一定非要接口来指定?!?
    public object Clone()
    {
        return this.MemberwiseClone();      // 浅拷贝; 拷贝后的对象与援对象共用内存; 实际上就是引用11
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

//
class Client
{
    public static void Main()
    {
        ShallowCopy sc1 = new ShallowCopy();
        ShallowCopy sc2 = (ShallowCopy)sc1.Clone();

        sc2.Display();
        sc1.v[0] = 100;
        sc2.Display();          // sc2 其实就是 sc1 的引用
    }
}