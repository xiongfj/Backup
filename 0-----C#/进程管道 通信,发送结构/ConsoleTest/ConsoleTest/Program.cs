using ConsoleTest;
using System;
using System.IO;
using System.IO.Pipes;
using System.Net;
using System.Text;


public class Program
{ 
	static void Main()
	{
		new NamedPipeObjectServer().WaitConnect();

		//new NamedMsgPipeServer().WaitConnect();

		//new AnonymousPipeServer().Connect();

		//new NamedPipeServer().WaitConnect();


		//StreamWriter sw = System.IO.File.AppendText("D:\\test.txt");
		//sw.WriteLine(DateTime.Now.ToString());
		//sw.Close();

		Console.Read();
	}

}

