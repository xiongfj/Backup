using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
	[Serializable]
	public class Email
	{
		public Email()
		{
			EmailTo = "EMailTo";
			EmailUserName = "Jacksd";
			EmailPassword = "xxxxxxxxxxxxxx";
			lists.Add(new People("asd", 132) );
			lists.Add(new People("44", 12) );
			lists.Add(new People("s", 34) );
			lists.Add(new People("bbbg", 62) );
		}

		// 默认邮件发送目的地
		public string EmailTo { get; set; }

		// 发送方邮件名
		public string EmailUserName { get; set; }

		// 发送方密码或者授权码，有些需要登录邮箱设置获取客户端授权码擦才能正确发送
		public string EmailPassword { get; set; }

		// 服务地址: 像 smtp.163.com
		public string EmailServer { get; set; }

		// 端口号，smtp 为 25
		public int EmailServerPort { get; set; }

		// 主题前缀
		public string EmailSubjectPrefix { get; set; }

		// 是否启用 ssl
		public bool EmailEnableSsl { get; set; }

		public List<People> lists { set; get; } = new List<People>();
	}
}
