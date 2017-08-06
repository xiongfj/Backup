#region 程序集 System.Web, Version=4.0.0.0, Culture=neutral, */
		publicKeyToken=b03f5f7f11d50a3a
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.2\System.Web.dll
#endregion

using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Security.Principal;
using System.Threading.Tasks;
using System.Web.Caching;
using System.Web.Configuration;
using System.Web.Instrumentation;
using System.Web.Profile;
using System.Web.SessionState;
using System.Web.WebSockets;

namespace System.Web
{
    //
    /*
    * HttpContext类它对Request、Respose、Server等等都进行了封装,并保证在整个请求周期内都可以随时随地的调用
	* 为 IHttpHandler 和 IHttpModule 体统 HttpContext 使用
	* 该类对象生存周期：从客户端用户点击并产生了一个向服务器发送请求开始 -> 服务器处理完请求并生成返回到客户端为止
    */
	public sealed class HttpContext : IServiceProvider, IPrincipalContainer
    {
        /*
        //     使用指定的辅助请求对象初始化 System.Web.HttpContext 类的新实例。
        //
        // 参数:
        //   wr:
        //     当前 HTTP 请求的 System.Web.HttpWorkerRequest 对象。
        */
		public HttpContext(HttpWorkerRequest wr);
        /*
        //     使用指定的请求和响应对象初始化 System.Web.HttpContext 类的新实例。
        //
        // 参数:
        //   request:
        //     当前 HTTP 请求的 System.Web.HttpRequest 对象。
        //
        //   response:
        //     当前 HTTP 请求的 System.Web.HttpResponse 对象。
        */
		public HttpContext(HttpRequest request, HttpResponse response);
        /*
        //     为当前 HTTP 请求获取或设置 System.Web.HttpContext 对象。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Web.HttpContext 实例。
        */
		public static HttpContext Current { get; set; }
        /*
        //     为当前 HTTP 请求获取 System.Web.HttpApplicationState 对象。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Web.HttpApplicationState。若要获取当前 HTTP 请求的 System.Web.HttpApplication
        //     对象，请使用 System.Web.HttpContext.ApplicationInstance。 （ASP.NET 使用 ApplicationInstance
        //     代替 Application 作为属性名来引用当前的 System.Web.HttpApplication 实例，以避免 ASP.NET 与经典 ASP
        //     之间产生混淆。 在经典 ASP 中，Application 引用全局应用程序状态字典。）
        */
		public HttpApplicationState Application { get; }
        /*
        //     获取或设置负责处理 HTTP 请求的 System.Web.IHttpHandler 对象。
        //
        // 返回结果:
        //     负责处理 HTTP 请求的 System.Web.IHttpHandler。
        */
		public IHttpHandler Handler { get; set; }
        /*
        //     获取父处理程序的 System.Web.IHttpHandler 对象。
        //
        // 返回结果:
        //     System.Web.IHttpHandler 实例，如果未找到上一个处理程序，则为 null。
        */
		public IHttpHandler PreviousHandler { get; }
        /*
        //     获取表示当前正在执行的处理程序的 System.Web.IHttpHandler 对象。
        //
        // 返回结果:
        //     一个 System.Web.IHttpHandler，表示当前正在执行的处理程序。
        */
		public IHttpHandler CurrentHandler { get; }
        /*
        //     为当前 HTTP 请求获取 System.Web.HttpRequest 对象。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Web.HttpRequest。
        //
        // 异常:
        //   T:System.Web.HttpException:
        //     在集成模式下在 IIS 7 下运行 Web 应用程序。
        */
		public HttpRequest Request { get; }
        /*
        //     获取当前 HTTP 响应的 System.Web.HttpResponse 对象。
        //
        // 返回结果:
        //     当前 HTTP 响应的 System.Web.HttpResponse。
        //
        // 异常:
        //   T:System.Web.HttpException:
        //     在集成模式下在 IIS 7 下运行 Web 应用程序。
        */
		public HttpResponse Response { get; }
        /*
        //     获取当前 HTTP 响应的 System.Web.TraceContext 对象。
        //
        // 返回结果:
        //     当前 HTTP 响应的 System.Web.TraceContext。
        */
		public TraceContext Trace { get; }
		
        /* 可以通过它来存储一些临时的数据
        * 获取可用于在 HTTP 请求过程中在 System.Web.IHttpModule 接口
		* 和 System.Web.IHttpHandler 接口之间组织和共享数据的键/值集合。
		例如:
			----------	test.cs: 	// 存储数据到 Items
			....
			HttpContext.Current.Items["TransferName"] = 某个 List<string> 数据;
			Server.Transfer("Index.aspx");
			// Response.Redirect("Index.aspx"); 如果使用这个, 客户端会重新发送请求, 所以 Index.aspx 内就无法获取数据!!
			....
			---------- Index.aspx:	// 获取 Items 数据
			..
			List<string> list = HttpContext.Current.Items["TransferName"] as List<string>;
			..
        */
		public IDictionary Items { get; }
        /*
        //     为当前 HTTP 请求获取 System.Web.SessionState.HttpSessionState 对象。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Web.SessionState.HttpSessionState 对象。
        */
		public HttpSessionState Session { get; }
        /*
        //     获取提供用于处理 Web 请求的方法的 System.Web.HttpServerUtility 对象。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Web.HttpServerUtility。
        */
		public HttpServerUtility Server { get; }
        /*
        //     获取在处理 HTTP 请求的过程中累积的错误数组。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Exception 对象数组。
        */
		public Exception[] AllErrors { get; }
        /*
        //     为当前 HTTP 请求获取或设置 System.Web.HttpApplication 对象。
        //
        // 返回结果:
        //     当前 HTTP 请求的 System.Web.HttpApplication。ASP.NET 使用 ApplicationInstance 代替 Application
        //     作为属性名来引用当前的 System.Web.HttpApplication 实例，以避免 ASP.NET 与经典 ASP 之间产生混淆。 在经典 ASP
        //     中，Application 引用全局应用程序状态字典。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     在集成模式下，在 IIS 7.0 下运行 Web 应用程序并尝试将属性值从非 null 值赋予更改 null。
        */
		public HttpApplication ApplicationInstance { get; set; }
        /*
        //     获取或设置当前 HTTP 请求的安全信息。
        //
        // 返回结果:
        //     当前 HTTP 请求的安全信息。
        */
		public IPrincipal User { get; set; }
        /*
        //     获取当前用户配置文件的 System.Web.Profile.ProfileBase 对象。
        //
        // 返回结果:
        //     如果应用程序配置文件包含配置文件的属性的定义，则为 System.Web.Profile.ProfileBase；否则为 null。
        */
		public ProfileBase Profile { get; }
        /*
        //     获取或设置一个值，该值指定 System.Web.Security.UrlAuthorizationModule 对象是否应跳过对当前请求的授权检查。
        //
        // 返回结果:
        //     如果 System.Web.Security.UrlAuthorizationModule 应跳过授权检查，则为 true；否则为 false。 默认值为
        //     false。
        */
		public bool SkipAuthorization { get; set; }
        /*
        //     获取一个值，该值指示当前 HTTP 请求是否处于调试模式。
        //
        // 返回结果:
        //     如果请求处于调试模式，则为 true；否则，为 false。
        */
		public bool IsDebuggingEnabled { get; }
        /*
        //     获取一个值，该值指示是否已为当前 HTTP 请求启用自定义错误。
        //
        // 返回结果:
        //     如果启用了自定义错误，则为 true；否则，为 false。
        */
		public bool IsCustomErrorEnabled { get; }
        /*
        //     获取当前 HTTP 请求的初始时间戳。
        //
        // 返回结果:
        //     当前 HTTP 请求的时间戳。
        */
		public DateTime Timestamp { get; }
        /*
        //     获取当前应用程序域的 System.Web.Caching.Cache 对象。
        //
        // 返回结果:
        //     当前应用程序域的 System.Web.Caching.Cache。
        */
		public Cache Cache { get; }
        /*
        //     获取此要求的页检测服务实例的引用。
        //
        // 返回结果:
        //     此请求的页检测服务实例。
        */
		public PageInstrumentationService PageInstrumentation { get; }
        /*
        //     获取或设置一个值，此值指示 ASP.NET 运行时是否应在请求超时时，调用为该请求提供服务的线程上的 System.Threading.Thread.Abort。
        //
        // 返回结果:
        //     如果在线程超时时调用 System.Threading.Thread.Abort，则为 true；否则为 false。 默认值为 true。
        */
		public bool ThreadAbortOnTimeout { get; set; }
        /*
        //     获取在处理 HTTP 请求的过程中累积的第一个错误（如果有）。
        //
        // 返回结果:
        //     当前 HTTP 请求/响应过程的第一个 System.Exception；如果在处理 HTTP 请求期间没有发生任何错误，则为 null。 默认值为 null。
        */
		public Exception Error { get; }
        /*
        //     获取或设置一个值，此值指示 ASP.NET 请求处理过程中是否允许非预期的异步操作。
        //
        // 返回结果:
        //     当异步 API 在不是预期的时间使用时 ASP.NET 将引发异常，则为 false，否则为 true。 默认值为 false。
        [EditorBrowsable(EditorBrowsableState.Advanced)]
        */
		public bool AllowAsyncDuringSyncStages { get; set; }
        /*
        //     在 System.Web.HttpApplication 事件完成处理之后获取 ASP.NET 管道的当前进程点的值。
        //
        // 返回结果:
        //     如果启用了自定义错误，则为 true；否则，为 false。
        //
        // 异常:
        //   T:System.PlatformNotSupportedException:
        //     该操作所需要的集成的管道模式 IIS 7.0 并且至少.NET Framework 3.0。
        */
		public bool IsPostNotification { get; }
        /*
        //     获取一个 System.Web.RequestNotification 值，该值指示当前正在处理的 System.Web.HttpApplication
        //     事件。
        //
        // 返回结果:
        //     System.Web.RequestNotification 值之一。
        //
        // 异常:
        //   T:System.PlatformNotSupportedException:
        //     该操作需要在集成的管道模式下 IIS 7.0 并且至少.NET Framework 版本 3.0。
        */
		public RequestNotification CurrentNotification { get; }
        /*
        //     获取用于 System.Web.WebSockets.AspNetWebSocket 连接而从服务器发送到客户端的协商协议。
        //
        // 返回结果:
        //     协商协议。
        */
		public string WebSocketNegotiatedProtocol { get; }
        /*
        //     获取客户要求的子协议列表的有序列表。
        //
        // 返回结果:
        //     请求的协议，如果不是 System.Web.WebSockets.AspNetWebSocket 请求，或者列表不存在则为 null。
        */
		public IList<string> WebSocketRequestedProtocols { get; }
        /*
        //     获取指示连接是否从 HTTP 连接升级到 System.Web.WebSockets.AspNetWebSocket 连接的值。
        //
        // 返回结果:
        //     如果连接正在升级，则为 true；否则为 false。
        */
		public bool IsWebSocketRequestUpgrading { get; }
        /*
        //     获取一个值，该值指示此请求是否是一个 System.Web.WebSockets.AspNetWebSocket 请求。
        //
        // 返回结果:
        //     如果该请求是一个 System.Web.WebSockets.AspNetWebSocket 请求，则为 true，否则为 false。
        */
		public bool IsWebSocketRequest { get; }
        /*
        //     获取或设置包含适用于异步预加载模式的标志的对象。
        //
        // 返回结果:
        //     包含适用于异步预加载模式的标志的对象。
        */
		public AsyncPreloadModeFlags AsyncPreloadMode { get; set; }
        /*
        //     为当前应用程序返回请求的配置信息。
        //
        // 参数:
        //   name:
        //     为其请求信息的应用程序配置标记。
        //
        // 返回结果:
        //     包含配置信息的对象。 （在使用之前，将返回的配置节强制转换为适当的配置类型。）
        [Obsolete("The recommended alternative is System.Web.Configuration.WebConfigurationManager.GetWebApplicationSection in System.Web.dll. http://go.microsoft.com/fwlink/?linkid=14202")]
        */
		public static object GetAppConfig(string name);
        /*
        //     根据指定的 System.Web.Compilation.ResourceExpressionFields.ClassKey 和 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性以及 System.Globalization.CultureInfo 对象，获取一个应用程序级别资源对象。
        //
        // 参数:
        //   classKey:
        //     一个字符串，表示所请求资源对象的 System.Web.Compilation.ResourceExpressionFields.ClassKey 属性。
        //
        //   resourceKey:
        //     一个字符串，表示所请求资源对象的 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性。
        //
        //   culture:
        //     一个字符串，表示所请求资源的 System.Globalization.CultureInfo 对象。
        //
        // 返回结果:
        //     一个 System.Object，表示请求的应用程序级别资源对象（对指定区域性对其进行了本地化）；否则，如果未找到资源对象，或找到了资源对象但其没有请求的属性，则为
        //     null。
        //
        // 异常:
        //   T:System.Resources.MissingManifestResourceException:
        //     资源对象为其指定 classKey 找不到参数。- 或 -主程序集不包含非特定区域性的资源，这些资源是必需的由于缺少适当的附属程序集。
        */
		public static object GetGlobalResourceObject(string classKey, string resourceKey, CultureInfo culture);
        /*
        //     根据指定的 System.Web.Compilation.ResourceExpressionFields.ClassKey 和 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性，获取应用程序级别资源对象。
        //
        // 参数:
        //   classKey:
        //     一个字符串，表示所请求资源对象的 System.Web.Compilation.ResourceExpressionFields.ClassKey 属性。
        //
        //   resourceKey:
        //     一个字符串，表示所请求资源对象的 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性。
        //
        // 返回结果:
        //     一个 System.Object，表示请求的应用程序级别资源对象；否则，如果未找到资源对象，或找到了资源对象但其没有请求的属性，则为 null。
        //
        // 异常:
        //   T:System.Resources.MissingManifestResourceException:
        //     具有指定的资源对象 classKey 找不到参数。- 或 -主程序集不包含非特定区域性的资源，这些资源是必需的由于缺少适当的附属程序集。
        */
		public static object GetGlobalResourceObject(string classKey, string resourceKey);
        /*
        //     根据指定的 System.Web.Compilation.ExpressionBuilderContext.VirtualPath 和 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性以及 System.Globalization.CultureInfo 对象，获取一个页级别资源对象。
        //
        // 参数:
        //   virtualPath:
        //     本地资源对象的 System.Web.Compilation.ExpressionBuilderContext.VirtualPath 属性。
        //
        //   resourceKey:
        //     一个字符串，表示所请求资源对象的 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性。
        //
        //   culture:
        //     一个字符串，表示所请求资源对象的 System.Globalization.CultureInfo 对象。
        //
        // 返回结果:
        //     System.Object，表示请求的本地资源对象（针对指定区域性进行了本地化的对象）；否则，如果找到了匹配的资源对象但不是 null 参数，则为 resourceKey。
        //
        // 异常:
        //   T:System.Resources.MissingManifestResourceException:
        //     未找到资源对象为指定 virtualPath 参数。
        //
        //   T:System.ArgumentException:
        //     指定 virtualPath 参数不是当前应用程序的根目录中。
        //
        //   T:System.InvalidOperationException:
        //     找不到页上的资源类。
        */
		public static object GetLocalResourceObject(string virtualPath, string resourceKey, CultureInfo culture);
        /*
        //     根据指定的 System.Web.Compilation.ExpressionBuilderContext.VirtualPath 和 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性，获取页级别资源对象。
        //
        // 参数:
        //   virtualPath:
        //     本地资源对象的 System.Web.Compilation.ExpressionBuilderContext.VirtualPath 属性。
        //
        //   resourceKey:
        //     一个字符串，表示所请求资源对象的 System.Web.Compilation.ResourceExpressionFields.ResourceKey
        //     属性。
        //
        // 返回结果:
        //     System.Object，表示请求的页级别资源对象；否则，如果找到了匹配的资源对象但不是 resourceKey 参数，则为 null。
        //
        // 异常:
        //   T:System.Resources.MissingManifestResourceException:
        //     未找到资源对象为指定 virtualPath 参数。
        //
        //   T:System.ArgumentException:
        //     指定 virtualPath 参数不是当前应用程序的根目录中。
        //
        //   T:System.InvalidOperationException:
        //     找不到页上的资源类。
        */
		public static object GetLocalResourceObject(string virtualPath, string resourceKey);
        /*
        //     接受一个使用指定用户函数和选项对象 System.Web.WebSockets.AspNetWebSocket 请求。
        //
        // 参数:
        //   userFunc:
        //     用户函数。
        //
        //   options:
        //     选项对象。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     userFunc 参数为 null。
        //
        //   T:System.NotSupportedException:
        //     此请求不是 System.Web.WebSockets.AspNetWebSocket 请求。
        */
		public void AcceptWebSocketRequest(Func<AspNetWebSocketContext, Task> userFunc, AspNetWebSocketOptions options);
        /*
        //     接受一个使用指定用户函数的 System.Web.WebSockets.AspNetWebSocket 请求。
        //
        // 参数:
        //   userFunc:
        //     用户函数。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     userFunc 参数为 null。
        //
        //   T:System.NotSupportedException:
        //     此请求不是 System.Web.WebSockets.AspNetWebSocket 请求。
        */
		public void AcceptWebSocketRequest(Func<AspNetWebSocketContext, Task> userFunc);
        /*
        //     将异常添加到当前 HTTP 请求的异常集合中。
        //
        // 参数:
        //   errorInfo:
        //     要添加到异常集合中的 System.Exception。
        */
		public void AddError(Exception errorInfo);
        /*
        //     引发在请求的 HTTP 部分结束时发生的虚拟事件。
        //
        // 参数:
        //   callback:
        //     HTTP 上下文对象。
        //
        // 返回结果:
        //     订阅标记。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     callback 参数为 null。
        */
		public ISubscriptionToken AddOnRequestCompleted(Action<HttpContext> callback);
        /*
        //     清除当前 HTTP 请求的所有错误。
        */
		public void ClearError();
        /*
        //     使对象的 System.IDisposable.Dispose 方法可以在此请求的 System.Web.WebSockets.AspNetWebSocket
        //     连接部分完成时进行调用。
        //
        // 参数:
        //   target:
        //     在请求的 System.IDisposable.Dispose 连接部分完成时必须调动用其 System.Web.WebSockets.AspNetWebSocket
        //     方法的对象。
        //
        // 返回结果:
        //     订阅标记。
        */
		public ISubscriptionToken DisposeOnPipelineCompleted(IDisposable target);
        /*
        //     为当前 HTTP 请求返回所请求的配置信息。
        //
        // 参数:
        //   name:
        //     为其请求信息的配置标记。
        //
        // 返回结果:
        //     指定的 System.Configuration.ConfigurationSection，如果该节不存在，则为 null，或是如果该节不能在运行时访问，则为一个内部对象。
        //     （在使用之前，将返回的对象强制转换为适当的配置类型。）
        [Obsolete("The recommended alternative is System.Web.HttpContext.GetSection in System.Web.dll. http://go.microsoft.com/fwlink/?linkid=14202")]
        */
		public object GetConfig(string name);
        /*
        //     获取当前应用程序的默认配置的指定配置节。
        //
        // 参数:
        //   sectionName:
        //     配置节路径（使用 XPath 格式）和配置元素名称。
        //
        // 返回结果:
        //     指定的 System.Configuration.ConfigurationSection，如果该节不存在，则为 null，或是如果该节不能在运行时访问，则为一个内部对象。
        */
		public object GetSection(string sectionName);
        /*
        //     用于为请求指定处理程序。
        //
        // 参数:
        //   handler:
        //     应处理请求的对象。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     System.Web.HttpContext.RemapHandler(System.Web.IHttpHandler) 方法之后调用 System.Web.HttpApplication.MapRequestHandler
        //     事件发生。
        */
		public void RemapHandler(IHttpHandler handler);
        /*
        //     使用给定的路径、路径信息和查询字符串信息重写 URL。
        //
        // 参数:
        //   filePath:
        //     内部重写路径。
        //
        //   pathInfo:
        //     资源的附加路径信息。 有关详细信息，请参阅System.Web.HttpRequest.PathInfo。
        //
        //   queryString:
        //     请求查询字符串。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     path 参数不是当前应用程序的根目录中。
        //
        //   T:System.Web.HttpException:
        //     filePath 参数不在当前应用程序的根目录下。
        */
		public void RewritePath(string filePath, string pathInfo, string queryString);
        /*
        //     使用给定虚拟路径、路径信息、查询字符串信息和一个布尔值重写 URL，该布尔值用于指定是否将客户端文件路径设置为重写路径。
        //
        // 参数:
        //   filePath:
        //     服务请求的资源的虚拟路径。
        //
        //   pathInfo:
        //     用于 URL 重定向的附加路径信息。 有关详细信息，请参阅System.Web.HttpRequest.PathInfo。
        //
        //   queryString:
        //     用于 URL 重定向的请求查询字符串。
        //
        //   setClientFilePath:
        //     若要将用于客户端资源的文件路径设置为 filePath 参数的值，则为 true；否则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     path 参数不是当前应用程序的根目录中。
        //
        //   T:System.Web.HttpException:
        //     filePath 参数不在当前应用程序的根目录下。
        */
		public void RewritePath(string filePath, string pathInfo, string queryString, bool setClientFilePath);
        /*
        //     使用给定路径和一个布尔值重写 URL，该布尔值用于指定是否修改服务器资源的虚拟路径。
        //
        // 参数:
        //   path:
        //     内部重写路径。
        //
        //   rebaseClientPath:
        //     如果重置虚拟路径，则为 true；如果保持虚拟路径不变，则为 false。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     path 参数为 null。
        //
        //   T:System.Web.HttpException:
        //     path 参数不是当前应用程序的根目录中。
        */
		public void RewritePath(string path, bool rebaseClientPath);
        /*
        //     使用给定路径重写 URL。
        //
        // 参数:
        //   path:
        //     内部重写路径。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     path 参数为 null。
        //
        //   T:System.Web.HttpException:
        //     path 参数不是当前应用程序的根目录中。
        */
		public void RewritePath(string path);
        /*
        //     设置支持 HTTP 请求所需的会话状态行为的类型。
        //
        // 参数:
        //   sessionStateBehavior:
        //     枚举值之一，该值指定需要什么类型的会话状态行为。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     该方法调用之后 System.Web.HttpApplication.AcquireRequestState 引发事件。
        */
		public void SetSessionStateBehavior(SessionStateBehavior sessionStateBehavior);
    }
}














