using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Web;
using System.Web.Mvc;

namespace WebApplication9.Controllers
{
	public class HomeController : Controller
	{
		public ActionResult Index()
		{
			ViewBag.Title = "Home Page";

			//GetTest();
			PostTest();

			return View();
		}

		public void GetTest()
		{
			HttpClient http = new HttpClient();
			var ss = http.GetAsync("http://localhost:62648/api/Values/12").Result;
			ss.EnsureSuccessStatusCode();
			var result = ss.Content.ReadAsStringAsync();
		}

		public void PostTest()
		{
			HttpClient http = new HttpClient();

			//// 无法接收这种格式数据 ?!
			//var tokenRequestParameters = new List<KeyValuePair<string, string>>()
			//{
			//	new KeyValuePair<string, string>("value", "admin,zhao,user")
			//};
			//var requestContent = new FormUrlEncodedContent(tokenRequestParameters);

			var jsonText = JsonConvert.SerializeObject(Data.Instance);

			http.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
			//var content = new StringContent("{name:'asdasd', Email:'asdj@qq.com', labels: ['label-1','label-2','label-3']}", Encoding.UTF8, "application/json");
			var content = new StringContent(jsonText, Encoding.UTF8, "application/json");

			var ss = http.PostAsync("http://localhost:62648/api/Values", content).Result;
			ss.EnsureSuccessStatusCode();
			var result = ss.Content.ReadAsStringAsync();
		}
	}
}
