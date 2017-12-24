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
			//_pipe.BeginWaitForConnection(WaitForConnectionCallback_1, _pipe);
			//_pipe.BeginWaitForConnection(WaitForConnectionCallback_2, _pipe);
		}

		// 单接收数据,不发送数据, 可以接收无数次 Write 过来的数据
		private void WaitForConnectionCallback(IAsyncResult ar)
		{
			var pipeServer = (NamedPipeServerStream)ar.AsyncState;
			pipeServer.EndWaitForConnection(ar);

			// 拼接 byte 流
			List<byte> byteSource = new List<byte>();
			byte[] bytes = new byte[256];
			int numBytes = 0;
			do
			{
				try
				{
					do
					{
						numBytes = _pipe.Read(bytes, 0, bytes.Length);
						if (numBytes < 256)
						{
							byte[] subData = bytes.Take(numBytes).ToArray();
							byteSource.AddRange(subData);
						}
						else
							byteSource.AddRange(bytes);

					} while (!_pipe.IsMessageComplete);
				}
				catch (Exception)
				{
					_pipe.Dispose();
					InitPipe();
				}

				MemoryStream ms = new MemoryStream(byteSource.ToArray());
				IFormatter formatter = new BinaryFormatter();
				Person person = (Person)formatter.Deserialize(ms);
				Console.WriteLine(person.name + " - " + person.age);
			} while (numBytes != 0);

			// 发送数据, 如果另一端不接收,会阻塞
			//try
			//{
			//	byte[] sendData = encoding.GetBytes("服务端收到数据...");
			//	pipeServer.Write(sendData, 0, sendData.Length);

			//	// 重新等待新的数据链接
			//	pipeServer.Disconnect();
			//	pipeServer.BeginWaitForConnection(WaitForConnectionCallback, pipeServer);
			//}
			//catch (Exception)
			//{
			//	// 防止 Server 端接收/发送数据未完成之前 Client 端断开连接导致的异常
			//	_pipe.Dispose();
			//	InitPipe();
			//}
		}

		// 先接收,后发送; 另一端也需要有发送和接收, 不然会阻塞
		private void WaitForConnectionCallback_1(IAsyncResult ar)
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

			try
			{
				byte[] sendData = encoding.GetBytes("服务端收到数据...");
				pipeServer.Write(sendData, 0, sendData.Length);

				// 重新等待新的数据链接
				pipeServer.Disconnect();
				pipeServer.BeginWaitForConnection(WaitForConnectionCallback_1, pipeServer);
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
				pipeServer.BeginWaitForConnection(WaitForConnectionCallback_2, pipeServer);
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
