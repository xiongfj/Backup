using System;

namespace Wrox.ProCSharp.Delegates
{
    delegate double DoubleOp(double x);

    class Program
    {
        static void Main()
        {
            // 使用没有参数的 Action 委托
            Action a = speak;
            a();

            // Action<T> 是系统定义好的委托. Action<> 没有返回值
            Action<string> adelegate = func;
            adelegate("我是 Action<T> 泛型委托.. ");

            // 带两个输入参数的委托
            Action<int, int> dele = func2;
            dele(12, 43);

           // Action<int, int, string ...>    // 最多可以定义 8 个参数
        }

        public static void speak()
        {
            Console.WriteLine("我是没有参数的 Action 委托");
        }

        public static void func(string s)
        {
            Console.WriteLine(s);
        }

        public static void func2(int a, int b)
        {
            Console.WriteLine("{0} + {1} = {2}", a, b, a+b);
        }
    }

}
