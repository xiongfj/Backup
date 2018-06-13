using System;

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

/*
 * 一般做成单一实例静态的
 * 使用参数获取不同的 Light 
 */

public class CreatorFactory
{
    public static Light factory( string type)
    {
        switch(type)
        {
            case "TubeLight":
                return new TubeLight();
            case "BulbLight":
                return new BulbLight();
            default:
                throw new Exception();
        }
    }
}

/*
 * 主程序持有一个 Light
 * 还需要提供一个 type ( 这个环境可以在 web.config 之类的地方提供)
 */
public class Client
{
    public static void Main()
    {
        Light light = CreatorFactory.factory("TubeLight");
        light.TurnOn();
    }
}
