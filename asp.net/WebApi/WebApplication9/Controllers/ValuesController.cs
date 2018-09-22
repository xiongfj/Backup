using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace WebApplication9.Controllers
{
	public class ValuesController : ApiController
	{
		// GET api/values
		public IEnumerable<string> Get()
		{
			return new string[] { "value1", "value2" };
		}

		// GET api/values/5
		public string Get(int id)
		{
			return "value";
		}

		// POST api/values
		// 发送格式要与接收格式匹配才能正常访问！
		public string Post(Data value)
		{
			return "success;;;; " + value;
		}

		// PUT api/values/5
		public void Put(int id, [FromBody]string value)
		{
		}

		// DELETE api/values/5
		public void Delete(int id)
		{
		}
	}

	public class Data
	{
		public static Data Instance
		{
			get
			{
				return new Data
				{
					Name = "kajsd young",
					Email = "password",
					Labels = new List<string> { "a", "b", "c" }
				};
			}
		}

		public string Name { set; get; }

		public string Email { set; get; }

		public List<string> Labels { set; get; }
	}

}
