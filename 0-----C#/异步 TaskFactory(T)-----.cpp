#region 程序集 mscorlib, Version=4.0.0.0, Culture=neutral, */
		publicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.1\mscorlib.dll
#endregion

namespace System.Threading.Tasks
{
    //
    /*:
    //     提供对创建和计划 System.Threading.Tasks.Task`1 对象的支持。
    //
    // 类型参数:
    //   TResult:
    //     此类的方法创建的 System.Threading.Tasks.Task`1 对象的返回值。
    */
		public class TaskFactory<TResult>
    {
        //
        /*:
        //     使用默认配置初始化 System.Threading.Tasks.TaskFactory`1 实例。
        */
		public TaskFactory();
        //
        /*:
        //     使用默认配置初始化 System.Threading.Tasks.TaskFactory`1 实例。
        //
        // 参数:
        //   cancellationToken:
        //     将指派给由此 System.Threading.Tasks.TaskFactory 创建的任务的默认取消标记（除非在调用工厂方法时显式指定另一个取消标记）。
        */
		public TaskFactory(CancellationToken cancellationToken);
        //
        /*:
        //     使用指定配置初始化 System.Threading.Tasks.TaskFactory`1 实例。
        //
        // 参数:
        //   scheduler:
        //     要用于计划使用此 System.Threading.Tasks.TaskFactory`1 创建的任何任务的计划程序。 一个 null 值，该值指示应使用当前
        //     System.Threading.Tasks.TaskScheduler。
        */
		public TaskFactory(TaskScheduler scheduler);
        //
        /*:
        //     使用指定配置初始化 System.Threading.Tasks.TaskFactory`1 实例。
        //
        // 参数:
        //   creationOptions:
        //     在使用此 System.Threading.Tasks.TaskFactory`1 创建任务时要使用的默认选项。
        //
        //   continuationOptions:
        //     在使用此 System.Threading.Tasks.TaskFactory`1 创建任务时要使用的默认选项。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 或 continuationOptions 指定了无效值。
        */
		public TaskFactory(TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     使用指定配置初始化 System.Threading.Tasks.TaskFactory`1 实例。
        //
        // 参数:
        //   cancellationToken:
        //     将指派给由此 System.Threading.Tasks.TaskFactory 创建的任务的默认取消标记（除非在调用工厂方法时显式指定另一个取消标记）。
        //
        //   creationOptions:
        //     在使用此 System.Threading.Tasks.TaskFactory`1 创建任务时要使用的默认选项。
        //
        //   continuationOptions:
        //     在使用此 System.Threading.Tasks.TaskFactory`1 创建任务时要使用的默认选项。
        //
        //   scheduler:
        //     要用于计划使用此 System.Threading.Tasks.TaskFactory`1 创建的任何任务的默认计划程序。 null 值指示应使用 System.Threading.Tasks.TaskScheduler.Current。
        //
        // 异常:
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 或 continuationOptions 指定了无效值。
        */
		public TaskFactory(CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);

        //
        /*:
        //     获取此任务工厂的任务计划程序。
        //
        // 返回结果:
        //     此任务工厂的任务计划程序。
        */
		public TaskScheduler Scheduler { get; }
        //
        /*:
        //     获取此任务工厂的默认取消标记。
        //
        // 返回结果:
        //     此任务工厂的默认取消标记。
        */
		public CancellationToken CancellationToken { get; }
        //
        /*:
        //     获取此任务工厂的 System.Threading.Tasks.TaskCreationOptions 枚举值。
        //
        // 返回结果:
        //     指定此任务工厂的默认创建选项的枚举值之一。
        */
		public TaskCreationOptions CreationOptions { get; }
        //
        /*:
        //     获取此任务工厂的 System.Threading.Tasks.TaskContinuationOptions 枚举值。
        //
        // 返回结果:
        //     指定此任务工厂的默认延续选项的枚举值之一。
        */
		public TaskContinuationOptions ContinuationOptions { get; }

        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。 NotOn* 或 OnlyOn* 值均无效。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定值无效。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAll(Task[] tasks, Func<Task[], TResult> continuationFunction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。 NotOn* 或 OnlyOn* 值均无效。
        //
        //   scheduler:
        //     用于计划所创建的延续任务的计划程序。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定值无效。
        //
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        */
		public Task<TResult> ContinueWhenAll<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>[], TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。 NotOn* 或 OnlyOn* 值均无效。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定值无效。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAll<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>[], TResult> continuationFunction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAll<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>[], TResult> continuationFunction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAll<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>[], TResult> continuationFunction);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。 NotOn* 或 OnlyOn* 值均无效。
        //
        //   scheduler:
        //     用于计划所创建的延续任务的计划程序。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 指定了无效的值。
        //
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        */
		public Task<TResult> ContinueWhenAll(Task[] tasks, Func<Task[], TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAll(Task[] tasks, Func<Task[], TResult> continuationFunction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个延续任务，它将在提供的一组任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的所有任务完成时要异步执行的函数委托。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAll(Task[] tasks, Func<Task[], TResult> continuationFunction);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。NotOn* 或 OnlyOn* 值均无效。
        //
        //   scheduler:
        //     用于计划所创建的延续 System.Threading.Tasks.TaskScheduler 的 System.Threading.Tasks.Task`1。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定 TaskContinuationOptions 值无效。
        //
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        */
		public Task<TResult> ContinueWhenAny<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。NotOn* 或 OnlyOn* 值均无效。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定无效的枚举值。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        */
		public Task<TResult> ContinueWhenAny<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        */
		public Task<TResult> ContinueWhenAny<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        // 类型参数:
        //   TAntecedentResult:
        //     以前的 tasks 结果的类型。
        //
        // 返回结果:
        //     新的延续 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        */
		public Task<TResult> ContinueWhenAny<TAntecedentResult>(Task<TAntecedentResult>[] tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。NotOn* 或 OnlyOn* 值均无效。
        //
        //   scheduler:
        //     用于计划所创建的延续任务的任务计划程序。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定了无效 System.Threading.Tasks.TaskContinuationOptions 值。
        //
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        */
		public Task<TResult> ContinueWhenAny(Task[] tasks, Func<Task, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        //   continuationOptions:
        //     控制所创建的延续任务的行为的枚举值之一。NotOn* 或 OnlyOn* 值均无效。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     continuationOptions 参数指定无效的枚举值。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        */
		public Task<TResult> ContinueWhenAny(Task[] tasks, Func<Task, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        //   cancellationToken:
        //     将指派给新的延续任务的取消标记。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。- 或 -System.Threading.CancellationTokenSource 创建 cancellationToken
        //     被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组为 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值。- 或 -tasks 数组为空。
        */
		public Task<TResult> ContinueWhenAny(Task[] tasks, Func<Task, TResult> continuationFunction, CancellationToken cancellationToken);
        //
        /*:
        //     创建一个延续任务，它将在提供的组中的任何任务完成后马上开始。
        //
        // 参数:
        //   tasks:
        //     在一个任务完成时继续执行的任务所在的数组。
        //
        //   continuationFunction:
        //     在 tasks 数组中的一个任务完成时要异步执行的函数委托。
        //
        // 返回结果:
        //     新的延续任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     中的元素之一 tasks 数组已被释放。
        //
        //   T:System.ArgumentNullException:
        //     tasks 数组是 null。- 或 -continuationFunction 参数为 null。
        //
        //   T:System.ArgumentException:
        //     tasks 数组包含一个 null 值或为空。
        */
		public Task<TResult> ContinueWhenAny(Task[] tasks, Func<Task, TResult> continuationFunction);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   arg1:
        //     传递给 beginMethod 委托的第一个参数。
        //
        //   arg2:
        //     传递给 beginMethod 委托的第二个参数。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        //   creationOptions:
        //     一个对象，用于控制所创建的 System.Threading.Tasks.Task`1 的行为。
        //
        // 类型参数:
        //   TArg1:
        //     传递给 beginMethod 委托的第二个参数的类型。
        //
        //   TArg2:
        //     传递给 beginMethod 委托的第一个参数的类型。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> FromAsync<TArg1, TArg2>(Func<TArg1, TArg2, AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建一个任务，它在指定的 System.IAsyncResult 完成时执行一个结束方法函数。
        //
        // 参数:
        //   asyncResult:
        //     System.IAsyncResult，完成它时将触发对 endMethod 的处理。
        //
        //   endMethod:
        //     用于处理完成的 asyncResult 的函数委托。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        //   scheduler:
        //     用于计划将执行结束方法的任务计划程序。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     asyncResult 参数为 null。- 或 -endMethod 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod, TaskCreationOptions creationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   arg1:
        //     传递给 beginMethod 委托的第一个参数。
        //
        //   arg2:
        //     传递给 beginMethod 委托的第二个参数。
        //
        //   arg3:
        //     传递给 beginMethod 委托的第三个参数。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        // 类型参数:
        //   TArg1:
        //     传递给 beginMethod 委托的第二个参数的类型。
        //
        //   TArg2:
        //     传递给 beginMethod 委托的第三个参数的类型。
        //
        //   TArg3:
        //     传递给 beginMethod 委托的第一个参数的类型。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        */
		public Task<TResult> FromAsync<TArg1, TArg2, TArg3>(Func<TArg1, TArg2, TArg3, AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, object state);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   arg1:
        //     传递给 beginMethod 委托的第一个参数。
        //
        //   arg2:
        //     传递给 beginMethod 委托的第二个参数。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        // 类型参数:
        //   TArg1:
        //     传递给 beginMethod 委托的第二个参数的类型。
        //
        //   TArg2:
        //     传递给 beginMethod 委托的第一个参数的类型。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        */
		public Task<TResult> FromAsync<TArg1, TArg2>(Func<TArg1, TArg2, AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, object state);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   arg1:
        //     传递给 beginMethod 委托的第一个参数。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        // 类型参数:
        //   TArg1:
        //     传递给 beginMethod 委托的第一个参数的类型。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> FromAsync<TArg1>(Func<TArg1, AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   arg1:
        //     传递给 beginMethod 委托的第一个参数。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        // 类型参数:
        //   TArg1:
        //     传递给 beginMethod 委托的第一个参数的类型。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        */
		public Task<TResult> FromAsync<TArg1>(Func<TArg1, AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, object state);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        // 返回结果:
        //     创建的表示异步操作的 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> FromAsync(Func<AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        */
		public Task<TResult> FromAsync(Func<AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, object state);
        //
        /*:
        //     创建一个任务，它表示符合异步编程模型模式的成对的开始和结束方法。
        //
        // 参数:
        //   beginMethod:
        //     用于启动异步操作的委托。
        //
        //   endMethod:
        //     用于结束异步操作的委托。
        //
        //   arg1:
        //     传递给 beginMethod 委托的第一个参数。
        //
        //   arg2:
        //     传递给 beginMethod 委托的第二个参数。
        //
        //   arg3:
        //     传递给 beginMethod 委托的第三个参数。
        //
        //   state:
        //     一个包含由 beginMethod 委托使用的数据的对象。
        //
        //   creationOptions:
        //     一个对象，用于控制所创建的任务的行为。
        //
        // 类型参数:
        //   TArg1:
        //     传递给 beginMethod 委托的第二个参数的类型。
        //
        //   TArg2:
        //     传递给 beginMethod 委托的第三个参数的类型。
        //
        //   TArg3:
        //     传递给 beginMethod 委托的第一个参数的类型。
        //
        // 返回结果:
        //     创建的表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     beginMethod 参数为 null。- 或 -endMethod 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> FromAsync<TArg1, TArg2, TArg3>(Func<TArg1, TArg2, TArg3, AsyncCallback, object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建一个任务，它在指定的 System.IAsyncResult 完成时执行一个结束方法函数。
        //
        // 参数:
        //   asyncResult:
        //     System.IAsyncResult，完成它时将触发对 endMethod 的处理。
        //
        //   endMethod:
        //     用于处理完成的 asyncResult 的函数委托。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        // 返回结果:
        //     表示异步操作的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     asyncResult 参数为 null。- 或 -endMethod 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建一个任务，它在指定的 System.IAsyncResult 完成时执行一个结束方法函数。
        //
        // 参数:
        //   asyncResult:
        //     System.IAsyncResult，完成它时将触发对 endMethod 的处理。
        //
        //   endMethod:
        //     用于处理完成的 asyncResult 的函数委托。
        //
        // 返回结果:
        //     表示异步操作的 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     asyncResult 参数为 null。- 或 -endMethod 参数为 null。
        */
		public Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task<TResult> StartNew(Func<TResult> function);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   cancellationToken:
        //     将指派给新的任务的取消标记。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     取消标记源创建cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task<TResult> StartNew(Func<TResult> function, CancellationToken cancellationToken);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   state:
        //     包含 function 委托所用数据的对象。
        //
        //   cancellationToken:
        //     将指派给新的任务的取消标记。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     取消标记源创建cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task<TResult> StartNew(Func<object, TResult> function, object state, CancellationToken cancellationToken);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   cancellationToken:
        //     将指派给新的任务的取消标记。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        //   scheduler:
        //     用于计划所创建的任务的任务计划程序。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     取消标记源创建cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> StartNew(Func<TResult> function, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   state:
        //     包含 function 委托所用数据的对象。
        //
        //   cancellationToken:
        //     将指派给新的任务的取消标记。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        //   scheduler:
        //     用于计划所创建的任务的任务计划程序。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ObjectDisposedException:
        //     取消标记源创建cancellationToken 被释放。
        //
        //   T:System.ArgumentNullException:
        //     function 参数为 null。- 或 -scheduler 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> StartNew(Func<object, TResult> function, object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        // 返回结果:
        //     已启动的 System.Threading.Tasks.Task`1。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> StartNew(Func<TResult> function, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   state:
        //     包含 function 委托所用数据的对象。
        //
        //   creationOptions:
        //     控制所创建的任务的行为的枚举值之一。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        //
        //   T:System.ArgumentOutOfRangeException:
        //     creationOptions 参数指定值无效。
        */
		public Task<TResult> StartNew(Func<object, TResult> function, object state, TaskCreationOptions creationOptions);
        //
        /*:
        //     创建并启动 任务。
        //
        // 参数:
        //   function:
        //     一个函数委托，可返回能够通过任务获得的将来结果。
        //
        //   state:
        //     包含 function 委托所用数据的对象。
        //
        // 返回结果:
        //     已启动的任务。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     function 参数为 null。
        */
		public Task<TResult> StartNew(Func<object, TResult> function, object state);
    }
}