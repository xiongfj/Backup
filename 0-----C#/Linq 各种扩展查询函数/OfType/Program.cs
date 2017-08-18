using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OfType
{
    interface IPeople
    {
        string name { get; }
        int age { get; }
    };

    class Man : IPeople
    {
        public Man(string s, int a)
        {
            name = s;
            age = a;
        }

        public string name { get; private set; }
        public int age { get; private set; }
    }

    class Woman : IPeople
    {
        public Woman(string s, int a)
        {
            name = s;
            age = a;
        }

        public string name { get; private set; }
        public int age { get; private set; }
    }


    class Program
    {
        static void Main(string[] args)
        {
            var lists = new List<IPeople> {
                new Man("Jack", 23),
                new Man("Loch", 23),
                new Woman("Maliy", 25),
                new Woman("Lili", 23) };

            // 筛选是 Woman 的数据, 不包含 Man
            IEnumerable<Woman> result = lists.OfType<Woman>();

            foreach(var item in result)
            {
                Console.WriteLine("{0}, {1} \n", item.name, item.age);
            }
        }
    }
}
