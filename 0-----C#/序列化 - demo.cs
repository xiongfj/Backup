using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace ConsoleApp
{
	[Serializable]
	public class Man
	{
		public string name;
		public int age;

		public Man(string n, int a)
		{
			name = n;
			age = a;
		}
	}

	public class SerializTest
	{
		public void run()
		{
			Man man = new Man("asdasd", 92);
			MemoryStream ms = new MemoryStream();
			IFormatter formatter = new BinaryFormatter();
			formatter.Serialize(ms, man);
			byte[] bytes = ms.GetBuffer();


			MemoryStream mn = new MemoryStream(bytes);
			IFormatter result = new BinaryFormatter();
			Man pp = (Man)result.Deserialize(mn);
			Console.WriteLine(pp.name + " - " + pp.age);

			Console.Read();
		}

		
		//public void test()
		//{该函数失败
		//	Man man = new Man("asdasd", 92);

		//	byte[] bytes = null;
		//	try
		//	{
		//		MemoryStream ms = new MemoryStream();
		//		XmlSerializer formatter = new XmlSerializer(typeof(ConsoleApp.Man));
		//		formatter.Serialize(ms, man);
		//		bytes = ms.GetBuffer();
		//	}
		//	catch (Exception) { }


		//	try
		//	{
		//		MemoryStream mn = new MemoryStream(bytes);
		//		XmlSerializer formatter = new XmlSerializer(typeof(ConsoleApp.Man));
		//		Man o = (Man)formatter.Deserialize(mn);

		//		Console.WriteLine(o.name + o.age);
		//	}
		//	catch (Exception)
		//	{
		//	}


		//	Console.Read();
		//}

		public void soap()
		{
			byte[] bytes = null;
			try
			{
				Man man = new Man("asdasd", 92);
				SoapFormatter formatter = new SoapFormatter();
				MemoryStream ms = new MemoryStream();
				formatter.Serialize(ms, man);
				bytes = ms.GetBuffer();


			}
			catch (Exception) { }


			try
			{
				SoapFormatter formatter = new SoapFormatter();
				MemoryStream mn = new MemoryStream(bytes);
				Man o = (Man)formatter.Deserialize(mn);
				Console.WriteLine(o.name + o.age);
			}
			catch (Exception)
			{
			}
			Console.Read();
		}

		public void soapFile()
		{
			Man man = new Man("asdasd", 92);
			try
			{
				SoapFormatter formatter = new SoapFormatter();
				Stream stream = new FileStream("byte.txt", FileMode.OpenOrCreate, FileAccess.Write, FileShare.None);
				formatter.Serialize(stream, man);
				stream.Flush();
				stream.Close();
			}
			catch (Exception) { }

			try
			{
				SoapFormatter formatter = new SoapFormatter();
				Stream destream = new FileStream("byte.txt", FileMode.Open, FileAccess.Read, FileShare.Read);
				Man m = (Man)formatter.Deserialize(destream);
				byte[] bytes = new byte[destream.Length];
				destream.Read(bytes, 0, bytes.Length);

				destream.Flush();
				destream.Close();

				Console.WriteLine(m.name + m.age);
				Console.Read();
			}
			catch (Exception)
			{
			}
		}
	}
}
