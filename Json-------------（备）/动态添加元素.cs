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
			IList<Model.CityItem> list = BLL.CityItem.SelectCity();

			// 返回 json 字符串
			Response.Write( JsonConvert.SerializeObject(list) + "<br/>");

			// 或者直接转换成 json 对象，
			// JObject json = (JObject)JsonConvert.DeserializeObject(str);
			// JArray array = (JArray)json["article"];			// 获取其中的数据之类的

			JArray array = new JArray();
			for ( int i = 0; i < list.Count; i++ )
			{
				JObject obj = new JObject( new JProperty("cityID", list[i].cityID), new JProperty("cityName", list[i].cityName) );
				array.Add(obj);
			}

			for (int i = 0; i < array.Count; i++)
			{
				Response.Write( array[i]["cityID"].ToString() + array[i]["cityName"].ToString() + "<br/>" );
			}

			// 可以使用 JObject.parse("json字符串") 生成 json 对象
			// 或者使用 JArray.parse() 生成数组
		} 
	}
}