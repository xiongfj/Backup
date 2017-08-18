using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Threading;

namespace Foundations
{
    class Program
    {
        static void Main()
        {
            var ctx = new DispatcherSynchronizationContext();

            // SynchronizationContext.SetSynchronizationContext(ctx);
            // CallerWithAsync();
            // CallerWithContinuationTask();
            // CallerWithAwaiter();
            // MultipleAsyncMethods();
            // MultipleAsyncMethodsWithCombinators1();
            //   MultipleAsyncMethodsWithCombinators2();
            // ConvertingAsyncPattern();

            ConvertingAsyncPattern();

            while (true)
            {
               // Console.WriteLine("UI 线程 ");
                Thread.Sleep(733);
            }
        }
        //------------------------------------------------------------------------------
        //-------------------------- 另类异步模式 ----------------------------------
        //------------------------------------------------------------------------------
        private static async void ConvertingAsyncPattern()
        {
            string r = await Task<string>.Factory.FromAsync<string>(BeginGreeting, EndGreeting, "Angela", null);
            Console.WriteLine(r);
        }

        static string Greeting(string name)
        {
            // 线程执行代码
            Console.WriteLine("running greeting in thread {0} and task {1}", Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            Thread.Sleep(3000);
            return string.Format("Hello, {0}", name);
        }

        private static Func<string, string> greetingInvoker = Greeting;

        static IAsyncResult BeginGreeting(string name, AsyncCallback callback, object state)
        {
            // UI 线程;
            // 进入 Greeting 前调用
            // name = "Angela"
            Console.WriteLine("BeginGreeting - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            return greetingInvoker.BeginInvoke(name, callback, state);
        }

        static string EndGreeting(IAsyncResult ar)
        {
            // 线程结束时调用
            Console.WriteLine("EndGreeting - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            return greetingInvoker.EndInvoke(ar);
        }
        //------------------------------------------------------------------------------
        //------------------------------------------------------------------------------
        //------------------------------------------------------------------------------

        // 一个线程等待另一个线程
        private async static void MultipleAsyncMethods()
        {
            // 主线程
            Console.WriteLine("000 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            string s1 = await GreetingAsync("Stephanie");
            Console.WriteLine("111 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            string s2 = await GreetingAsync("Matthias");            // 需要等待第一个 await 结束后才会执行
            Console.WriteLine("222 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
            Console.WriteLine("Finished both methods.\n Result 1: {0}\n Result 2: {1}", s1, s2);
        }

        // 两个并行运行的线程
        private async static void MultipleAsyncMethodsWithCombinators1()
        {
            Task<string> t1 = GreetingAsync("Stephanie");
            // UI 
            Console.WriteLine("000 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            Task<string> t2 = GreetingAsync("Matthias");
            // UI
            Console.WriteLine("111 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            await Task.WhenAll(t1, t2);
            // string[] result = await Task.WhenAll(t1, t2); // 通过返回值获取task结果

            // 此处的线程属于最后执行完的那个线程
            Console.WriteLine("222 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
            Console.WriteLine("Finished both methods.\n Result 1: {0}\n Result 2: {1}", t1.Result, t2.Result);
        }

        // 只要有一个线程结束, 就返回那个线程的结果
        private async static void WhenAny()
        {
            Task<string> t1 = GreetingAsync("Stephanie");
            Task<string> t2 = GreetingAsync("Matthias");
            Task<string> task = await Task.WhenAny(t1, t2); // await 过滤调用 Task<T> 中的Task, 返回 T
            Console.WriteLine("Finished both methods.\n Result 1: {0}\n ", task.Result);
        }

        // 
        private static void CallerWithContinuationTask()
        {
            // UI 线程
            Console.WriteLine("000 - thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
            // 线程 1
            var t1 = GreetingAsync("Stephanie");

            // UI 线程
            Console.WriteLine("111 ---  in thread {0} and task {1}",
                                            Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            // 这里又是另外一个线程 2
            t1.ContinueWith(t =>
              {
                  string result = t.Result;     // 获取线程返回结果
                  Console.WriteLine(result);
                  Console.WriteLine("finished CallerWithContinuationTask in thread {0} and task {1}",
                                                    Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
              });
        }

        // GetAwaiter() 会使主线程等待
        private static void CallerWithAwaiter()
        {
            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
            string result = GreetingAsync("Matthias").GetAwaiter().GetResult();
            Console.WriteLine(result);
            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
        }

        /*
         * 在函数内部 await 开始,会分化出一个线程
         */
        private async static void CallerWithAsync()
        {
            // UI 线程执行
            Console.WriteLine("      CallerWithAsync  thread {0} and task {1}",
                                Thread.CurrentThread.ManagedThreadId, Task.CurrentId);

            // 新线程执行
            string result = await GreetingAsync("Stephanie");       // 该函数会等待
            Console.WriteLine("      CallerWithAsync 线程结束 thread {0} and task {1}",
                                Thread.CurrentThread.ManagedThreadId, Task.CurrentId);
        }

        // 主线程调用这个函数不会阻塞主线程
        static Task<string> GreetingAsync(string name)
        {
            // Run 里面的代码在另外一个线程内运行
            return Task.Run<string>(() =>
              {
                  Console.WriteLine("running greetingasync in thread {0} and task {1}",
                                        Thread.CurrentThread.ManagedThreadId,       // 线程 id
                                        Task.CurrentId);                            // Task id
                  return Greeting(name);
              });
        }
    
    }
}
