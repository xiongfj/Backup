using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonDll
{
	[Serializable]
	public class Person
    {
		public string name;
		public int age;
		public Person(string n, int a)
		{
			name = n;
			age = a;
		}
    }
}
