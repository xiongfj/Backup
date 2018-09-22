
* ע���м��:
{
	app.UseCookieAuthentication(new CookieAuthenticationOptions()
	{
		CookieName = "MyidLoginData",   // �ڲ�Դ�� CookieAuthenticationMiddleware �����ã���� CookieName δָ��, ��ô���� CookieName ����Ϊ AuthenticationType �Ӹ�ǰ׺
		AuthenticationType = DefaultAuthenticationTypes.ApplicationCookie,
		LoginPath = new PathString("/OAuth/Account/Login"),
		ExpireTimeSpan = TimeSpan.FromMinutes(15)
	});
}
	
	
* ����ִ����㣺 AuthenticationMiddleware<TOptions>.Invoke(context)		// ��������������ת֮ǰִ�иú���
{
	public override async Task Invoke(IOwinContext context)
	{
		AuthenticationHandler<TOptions> handler = CreateHandler();
		await handler.Initialize(Options, context);
		if (!await handler.InvokeAsync())			// �ú��� CookiexxxHandler û��ʵ�֣����Ե��õ��ǻ���ģ�����ĸú���ֱ�ӷ��� false
		{
			await Next.Invoke(context);
		}
		await handler.TeardownAsync();		// ����ʵ��ֻ�������������
	}
}

* ��һ���� await handler.TeardownAsync() ����˳����������������� 
	CookiexxHandler.ApplyResponseGrantAsync();
	CookiexxHandler.ApplyResponseChallengeAsync();