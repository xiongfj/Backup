using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace test.HttpModules
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
			var path = context.Request.Path.ToUpperInvariant();
			var url = context.Request.Path + "?" + context.Request.QueryString;

			//context.RewritePath("/", false);
		}
	}
}