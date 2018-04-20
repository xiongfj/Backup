using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication4
{
	public partial class _default : System.Web.UI.Page
	{
		protected void Page_Load(object sender, EventArgs e)
		{

			////申明一个容器result接收数据
			//string result = "";
			////首先创建一个HttpWebRequest,申明传输方式POST
			////HttpWebRequest req = (HttpWebRequest)WebRequest.Create("https://openapi.baidu.com/oauth/2.0/token?grant_type=client_credentials&client_id=6tSitMHLktVopCoO8D0Z1tAq&client_secret=GTjnXhReW7gxL3o1Ntk5M2UGEIRzmRxc");
			//HttpWebRequest req = (HttpWebRequest)WebRequest.Create("http://openapi.baidu.com/oauth/2.0/authorize?response_type=code&client_id=6tSitMHLktVopCoO8D0Z1tAq&redirect_uri=http://sso.easyx.cn/callback.aspx&display=popup");
			//req.ContentType = "application/x-www-form-urlencoded";

			////添加POST参数
			////byte[] data = Encoding.UTF8.GetBytes(content);
			////req.ContentLength = data.Length;
			////using (Stream reqStream = req.GetRequestStream())
			////{
			////	reqStream.Write(data, 0, data.Length);
			////	reqStream.Close();
			////}

			////申明一个容器resp接收返回数据
			//HttpWebResponse resp = (HttpWebResponse)req.GetResponse();
			//Stream stream = resp.GetResponseStream();
			////获取响应内容 
			//using (StreamReader reader = new StreamReader(stream, Encoding.UTF8))
			//{
			//	result = reader.ReadToEnd();
			//}
			//Response.Write(result);
		}
	}
}