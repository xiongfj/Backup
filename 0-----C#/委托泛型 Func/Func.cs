using System;

namespace Wrox.ProCSharp.Delegates
{
    delegate double DoubleOp(double x);

    class Program
    {
        // Func<..> 最后一个T表示返回值类型, 必须有返回值
        static void Main()
        {
            /*
             * Func<T> 表示没有参数, 有 T 返回值的委托
             */
            Func<int> intFunc = speak;
            Console.WriteLine(intFunc());

            /*
             * Func<string, string> 表示有一个 string 参数, 返回 string 类型的委托
             */
            Func<string, string> strFunc = func;
            Console.WriteLine(strFunc("strFunc"));

            /*
             * Func<int, int, string> 表示有两个 int 参数, 返回 string 类型的委托
             */
            Func<int, int, string> sanFunc = func2;
            Console.WriteLine(sanFunc(119, 140));

            /*
             * 最后可以定义 7 个参数 1 个返回值.. 貌似,
             */
        }

        public static int speak()
        {
            return 100;
        }

        public static string func(string s)
        {
            return "hello Func<T, sting>  " + s;
        }

        public static string func2(int a, int b)
        {
            return "hello Func<T1, T2, Result_Int> " + a + " - " + b;
        }
    }

}
