using System;
using System.Collections.Generic;

namespace Wrox.ProCSharp.Delegates
{
    class Program
    {
        static void Main()
        {
            var values = new List<int>() { 10, 20, 30};
            var funcs = new List<Func<int>>();

            /*
             * C#4.0 与 C#5.0 对 foreach 语法不一样. 4.0 的 val 和 ()=>val 是同一个
             */
            foreach(var val in values)
            {
                funcs.Add(()=>val); // 5.0中, ()=>val 的 val 是 foreach(var val) 的拷贝
            }

            foreach(var f in funcs)
            {
                Console.WriteLine( (f()) );
            }
        }
    }
}
