using Aop.Api;
using Aop.Api.Request;
using Aop.Api.Response;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication4
{
	public partial class callback : System.Web.UI.Page
	{
		protected void Page_Load(object sender, EventArgs e)
		{
			// 百度第三方登录教程 : http://developer.baidu.com/wiki/index.php?title=docs/oauth/authorization
			var code = Request.QueryString["code"];
			//申明一个容器result接收数据
			string result = "";
			//首先创建一个HttpWebRequest,申明传输方式POST
			HttpWebRequest req = (HttpWebRequest)WebRequest.Create("https://openapi.baidu.com/oauth/2.0/token?" +
				"grant_type=authorization_code" +       // 指明登录认证的方式, 还有其它方式必须选择正确!!
				"&code=" + code +
				"&client_id=6tSitMHLktVopCoO8D0Z1tAq" +
				"&client_secret=GTjnXhReW7gxL3o1Ntk5M2UGEIRzmRxc" +
				"&redirect_uri=http://sso.easyx.cn/callback.aspx");
			req.ContentType = "application/x-www-form-urlencoded";

			//添加POST参数
			//byte[] data = Encoding.UTF8.GetBytes(content);
			//req.ContentLength = data.Length;
			//using (Stream reqStream = req.GetRequestStream())
			//{
			//	reqStream.Write(data, 0, data.Length);
			//	reqStream.Close();
			//}

			//申明一个容器resp接收返回数据
			HttpWebResponse resp = (HttpWebResponse)req.GetResponse();
			Stream stream = resp.GetResponseStream();
			//获取响应内容 
			using (StreamReader reader = new StreamReader(stream, Encoding.UTF8))
			{
				result = reader.ReadToEnd();
			}
			// 获取的结果如下
			/*{"expires_in":2592000,"refresh_token":"22.ad103c2f6c6494ecb30c4ff7c8573384.315360000.1833158095.1628322434-10789598","access_token":"21.e869cc0456d28fe52afb17daeee8ddcd.2592000.1520390095.1628322434-10789598","session_secret":"fe94e996b03794a3af60e6e7c22aa866","session_key":"9mnRIQp0NPW8ZF8Y17jPHTMkX3rTPF9dFMK8r4SszTHB4RNztNkGHmJd7xYZlFGzJJGyumrwio0w5qiBDRE4tVaS8PCG9VBEajM=","scope":"basic"} */


			FileStream fs = new FileStream(Request.PhysicalApplicationPath + "\\lgo.txt", FileMode.Create);
			StreamWriter sw = new StreamWriter(fs);
			sw.Write(code + "\n" + result);
			sw.Flush();
			sw.Close();
			fs.Close();

			Response.Write(result);

















			// 支付宝第三方登录教程: https://docs.open.alipay.com/289/105656#s3
			// default.aspx 内的链接跳转; 支付宝用户登录后; 会回调这个页面执行的代码; 然后根据获得的auth_code获取用户的 access_token

			//var auth_code = Request.QueryString["auth_code"];
			//IAopClient client = new DefaultAopClient("https://openapi.alipaydev.com/gateway.do", "2016091200494991", "MIIEpQIBAAKCAQEAnuD88nBuTmbMUe5NKFM0LfXcpmqNSZjTCsxmfxcUQYkVl7k2GOY1kK/SWP+O/lb9bY5XXV/P+RQGTXSG1lB+Gqzz774rW0KTXEjZy0MGhFukD1+3PZJRZs9NHFc9I4W7uHCZmNZhDxuCGfB2sx5xZgKVoyBnB4snM1fNc+iAktk1q1AHDcHs6KikVqic/WVHJ8/YaflK/nRmp94gkLzSm/+At2k9s6h9W8rcTF7R+nXKXTFSXi6RVhL/DJEIJgsaopEmRezkeDAEpPaR5OmSHxz1eEcr8TxdzvAuW7E4VSJfCr5NMI8tsIEdxclu8Ij5SzT5oE/b222EVue0kSsTNwIDAQABAoIBAEvQXsOtpOVipnMePNFWStr3rI/43mzVMTfA69QPhknziUs6RTdCeyMM01pGsMxrZEloGAZllw9rX8qMJV+VT2eZSloHrBbDQSBTXyJgXHbCaBox+XW3IYLmvwwcEP+nbDmJ+bF18yDLZpzMI0g76a7c4tzRtHhkDZOxfUenFdt8bF/F7hseqFXl0lIVV15nWFjzG+xEFUE6KW2WoLaLLD41JDHJHAlK40OBy25uD+pe7k2mCdKUYhChL+CUUn5Z2iNvJB+J5PJX0goa6koiR0fBMUOFiGZe0TGfFnBFOAPN4dek6qBd+7wnuTMH2z58ECXwXlBN1GRJgrJaFgQm4MkCgYEAzUGQCUeQdmiTz8uKTgRnyry0G5WqjbLIjNBnIXFL2QnC1fmmT9hayqvYs1DpMOFpRL9Ny9/G8Ic2m7EWud0N4NIHp7ikuoHmidrd9H3UmB93Qi6m0Gpetp4GgqdfnyY+bCBDQQWWi/CjBoi5Vpj8ynJ8J/hNGuVJCtPnTjzuP1UCgYEAxihCeguJ3iFV6kcpRAviwK3HhXbp6q0Uu4PBLOfTpGa3mcOev6KmJJVuW7Ni2QuiI8HBxU7Rax27DxF5k598zvXx2DcqUFoy4hrw81jI2g6CVjck5bT1k3nEAa3BozHF0beuMxC2u+DDYp3znSPobwp9CvxAX0CzffEDwMHwUFsCgYEAnEBGx+mkvZ8Ktur5lD6iTKGucjlTJp9tMFUNzVWUKdrWaVGtG6dWJmb/hjIX8tAF9QG01Xi61yv3lDoRVNhE0lrQ3Qsgy6JLv7HPuWl4x31cqhMdhhcTlu1hg2Cq2FqitmkxCXSZkFpVoInAnX3FItBYV40cFVdqbUW3FcYokCkCgYEAspwXT2qXGmFxz3nU+EC+Ym5BKUvGDIF17o8T0CYl3km3tCFfNdylZNRMZNuMfZa+zvwWbIJewO5LbYmSzD01glatZvZSbZrfwm4GQVIFuIbbdFrAJ0y1Dfjzc4/que5jIGUv31dxXmd5taopq7pyB6SskPpOC42GPD7B4zzsH4ECgYEAo67aXyFlW3SwHPKpZN/d+YuKC2g7hKghsTyP6QZgeKYZ8VKAxi71Oz5J6m5ajr82kCtGsbsZVaLX7DR0hTj7wdr0ITkASV8em5mbwAmGnjtsmGw/UTW+LEfddKt09XaJbwX56arvWOK73ZQAZif5vm8oge7vgYDQ3VAidtJoUWA=", "json", "1.0", "RSA2", "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAnuD88nBuTmbMUe5NKFM0LfXcpmqNSZjTCsxmfxcUQYkVl7k2GOY1kK/SWP+O/lb9bY5XXV/P+RQGTXSG1lB+Gqzz774rW0KTXEjZy0MGhFukD1+3PZJRZs9NHFc9I4W7uHCZmNZhDxuCGfB2sx5xZgKVoyBnB4snM1fNc+iAktk1q1AHDcHs6KikVqic/WVHJ8/YaflK/nRmp94gkLzSm/+At2k9s6h9W8rcTF7R+nXKXTFSXi6RVhL/DJEIJgsaopEmRezkeDAEpPaR5OmSHxz1eEcr8TxdzvAuW7E4VSJfCr5NMI8tsIEdxclu8Ij5SzT5oE/b222EVue0kSsTNwIDAQAB", "UTF-8", false);
			//AlipaySystemOauthTokenRequest request = new AlipaySystemOauthTokenRequest();
			//request.GrantType = "authorization_code";
			////request.Code = auth_code;//"4b203fe6c11548bcabd8da5bb087a83b";
			////request.RefreshToken = "201208134b203fe6c11548bcabd8da5bb087a83b";
			//AlipaySystemOauthTokenResponse response = client.Execute(request);
			//label.Text = response.Body;
		}
	}
}