﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
	abstract class Element
	{
		public abstract void Accept(Visitor visitor);
	}

	class ConcreteElementA : Element
	{
		public override void Accept(Visitor visitor)
		{
			visitor.VisitConcreteElementA(this);
		}

		public void OperationA()
		{

		}
	}

	class ConcreteElementB : Element
	{
		public override void Accept(Visitor visitor)
		{
			visitor.VisitConcreteElementB(this);
		}

		public void OperationB()
		{

		}
	}
}
