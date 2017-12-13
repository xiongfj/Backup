using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
	abstract class Visitor
	{
		public abstract void VisitConcreteElementA(ConcreteElementA cea);
		public abstract void VisitConcreteElementB(ConcreteElementB ceb);
	}

	class ConcreteVisitor1 : Visitor
	{
		public override void VisitConcreteElementA(ConcreteElementA cea)
		{
			Console.WriteLine(cea.GetType().Name + " - " + this.GetType().Name);
		}

		public override void VisitConcreteElementB(ConcreteElementB ceb)
		{
			Console.WriteLine(ceb.GetType().Name + " - " + this.GetType().Name);
		}
	}


	class ConcreteVisitor2 : Visitor
	{
		public override void VisitConcreteElementA(ConcreteElementA cea)
		{
			Console.WriteLine(cea.GetType().Name + " - " + this.GetType().Name);
		}

		public override void VisitConcreteElementB(ConcreteElementB ceb)
		{
			Console.WriteLine(ceb.GetType().Name + " - " + this.GetType().Name);
		}
	}
}
