using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Globalization;
using System.Linq;
using System.Net.Mail;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
	class Program
	{
		static void Main(string[] args)
		{
			// 模拟数据库中存储的数据; 实际使用时需要事先提供
			var data = new StringDictionary();
			data.Add("EmailTo", "837943056@qq.com");
			data.Add("EmailUserName", "xiongfjabc@163.com");
			data.Add("EmailPassword", "xiongfj123");
			data.Add("EmailServer", "smtp.163.com");
			data.Add("EmailServerPort", "25");
			data.Add("EmailSubjectPrefix", "Myid");
			data.Add("EmailEnableSsl", "True");

			// 获取类中属性键对： 属性名-属性PropertyInfo
			var result = new Email();
			var settingsProps = new Dictionary<String, PropertyInfo>(StringComparer.OrdinalIgnoreCase);
			foreach (var prop in result.GetType().GetProperties())
			{
				settingsProps[prop.Name] = prop;
			}

			foreach (DictionaryEntry entry in data)
			{
				string name = (string)entry.Key;
				PropertyInfo property = null;

				// 定位属性名对应的 属性PropertyInfo -> property
				if (settingsProps.TryGetValue(name, out property))
				{
					if (property.CanWrite)
					{
						// 将 data 中的数据对应的设置到对应的 property 中去, 会自行并判断数据类型并转换
						string value = (string)entry.Value;
						var propType = property.PropertyType;
						if (propType.IsEnum)
						{
							property.SetValue(result, Enum.Parse(propType, value), null);
						}
						else
						{
							property.SetValue(result, Convert.ChangeType(value, propType, CultureInfo.CurrentCulture), null);
						}
					}
				}
			}
			foreach (var p in result.GetType().GetProperties())
			{
				Console.WriteLine(p.GetValue(result));
			}
		}
	}
}
