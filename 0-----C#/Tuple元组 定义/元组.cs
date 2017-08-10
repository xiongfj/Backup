using System;

namespace TuplesSample
{
    class Program
    {
        static void Main()
        {
            Tuple<string, string> name = new Tuple<string, string>("Jochen", "Rindt");
            Console.WriteLine(name.ToString());

            var result = Divide(5, 2);
            Console.WriteLine("result of division: {0}, reminder: {1}", result.Item1, result.Item2);

            AnyElementNumber();

            // item1.2.3.4... 会自动增加!!
            var s = test(33, 2, 45);
            Console.WriteLine("{0},{1}, {2}", s.Item1, s.Item2, s.Item3);
        }

        // 最多有八个元素, 元素内又可以有元素
        static void AnyElementNumber()
        {
            var tuple = Tuple.Create<string, string, string, int, int, int, double, Tuple<int, int>>(
                "Stephanie", "Alina", "Nagel", 2009, 6, 2, 1.37, Tuple.Create<int, int>(52, 3490));
            Console.WriteLine(tuple.Item1);
        }

        public static Tuple<int, int> Divide(int dividend, int divisor)
        {
            int result = dividend / divisor;
            int reminder = dividend % divisor;

            return Tuple.Create<int, int>(result, reminder);
        }


        public static Tuple<int, int, int> test(int dividend, int divisor, int third)
        {
            int result = dividend / divisor;
            int reminder = dividend % divisor;

            return Tuple.Create<int, int, int>(result, reminder, third);
        }
    }
}
