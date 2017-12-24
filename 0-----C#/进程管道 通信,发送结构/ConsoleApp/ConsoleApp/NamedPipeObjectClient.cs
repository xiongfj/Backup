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

namespace ConsoleApp
{
	// 发送数据到服务端或客户端, 需要引用共同的 dll, 把 Person 做成 dll 的形式,服务端客户端引用同一个dll或dll副本才正确
	//[Serializable]
	//public class Person
	//{
	//	public string name;
	//	public int age;

	//	public Person(string n, int a)
	//	{
	//		name = n;
	//		age = a;
	//	}
	//}

	public class NamedPipeObjectClient
	{
		private string PipeName = "Maintain_QQRobot_Pipe";
		private Encoding encoding = Encoding.UTF8;
		private NamedPipeClientStream _pipe;

		public void Connect()
		{
			Person person = new Person("Manlihhy", 26);
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

				while (true)
				{
					Thread.Sleep(300);

					if (_pipe.IsConnected)
					{
						_pipe.ReadMode = PipeTransmissionMode.Message;

						MemoryStream ms = new MemoryStream();
						IFormatter formatter = new BinaryFormatter();
						formatter.Serialize(ms, person);
						byte[] bytes = ms.GetBuffer();

						//_pipe.BeginWrite(bytes, 0, bytes.Length, PipeWriteCallback, _pipe);
						_pipe.Write(bytes, 0, bytes.Length);
						_pipe.WaitForPipeDrain();
						//_pipe.Write(bytes, 0, bytes.Length);
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
