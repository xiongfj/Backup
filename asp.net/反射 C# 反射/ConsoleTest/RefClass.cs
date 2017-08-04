using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
    public class RefClass
    {
        // 字段,不是属性
        private int age = 100;

        // get,set 既是方法也是属性
        // 包含了一个 salar 隐含属性, 一个<salar>k_BackingField 字段, set_salar, get_salar 两个方法
        private int salar { get; set; }
        protected string address { get; set; }

        public double id { get; set; }

        public string Show(string s)
        {
            string str;
            return s;
        }

        public static string staticFunc(string s)
        {
            int a, b;
            return s;
        }
    }
}
