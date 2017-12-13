using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
	public class AnonymousPipeClient
	{
		public void Connect(string pipe_id)
		{
			using (StreamReader sr = new StreamReader(
			new AnonymousPipeClientStream(PipeDirection.In, pipe_id)))
			{
				string line;
				while ((line = sr.ReadLine()) != null)
				{
					Console.WriteLine("Echo: {0}", line);
				}
			}
		}
	}
}
