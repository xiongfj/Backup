using System;
using System.Collections.Generic;
using System.Linq;


/*
 * 数据源来自 DataLib 项目
 * 使用 Linq 函数筛选数据
 */

namespace Wrox.ProCSharp.LINQ
{
    class Program
    {
        static void Main()
        {
            DeferredQuery();
        }

        static void DeferredQuery()
        {
            var names = new List<string> { "Nino", "Alberto", "Juan", "Mike", "Phil" };

            // 每次遍历该变量, 都会重新查询
            var namesWithJ = from n in names
                             where n.StartsWith("J")
                             orderby n
                             select n;

            // 锁定结果, 
            var tempList = namesWithJ.ToList<string>();

            Console.WriteLine("First iteration");
            foreach (string name in namesWithJ)
            {
                Console.WriteLine(name);
            }
            Console.WriteLine();

            names.Add("John");
            names.Add("Jim");
            names.Add("Jack");
            names.Add("Denny");

            // 能够查询到后面添加的数据!!
            Console.WriteLine("Second iteration");
            foreach (string name in namesWithJ)
            {
                Console.WriteLine(name);
            }

            Console.WriteLine();
            // 这里查询不到后面添加的数据!!!
            Console.WriteLine("3333 iteration");
            foreach (string name in tempList)
            {
                Console.WriteLine(name);
            }

        }
    }
}
