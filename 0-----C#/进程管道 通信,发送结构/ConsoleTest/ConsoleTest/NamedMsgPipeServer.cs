using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleTest
{
	public class NamedMsgPipeServer
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
			_pipe.BeginWaitForConnection(WaitForConnectionCallback_2, _pipe);
		}

		private void WaitForConnectionCallback(IAsyncResult ar)
		{
			var pipeServer = (NamedPipeServerStream)ar.AsyncState;
			pipeServer.EndWaitForConnection(ar);

			using (StreamReader sr = new StreamReader(pipeServer))
			{
				string msg = sr.ReadToEnd();
				Console.WriteLine(msg);
			}

			Decoder decoder = Encoding.UTF8.GetDecoder();
			Byte[] bytes = new Byte[10];
			Char[] chars = new Char[10];

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

			Decoder decoder = Encoding.UTF8.GetDecoder();
			Byte[] bytes = new Byte[10];
			Char[] chars = new Char[10];
			string message = "";
			try
			{
				do
				{
					int numBytes = _pipe.Read(bytes, 0, bytes.Length);
					int numChars = decoder.GetChars(bytes, 0, numBytes, chars, 0);
					message += new String(chars, 0, numChars);

				} while (!_pipe.IsMessageComplete);
			}
			catch (Exception)
			{
				_pipe.Dispose();
				InitPipe();
			}
			Console.WriteLine(message);
			decoder.Reset();

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
			switch(cmd)
			{
				case "cmd_quit":break;
				default:break;
			}
		}
	}
}
