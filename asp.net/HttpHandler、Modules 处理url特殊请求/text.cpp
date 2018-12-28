* �� mvc ���� webapi �У������Ҫ���� http://xxxxx.vcf ����׺������ò�Ʋ�������

* ��� VcfHandler.cs		// ����Ϊ��
{
	namespace Myid.HttpHandlers
	{
		public class VcfHandler
		{
		}
	}
}

* ���� handler
	<add name="VcfHandler" verb="*" path="*.vcf" type="Myid.HttpModules.VcfHandler, Myid"/>
	
	
* ��� UrlRewrite.cs  Modules
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
						TxtLog.WriteLog("Rewrite ��" + $"/api/Profile/{dataType}" + path);
					}
					else
					{
						// rewrite ��������ҳ
						context.RewritePath("/api/Profile/" + path, false);
					}
				}
			}
		}
	}
}
* ���� Module��<add name="UrlRewrite" type="Myid.HttpModules.UrlRewrite, Myid"/>


* ��ʱ���� http://xxx.vcf ���ᶨ�� VcfHangler������˲��ܽ�������Ȼ���� module ���ٽ����ض�λ�����ɴ���������߼�