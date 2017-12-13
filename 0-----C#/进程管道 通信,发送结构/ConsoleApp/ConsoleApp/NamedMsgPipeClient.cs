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

namespace ConsoleApp
{
	public class NamedMsgPipeClient
	{
		private string PipeName = "Maintain_QQRobot_Pipe";
		private Encoding encoding = Encoding.UTF8;
		private NamedPipeClientStream _pipe;

		public void Connect()
		{
			try
			{
				_pipe = new NamedPipeClientStream
				(
					".",
					PipeName,
					PipeDirection.InOut,
					PipeOptions.Asynchronous | PipeOptions.WriteThrough
				);

				_pipe.ConnectAsync();

				string message = "Connected!";

				int i = 20;
				while (i-- > 0)
				{
					Thread.Sleep(300);

					if (_pipe.IsConnected)
					{
						_pipe.ReadMode = PipeTransmissionMode.Message;
						byte[] data = encoding.GetBytes(message);
						_pipe.BeginWrite(data, 0, data.Length, PipeWriteCallback, _pipe);
					}
				}
			}
			catch (Exception ex)
			{
				Debug.Write(ex.StackTrace);
			}
		}

		private void PipeWriteCallback(IAsyncResult ar)
		{
			var pipe = (NamedPipeClientStream)ar.AsyncState;

			pipe.EndWrite(ar);
			pipe.Flush();
			//pipe.WaitForPipeDrain();		// 阻塞



			//Decoder decoder = Encoding.UTF8.GetDecoder();
			//Byte[] bytes = new Byte[10];
			//Char[] chars = new Char[10];

			//string message = "";
			//do
			//{
			//	int numBytes = _pipe.Read(bytes, 0, bytes.Length);
			//	int numChars = decoder.GetChars(bytes, 0, numBytes, chars, 0);
			//	message += new String(chars, 0, numChars);

			//} while (!_pipe.IsMessageComplete);
			//Console.WriteLine(message);
			//decoder.Reset();
		}

		/// <summary>
		/// 判断进程是否启动
		/// </summary>
		/// <returns></returns>
		private bool IsProcessExist(string processName)
		{
			Process[] processes = Process.GetProcesses();
			foreach (Process p in processes)
			{
				if (p.ProcessName.Equals("QQRobot", StringComparison.OrdinalIgnoreCase))
				{
					return true;
				}
			}
			return false;
		}

		/// <summary>
		/// 启动进程
		/// </summary>
		/// <param name="exePath"></param>
		private void StartQQRobot()
		{
			Process process = new Process();
			process.StartInfo.FileName = "D:\\QQRobot\\QQRobot.exe";
			process.Start();
		}

		/// <summary>
		/// 发送退出
		/// </summary>
		public void PostQuitMsg()
		{
			if (_pipe.IsConnected)
			{
				_pipe.ReadMode = PipeTransmissionMode.Message;
				byte[] data = encoding.GetBytes("cmd_quit");
				//_pipe.Write(data, 0, data.Length);

				_pipe.BeginWrite(data, 0, data.Length, PipeWriteCallback, _pipe);
			}
		}

		public void KillQQRobot()
		{
			Process[] processes = Process.GetProcesses();
			foreach (Process p in processes)
			{
				if (p.ProcessName.Equals("QQRobot", StringComparison.OrdinalIgnoreCase))
				{
					p.Kill();
				}
			}
		}
	}
}
