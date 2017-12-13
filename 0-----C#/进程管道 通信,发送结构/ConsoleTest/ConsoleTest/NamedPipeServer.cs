using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
	public class NamedPipeServer : IDisposable
	{
		public void WaitConnect()
		{
			using (NamedPipeServerStream pipeStream = new NamedPipeServerStream("testpipe"))
			{
				pipeStream.WaitForConnection();

				using (StreamWriter writer = new StreamWriter(pipeStream))
				{
					writer.AutoFlush = true;
					string temp;

					while ((temp = Console.ReadLine()) != "stop")
					{
						writer.WriteLine(temp);
					}
				}
			}
		}


		public void Dispose()
		{
			throw new NotImplementedException();
		}
	}

	//public void Connect()
	//{
	//	UTF8Encoding encoding = new UTF8Encoding();
	//	string message1 = "Named Pipe Message Example.";
	//	string message2 = "Another Named Pipe Message Example.";
	//	Byte[] bytes;
	//	using (NamedPipeServerStream pipeStream = new
	//			NamedPipeServerStream("messagepipe", PipeDirection.InOut, 1,
	//			PipeTransmissionMode.Message, PipeOptions.None))
	//	{
	//		pipeStream.WaitForConnection();

	//		// Let’s send two messages.
	//		bytes = encoding.GetBytes(message1);
	//		pipeStream.Write(bytes, 0, bytes.Length);
	//		bytes = encoding.GetBytes(message2);
	//		pipeStream.Write(bytes, 0, bytes.Length);

	//	}
	//}
}
