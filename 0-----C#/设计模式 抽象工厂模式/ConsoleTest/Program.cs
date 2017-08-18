using System;

abstract class AbstractFactory
{
    abstract public AbstractProductA CreateProductA();  // 有多少个抽象产品子类就要有多少个函数
    abstract public AbstractProductB CreateProductB();
}

class Factory_One : AbstractFactory
{
    public override AbstractProductA CreateProductA()
    {
        return new ProductA1();
    }
    public override AbstractProductB CreateProductB()
    {
        return new ProductB1();
    }
}

class Factory_Two : AbstractFactory
{
    public override AbstractProductA CreateProductA()
    {
        return new ProductA2();
    }
    public override AbstractProductB CreateProductB()
    {
        return new ProductB2();
    }
}

// d--------------------------------------------------

abstract class AbstractProductA
{

}
abstract class AbstractProductB
{
    abstract public void Interact(AbstractProductA a);
}

class ProductA1 : AbstractProductA
{

}
class ProductB1 : AbstractProductB
{
    public override void Interact(AbstractProductA a)
    {
        Console.WriteLine(this + "interacts with " + a);
    }
}

class ProductA2 : AbstractProductA
{

}
class ProductB2 : AbstractProductB
{
    public override void Interact(AbstractProductA a)
    {
        Console.WriteLine(this + "interacts with " + a);
    }
}

/*
 * 接收子工厂 factory 作为变量
 * 决定生产① 还是②产品
 */
class Environment
{
    private AbstractProductA AbstractProductA;
    private AbstractProductB AbstractProductB;

    public Environment(AbstractFactory factory)
    {
        AbstractProductA = factory.CreateProductA();
        AbstractProductB = factory.CreateProductB();
    }

    public void Run()
    {
        AbstractProductB.Interact(AbstractProductA);
    }
}

/*
                                            (A)                    (B)
                                        AbstractProductA     AbstractProductB
                                        --------------------------------------
                 |Factory_One            ProductA1              ProductB1           ①
  AbstractFactory|              ->      --------------------------------------
                 |Factory_Two            ProductA2              ProductB2           ②
                                        --------------------------------------

 * AbstractFactory 抽象工厂定义两个函数 AbstractProductA FactoryA()   表示工厂生产 (A) (B) 两类抽象产品
                                        AbstractProductB FactoryB()
    - 子工厂一负责生产AB类产品中的 ① 线产品 FactoryA(){ return ProductA1; }
                                             FactoryB(){ return ProductB1; }
    - 子工厂二负责生产 ② 线产品 FactoryA(){ return ProductA2; }
                                 FactoryB(){ return ProductB2; }
    
 * 子工厂作为游标, 指向 ① 或者 ②
 * 子工厂内部生产线内的所有产品
 * 扩展左半边或者扩展有半边, 都会印象对半边..

 */

class ClientApp
{
    public static void Main()
    {
        AbstractFactory factory1 = new Factory_One();
        Environment e1 = new Environment(factory1);
        e1.Run();

        AbstractFactory factory2 = new Factory_Two();
        Environment e2 = new Environment(factory2);
        e2.Run();
    }
}
