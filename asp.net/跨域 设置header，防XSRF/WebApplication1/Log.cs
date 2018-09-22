using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;

namespace WebApplication1
{
	public class Log
	{
		public static void WriteLog(string msg)
		{
			StreamWriter wr = File.AppendText(HttpRuntime.AppDomainAppPath + "Myid_log.txt");
			wr.WriteLine(msg + "\n");
			wr.Flush();
			wr.Close();
		}
	}
}