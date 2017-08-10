using System;

namespace Wrox.ProCSharp.Delegates
{
    class Program
    {
        static void Main()
        {
            // 匿名委托
            Action<string> act = delegate (string str)
            {
                Console.WriteLine(str);
            };

            // 匿名 lambda 表达式
            act += (s) =>       // s 就代表上面 delegate 的 参数
            {
                Console.WriteLine("我是匿名 Lambda 表达式 委托.");
            };
            act("hello Action<T> ...");

            // 带返回值的匿名委托
            Func<int, string> func = delegate (int value)
            {
                return "参数是: " + value;
            };
            Console.WriteLine(func(1234));
        }
    }
}
