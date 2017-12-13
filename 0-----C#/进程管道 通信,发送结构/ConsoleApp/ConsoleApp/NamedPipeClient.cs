using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
	public class NamedPipeClient
	{
		public void Connect()
		{
			using (NamedPipeClientStream pipeStream = new NamedPipeClientStream("testpipe"))
			{
				pipeStream.Connect();
				//在client读取server端写的数据
				using (StreamReader rdr = new StreamReader(pipeStream))
				{
					string temp;
					while ((temp = rdr.ReadLine()) != "stop")
					{
						Console.WriteLine("{0}:{1}", DateTime.Now, temp);
					}
				}
			}

			Console.Read();
		}
	}
}
