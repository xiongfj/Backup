using System;

abstract class Component
{
	abstract public void Operation();
}

class ConcreteComponent : Component
{
	public override void Operation()
	{
		Console.WriteLine("ConcreteComponent.Operation() ..");
	}
}

abstract class Decorator : Component
{
	protected Component component;
	public void SetComponent(Component component)
	{
		this.component = component;
	}

	public override void Operation()
	{
		if (component != null)
			component.Operation();
	}
}

class ConcreteDecoratorA : Decorator
{
	private string addedState;
	public override void Operation()
	{
		base.Operation();
		addedState = "new state";
		Console.WriteLine("ConcreteDecoratorA.Opertion()    ..");
	}
}

class ConcreteDecoratorB : Decorator
{
	public override void Operation()
	{
		base.Operation();
		AddedBehavior();
		Console.WriteLine("ConcreteDecoratorB.Opertion()       ...");
	}

	void AddedBehavior()
	{

	}
}

public class Client
{
	public static void Main(string[] args)
	{
		ConcreteComponent c = new ConcreteComponent();
		ConcreteDecoratorA d1 = new ConcreteDecoratorA();
		ConcreteDecoratorB d2 = new ConcreteDecoratorB();

		d1.SetComponent(c);
		d2.SetComponent(d1);
		d2.Operation();
	}
}

/*结果:
	ConcreteComponent.Operation() ..
	ConcreteDecoratorA.Opertion()    ..
	ConcreteDecoratorB.Opertion()       ...
*/
