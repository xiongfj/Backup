using System;

/*
 * 工厂方法模式
 * main 函数需要有一个抽象 Light
 * 调用具体的工厂方法 创建具体的Light
 */


public abstract class Light
{
    public abstract void TurnOn();
    public abstract void TurnOff();
}

public class BulbLight : Light
{
    public override void TurnOn()
    {
        Console.WriteLine("BulbLight:TurnOn()..");
    }
    public override void TurnOff()
    {
        Console.WriteLine("BulbLight:TurnOff()..");
    }
}

public class TubeLight : Light
{
    public override void TurnOn()
    {
        Console.WriteLine("     TubeLight:TurnOn()..");
    }
    public override void TurnOff()
    {
        Console.WriteLine("     TubeLight:TurnOff()..");
    }
}
// 扩展
//public class xxLinght : Light
//{
//        ...
//    ...
//}


/* 
 * 抽象工厂使用抽象 Light,
 * 每一个子工厂都可以使用抽象 Light 的各种子类
 */
public abstract class Creator
{
    public abstract Light factory();
}

public class BulbCreator : Creator
{
    public override Light factory()
    {
        return new BulbLight();
    }
}

public class TubeCreator : Creator
{
    public override Light factory()
    {
        return new TubeLight();
    }
}
// 扩展
//public class xxCreator : Creator
//{
//    public override Light factory()
//   {
//        ...
//    }
//}

/* 扩展是类级别的; (即扩展的时候需要新增一个类,继承 Creator 即可)
 * 而简单工厂的扩展是代码块级别的; (扩展需要修改类内部代码)
 */

public class Client
{
    public static void Main()
    {
        Creator c1 = new BulbCreator();
        Creator c2 = new TubeCreator();

        Light l1 = c1.factory();
        Light l2 = c2.factory();

        l1.TurnOn();
        l1.TurnOff();

        l2.TurnOn();
        l2.TurnOff();
    }
}
