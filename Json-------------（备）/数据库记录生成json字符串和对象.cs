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
			IList<CityItem> list = xxx....

			// 返回 json 字符串
			Response.Write( JsonConvert.SerializeObject(list) + "<br/>");

			// 或者直接转换成 json 对象，
			// JObject json = (JObject)JsonConvert.DeserializeObject(str);
			// JArray array = (JArray)json["article"];			// 获取其中的数据之类的

			// 自定义复杂的 json 数据
			var jsonObj = new JObject(
				new JProperty("total", list.Count),
				new JProperty("rows", new JArray(
						from p in list select new JObject(
								new JProperty("cityID", p.cityID),
								new JProperty("cityName", p.cityName)
							)
					)));

			Response.Write( jsonObj["total"] + "<br/>" );
			for (int i = 0; i < list.Count; i++)
			{
				Response.Write( jsonObj["rows"][i]["cityID"].ToString() + jsonObj["rows"][i]["cityName"].ToString() + "<br/>" );
			}

			// 可以使用 JObject.parse("json字符串") 生成 json 对象
			// 或者使用 JArray.parse() 生成数组
		} 
	}
}


-- CityItem.cs --------------------------------------------------

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
	public class CityItem	// 一个城市里面有许多排口
	{
		public long cityID { set; get; }
		public string cityName { set; get; }

		public CityItem(long id, string name)
		{
			cityID = id;
			cityName = name;
		}
	}
}
