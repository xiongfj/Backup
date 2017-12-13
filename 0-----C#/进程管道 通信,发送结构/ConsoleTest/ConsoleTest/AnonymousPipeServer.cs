using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
	public class AnonymousPipeServer
	{
		public void Connect()
		{
			Process process = new Process();
			process.StartInfo.FileName = @"F:\Temp\vs2017----\ConsoleApp\ConsoleApp\bin\Debug\ConsoleApp.exe";

			//创建匿名管道流实例，
			using (AnonymousPipeServerStream pipeStream =
				new AnonymousPipeServerStream(PipeDirection.Out, HandleInheritability.Inheritable))
			{
				//将句柄传递给子进程
				process.StartInfo.Arguments = pipeStream.GetClientHandleAsString();
				process.StartInfo.UseShellExecute = false;
				process.Start();

				// 判断进程是否启动
				Process[] vProcesses = Process.GetProcesses();
				foreach (Process vProcess in vProcesses)
					if (vProcess.ProcessName.Equals("ConsoleApp",
					StringComparison.OrdinalIgnoreCase))
					{
						break;
					}

				//销毁子进程的客户端句柄？
				pipeStream.DisposeLocalCopyOfClientHandle();

				using (StreamWriter sw = new StreamWriter(pipeStream))
				{
					sw.AutoFlush = true;
					//向匿名管道中写入内容
					sw.WriteLine("fdgfdgdgdfg");
				}
			}

			process.WaitForExit();
			process.Close();
		}

	}
}
