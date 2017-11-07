using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvc.Models
{
	public class AspUser
	{
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