using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvc.Models
{
	public class AspUser
	{
		public static List<AspUser> Users = new List<AspUser> {
			new AspUser("aa"),
			new AspUser("abc"),
			new AspUser("vfbf"),
			new AspUser("sdsd"),
			new AspUser("adfdbc"),
			new AspUser("afdfrbc"),
			new AspUser("fdf"),
			new AspUser("fdfd"),
			new AspUser("afdgrbc")
		};

		public AspUser(string id)
		{
			Name = "HelloKitty " + id;
			addr = "address" + id;
			email = "email " + id;
		}

		public string Name { get; set; }
		public string addr { get; set; }
		public string email { get; set; }
	}
}