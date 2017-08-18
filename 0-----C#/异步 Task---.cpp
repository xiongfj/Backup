#region 程序集 mscorlib, Version=4.0.0.0, Culture=neutral, */
		publicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\mscorlib.dll
#endregion

using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime;
using System.Runtime.CompilerServices;

namespace System.Threading.Tasks
{
    //
    /*:
    //     表示一个异步操作。若要浏览此类型的.NET Framework 源代码，请参阅 Reference Source。
    [DebuggerDisplay("Id = {Id}, Status = {Status}, Method = {DebuggerDisplayMethodDescription}")]
    [DebuggerTypeProxy(typeof(SystemThreadingTasks_TaskDebugView))]
    */
		public class Task : IThreadPoolWorkItem, IAsyncResult, IDisposable
    {
        //
        /*:
        //     使用指定的操作初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        */
		public Task(Action action);
        //
        /*:
        //     使用指定的操作和 System.Threading.Tasks.Task 初始化新的 System.Threading.CancellationToken。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   cancellationToken:
        //     新任务将观察的 System.Threading.CancellationToken。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放提供的 System.Threading.CancellationToken。
        //
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        */
		public Task(Action action, CancellationToken cancellationToken);
        //
        /*:
        //     使用指定的操作和创建选项初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        */
		public Task(Action action, TaskCreationOptions creationOptions);
        //
        /*:
        //     使用指定的操作和状态初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   state:
        //     一个表示由该操作使用的数据的对象。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        */
		public Task(Action<object> action, object state);
        //
        /*:
        //     使用指定的操作和创建选项初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   cancellationToken:
        //     新任务将观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        */
		public Task(Action action, CancellationToken cancellationToken, TaskCreationOptions creationOptions);
        //
        /*:
        //     使用指定的操作、状态和选项初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   state:
        //     一个表示由该操作使用的数据的对象。
        //
        //   cancellationToken:
        //     新任务将观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        */
		public Task(Action<object> action, object state, CancellationToken cancellationToken);
        //
        /*:
        //     使用指定的操作、状态和选项初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   state:
        //     一个表示由该操作使用的数据的对象。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        */
		public Task(Action<object> action, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     使用指定的操作、状态和选项初始化新的 System.Threading.Tasks.Task。
        //
        // 参数:
        //   action:
        //     表示要在任务中执行的代码的委托。
        //
        //   state:
        //     一个表示由该操作使用的数据的对象。
        //
        //   cancellationToken:
        //     新任务将观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        */
		public Task(Action<object> action, object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions);

        //
        /*:
        //     返回当前正在执行 System.Threading.Tasks.Task 的 ID。
        //
        // 返回结果:
        //     系统分配给当前正在执行的任务的一个整数。
        */
		public static int? CurrentId { get; }
        //
        /*:
        //     提供对用于创建 System.Threading.Tasks.Task 和 System.Threading.Tasks.Task`1 的工厂方法的访问。
        //
        // 返回结果:
        //     一个工厂对象，可创建多种 System.Threading.Tasks.Task 和 System.Threading.Tasks.Task`1 对象。
        */
		public static TaskFactory Factory { get; }
        //
        /*:
        //     获取此 System.Threading.Tasks.Task 是否已完成。
        //
        // 返回结果:
        //     如果任务已完成，则为 true；否则为 false。
        */
		public bool IsCompleted { get; }
        //
        /*:
        //     获取此 System.Threading.Tasks.Task 实例是否由于被取消的原因而已完成执行。
        //
        // 返回结果:
        //     如果任务由于被取消而完成，则为 true；否则为 false。
        */
		public bool IsCanceled { get; }
        //
        /*:
        //     获取此任务的 System.Threading.Tasks.TaskStatus。
        //
        // 返回结果:
        //     此任务实例的当前 System.Threading.Tasks.TaskStatus。
        */
		public TaskStatus Status { get; }
        //
        /*:
        //     获取导致 System.AggregateException 提前结束的 System.Threading.Tasks.Task。 如果 System.Threading.Tasks.Task
        //     成功完成或尚未引发任何异常，这将返回 null。
        //
        // 返回结果:
        //     导致 System.AggregateException 提前结束的 System.Threading.Tasks.Task。
        */
		public AggregateException Exception { get; }
        //
        /*:
        //     获取此 System.Threading.Tasks.Task 实例的 ID。
        //
        // 返回结果:
        //     系统分配到此 System.Threading.Tasks.Task 实例的标识符。
        */
		public int Id { get; }
        //
        /*:
        //     获取用于创建此任务的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 返回结果:
        //     用于创建此任务的 System.Threading.Tasks.TaskCreationOptions。
        */
		public TaskCreationOptions CreationOptions { get; }
        //
        /*:
        //     获取在创建 System.Threading.Tasks.Task 时提供的状态对象，如果未提供，则为 null。
        //
        // 返回结果:
        //     一个 System.Object，表示在创建任务时传递给该任务的状态数据。
        */
		public object AsyncState { get; }
        //
        /*:
        //     获取 System.Threading.Tasks.Task 是否由于未经处理异常的原因而完成。
        //
        // 返回结果:
        //     如果任务引发了未经处理的异常，则为 true；否则为 false。
        */
		public bool IsFaulted { get; }

        //
        /*:
        //     创建一个在指定的时间间隔后完成的任务。
        //
        // 参数:
        //   delay:
        //     在完成返回的任务前等待的时间跨度；如果无限期等待，则为 TimeSpan.FromMilliseconds(-1)。
        //
        // 返回结果:
        //     表示时间延迟的任务。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     delay 表示负时间间隔以外 TimeSpan.FromMillseconds(-1)。- 或 -delay 参数的 System.TimeSpan.TotalMilliseconds
        //     属性大于 System.Int32.MaxValue。
        */
		public static Task Delay(TimeSpan delay);
        //
        /*:
        //     创建一个在指定的时间间隔后完成的可取消任务。
        //
        // 参数:
        //   delay:
        //     在完成返回的任务前等待的时间跨度；如果无限期等待，则为 TimeSpan.FromMilliseconds(-1)。
        //
        //   cancellationToken:
        //     将在完成返回的任务之前选中的取消标记。
        //
        // 返回结果:
        //     表示时间延迟的任务。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     delay 表示负时间间隔以外 TimeSpan.FromMillseconds(-1)。- 或 -delay 参数的 System.TimeSpan.TotalMilliseconds
        //     属性大于 System.Int32.MaxValue。
        //
        //   T:System.Threading.Tasks.TaskCanceledException:
        //     该任务已取消。
        //
        //   T:System.ObjectDisposedException:
        //     提供 cancellationToken 被释放。
        */
		public static Task Delay(TimeSpan delay, CancellationToken cancellationToken);
        //
        /*:
        //     创建将在时间延迟后完成的任务。
        //
        // 参数:
        //   millisecondsDelay:
        //     在完成返回的任务前要等待的毫秒数；如果无限期等待，则为 -1。
        //
        // 返回结果:
        //     表示时间延迟的任务。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsDelay 参数是小于-1。
        */
		public static Task Delay(int millisecondsDelay);
        //
        /*:
        //     创建将在时间延迟后完成的可取消任务。
        //
        // 参数:
        //   millisecondsDelay:
        //     在完成返回的任务前要等待的毫秒数；如果无限期等待，则为 -1。
        //
        //   cancellationToken:
        //     将在完成返回的任务之前选中的取消标记。
        //
        // 返回结果:
        //     表示时间延迟的任务。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsDelay 参数是小于-1。
        //
        //   T:System.Threading.Tasks.TaskCanceledException:
        //     该任务已取消。
        //
        //   T:System.ObjectDisposedException:
        //     提供 cancellationToken 被释放。
        */
		public static Task Delay(int millisecondsDelay, CancellationToken cancellationToken);
        //
        /*:
        //     创建指定结果的、成功完成的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   result:
        //     存储入已完成任务的结果。
        //
        // 类型参数:
        //   TResult:
        //     任务返回的结果的类型。
        //
        // 返回结果:
        //     已成功完成的任务。
        */
		public static Task<TResult> FromResult<TResult>(TResult result);
        //
        /*:
        //     将在线程池上运行的指定工作排队，并返回 function 所返回的任务的代理项。
        //
        // 参数:
        //   function:
        //     以异步方式执行的工作。
        //
        //   cancellationToken:
        //     应用以取消工作的取消标记。
        //
        // 返回结果:
        //     表示由 function 返回的任务代理的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        //
        //   T:System.Threading.Tasks.TaskCanceledException:
        //     该任务已取消。
        //
        //   T:System.ObjectDisposedException:
        //     与 cancellationToken 关联的 System.Threading.CancellationTokenSource 已释放。
        */
		public static Task Run(Func<Task> function, CancellationToken cancellationToken);
        //
        /*:
        //     将在线程池上运行的指定工作排队，并返回 function 所返回的任务的代理。
        //
        // 参数:
        //   function:
        //     以异步方式执行的工作量。
        //
        // 返回结果:
        //     表示由 function 返回的任务代理的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数是 null。
        */
		public static Task Run(Func<Task> function);
        //
        /*:
        //     将在线程池上运行的指定工作排队，并返回代表该工作的 System.Threading.Tasks.Task 对象。 可使用取消标记来取消工作。
        //
        // 参数:
        //   action:
        //     以异步方式执行的工作量。
        //
        //   cancellationToken:
        //     可用于取消工作的取消标记
        //
        // 返回结果:
        //     一个任务，它表示在线程池中排队等待执行的工作。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     action 参数为 null。
        //
        //   T:System.Threading.Tasks.TaskCanceledException:
        //     该任务已取消。
        //
        //   T:System.ObjectDisposedException:
        //     已释放与 cancellationToken 关联的 System.Threading.CancellationTokenSource。
        */
		public static Task Run(Action action, CancellationToken cancellationToken);
        //
        /*:
        //     在线程池上运行的指定的工作排队，并返回的代理 Task(TResult) 返回 function。
        //
        // 参数:
        //   function:
        //     以异步方式执行的工作量。
        //
        // 类型参数:
        //   TResult:
        //     代理任务返回的结果的类型。
        //
        // 返回结果:
        //     表示由 Task(TResult) 返回的 Task(TResult) 的代理的 function。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数是 null。
        */
		public static Task<TResult> Run<TResult>(Func<Task<TResult>> function);
        //
        /*:
        //     在线程池上运行的指定的工作排队，并返回的代理 Task(TResult) 返回 function。
        //
        // 参数:
        //   function:
        //     以异步方式执行的工作量。
        //
        //   cancellationToken:
        //     应用以取消工作的取消标记
        //
        // 类型参数:
        //   TResult:
        //     代理任务返回的结果的类型。
        //
        // 返回结果:
        //     表示由 Task(TResult) 返回的 Task(TResult) 的代理的 function。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数是 null。
        //
        //   T:System.Threading.Tasks.TaskCanceledException:
        //     该任务已取消。
        //
        //   T:System.ObjectDisposedException:
        //     与 cancellationToken 关联的 System.Threading.CancellationTokenSource 已释放。
        */
		public static Task<TResult> Run<TResult>(Func<Task<TResult>> function, CancellationToken cancellationToken);
        //
        /*:
        //     将在线程池上运行的指定工作排队，并返回代表该工作的 System.Threading.Tasks.Task 对象。
        //
        // 参数:
        //   action:
        //     以异步方式执行的工作量。
        //
        // 返回结果:
        //     表示在线程池执行的队列的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     action 参数是 null。
        */
		public static Task Run(Action action);
        //
        /*:
        //     将在线程池上运行的指定工作排队，并返回代表该工作的 Task(TResult) 对象。 借助取消标记，可取消工作。
        //
        // 参数:
        //   function:
        //     以异步方式执行的工作量。
        //
        //   cancellationToken:
        //     应用以取消工作的取消标记
        //
        // 类型参数:
        //   TResult:
        //     任务的结果类型。
        //
        // 返回结果:
        //     一个 Task(TResult)，它表示在线程池中排队等待执行的工作。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        //
        //   T:System.Threading.Tasks.TaskCanceledException:
        //     该任务已取消。
        //
        //   T:System.ObjectDisposedException:
        //     与 cancellationToken 关联的 System.Threading.CancellationTokenSource 已释放。
        */
		public static Task<TResult> Run<TResult>(Func<TResult> function, CancellationToken cancellationToken);
        //
        /*:
        //     将在线程池上运行的指定工作排队，并返回代表该工作的 System.Threading.Tasks.Task`1 对象。
        //
        // 参数:
        //   function:
        //     以异步方式执行的工作。
        //
        // 类型参数:
        //   TResult:
        //     任务的返回类型。
        //
        // 返回结果:
        //     表示在线程池中排队执行的工作的任务对象。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public static Task<TResult> Run<TResult>(Func<TResult> function);
        //
        /*:
        //     等待提供的所有 System.Threading.Tasks.Task 对象完成执行过程。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     tasks 中的一个或多个 System.Threading.Tasks.Task 对象已释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。- 或 -tasks 参数为空数组。
        //
        //   T:System.AggregateException:
        //     至少一个 System.Threading.Tasks.Task 实例已取消。 如果任务已被取消， System.AggregateException 异常将包含
        //     System.OperationCanceledException 中的异常其 System.AggregateException.InnerExceptions
        //     集合。- 或 -在至少一个 System.Threading.Tasks.Task 实例的执行过程中引发了异常。
        */
		public static void WaitAll(params Task[] tasks);
        //
        /*:
        //     等待所有提供的可取消 System.Threading.Tasks.Task 对象在指定的时间间隔内完成执行。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   timeout:
        //     表示等待毫秒数的 System.TimeSpan，或表示 -1 毫秒（无限期等待）的 System.TimeSpan。
        //
        // 返回结果:
        //     如果在分配的时间内所有 true 实例都已完成执行，则为 System.Threading.Tasks.Task；否则为 false。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     tasks 中的一个或多个 System.Threading.Tasks.Task 对象已释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.AggregateException:
        //     至少一个 System.Threading.Tasks.Task 实例已取消。 如果任务已取消，则 System.AggregateException 在其
        //     System.AggregateException.InnerExceptions 集合中包含 System.OperationCanceledException。-
        //     或 -在至少一个 System.Threading.Tasks.Task 实例的执行过程中引发了异常。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     timeout 为 -1 毫秒以外的负数，表示无限期超时。- 或 -timeout 大于 System.Int32.MaxValue。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。- 或 -tasks 参数为空数组。
        */
		public static bool WaitAll(Task[] tasks, TimeSpan timeout);
        //
        /*:
        //     等待所有提供的 System.Threading.Tasks.Task 在指定的毫秒数内完成执行。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   millisecondsTimeout:
        //     等待的毫秒数，或为 System.Threading.Timeout.Infinite (-1)，表示无限期等待。
        //
        // 返回结果:
        //     如果在分配的时间内所有 true 实例都已完成执行，则为 System.Threading.Tasks.Task；否则为 false。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     tasks 中的一个或多个 System.Threading.Tasks.Task 对象已释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.AggregateException:
        //     至少一个 System.Threading.Tasks.Task 实例已取消。 如果任务已取消，则 System.AggregateException 在其
        //     System.AggregateException.InnerExceptions 集合中包含 System.OperationCanceledException。-
        //     或 -在至少一个 System.Threading.Tasks.Task 实例的执行过程中引发了异常。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsTimeout 是一个非 -1 的负数，而 -1 表示无限期超时。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。- 或 -tasks 参数为空数组。
        */
		public static bool WaitAll(Task[] tasks, int millisecondsTimeout);
        //
        /*:
        //     等待提供的所有 System.Threading.Tasks.Task 对象完成执行过程（除非取消等待）。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   cancellationToken:
        //     等待任务完成期间要观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 异常:
        //   T:System.OperationCanceledException:
        //     cancellationToken 已取消。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.AggregateException:
        //     至少一个 System.Threading.Tasks.Task 实例已取消。 如果任务已取消，则 System.AggregateException 在其
        //     System.AggregateException.InnerExceptions 集合中包含 System.OperationCanceledException。-
        //     或 -在至少一个 System.Threading.Tasks.Task 实例的执行过程中引发了异常。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。- 或 -tasks 参数为空数组。
        //
        //   T:System.ObjectDisposedException:
        //     tasks 中的一个或多个 System.Threading.Tasks.Task 对象已释放。
        */
		public static void WaitAll(Task[] tasks, CancellationToken cancellationToken);
        //
        /*:
        //     等待提供的所有 System.Threading.Tasks.Task 对象在指定的毫秒数内完成执行，或等到取消等待。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   millisecondsTimeout:
        //     等待的毫秒数，或为 System.Threading.Timeout.Infinite (-1)，表示无限期等待。
        //
        //   cancellationToken:
        //     等待任务完成期间要观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 返回结果:
        //     如果在分配的时间内所有 true 实例都已完成执行，则为 System.Threading.Tasks.Task；否则为 false。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     tasks 中的一个或多个 System.Threading.Tasks.Task 对象已释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.AggregateException:
        //     至少一个 System.Threading.Tasks.Task 实例已取消。 如果任务已取消，则 System.AggregateException 在其
        //     System.AggregateException.InnerExceptions 集合中包含 System.OperationCanceledException。-
        //     或 -在至少一个 System.Threading.Tasks.Task 实例的执行过程中引发了异常。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsTimeout 是一个非 -1 的负数，而 -1 表示无限期超时。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。- 或 -tasks 参数为空数组。
        //
        //   T:System.OperationCanceledException:
        //     cancellationToken 已取消。
        */
		public static bool WaitAll(Task[] tasks, int millisecondsTimeout, CancellationToken cancellationToken);
        //
        /*:
        //     等待提供的任一 System.Threading.Tasks.Task 对象完成执行过程。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        // 返回结果:
        //     tasks 数组中已完成的 System.Threading.Tasks.Task 对象的所有。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。
        */
		public static int WaitAny(params Task[] tasks);
        //
        /*:
        //     等待任何提供的 System.Threading.Tasks.Task 对象在指定的时间间隔内完成执行。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   timeout:
        //     表示等待毫秒数的 System.TimeSpan，或表示 -1 毫秒（无限期等待）的 System.TimeSpan。
        //
        // 返回结果:
        //     已完成的任务在 tasks 数组参数中的索引，如果发生超时，则为 -1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     timeout 为 -1 毫秒以外的负数，表示无限期超时。- 或 -timeout 大于 System.Int32.MaxValue。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。
        */
		public static int WaitAny(Task[] tasks, TimeSpan timeout);
        //
        /*:
        //     等待任何提供的 System.Threading.Tasks.Task 对象在指定的毫秒数内完成执行。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   millisecondsTimeout:
        //     等待的毫秒数，或为 System.Threading.Timeout.Infinite (-1)，表示无限期等待。
        //
        // 返回结果:
        //     已完成的任务在 tasks 数组参数中的索引，如果发生超时，则为 -1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsTimeout 是一个非 -1 的负数，而 -1 表示无限期超时。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。
        */
		public static int WaitAny(Task[] tasks, int millisecondsTimeout);
        //
        /*:
        //     等待提供的任何 System.Threading.Tasks.Task 对象完成执行过程（除非取消等待）。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   cancellationToken:
        //     等待任务完成期间要观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 返回结果:
        //     已完成的任务在 tasks 数组参数中的索引。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。
        //
        //   T:System.OperationCanceledException:
        //     cancellationToken 已取消。
        */
		public static int WaitAny(Task[] tasks, CancellationToken cancellationToken);
        //
        /*:
        //     等待提供的任何 System.Threading.Tasks.Task 对象在指定的毫秒数内完成执行，或等到取消标记取消。
        //
        // 参数:
        //   tasks:
        //     要等待的 System.Threading.Tasks.Task 实例的数组。
        //
        //   millisecondsTimeout:
        //     等待的毫秒数，或为 System.Threading.Timeout.Infinite (-1)，表示无限期等待。
        //
        //   cancellationToken:
        //     等待任务完成期间要观察的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 返回结果:
        //     已完成的任务在 tasks 数组参数中的索引，如果发生超时，则为 -1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     tasks 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsTimeout 是一个非 -1 的负数，而 -1 表示无限期超时。
        //
        //   T:System.ArgumentException:
        //     tasks 参数包含一个 null 元素。
        //
        //   T:System.OperationCanceledException:
        //     cancellationToken 已取消。
        */
		public static int WaitAny(Task[] tasks, int millisecondsTimeout, CancellationToken cancellationToken);
        //
        /*:
        * .. = await WhenAll(..)
		* 等待所有的 task 结束才返回
        */
		public static Task WhenAll(IEnumerable<Task> tasks);
		public static Task WhenAll(params Task[] tasks);
		public static Task<TResult[]> WhenAll<TResult>(IEnumerable<Task<TResult>> tasks);
		public static Task<TResult[]> WhenAll<TResult>(params Task<TResult>[] tasks);
		
		/*
		* 任务列表中只要有一个任务结束, 就结束列表并返回那个任务
		*/
		public static Task<Task> WhenAny(params Task[] tasks);
		public static Task<Task> WhenAny(IEnumerable<Task> tasks);
		public static Task<Task<TResult>> WhenAny<TResult>(params Task<TResult>[] tasks);
		public static Task<Task<TResult>> WhenAny<TResult>(IEnumerable<Task<TResult>> tasks);
        //
        /*:
        //     创建异步产生当前上下文的等待任务。
        //
        // 返回结果:
        //     等待时，上下文将异步转换回等待时的当前上下文。 如果当前 System.Threading.SynchronizationContext 不为 null，则将其视为当前上下文。
        //     否则，与当前执行任务关联的任务计划程序将视为当前上下文。
        */
		public static YieldAwaitable Yield();
        //
        /*:
        //     配置用于等待此 System.Threading.Tasks.Task的 awaiter。
        //
        // 参数:
        //   continueOnCapturedContext:
        //     尝试将延续任务封送回原始上下文，则为 true；否则为 false。
        //
        // 返回结果:
        //     用于的等待此任务的对象。
        [TargetedPatchingOptOut("Performance critical to inline across NGen image boundaries")]
        */
		public ConfiguredTaskAwaitable ConfigureAwait(bool continueOnCapturedContext);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成并返回一个值时根据指定的任务延续选项执行的延续任务。 延续任务接收调用方提供的状态信息和取消标记，并使用指定计划程序。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.CancellationToken。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        //
        //   T:System.ArgumentNullException:
        //     scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        //
        //   T:System.ObjectDisposedException:
        //     提供 System.Threading.CancellationToken 被释放。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, object, TResult> continuationFunction, object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时根据指定的任务延续选项执行的延续任务。 延续任务接收调用方提供的状态信息。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, object, TResult> continuationFunction, object state, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时异步执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        */
		public Task ContinueWith(Action<Task> continuationAction);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时可接收取消标记并以异步方式执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建该标记已被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        */
		public Task ContinueWith(Action<Task> continuationAction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时异步执行的延续任务。 延续任务使用指定计划程序。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。- 或 -scheduler 参数为 null。
        */
		public Task ContinueWith(Action<Task> continuationAction, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标任务完成时按照指定的 System.Threading.Tasks.TaskContinuationOptions 执行的延续任务。 延续任务会收到一个取消标记，并使用指定计划程序。
        //
        // 参数:
        //   continuationAction:
        //     根据在 continuationOptions 中指定的条件运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建该标记已被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task ContinueWith(Action<Task> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时接收调用方提供的状态信息并执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在任务完成时要运行的操作。 运行时，委托作为一个参数传递给完成的任务和调用方提供的状态对象。
        //
        //   state:
        //     一个表示由该延续操作使用的数据的对象。
        //
        // 返回结果:
        //     一个新的延续任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        */
		public Task ContinueWith(Action<Task, object> continuationAction, object state);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时接收调用方提供的状态信息和取消标记，并以异步方式执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续操作使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.CancellationToken。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        //
        //   T:System.ObjectDisposedException:
        //     提供 System.Threading.CancellationToken 被释放。
        */
		public Task ContinueWith(Action<Task, object> continuationAction, object state, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时接收调用方提供的状态信息并以异步方式执行的延续任务。 延续任务使用指定计划程序。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续操作使用的数据的对象。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        //
        //   T:System.ArgumentNullException:
        //     scheduler 参数为 null。
        */
		public Task ContinueWith(Action<Task, object> continuationAction, object state, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时接收调用方提供的状态信息并执行的延续任务。 延续任务根据一组指定的条件执行。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续操作使用的数据的对象。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task ContinueWith(Action<Task, object> continuationAction, object state, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标任务完成时按照指定的 System.Threading.Tasks.TaskContinuationOptions 执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     根据在 continuationOptions 中指定的条件运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task ContinueWith(Action<Task> continuationAction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时异步执行并返回一个值的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, TResult> continuationFunction);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成并返回一个值时异步执行的延续任务。 延续任务收到取消标记。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。- 或 -System.Threading.CancellationTokenSource
        //     创建该标记已被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, TResult> continuationFunction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时异步执行并返回一个值的延续任务。 延续任务使用指定计划程序。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, TResult> continuationFunction, TaskScheduler scheduler);
        //
        /*:
        //     创建一个按照指定延续任务选项执行并返回一个值的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     根据在 continuationOptions 中指定的条件运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个按照指定延续任务选项执行并返回一个值的延续任务。 延续任务被传入一个取消标记，并使用指定计划程序。
        //
        // 参数:
        //   continuationFunction:
        //     根据 continuationOptions. 中指定的条件运行函数。在运行时，委托将作为一个自变量传递给完成的任务。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.Tasks.TaskFactory.CancellationToken。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。- 或 -System.Threading.CancellationTokenSource
        //     创建该标记已被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成并返回一个值时接收调用方提供的状态信息并以异步方式执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, object, TResult> continuationFunction, object state);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时异步执行并返回一个值的延续任务。 延续任务接收调用方提供的状态信息和取消标记。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.CancellationToken。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        //
        //   T:System.ObjectDisposedException:
        //     提供 System.Threading.CancellationToken 被释放。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, object, TResult> continuationFunction, object state, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时异步执行的延续任务。 延续任务接收调用方提供的状态信息，并使用指定计划程序。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        //
        //   T:System.ArgumentNullException:
        //     scheduler 参数为 null。
        */
		public Task<TResult> ContinueWith<TResult>(Func<Task, object, TResult> continuationFunction, object state, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task 完成时接收调用方提供的状态信息和取消标记并执行的延续任务。 延续任务根据一组指定的条件执行，并使用指定的计划程序。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续操作使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的 System.Threading.CancellationToken。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        //
        //   T:System.ArgumentNullException:
        //     scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        //
        //   T:System.ObjectDisposedException:
        //     提供 System.Threading.CancellationToken 被释放。
        */
		public Task ContinueWith(Action<Task, object> continuationAction, object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     释放 System.Threading.Tasks.Task 类的当前实例所使用的所有资源。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     任务未处于最终状态之一 ︰ System.Threading.Tasks.TaskStatus.RanToCompletion, ，System.Threading.Tasks.TaskStatus.Faulted,
        //     ，或 System.Threading.Tasks.TaskStatus.Canceled。
        */
		public void Dispose();
        //
        /*:
        //     获取用于等待此 System.Threading.Tasks.Task 的 awaiter。
        //
        // 返回结果:
        //     一个 awaiter 实例。
        [TargetedPatchingOptOut("Performance critical to inline across NGen image boundaries")]
        */
		public TaskAwaiter GetAwaiter();
        //
        /*:
        //     对当前的 System.Threading.Tasks.Task 同步运行 System.Threading.Tasks.TaskScheduler。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task 实例。
        //
        //   T:System.InvalidOperationException:
        //     System.Threading.Tasks.Task 并非要启动的有效状态。 它可能已启动、执行或取消，或者它可能是以不支持直接计划的方式创建的。
        */
		public void RunSynchronously();
        //
        /*:
        //     对提供的 System.Threading.Tasks.Task 同步运行 System.Threading.Tasks.TaskScheduler。
        //
        // 参数:
        //   scheduler:
        //     尝试对其以内联方式运行此任务的计划程序。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task 实例。
        //
        //   T:System.ArgumentNullException:
        //     scheduler 参数为 null。
        //
        //   T:System.InvalidOperationException:
        //     System.Threading.Tasks.Task 并非要启动的有效状态。 它可能已启动、执行或取消，或者它可能是以不支持直接计划的方式创建的。
        */
		public void RunSynchronously(TaskScheduler scheduler);
        //
        /*:
        //     启动 System.Threading.Tasks.Task，并将它安排到当前的 System.Threading.Tasks.TaskScheduler
        //     中执行。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task 实例。
        //
        //   T:System.InvalidOperationException:
        //     System.Threading.Tasks.Task 并非要启动的有效状态。 它可能已启动、执行或取消，或者它可能是以不支持直接计划的方式创建的。
        */
		public void Start();
        //
        /*:
        //     启动 System.Threading.Tasks.Task，并将它安排到指定的 System.Threading.Tasks.TaskScheduler
        //     中执行。
        //
        // 参数:
        //   scheduler:
        //     要与之关联并执行此任务的 System.Threading.Tasks.TaskScheduler。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     scheduler 参数为 null。
        //
        //   T:System.InvalidOperationException:
        //     System.Threading.Tasks.Task 并非要启动的有效状态。 它可能已启动、执行或取消，或者它可能是以不支持直接计划的方式创建的。
        //
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task 实例。
        //
        //   T:System.Threading.Tasks.TaskSchedulerException:
        //     计划程序无法将此任务进行排队。
        */
		public void Start(TaskScheduler scheduler);
        //
        /*:
        //     等待 System.Threading.Tasks.Task 在指定的毫秒数内完成执行。
        //
        // 参数:
        //   millisecondsTimeout:
        //     等待的毫秒数，或为 System.Threading.Timeout.Infinite (-1)，表示无限期等待。
        //
        // 返回结果:
        //     如果在分配的时间内 true 完成执行，则为 System.Threading.Tasks.Task；否则为 false。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsTimeout 是一个非 -1 的负数，而 -1 表示无限期超时。
        //
        //   T:System.AggregateException:
        //     任务已取消。System.AggregateException.InnerExceptions 集合包含 System.Threading.Tasks.TaskCanceledException
        //     对象。- 或 -该任务的执行过程中引发异常。System.AggregateException.InnerExceptions 集合包含有关异常或异常的信息。
        */
		public bool Wait(int millisecondsTimeout);
        //
        /*:
        //     等待 System.Threading.Tasks.Task 完成执行过程。 如果在任务完成之前取消标记已取消，等待将终止。
        //
        // 参数:
        //   cancellationToken:
        //     等待任务完成期间要观察的取消标记。
        //
        // 异常:
        //   T:System.OperationCanceledException:
        //     cancellationToken 已取消。
        //
        //   T:System.ObjectDisposedException:
        //     该任务已被释放。
        //
        //   T:System.AggregateException:
        //     任务已取消。System.AggregateException.InnerExceptions 集合包含 System.Threading.Tasks.TaskCanceledException
        //     对象。- 或 -该任务的执行过程中引发异常。System.AggregateException.InnerExceptions 集合包含有关异常或异常的信息。
        */
		public void Wait(CancellationToken cancellationToken);
        //
        /*:
        //     等待 System.Threading.Tasks.Task 完成执行过程。 如果在任务完成之前超时间隔结束或取消标记已取消，等待将终止。
        //
        // 参数:
        //   millisecondsTimeout:
        //     等待的毫秒数，或为 System.Threading.Timeout.Infinite (-1)，表示无限期等待。
        //
        //   cancellationToken:
        //     等待任务完成期间要观察的取消标记。
        //
        // 返回结果:
        //     如果在分配的时间内 true 完成执行，则为 System.Threading.Tasks.Task；否则为 false。
        //
        // 异常:
        //   T:System.OperationCanceledException:
        //     cancellationToken 已取消。
        //
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     millisecondsTimeout 是一个非 -1 的负数，而 -1 表示无限期超时。
        //
        //   T:System.AggregateException:
        //     任务已取消。System.AggregateException.InnerExceptions 集合包含 System.Threading.Tasks.TaskCanceledException
        //     对象。- 或 -该任务的执行过程中引发异常。System.AggregateException.InnerExceptions 集合包含有关异常或异常的信息。
        */
		public bool Wait(int millisecondsTimeout, CancellationToken cancellationToken);
        //
        /*:
        //     等待 System.Threading.Tasks.Task 完成执行过程。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.AggregateException:
        //     任务已取消。System.AggregateException.InnerExceptions 集合包含 System.Threading.Tasks.TaskCanceledException
        //     对象。- 或 -该任务的执行过程中引发异常。System.AggregateException.InnerExceptions 集合包含有关异常或异常的信息。
        */
		public void Wait();
        //
        /*:
        //     等待 System.Threading.Tasks.Task 在指定的时间间隔内完成执行。
        //
        // 参数:
        //   timeout:
        //     表示等待毫秒数的 System.TimeSpan，或表示 -1 毫秒（无限期等待）的 System.TimeSpan。
        //
        // 返回结果:
        //     如果在分配的时间内 true 完成执行，则为 System.Threading.Tasks.Task；否则为 false。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     timeout 为 -1 毫秒以外的负数，表示无限期超时。- 或 -timeout 大于 System.Int32.MaxValue。
        //
        //   T:System.AggregateException:
        //     任务已取消。System.AggregateException.InnerExceptions 集合包含 System.Threading.Tasks.TaskCanceledException
        //     对象。- 或 -该任务的执行过程中引发异常。System.AggregateException.InnerExceptions 集合包含有关异常或异常的信息。
        */
		public bool Wait(TimeSpan timeout);
        //
        /*:
        //     释放 System.Threading.Tasks.Task，同时释放其所有非托管资源。
        //
        // 参数:
        //   disposing:
        //     一个布尔值，该值指示是否由于调用 System.Threading.Tasks.Task.Dispose 的原因而调用此方法。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     任务未处于最终状态之一 ︰ System.Threading.Tasks.TaskStatus.RanToCompletion, ，System.Threading.Tasks.TaskStatus.Faulted,
        //     ，或 System.Threading.Tasks.TaskStatus.Canceled。
        protected virtual void Dispose(bool disposing);
    }
}