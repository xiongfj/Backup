#region 程序集 System.Web, Version=4.0.0.0, Culture=neutral, */
		publicKeyToken=b03f5f7f11d50a3a
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.2\System.Web.dll
#endregion

using System.ComponentModel;
using System.Security.Principal;
using System.Web.SessionState;
using System.Web.Util;

namespace System.Web
{
    /*
    //     定义对 ASP.NET 应用程序内所有应用程序对象公用的方法、属性和事件。 此类是用户在 Global.asax 文件中定义的应用程序的基类。
    [ToolboxItem(false)]
    */
	public class HttpApplication : IComponent, IDisposable, IHttpAsyncHandler, IHttpHandler, IRequestCompletedNotifier, ISyncContext
    {
        /*
        //     初始化 System.Web.HttpApplication 类的新实例。
        */
		public HttpApplication();
        /*
        //     获取或设置的网站接口 System.ComponentModel.IComponent 实现。
        //
        // 返回结果:
        //     System.ComponentModel.ISite 对象，它使一个容器，以管理和与及其子组件进行通信。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public ISite Site { get; set; }
        /*
        //     获取当前请求的内部用户对象。
        //
        // 返回结果:
        //     System.Security.Principal.IPrincipal 对象，表示当前已经过身份验证或匿名用户。
        //
        // 异常:
        //   T:System.Web.HttpException:
        //     System.Security.Principal.IPrincipal 对象是 null。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public IPrincipal User { get; }
        /* 对应 HttpContext.Current.Server
        //     获取当前请求的内部服务器对象。
        //
        // 返回结果:
        //     System.Web.HttpServerUtility 应用程序处理的对象。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpServerUtility Server { get; }
        /*
        //     获取应用程序的当前状态。
        //
        // 返回结果:
        //     System.Web.HttpApplicationState 为当前请求。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpApplicationState Application { get; }
        /* 对应 HttpContext.Current.Session
        //     获取提供对会话数据的访问的内部会话对象。
        //
        // 返回结果:
        //     System.Web.SessionState.HttpSessionState 当前会话的对象。
        //
        // 异常:
        //   T:System.Web.HttpException:
        //     System.Web.SessionState.HttpSessionState 对象是 null。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpSessionState Session { get; }
        /*
        //     获取当前应用程序的模块集合。
        //
        // 返回结果:
        //     System.Web.HttpModuleCollection ，其中包含应用程序的模块的名称。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpModuleCollection Modules { get; }
        /*  对应 HttpContext.Current.Request
        //     获取当前请求的内部请求对象。
        //
        // 返回结果:
        //     System.Web.HttpRequest 应用程序处理的对象。
        //
        // 异常:
        //   T:System.Web.HttpException:
        //     System.Web.HttpRequest 对象是 null。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpRequest Request { get; }
        /* 对应 HttpContext.Current
        //     获取有关当前请求的 HTTP 特定信息。
        //
        // 返回结果:
        //     System.Web.HttpContext 为当前请求。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpContext Context { get; }
        /* 与 HttpContext.Current.Response 是同一个
        //     获取当前请求的内部函数的响应对象。
        //
        // 返回结果:
        //     System.Web.HttpResponse 应用程序处理的对象。
        //
        // 异常:
        //   T:System.Web.HttpException:
        //     System.Web.HttpResponse 对象是 null。
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        */
		public HttpResponse Response { get; }
        /*
        //     获取处理所有的应用程序事件的处理程序委托的事件的列表。
        //
        // 返回结果:
        //     System.ComponentModel.EventHandlerList ，其中包含事件处理程序委托的名称。
        protected EventHandlerList Events { get; }

        //
        /*
        //     ASP.NET 将 HTTP 标头发送到客户端之前发生。
        */
		public event EventHandler PreSendRequestHeaders;
        /*
        //     在选择该处理程序对请求作出响应时发生。
        */
		public event EventHandler MapRequestHandler;
        /*
        //     释放应用程序时发生。
        */
		public event EventHandler Disposed;
        /*
        //     作为执行的 HTTP 管道链中的第一个事件发生，当 ASP.NET 的请求做出响应。
        */
		public event EventHandler BeginRequest;
        /*
        //     当安全模块已建立的用户标识时出现。
        */
		public event EventHandler AuthenticateRequest;
        /*
        //     当安全模块已建立的用户标识时出现。
        */
		public event EventHandler PostAuthenticateRequest;
        /*
        //     安全模块已验证用户身份验证时发生。
        */
		public event EventHandler AuthorizeRequest;
        /*
        //     当前请求的用户已被授权时发生。
        */
		public event EventHandler PostAuthorizeRequest;
        /*
        //     当 ASP.NET 完成授权事件以便从缓存中，跳过的事件处理程序 （例如，一个页面或 XML Web 服务） 执行的请求提供服务的缓存模块时发生。
        */
		public event EventHandler ResolveRequestCache;
        /*
        //     ASP.NET 将绕过当前事件处理程序的执行，并允许缓存模块以处理从缓存请求时发生。
        */
		public event EventHandler PostResolveRequestCache;
        /*
        //     ASP.NET 将内容发送到客户端之前发生。
        */
		public event EventHandler PreSendRequestContent;
        /*
        //     当 ASP.NET 已映射到相应的事件处理程序的当前请求时出现。
        */
		public event EventHandler PostMapRequestHandler;
        /*
        //     当 ASP.NET 已完成处理的事件处理程序时发生 System.Web.HttpApplication.LogRequest 事件。
        */
		public event EventHandler PostLogRequest;
        /*
        //     已释放与请求相关联的托管的对象时发生。
        */
		public event EventHandler RequestCompleted;
        //
        /*
        //     获取与当前的请求相关联的请求状态 （例如，会话状态） 时发生。
        */
		public event EventHandler PostAcquireRequestState;
        /*
        //     ASP.NET 开始执行事件处理程序 （例如，一个页面或 XML Web 服务） 之前发生。
        */
		public event EventHandler PreRequestHandlerExecute;
        /*
        //     当 ASP.NET 事件处理程序 （例如，一个页面或 XML Web 服务） 完成执行时发生。
        */
		public event EventHandler PostRequestHandlerExecute;
        /*
        //     ASP.NET 完成执行所有请求事件处理程序后发生。 此事件会导致状态模块保存当前的状态数据。
        */
		public event EventHandler ReleaseRequestState;
        /*
        //     当 ASP.NET 已完成执行所有请求事件处理程序和存储数据的请求状态时发生。
        */
		public event EventHandler PostReleaseRequestState;
        /*
        //     当 ASP.NET 完成执行事件处理程序，以便让缓存模块存储将用于为从缓存中的后续请求提供服务的响应时发生。
        */
		public event EventHandler UpdateRequestCache;
        /*
        //     当 ASP.NET 完成更新的缓存模块和存储用于为从缓存中的后续请求提供服务的响应时发生。
        */
		public event EventHandler PostUpdateRequestCache;
        /*
        //     ASP.NET 执行当前请求的任何日志记录之前发生。
        */
		public event EventHandler LogRequest;
        /*
        //     当 ASP.NET 获取与当前的请求相关联的当前状态 （例如，会话状态）。
        */
		public event EventHandler AcquireRequestState;
        /*
        //     作为执行的 HTTP 管道链中的最后一个事件发生，当 ASP.NET 的请求做出响应。
        */
		public event EventHandler EndRequest;
        /*
        //     当引发未处理的异常时发生。
        */
		public event EventHandler Error;
        /*
        //     注册应用模块。
        //
        // 参数:
        //   moduleType:
        //     该模块的类型。
        */
		public static void RegisterModule(Type moduleType);
        /*
        //     添加指定 System.Web.HttpApplication.AcquireRequestState 事件的异步集合到 System.Web.HttpApplication.AcquireRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.AcquireRequestState。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.AcquireRequestState。
        */
		public void AddOnAcquireRequestStateAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.AcquireRequestState 事件的异步集合到 System.Web.HttpApplication.AcquireRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.AcquireRequestState。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.AcquireRequestState。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.AcquireRequestState。
        */
		public void AddOnAcquireRequestStateAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.AuthenticateRequest 事件的异步集合到 System.Web.HttpApplication.AuthenticateRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.AuthenticateRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.AuthenticateRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.AuthenticateRequest。
        */
		public void AddOnAuthenticateRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.AuthenticateRequest 事件的异步集合到 System.Web.HttpApplication.AuthenticateRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.AuthenticateRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.AuthenticateRequest。
        */
		public void AddOnAuthenticateRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.AuthorizeRequest 事件的异步集合到 System.Web.HttpApplication.AuthorizeRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.AuthorizeRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.AuthorizeRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.AcquireRequestState。
        */
		public void AddOnAuthorizeRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.AuthorizeRequest 事件的异步集合到 System.Web.HttpApplication.AuthorizeRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.AuthorizeRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.AuthorizeRequest。
        */
		public void AddOnAuthorizeRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.BeginRequest 事件的异步集合到 System.Web.HttpApplication.BeginRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.BeginRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.BeginRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.BeginRequest。
        */
		public void AddOnBeginRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.BeginRequest 事件的异步集合到 System.Web.HttpApplication.BeginRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.BeginRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.BeginRequest。
        */
		public void AddOnBeginRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.EndRequest 事件的异步集合到 System.Web.HttpApplication.EndRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.EndRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.EndRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.EndRequest。
        */
		public void AddOnEndRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.EndRequest 事件的异步集合到 System.Web.HttpApplication.EndRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.EndRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.EndRequest。
        */
		public void AddOnEndRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.LogRequest 事件的异步集合到 System.Web.HttpApplication.LogRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.LogRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.LogRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.LogRequest。
        */
		public void AddOnLogRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.LogRequest 事件的异步集合到 System.Web.HttpApplication.LogRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.LogRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.LogRequest。
        */
		public void AddOnLogRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.MapRequestHandler 事件的异步集合到 System.Web.HttpApplication.MapRequestHandler
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.MapRequestHandler。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.MapRequestHandler。
        */
		public void AddOnMapRequestHandlerAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.MapRequestHandler 事件的异步集合到 System.Web.HttpApplication.MapRequestHandler
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.MapRequestHandler。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.MapRequestHandler。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.MapRequestHandler。
        */
		public void AddOnMapRequestHandlerAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostAcquireRequestState 事件的异步集合到 System.Web.HttpApplication.PostAcquireRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostAcquireRequestState。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostAcquireRequestState。
        */
		public void AddOnPostAcquireRequestStateAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostAcquireRequestState 事件的异步集合到 System.Web.HttpApplication.PostAcquireRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostAcquireRequestState。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostAcquireRequestState。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostAcquireRequestState。
        */
		public void AddOnPostAcquireRequestStateAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostAuthenticateRequest 事件的异步集合到 System.Web.HttpApplication.PostAuthenticateRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostAuthenticateRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostAuthenticateRequest。
        */
		public void AddOnPostAuthenticateRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostAuthorizeRequest 事件的异步集合到 System.Web.HttpApplication.PostAuthorizeRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostAuthorizeRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostAuthorizeRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostAuthorizeRequest。
        */
		public void AddOnPostAuthenticateRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostAuthorizeRequest 到异步集合 System.Web.HttpApplication.PostAuthorizeRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostAuthorizeRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostAuthorizeRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostAuthorizeRequest。
        */
		public void AddOnPostAuthorizeRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostAuthorizeRequest 事件的异步集合到 System.Web.HttpApplication.PostAuthorizeRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostAuthorizeRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostAuthorizeRequest。
        */
		public void AddOnPostAuthorizeRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostLogRequest 事件的异步集合到 System.Web.HttpApplication.PostLogRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostLogRequest。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostLogRequest。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostLogRequest。
        */
		public void AddOnPostLogRequestAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostLogRequest 事件的异步集合到 System.Web.HttpApplication.PostLogRequest
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostLogRequest。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostLogRequest。
        */
		public void AddOnPostLogRequestAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostMapRequestHandler 事件的异步集合到 System.Web.HttpApplication.PostMapRequestHandler
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostMapRequestHandler。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostMapRequestHandler。
        */
		public void AddOnPostMapRequestHandlerAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostMapRequestHandler 事件的异步集合到 System.Web.HttpApplication.PostMapRequestHandler
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostMapRequestHandler。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostMapRequestHandler。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostMapRequestHandler 集合。
        */
		public void AddOnPostMapRequestHandlerAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostReleaseRequestState 事件的异步集合到 System.Web.HttpApplication.PostReleaseRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostReleaseRequestState。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostReleaseRequestState。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostReleaseRequestState。
        */
		public void AddOnPostReleaseRequestStateAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostReleaseRequestState 事件的异步集合到 System.Web.HttpApplication.PostReleaseRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostReleaseRequestState。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostReleaseRequestState。
        */
		public void AddOnPostReleaseRequestStateAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostRequestHandlerExecute 事件的异步集合到 System.Web.HttpApplication.PostRequestHandlerExecute
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostRequestHandlerExecute。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostRequestHandlerExecute。
        */
		public void AddOnPostRequestHandlerExecuteAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostRequestHandlerExecute 事件的异步集合到 System.Web.HttpApplication.PostRequestHandlerExecute
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostRequestHandlerExecute。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostRequestHandlerExecute。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostRequestHandlerExecute。
        */
		public void AddOnPostRequestHandlerExecuteAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostResolveRequestCache 事件的异步集合到 System.Web.HttpApplication.PostResolveRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostResolveRequestCache。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostResolveRequestCache。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostResolveRequestCache。
        */
		public void AddOnPostResolveRequestCacheAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PostResolveRequestCache 事件的异步集合到 System.Web.HttpApplication.PostResolveRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostResolveRequestCache。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostResolveRequestCache。
        */
		public void AddOnPostResolveRequestCacheAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostUpdateRequestCache 事件的异步集合到 System.Web.HttpApplication.PostUpdateRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PostUpdateRequestCache。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostUpdateRequestCache。
        */
		public void AddOnPostUpdateRequestCacheAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.PostUpdateRequestCache 事件的异步集合到 System.Web.HttpApplication.PostUpdateRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动事件的异步处理。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PostUpdateRequestCache。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PostUpdateRequestCache。
        */
		public void AddOnPostUpdateRequestCacheAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PreRequestHandlerExecute 事件的异步集合到 System.Web.HttpApplication.PreRequestHandlerExecute
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PreRequestHandlerExecute。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PreRequestHandlerExecute。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.PreRequestHandlerExecute 集合。
        */
		public void AddOnPreRequestHandlerExecuteAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.PreRequestHandlerExecute 事件的异步集合到 System.Web.HttpApplication.PreRequestHandlerExecute
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.PreRequestHandlerExecute。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.PreRequestHandlerExecute。
        */
		public void AddOnPreRequestHandlerExecuteAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.ReleaseRequestState 事件的异步集合到 System.Web.HttpApplication.ReleaseRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.ReleaseRequestState。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.ReleaseRequestState。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.ReleaseRequestState。
        */
		public void AddOnReleaseRequestStateAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.ReleaseRequestState 事件的异步集合到 System.Web.HttpApplication.ReleaseRequestState
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.ReleaseRequestState。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.ReleaseRequestState。
        */
		public void AddOnReleaseRequestStateAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.ResolveRequestCache 到集合的异步事件处理程序 System.Web.HttpApplication.ResolveRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.ResolveRequestCache。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.ResolveRequestCache。
        */
		public void AddOnResolveRequestCacheAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.ResolveRequestCache 到集合的异步事件处理程序 System.Web.HttpApplication.ResolveRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.ResolveRequestCache。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.ResolveRequestCache。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.ResolveRequestCache。
        */
		public void AddOnResolveRequestCacheAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     添加指定 System.Web.HttpApplication.UpdateRequestCache 事件的异步集合到 System.Web.HttpApplication.UpdateRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   bh:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.UpdateRequestCache。
        //
        //   eh:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.UpdateRequestCache。
        */
		public void AddOnUpdateRequestCacheAsync(BeginEventHandler bh, EndEventHandler eh);
        /*
        //     添加指定 System.Web.HttpApplication.UpdateRequestCache 事件的异步集合到 System.Web.HttpApplication.UpdateRequestCache
        //     当前请求的事件处理程序。
        //
        // 参数:
        //   beginHandler:
        //     System.Web.BeginEventHandler 启动的异步处理 System.Web.HttpApplication.UpdateRequestCache。
        //
        //   endHandler:
        //     System.Web.EndEventHandler 结束的异步处理 System.Web.HttpApplication.UpdateRequestCache。
        //
        //   state:
        //     关联的状态将添加到异步 System.Web.HttpApplication.UpdateRequestCache。
        */
		public void AddOnUpdateRequestCacheAsync(BeginEventHandler beginHandler, EndEventHandler endHandler, object state);
        /*
        //     使 ASP.NET 可以绕过所有事件，并筛选在 HTTP 管道执行链并直接执行 System.Web.HttpApplication.EndRequest
        //     事件。
        */
		public void CompleteRequest();
        /*
        //     释放 System.Web.HttpApplication 实例。
        */
		public virtual void Dispose();
        /*
        //     获取网站的默认输出缓存提供程序配置的名称。
        //
        // 参数:
        //   context:
        //     System.Web.HttpContext ，它提供对用于处理 HTTP 请求的内部服务器对象的引用。
        //
        // 返回结果:
        //     默认的提供程序的名称。
        //
        // 异常:
        //   T:System.Configuration.Provider.ProviderException:
        //     context 是 null 或为空字符串。
        */
		public virtual string GetOutputCacheProviderName(HttpContext context);
        /*
        //     提供的应用程序范围内实现 System.Web.UI.PartialCachingAttribute.VaryByCustom 属性。
        //
        // 参数:
        //   context:
        //     System.Web.HttpContext 对象，其中包含有关当前 Web 请求的信息。
        //
        //   custom:
        //     自定义字符串，指定使用哪个缓存的响应对当前请求作出响应。
        //
        // 返回结果:
        //     如果值 custom 参数是 "browser", ，浏览器的 System.Web.Configuration.HttpCapabilitiesBase.Type;
        //     否则为 null。
        */
		public virtual string GetVaryByCustomString(HttpContext context, string custom);
        /*
        //     添加事件处理程序的所有模块后，请执行自定义初始化代码。
        */
		public virtual void Init();
    }
}