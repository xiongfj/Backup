using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ErrorHandling
{
    class Program
    {
        static void Main(string[] args)
        {
            // DontHandle();
             //HandleOneError();
           // StartTwoTasks();
            // StartTwoTasksParallel();
            ShowAggregatedException();

            Console.ReadLine();
        }

        private static async void ShowAggregatedException()
        {
            Task taskResult = null;
            try
            {
                Task t1 = ThrowAfter(2000, "first");
                Task t2 = ThrowAfter(1000, "second");
                await (taskResult = Task.WhenAll(t1, t2));
            }
            catch (Exception ex)
            {
                // 捕获的是最后执行完的task 内的异常
                Console.WriteLine("handled {0}", ex.Message);

                // 这里存储了所有异常
                foreach (var ex1 in taskResult.Exception.InnerExceptions)
                {
                    Console.WriteLine("inner exception {0} from task {1}", ex1.Message, ex1.Source);
                }
            }
        }

        private async static void StartTwoTasksParallel()
        {
            Task t1 = null;
            try
            {
                t1 = ThrowAfter(2000, "first");
                Task t2 = ThrowAfter(1000, "second");

                // 等到所有task完成才会继续执行,
                // 此时捕获的异常是最后结束的那个 task 抛出的异常
                await Task.WhenAll(t1, t2);
            }
            catch (Exception ex)
            {
                Console.WriteLine("handled {0}", ex.Message);
            }
        }

        private static async void StartTwoTasks()
        {
            try
            {
                await ThrowAfter(2000, "first");

                // 上一个 task 抛出异常, 这个 task 不会执行到
                // 因为需要等待上面的 task 执行完后才会执行这个 task 
                await ThrowAfter(1000, "second");
            }
            catch (Exception ex)
            {
                Console.WriteLine("handled {0}", ex.Message);
            }
        }

        // 无法在 UI 线程中 捕获 子线程的异常!!!
        private static void DontHandle()
        {
            try
            {
                ThrowAfter(200, "first");

                // 这里属于 UI 线程
                // 在发生异常的时候UI线程已经走过, 无法再捕获异常
                Console.WriteLine("DontHandle  {0} - {1}", Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        // 添加 await 后 try 才能捕获异常!
        private static async void HandleOneError()
        {
            try
            {
                await ThrowAfter(2000, "first");

                // 这里的代码属于子线程的
                Console.WriteLine("HandleOneError  {0} - {1}", Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
            }
            catch (Exception ex)
            {
                Console.WriteLine("handled {0}", ex.Message);
            }

            
        }

        // 返回类型是 Task, 那么 await ThrowAfter(..) = void
        static async Task ThrowAfter(int ms, string message)
        {
            // UI 线程
            Console.WriteLine("ThrowAfter前  {0} - {1}", Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            // 子线程
            await Task.Delay(ms);
            Console.WriteLine("ThrowAfter后  {0} - {1}", Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
            throw new Exception(message);
        }
    }
}
