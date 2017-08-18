

* (异步函数返回值)Task<TResult>.ContinueWith(Action<Task<TResult>> action)
/*
* 异步函数返回后, 可以用返回值调用这个函数. 参数 action 就是异步函数的返回值
ContinueWith(t => {
 TResult result = action.Result;
 ....
 // 这里的操作又是在另外一个线程中执行
 ...
 });
*/

namespace System.Threading.Tasks
{
    //
    /*:
    //     表示一个可以返回值的异步操作。
    //
    // 类型参数:
    //   TResult:
    //     此 System.Threading.Tasks.Task`1 生成的结果的类型。
    [DebuggerDisplay("Id = {Id}, Status = {Status}, Method = {DebuggerDisplayMethodDescription}, Result = {DebuggerDisplayResultDescription}")]
    [DebuggerTypeProxy(typeof(Tasks.SystemThreadingTasks_FutureDebugView<>))]
    */
		public class Task<TResult> : Task
    {
        //
        /*:
        //     使用指定的函数初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<TResult> function);
        //
        /*:
        //     使用指定的函数初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   cancellationToken:
        //     将指派给此任务的 System.Threading.CancellationToken。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<TResult> function, CancellationToken cancellationToken);
        //
        /*:
        //     使用指定的函数和创建选项初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<TResult> function, TaskCreationOptions creationOptions);
        //
        /*:
        //     使用指定的函数和状态初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   state:
        //     一个表示由该操作使用的数据的对象。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<object, TResult> function, object state);
        //
        /*:
        //     使用指定的函数和创建选项初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   cancellationToken:
        //     将指派给新任务的 System.Threading.CancellationToken。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<TResult> function, CancellationToken cancellationToken, TaskCreationOptions creationOptions);
        //
        /*:
        //     使用指定的操作、状态和选项初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   state:
        //     一个表示将由此函数使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给此新任务的 System.Threading.CancellationToken。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<object, TResult> function, object state, CancellationToken cancellationToken);
        //
        /*:
        //     使用指定的操作、状态和选项初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   state:
        //     一个表示将由此函数使用的数据的对象。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<object, TResult> function, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     使用指定的操作、状态和选项初始化新的 System.Threading.Tasks.Task`1。
        //
        // 参数:
        //   function:
        //     表示要在任务中执行的代码的委托。 在完成此函数后，该任务的 System.Threading.Tasks.Task`1.Result 属性将设置为返回此函数的结果值。
        //
        //   state:
        //     一个表示将由此函数使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给此新任务的 System.Threading.CancellationToken。
        //
        //   creationOptions:
        //     用于自定义任务的行为的 System.Threading.Tasks.TaskCreationOptions。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     System.Threading.CancellationTokenSource 创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定的值无效 System.Threading.Tasks.TaskCreationOptions。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task(Func<object, TResult> function, object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions);

        //
        /*:
        //     提供对用于创建和配置 System.Threading.Tasks.Task`1 实例的工厂方法的访问。
        //
        // 返回结果:
        //     一个工厂对象，可创建多种 System.Threading.Tasks.Task`1 对象。
        */
		public static TaskFactory<TResult> Factory { get; }
        //
        /*:
        //     获取此 System.Threading.Tasks.Task`1 的结果值。
        //
        // 返回结果:
        //     此 System.Threading.Tasks.Task`1 的结果值，该值类型与任务参数类型相同。
        //
        // 异常:
        //   T:System.AggregateException:
        //     任务已取消。System.AggregateException.InnerExceptions 集合包含 System.Threading.Tasks.TaskCanceledException
        //     对象。- 或 -该任务的执行过程中引发异常。System.AggregateException.InnerExceptions 集合包含有关异常或异常的信息。
        [DebuggerBrowsable(DebuggerBrowsableState.Never)]
        */
		public TResult Result { get; }

        /*
		* 如果异步函数返回值调用ConfigureAwait(false), 那么新线程的代码将无法访问 UI 线程的东西.得到的都是NULL 貌似是这样的
        */
		public ConfiguredTaskAwaitable<TResult> ConfigureAwait(bool continueOnCapturedContext);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给新任务的 System.Threading.CancellationToken。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TNewResult:
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
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, object, TNewResult> continuationFunction, object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 类型参数:
        //   TNewResult:
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
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, object, TNewResult> continuationFunction, object state, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TNewResult:
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
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, object, TNewResult> continuationFunction, object state, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        //   cancellationToken:
        //     将指派给新任务的 System.Threading.CancellationToken。
        //
        // 类型参数:
        //   TNewResult:
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
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, object, TNewResult> continuationFunction, object state, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
        //
        //   state:
        //     一个表示由该延续功能使用的数据的对象。
        //
        // 类型参数:
        //   TNewResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        */
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, object, TNewResult> continuationFunction, object state);
        //
        /*:
        //     创建根据 continuationOptions 中指定的条件加以执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     根据 continuationOptions 中指定的条件运行函数。在运行时，委托将作为一个参数传递给此完成的任务。
        //
        //   cancellationToken:
        //     将指派给新任务的 System.Threading.CancellationToken。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TNewResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。- 或 -System.Threading.CancellationTokenSource
        //     创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, TNewResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建根据 continuationOptions 中指定的条件加以执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     根据 continuationOptions 中指定的条件运行函数。在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 类型参数:
        //   TNewResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, TNewResult> continuationFunction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时异步执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 类型参数:
        //   TNewResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        */
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, TNewResult> continuationFunction, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时异步执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   cancellationToken:
        //     将指派给新任务的 System.Threading.CancellationToken。
        //
        // 类型参数:
        //   TNewResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。- 或 -System.Threading.CancellationTokenSource
        //     创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        */
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, TNewResult> continuationFunction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时异步执行的延续任务。
        //
        // 参数:
        //   continuationFunction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的函数。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        // 类型参数:
        //   TNewResult:
        //     延续任务生成的结果的类型。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。
        //
        //   T:System.ArgumentNullException:
        //     continuationFunction 参数为 null。
        */
		public Task<TNewResult> ContinueWith<TNewResult>(Func<Task<TResult>, TNewResult> continuationFunction);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
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
		public Task ContinueWith(Action<Task<TResult>, object> continuationAction, object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
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
		public Task ContinueWith(Action<Task<TResult>, object> continuationAction, object state, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
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
		public Task ContinueWith(Action<Task<TResult>, object> continuationAction, object state, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 运行时，将传递委托，如完成的任务一样，调用方提供的状态对象（如参数）。
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
		public Task ContinueWith(Action<Task<TResult>, object> continuationAction, object state, CancellationToken cancellationToken);
        //
        /*:
        //     创建根据 continuationOptions 中指定的条件加以执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     根据在 continuationOptions 中指定的条件运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
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
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。- 或 -System.Threading.CancellationTokenSource
        //     创建 cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task ContinueWith(Action<Task<TResult>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建根据 continuationOptions 中指定的条件加以执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 continuationOptions 中指定的条件的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   continuationOptions:
        //     用于设置计划延续任务的时间以及延续任务的工作方式的选项。 这包括条件（如 System.Threading.Tasks.TaskContinuationOptions.OnlyOnCanceled）和执行选项（如
        //     System.Threading.Tasks.TaskContinuationOptions.ExecuteSynchronously）。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定的值无效 System.Threading.Tasks.TaskContinuationOptions。
        */
		public Task ContinueWith(Action<Task<TResult>> continuationAction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时异步执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        //   scheduler:
        //     要与延续任务关联并用于其执行过程的 System.Threading.Tasks.TaskScheduler。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。- 或 -scheduler 参数为 null。
        */
		public Task ContinueWith(Action<Task<TResult>> continuationAction, TaskScheduler scheduler);
        //
        /*:
        //     创建一个在目标 System.Threading.Tasks.Task`1 完成时异步执行的可取消延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 在运行时，委托作为一个参数传递给完成的任务。
        //
        //   cancellationToken:
        //     传递给新的延续任务的取消标记。
        //
        // 返回结果:
        //     一个新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。- 或 -System.Threading.CancellationTokenSource
        //     创建 cancellationToken 已被释放。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        */
		public Task ContinueWith(Action<Task<TResult>> continuationAction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个在目标任务完成时异步执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 在运行时，委托将作为一个参数传递给完成的任务。
        //
        // 返回结果:
        //     一个新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     已释放了 System.Threading.Tasks.Task`1。
        //
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        */
		public Task ContinueWith(Action<Task<TResult>> continuationAction);
        //
        /*:
        //     创建一个传递了状态信息并在目标 System.Threading.Tasks.Task`1 完成时执行的延续任务。
        //
        // 参数:
        //   continuationAction:
        //     在 System.Threading.Tasks.Task`1 完成时要运行的操作。 运行时，委托作为一个参数传递给完成的任务和调用方提供的状态对象。
        //
        //   state:
        //     一个表示由该延续操作使用的数据的对象。
        //
        // 返回结果:
        //     一个新的延续 System.Threading.Tasks.Task。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     continuationAction 参数为 null。
        */
		public Task ContinueWith(Action<Task<TResult>, object> continuationAction, object state);
        
		/*
		* 在 UI 线程中调用 asyncFunc().GetAwaiter(); 就会阻塞主线程
		*/
		public TaskAwaiter<TResult> GetAwaiter();
    }
}