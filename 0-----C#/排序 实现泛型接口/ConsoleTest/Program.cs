using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

namespace ConsoleTest
{
    // 排序接口1
    class SortByName : IComparer<Fruit>
    {
        int IComparer<Fruit>.Compare(Fruit x, Fruit y)
        {
            return x.Name.CompareTo(y.Name);
        }
    }

    // 排序接口2
    class Fruit : IComparable<Fruit>
    {
        public string Name;
        public int Price;
        int IComparable<Fruit>.CompareTo(Fruit other)
        {
            return Price.CompareTo(other.Price);
        }
    }

    #region 换成上面的泛型效率比较高
    /* 
    class Fruit : IComparable
    {
        public string Name;
        public int Price;
        public int CompareTo(object obj)
        {
            if (obj == null) return 1;
            Fruit otherFruit = obj as Fruit;    这种接口需要装箱, 该换成上面的泛型比较好.

            // 这里可以自定义比较规则
            //if (Price > otherFruit.Price) { return 1; }
            //else
            //{
             //   if (Price == otherFruit.Price) { return 0; }
            //    else { return -1; }
           // }
            // int,string..等数据类型继承了 IComparable 接口, 可以直接使用
            return Price.CompareTo(otherFruit.Price);
        }
    }*/
    #endregion

    //
    class Program
    {
        static List<Fruit> fruit = new List<Fruit>();

        static void Main(string[] args)
        {
            fruit.Add(new Fruit { Name = "grape", Price = 30 });
            fruit.Add(new Fruit { Name = "apple", Price = 10 });
            fruit.Add(new Fruit { Name = "banana", Price = 15 });
            fruit.Add(new Fruit { Name = "orage", Price = 12 });

            sort3();
        }

        // 排序方法一
        public static void sort1()
        {
            Console.Write("未排序：");
            foreach (var f in fruit)
                Console.Write($"{f.Name} ");
            Console.WriteLine();

            fruit.Sort();

            Console.Write("排序后：");
            foreach (var f in fruit)
                Console.Write($"{f.Name} ");
            Console.WriteLine();
        }

        // 使用 Linq 函数语句直接排序
        public static void sort2()
        {
            Console.Write("排序前：");
            foreach (var f in fruit)
                Console.Write($"{f.Name} ");
            Console.WriteLine();

            // OrderBy 是扩展 IEnumerable 接口的函数
            var fruitSort = fruit.OrderBy(x => x.Price);

            Console.Write("排序后：");
            foreach (var f in fruitSort)
                Console.Write($"{f.Name} ");
            Console.WriteLine();
        }

        // 使用 IComparer<T> 泛型接口排序
        public static void sort3()
        {
            Console.Write("排序前：");
            foreach (var f in fruit)
                Console.Write($"{f.Name} ");
            Console.WriteLine();

            // OrderBy 是扩展 IEnumerable 接口的函数
            fruit.Sort(new SortByName());

            Console.Write("排序后：");
            foreach (var f in fruit)
                Console.Write($"{f.Name} ");
            Console.WriteLine();
        }
    }
}
