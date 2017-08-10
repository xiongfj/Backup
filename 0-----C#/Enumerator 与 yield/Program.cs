using System;
using System.Collections;
using System.Collections.Generic;

namespace Wrox.ProCSharp.Arrays
{
    public class HelloCollection
    {
        public IEnumerator<string> GetEnumerator()
        {
            // yield return 组合成一个 IEnumerator
            yield return "Hello";
            yield return "World";
        }
    }


    class Program
    {
        static void Main()
        {
            HelloWorld();
            MusicTitles();

            var game = new GameMoves(); // 内部不会输出

            IEnumerator enumerator = game.Cross();
            while (enumerator.MoveNext())           // 每次都会调用执行函数
            {
                enumerator = enumerator.Current as IEnumerator;
            }

            /* 不能使用 foreach 遍历 enumertor, 因为它没有GetEnumerator 方法
            foreach(var s in enumerator)
            {

            }*/
        }

        static void MusicTitles()
        {
            var titles = new MusicTitles();
            foreach (var title in titles)   // 默认查找 GetEnumerator() 匹配
            {
                Console.WriteLine(title);
            }
            Console.WriteLine();

            Console.WriteLine("reverse");
            foreach (var title in titles.Reverse())
            {
                Console.WriteLine(title);
            }
            Console.WriteLine();

            Console.WriteLine("subset");
            foreach (var title in titles.Subset(2, 2))
            {
                Console.WriteLine(title);
            }

        }

        static void HelloWorld()
        {
            var helloCollection = new HelloCollection();
            foreach (string s in helloCollection)
            {
                Console.WriteLine(s);
            }
        }
    }
}
