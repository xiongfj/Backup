
* 简单直接的在 UI 上执行一个异步任务
/*
* Run 里面的代码不会阻塞 UI 线程运行
Task.Run(() =>{
	Thread.Sleep(4000);
	Console.WriteLine("线程支线 2", 
		Thread.CurrentThread.ManagedThreadId,       // 线程 id
		Task.CurrentId);                            // Task id);
*/

* async - await -----------------------------------------
{
/*
* UI 线程遇到 await 会分化一个子线程; 子线程内部遇到 await 则不会在分化子线程
* await 只能在 async 函数内出现??
* await 只能'调用'返回类型为 Task 的函数
* async 只能用于返回类型为 Task 或 void 的函数.
*/
-------- <<async 函数的使用>> -------------
	class Program
	{
		...
		// 调用该函数的 UI 线程不会被阻塞
		public async static void asyncMethod()
		{
			// 这里会等待 GreetingAsync() 函数返回才会继续执行该函数后面的代码
			string result = await GreetingAsync("Stephanie");	// 该函数必须是 Task<string> 返回类型的
			...
			Console.WriteLine("我被阻塞..");
		}
		
		static Task<string> GreetingAsync(string name)
		{
			return Task.Run<string>(() =>
              {
                  Console.WriteLine("running greetingasync in thread {0} and task {1}",
                                        Thread.CurrentThread.ManagedThreadId,       // 线程 id
                                        Task.CurrentId);                            // Task id
										
					Thread.Sleep(3000);
                  return "hello "+ name;
              });
		}
	}
}

































