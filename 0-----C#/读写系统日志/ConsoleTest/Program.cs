using EGetIp.Util;
using System;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Net;
using System.Security;
using System.Text;

/*
 * 需要管理员身份才能日写入日志成功; 
 * 或者需要设置 注册表权限; HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\EventLog; 右击EventLog -> Permission -> 添加需要写日志的应用程序用户,例如当前计算机用户 xiongfj
 * 
*/

public class Program
{
	static void Main()
	{
		WriteLog();

		//ClearLog("Application");
		ReadLog();

		//WriteSysLog();
	}

	public static void WriteLog()
	{
		// 创建的自定义日志貌似不会显示在日志管理器中, 只能在注册表中看到?!
		//if (!EventLog.SourceExists("ax"))
		//	EventLog.CreateEventSource("ax", "Application");           // 会在 Application 同级目录下创建 MyEvent; MyEvent 内有创建一个 abc

		EventLog log = new EventLog("Application");
		log.Source = "aaa";
		log.WriteEntry("1111111");

		//try
		//{
		//	//EventLog.CreateEventSource("news2", "Application");
		//	EventLog.WriteEntry("ssss", "info dddddddd", EventLogEntryType.Error, 1009, 0);     // 默认写入 Windows Logs/Application 层里面
		//}
		//catch (Exception e)
		//{
		//	EventLog.WriteEntry("abc", e.Message, EventLogEntryType.Error);
		//}
	}

	public static void ReadLog()
	{
		//EventLog l = new EventLog("MyEvent");
		//l.Clear();

		EventLog eventLog = new EventLog();
		eventLog.Log = "Application";

		EventLogEntryCollection collection = eventLog.Entries;
		foreach (EventLogEntry entry in collection)
		{
			Console.WriteLine(entry.Source);
		}
	}

	public static void ClearLog(string logName)
	{
		EventLog log = new EventLog(logName);
		log.Clear();
	}
















	public static void createLog()
	{
		EventLog log = new EventLog();

		//  首先应判断日志来源是否存在，一个日志来源只能同时与一个事件绑定s


		try

		{
			if (!EventLog.SourceExists("new"))
				EventLog.CreateEventSource("new", "Application");

			log.Source = "new";
			log.WriteEntry("处理信息1", EventLogEntryType.Information, 1002, 0);


		//	throw new System.IO.FileNotFoundException("readme.txt文件未找到");

		}

		catch (SecurityException exception)

		{
			Console.WriteLine(exception.Message);
			//log.WriteEntry(exception.Message, EventLogEntryType.Error, 1003);

		}
	}

	public static void WriteSysLog()
	{
		EventLog log = new EventLog("MyEvent");

		//  首先应判断日志来源是否存在，一个日志来源只能同时与一个事件绑定s

		if (!EventLog.SourceExists("New Application"))

			EventLog.CreateEventSource("New Application", "MyEvent");

		try

		{

			log.Source = "New Application";

			log.WriteEntry("处理信息1", EventLogEntryType.Information);

			log.WriteEntry("处理信息2", EventLogEntryType.Information);

			throw new System.IO.FileNotFoundException("readme.txt文件未找到");

		}

		catch (System.IO.FileNotFoundException exception)

		{

			log.WriteEntry(exception.Message, EventLogEntryType.Error);

		}
	}

}

