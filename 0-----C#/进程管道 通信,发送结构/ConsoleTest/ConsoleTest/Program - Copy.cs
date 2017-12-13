using ConsoleTest;
using System;
using System.Diagnostics;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;


public class Program
{
	static int Main()
	{
		ObjectStructure o = new ObjectStructure();
		o.Attach(new ConcreteElementA());
		o.Attach(new ConcreteElementB());

		ConcreteVisitor1 v1 = new ConcreteVisitor1();
		ConcreteVisitor2 v2 = new ConcreteVisitor2();

		o.Accept(v1);
		o.Accept(v2);

		return 0;
	}
}

