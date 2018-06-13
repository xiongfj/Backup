using Microsoft.Owin;
using Owin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;

namespace WebApplication13
{
	public static class MyMidlewareExtention
	{
		public static IAppBuilder UseDing(this IAppBuilder app)
		{
			return app.Use<DingMiddleware>();
		}
		public static IAppBuilder UseDiDiDi(this IAppBuilder app)
		{
			return app.Use<DiDiDiMiddleware>();
		}
	}

	/// <summary>
	/// ///////////////////////// 1
	/// </summary>
	public class DingMiddleware : OwinMiddleware
	{
		public DingMiddleware(OwinMiddleware next) : base(next)
		{
		}

		public override Task Invoke(IOwinContext context)
		{
			if (context.Request.Path.Value.Equals("/home/index"))
			{
				context.Response.Write("hello world from DingMiddleware home/index</br>");
			}
			if (Next != null)
			{
				return Next.Invoke(context);
			}
			return Task.CompletedTask;
		}
	}

	/// <summary>
	/// ////////////////////////// 2
	/// </summary>
	public class DiDiDiMiddleware : OwinMiddleware
	{
		public DiDiDiMiddleware(OwinMiddleware next) : base(next)
		{
		}

		public override Task Invoke(IOwinContext context)
		{
			if (context.Request.QueryString.Value == "boom")
			{
				context.Response.Write("Boom! Boom! Boom!");
				return Task.CompletedTask;						// 结束, 不会执行后面的中间件
			}
			if (Next != null)
			{
				return Next.Invoke(context);
			}
			return Task.CompletedTask;
		}
	}

	public class MiddleTemp : OwinMiddleware
	{
		public MiddleTemp(OwinMiddleware next) : base(next)
		{
		}

		public override Task Invoke(IOwinContext context)
		{
			context.Response.Write("我不会被执行, 因为我在 app.Run() 后面添加的中间件");
			if (Next != null)
			{
				return Next.Invoke(context);
			}
			return Task.CompletedTask;
		}
	}
}