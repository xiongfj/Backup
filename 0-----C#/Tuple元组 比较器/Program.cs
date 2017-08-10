using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Wrox.ProCSharp.Arrays
{
    class TupleComparer : IEqualityComparer
    {
        #region IEqualityComparer Members

        // new 表示是覆盖基类的函数
        public new bool Equals(object x, object y)
        {
            bool result = x.Equals(y);
            return result;
        }

        public int GetHashCode(object obj)
        {
            return obj.GetHashCode();
        }

        #endregion
    }


    class Program
    {
        static void Main()
        {
            Person[] persons1 = { new Person { FirstName = "Michael", LastName = "Jackson" } };
            Person[] persons2 = { new Person { FirstName = "Michael", LastName = "Jackson" }};

            // 比较的是地址..
            if (persons1 != persons2)
                Console.WriteLine("not the same reference");

            // 数组没有实现 Equals 方法, 检测也会不相等
            if (!persons1.Equals(persons2))
                Console.WriteLine("equals returns false - not the same reference");

            // 转换成 IStructuralEquatable 就可以实现比较
            if ((persons1 as IStructuralEquatable).Equals(persons2, EqualityComparer<Person>.Default))
            {
                Console.WriteLine("the same content");
            }

            //------------------------------------------------

            var t1 = Tuple.Create<int, string>(1, "Stephanie");
            var t2 = Tuple.Create<int, string>(1, "Stephanie");

            // 比较的是地址
            if (t1 != t2)
                Console.WriteLine("not the same reference to the tuple");

            // 相等, Tuple 有 Equal 方法
            if (t1.Equals(t2))
                Console.WriteLine("equals returns true");

            // 使用自定义比较器
            TupleComparer tc = new TupleComparer();
            if ((t1 as IStructuralEquatable).Equals(t2, tc))
            {
                Console.WriteLine("yes, using TubpleComparer");
            }

        }
    }
}
