

{
	public delegate void EventHandler(object sender, MyEventArgs e);
	public static event EventHandler myEvent;
	
	public void Add(EventHandler handler)
	{
		myEvent += handler;
	}
	....

}		
		
	
	...
	
	外部调用:
	Add( (o, e)=>{ ... 处理回调 .. } );
	
	或者:
	public void func(object obj, MyEventArgs e)
	{
		//.....
	}
	Add(func);
		
		
----------------------------------------------------


