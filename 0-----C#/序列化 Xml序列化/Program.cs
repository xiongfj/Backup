using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Drawing;
using System.Drawing.Imaging;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Reflection;
using System.Runtime.Caching;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Web;
using System.Web.Caching;
using System.Web.Security;
using System.Xml;
using System.Xml.Serialization;

namespace ConsoleApp
{
	class Program
	{
		static void Main()
		{
			StringWriter sw = new StringWriter();
			Email email = new Email();

			XmlSerializer xml = new XmlSerializer(email.GetType());

			XmlSerializerNamespaces ns = new XmlSerializerNamespaces();
			ns.Add("ns", "ConsoleApp.Email");
			ns.Add("people", "ConsoleApp.People");

			xml.Serialize(sw, email, ns);
			Console.WriteLine(sw.ToString());



			Assembly ass = Assembly.Load("ConsoleApp");
			Type t = ass.GetType("ConsoleApp.Email");   //参数必须是类的全名
			if(t == null)
			{
				Console.WriteLine("类型不存在");
				return;
			}
			var x = new XmlSerializer(t);


			var txt = Encoding.Unicode.GetBytes(sw.ToString());
			MemoryStream ms = new MemoryStream(txt);
			var doc = (Email)(x.Deserialize(ms));
		}
	}

	[Serializable]
	public class People
	{
		public People() { }
		public People(string n, int a)
		{
			name = n;
			age = a;
		}
		public string name { set; get; }
		public int age { set; get; }
	}
}
