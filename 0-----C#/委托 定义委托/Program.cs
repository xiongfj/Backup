using System;

namespace Wrox.ProCSharp.Delegates
{
    class Program
    {
        // 所有返回 stirng , 没有参数的函数都可以赋值给该委托
        private delegate string GetAString();

        static void Main()
        {
            int x = 40;

            // 相当于函数指针的赋值
            GetAString firstStringMethod = x.ToString;
            Console.WriteLine("String is {0}", firstStringMethod());

            Currency balance = new Currency(34, 50);

            // firstStringMethod references an instance method
            firstStringMethod = balance.ToString;
            Console.WriteLine("String is {0}", firstStringMethod());

            // 委托内有个默认构造函数
            firstStringMethod = new GetAString(Currency.GetCurrencyUnit);
            Console.WriteLine("String is {0}", firstStringMethod());

        }
    }
}
