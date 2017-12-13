using PersonDll;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleTest
{
	public class NamedPipeObjectServer
	{
		private NamedPipeServerStream _pipe;
		private string PipeName = "Maintain_QQRobot_Pipe";
		private Encoding encoding = Encoding.UTF8;

		public void WaitConnect()
		{
			InitPipe();
		}

		private void InitPipe()
		{
			_pipe = new NamedPipeServerStream
			(
				PipeName,
				PipeDirection.InOut,
				1,
				PipeTransmissionMode.Message,
				PipeOptions.Asynchronous | PipeOptions.WriteThrough
			 );
			_pipe.BeginWaitForConnection(WaitForConnectionCallback, _pipe);
		}

		private void WaitForConnectionCallback(IAsyncResult ar)
		{
			var pipeServer = (NamedPipeServerStream)ar.AsyncState;
			pipeServer.EndWaitForConnection(ar);

			using (StreamReader sr = new StreamReader(pipeServer))
			{
				string msg = sr.ReadToEnd();
				byte[] bytes = System.Text.Encoding.ASCII.GetBytes(msg);

				MemoryStream ms = new MemoryStream(bytes);
				IFormatter formatter = new BinaryFormatter();
				Person person = (Person)formatter.Deserialize(ms);
				Console.WriteLine(person.name + " - " + person.age);
			}

			//byte[] bytes = new byte[1024];

			//try
			//{
			//	do
			//	{
			//		int numBytes = _pipe.Read(bytes, 0, bytes.Length);

			//	} while (!_pipe.IsMessageComplete);
			//}
			//catch (Exception e)
			//{
			//	_pipe.Dispose();
			//	InitPipe();
			//}

			try
			{
				byte[] sendData = encoding.GetBytes("服务端收到数据...");
				pipeServer.Write(sendData, 0, sendData.Length);

				// 重新等待新的数据链接
				pipeServer.Disconnect();
				pipeServer.BeginWaitForConnection(WaitForConnectionCallback, pipeServer);
			}
			catch (Exception)
			{
				// 防止 Server 端接收/发送数据未完成之前 Client 端断开连接导致的异常
				_pipe.Dispose();
				InitPipe();
			}
		}

		private void WaitForConnectionCallback_2(IAsyncResult ar)
		{
			var pipeServer = (NamedPipeServerStream)ar.AsyncState;
			pipeServer.EndWaitForConnection(ar);

			byte[] bytes = new byte[1024];

			try
			{
				do
				{
					int numBytes = _pipe.Read(bytes, 0, bytes.Length);

				} while (!_pipe.IsMessageComplete);
			}
			catch (Exception e)
			{
				_pipe.Dispose();
				InitPipe();
			}

			MemoryStream ms = new MemoryStream(bytes);
			IFormatter formatter = new BinaryFormatter();
			Person person = (Person)formatter.Deserialize(ms);
			Console.WriteLine(person.name + " - " + person.age);

			try
			{
				byte[] sendData = encoding.GetBytes("服务端收到数据...");
				pipeServer.Write(sendData, 0, sendData.Length);

				// 重新等待新的数据链接
				pipeServer.Disconnect();
				pipeServer.BeginWaitForConnection(WaitForConnectionCallback, pipeServer);
			}
			catch (Exception)
			{
				// 防止 Server 端接收/发送数据未完成之前 Client 端断开连接导致的异常
				_pipe.Dispose();
				InitPipe();
			}
		}

		public void DispatchCmdMsg(string cmd)
		{
			switch (cmd)
			{
				case "cmd_quit": break;
				default: break;
			}
		}
	}
}
