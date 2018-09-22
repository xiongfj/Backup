using Microsoft.Owin;
using Microsoft.Owin.Hosting;
using Owin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;

namespace WebApplication13
{

	public class Program
	{
		public static void Main()
		{
			// 运行程序后在浏览器输入下面的地址访问
			var url = "http://localhost:8080/";
			var opt = new StartOptions(url);

			using (WebApp.Start<Startup>(opt))
			{
				Console.WriteLine("Server run at " + url + " , press Enter to exit.");
				Console.ReadLine();
			}
		}
	}
}