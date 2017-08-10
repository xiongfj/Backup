using System;

namespace Wrox.ProCSharp.Delegates
{

    class MathOperations
    {
        public static void MultiplyByTwo(double value)
        {
            double result = value * 2;
            Console.WriteLine("Multiplying by 2: {0} gives {1}-----------", value, result);
        }

        public static void Square(double value)
        {
            double result = value * value;
            Console.WriteLine("Squaring: {0} gives {1}", value, result);
        }
    }

    class Program
    {
        static void Main()
        {
            Action<double> operations = MathOperations.MultiplyByTwo;
            operations += MathOperations.Square;

            ProcessAndDisplayNumber(operations, 2.0);
            ProcessAndDisplayNumber(operations, 7.94);
            ProcessAndDisplayNumber(operations, 1.414);
            Console.WriteLine();
        }

        static void ProcessAndDisplayNumber(Action<double> action, double value)
        {
            Console.WriteLine();
            Console.WriteLine("ProcessAndDisplayNumber called with value = {0}", value);

            // action ��������������, �����ε�������
            // ��� action �з���ֵ, ֻ�ܻ�ȡ������Ǹ������ķ���ֵ
			// �����һ����������һ��, �ôκ���ĺ��������ᱻ����
            action(value);
        }
    }

}
