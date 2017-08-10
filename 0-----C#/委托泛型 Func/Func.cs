using System;

namespace Wrox.ProCSharp.Delegates
{
    delegate double DoubleOp(double x);

    class Program
    {
        // Func<..> ���һ��T��ʾ����ֵ����, �����з���ֵ
        static void Main()
        {
            /*
             * Func<T> ��ʾû�в���, �� T ����ֵ��ί��
             */
            Func<int> intFunc = speak;
            Console.WriteLine(intFunc());

            /*
             * Func<string, string> ��ʾ��һ�� string ����, ���� string ���͵�ί��
             */
            Func<string, string> strFunc = func;
            Console.WriteLine(strFunc("strFunc"));

            /*
             * Func<int, int, string> ��ʾ������ int ����, ���� string ���͵�ί��
             */
            Func<int, int, string> sanFunc = func2;
            Console.WriteLine(sanFunc(119, 140));

            /*
             * �����Զ��� 7 ������ 1 ������ֵ.. ò��,
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
