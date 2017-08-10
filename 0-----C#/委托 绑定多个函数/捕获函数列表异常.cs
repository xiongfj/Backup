using System;

namespace Wrox.ProCSharp.Delegates
{

    class MathOperations
    {
        public static void MultiplyByTwo(double value)
        {
            Console.WriteLine("MultiplyByTwo");
            throw new Exception("异常..");
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

            Delegate[] delegates = operations.GetInvocationList();
            foreach(Action<double> d in delegates)
            {
                try
                {
                    d(23.4);
                }catch(Exception e)
                {
                    Console.WriteLine("抓到异常 ... ");
                }
            }
        }
    }
}
