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

    public class Option
    {
        public string CallbackPath { set; get; }
        public string AuthorizedType { set; get; }
    }

	/// <summary>
	/// ///////////////////////// 1
	/// </summary>
	public class DingMiddleware : OwinMiddleware
	{
        private Option _option;
		public DingMiddleware(OwinMiddleware next, Option option) : base(next)
		{
            _option = option;
        }

		public override Task Invoke(IOwinContext context)
		{
			if (context.Request.Path.Value.Equals("/home/index"))
			{
				context.Response.Write("hello world from DingMiddleware home/index option.CallbackPath-> " + _option.CallbackPath + "</br>");
			}
			if (Next != null)
			{
				 Next.Invoke(context);		// 堆栈操作，先执行完后面的中间件才执行下面的代码
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