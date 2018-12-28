* 在 mvc 或者 webapi 中，如果需要发起 http://xxxxx.vcf 带后缀的请求，貌似不起作用

* 添加 VcfHandler.cs		// 可以为空
{
	namespace Myid.HttpHandlers
	{
		public class VcfHandler
		{
		}
	}
}

* 设置 handler
	<add name="VcfHandler" verb="*" path="*.vcf" type="Myid.HttpModules.VcfHandler, Myid"/>
	
	
* 添加 UrlRewrite.cs  Modules
{
	public class UrlRewrite : IHttpModule
	{
		public void Dispose()
		{
		}

		public void Init(HttpApplication context)
		{
			context.BeginRequest += ContextBeginRequest;
		}

		private static void ContextBeginRequest(object sender, EventArgs e)
		{
			var context = ((HttpApplication)sender).Context;

			var path = context.Request.Path.TrimStart('/');

			TxtLog.WriteLog(path);
			if (!string.IsNullOrEmpty(path))
			{
				var strArray = path.Split('.');
				Guid guid;
				if (Guid.TryParse(strArray[0], out guid))
				{
					if (strArray.Length == 2)
					{
						//context.Response.AddHeader("Access-Control-Allow-Origin", "*");
						//context.Response.AddHeader("Access-Control-Allow-Methods", "GET, HEAD, OPTIONS, POST, PUT");
						//context.Response.AddHeader("Access-Control-Allow-Headers", "Access-Control-Allow-Headers, Origin, No-Cache, Accept, X-Requested-With, If-Modified-Since, Pragma, Last-Modified, Cache-Control, Expires, Content-Type, X-E4M-With,userId,token, Access-Control-Request-Method, Access-Control-Request-Headers");

						string dataType = strArray[1];
						switch (dataType.ToLower())
						{
							case "json":	context.RewritePath("/api/Profile/GetJson/" + path, false);		break;
							case "xml":		context.RewritePath("/api/Profile/GetXml/"	+ path, false);		break;
							case "png":		context.RewritePath("/api/Profile/GetPng/"	+ path, false);		break;
							case "vcf":		context.RewritePath("/api/Profile/GetVcf/"	+ path, false);		break;
							case "qr":		context.RewritePath("/api/Profile/GetQr/"	+ path, false);		break;
						}
						TxtLog.WriteLog("Rewrite 了" + $"/api/Profile/{dataType}" + path);
					}
					else
					{
						// rewrite 到个人主页
						context.RewritePath("/api/Profile/" + path, false);
					}
				}
			}
		}
	}
}
* 配置 Module：<add name="UrlRewrite" type="Myid.HttpModules.UrlRewrite, Myid"/>


* 此时请求 http://xxx.vcf 将会定向到 VcfHangler，服务端才能接收请求，然后在 module 中再进行重定位，即可处理特殊的逻辑