
* 注册中间件:
{
	app.UseCookieAuthentication(new CookieAuthenticationOptions()
	{
		CookieName = "MyidLoginData",   // 内部源码 CookieAuthenticationMiddleware 中设置，如果 CookieName 未指定, 那么设置 CookieName 设置为 AuthenticationType 加个前缀
		AuthenticationType = DefaultAuthenticationTypes.ApplicationCookie,
		LoginPath = new PathString("/OAuth/Account/Login"),
		ExpireTimeSpan = TimeSpan.FromMinutes(15)
	});
}
	
	
* 代码执行起点： AuthenticationMiddleware<TOptions>.Invoke(context)		// 发起请求、链接跳转之前执行该函数
{
	public override async Task Invoke(IOwinContext context)
	{
		AuthenticationHandler<TOptions> handler = CreateHandler();
		await handler.Initialize(Options, context);
		if (!await handler.InvokeAsync())			// 该函数 CookiexxxHandler 没有实现，所以调用的是基类的，基类的该函数直接返回 false
		{
			await Next.Invoke(context);
		}
		await handler.TeardownAsync();		// 所以实际只调用了这个函数
	}
}

* 上一步的 await handler.TeardownAsync() 最终顺序调用下面两个函数 
	CookiexxHandler.ApplyResponseGrantAsync();
	CookiexxHandler.ApplyResponseChallengeAsync();