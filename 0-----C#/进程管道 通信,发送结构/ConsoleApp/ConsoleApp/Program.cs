using ConsoleApp;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Net;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Timers;

public class Program
{

	static void Main(string[] args)
	{
		new NamedPipeObjectClient().Connect();

		//new NamedPipeClient().Connect();

		//new NamedMsgPipeClient().Connect();

		//new AnonymousPipeClient().Connect(args[0]);

		//new SerializTest().soapFile();

		//Person person = new Person("asdasd", 123);

		//MemoryStream ms = new MemoryStream();
		//IFormatter formatter = new BinaryFormatter();
		//formatter.Serialize(ms, person);
		//byte[] fd = ms.GetBuffer();

	}
	
}

