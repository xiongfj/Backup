using System;

namespace Wrox.ProCSharp.Delegates
{
    delegate double DoubleOp(double x);

    class Program
    {
        static void Main()
        {
            // ʹ��û�в����� Action ί��
            Action a = speak;
            a();

            // Action<T> ��ϵͳ����õ�ί��. Action<> û�з���ֵ
            Action<string> adelegate = func;
            adelegate("���� Action<T> ����ί��.. ");

            // ���������������ί��
            Action<int, int> dele = func2;
            dele(12, 43);

           // Action<int, int, string ...>    // �����Զ��� 8 ������
        }

        public static void speak()
        {
            Console.WriteLine("����û�в����� Action ί��");
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
