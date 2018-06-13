using Microsoft.Owin;
using Owin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;

namespace WebApplication13
{
	public class Startup
	{
		// owin 运行时会调用该函数
		// 依次调用中间件对应的函数
		// 如果一个中间件都没有执行, 那么会出现 404 等页面
		public void Configuration(IAppBuilder app)
		{
			//app.UseDing();  使用扩展类调用
			app.Use<DingMiddleware>();      // User() 是添加有后继的中间件

			// app.UseDiDiDi()
			app.Use<DiDiDiMiddleware>();

			// 向管道中添加一个没有后续中间件的中间件
			app.Run(HandleRequest);         // 该请求处理完后, 不会执行后面添加的中间件

			app.Use<MiddleTemp>();			// 该中间件不会被执行. 应为在 Run() 后面
		}


		static Task HandleRequest(IOwinContext context)
		{
			context.Response.ContentType = "text/plain";
			return context.Response.WriteAsync("Hello world from myOwin");
		}
	}
}