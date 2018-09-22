using System;
using System.Collections.Generic;
using Newtonsoft.Json;
using System.Linq;
using Newtonsoft.Json.Linq;

namespace lampblackSystem
{
	public partial class text : System.Web.UI.Page
	{ 
		protected void Page_Load(object sender, EventArgs e)
		{
			List<int> int_list = new List<int>() { 1,4,4,5,5,56,23,12,53,2,10,14 };
			string array_str = JsonConvert.SerializeObject(int_list);
			JArray array = JArray.Parse(array_str);				// 生成数组
			JProperty property = new JProperty("array", array); // 将数组做成 "array":[1,2,4,5,2,..] 的 key/value 对
			JObject obj = new JObject( property );              // 做成 {"array": [1,2,4,5,3,12..]} 对象
			JProperty p2 = new JProperty("obj", obj);           // 做成 "obj": {"array": [1,2,4,5,3,12..]} 的 key/value 对
			JObject mainObj = new JObject(p2);                  // 生成 {"obj": {"array": [1,2,3,4,5,12..]} } 无名对象
			mainObj.Add("text", "hello world!");            // {"obj": {"array": [1,2,3,4,5,12..]},
															//  "text": "hello world!" }
			
			/*
			[ {"ar1":"value1"},{"ar2": "value2"},{"ar3":"value33"} ]
			*/
			JArray arr = new JArray( new JObject(new JProperty("ar1", "value1")), new JObject(new JProperty("ar2", "value2")) );
			arr.Add(new JObject(new JProperty("ar3", "value33")));         // 向数组添加对象

			/*
			{
				....
				...
				"obj_array": [{"ar1":"value"}, {...}, { .. }]
			}
			*/
			mainObj.Add("obj_array", arr);

			Response.Write(mainObj.ToString());
		}
	}
}
/*
var chroma =
{
	"title": { "text": "油烟浓度曲线" },
	"type": "line",
	"legend":
	{
		"header": { "text": "排烟口" },
		"minimize": 1,
	},
	"plot": { "line-width": 1 },
	"series": [{"values": [1,2,3,5,56,5,755,6,4,3,3],
				"text": "asda"},
				]
}	

*/
