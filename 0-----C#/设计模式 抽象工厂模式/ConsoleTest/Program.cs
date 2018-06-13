using System;

abstract class AbstractFactory
{
    abstract public Steel_Abstract CreateSteel();
    abstract public Wood_Abstract CreateWood();
}

class Factory_One : AbstractFactory
{
    public override Steel_Abstract CreateSteel(){
        return new SteelBar();
    }
    public override Wood_Abstract CreateWood(){
        return new WoodTable();
    }
}

class Factory_Two : AbstractFactory
{
    public override Steel_Abstract CreateSteel(){
        return new SteelPanel();
    }
    public override Wood_Abstract CreateWood(){
        return new WoodChair();
    }
}

/* 定义了木材类与刚才类的关系 */
abstract class Steel_Abstract   // 钢类产品
{ }
abstract class Wood_Abstract    // 木材类产品
{
    abstract public void Interact(Steel_Abstract a);
}

/* 具体关系的实现 */
class SteelBar : Steel_Abstract	 // 钢条
{ }
class SteelPanel : Steel_Abstract// 钢板
{ }

class WoodTable : Wood_Abstract  // 木桌
{
	// 木桌可以使用所有的钢类子产品
    public override void Interact(Steel_Abstract a)  {
        Console.WriteLine(this + " interacts with " + a);
    }
}
class WoodChair : Wood_Abstract  // 木椅
{
	// 木椅也可以使用所有的钢类子产品
	public override void Interact(Steel_Abstract a)  {
        Console.WriteLine(this + " interacts with " + a);
    }
}
/*  */
class Environment
{
    private Steel_Abstract steelPro;
    private Wood_Abstract woodPro;

    public Environment(AbstractFactory factory) {
		steelPro = factory.CreateSteel();
		woodPro = factory.CreateWood();
    }

    public void Run() {
		woodPro.Interact(steelPro);
    }
}
class ClientApp
{
    public static void Main() {
        AbstractFactory factory1 = new Factory_One();
        Environment e1 = new Environment(factory1);
        e1.Run();

        AbstractFactory factory2 = new Factory_Two();
        Environment e2 = new Environment(factory2);
        e2.Run();
    }
}
/* 输出结果:
	WoodTable interacts with SteelBar
	WoodChair interacts with SteelPanel
*/

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

