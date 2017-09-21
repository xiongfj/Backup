
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

** 带返回值 Task<TResult> 的 async----------------------

static void Main(string[] args)
{
    Console.WriteLine("-------主线程启动-------");
    Task<int> task = GetStrLengthAsync();
    Console.WriteLine("主线程继续执行");
    Console.WriteLine("Task返回的值" + task.Result);
    Console.WriteLine("-------主线程结束-------");
}

static async Task<int> GetStrLengthAsync()
{
    Console.WriteLine("GetStrLengthAsync方法开始执行");
    //此处返回的<string>中的字符串类型，而不是Task<string>
    string str = await GetString();
    Console.WriteLine("GetStrLengthAsync方法执行结束");
    return str.Length;
}

static Task<string> GetString()
{
　　 //Console.WriteLine("GetString方法开始执行")
    return Task<string>.Run(() =>
    {
        Thread.Sleep(2000);
        return "GetString的返回值";
    });
}

































