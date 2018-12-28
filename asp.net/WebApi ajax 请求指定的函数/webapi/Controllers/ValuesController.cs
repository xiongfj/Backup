using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace webapi.Controllers
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
			return "Get(" + id + ")";
		}

		public string GetUser(int id)
		{
			return "GetUser(" + id + ")";
		}


		// POST api/values
		public string Post(string id)
		{
			return "Post(" + id + ")";
		}

		// 参数名称必须是 id 与路由配置的一样，才能使用 api/values/postPeople/id 的形式传递数据
		public string postPeople(string id)
		{
			return "postPeople(" + id + ")";
		}

		public string postModel(string id, [FromBody]Model model)	// 必须用 FromBody 才能接收到数据！？
		{
			return "postModel(" + model.name + ", " + model.address + ")" + id;
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

	public class Model
	{
		public string name { set; get; }
		public string address { set; get; }
	}
}
