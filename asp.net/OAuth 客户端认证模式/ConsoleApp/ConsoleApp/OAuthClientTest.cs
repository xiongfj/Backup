using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Web;
using System.Web.Script.Serialization;

namespace ConsoleApp
{
	public class OAuthClientTest
	{
		private HttpClient _httpClient;

		public OAuthClientTest()
		{
			_httpClient = new HttpClient();
		}

		private async Task<string> GetToken(string grantType, string refreshToken = null)
		{
			var clientId = "xishuai";
			var clientSecret = "123";
			var parameters = new Dictionary<string, string>();
			parameters.Add("client_id", clientId);
			parameters.Add("client_secret", clientSecret);
			parameters.Add("grant_type", grantType);
			if (!string.IsNullOrEmpty(refreshToken))
			{
				parameters.Add("refresh_token", refreshToken);
			}

			//_httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue(
			//	"Basic",
			//	Convert.ToBase64String(Encoding.ASCII.GetBytes(clientId + ":" + clientSecret)));

			var response = await _httpClient.PostAsync("/token", new FormUrlEncodedContent(parameters));
			var responseValue = await response.Content.ReadAsStringAsync();
			if (response.StatusCode != HttpStatusCode.OK)
			{
				Console.WriteLine(response.StatusCode);
				Console.WriteLine(await response.Content.ReadAsStringAsync());
				return null;
			}
			return responseValue;
		}

		public void OAuth_ClientCredentials_Test()
		{
			_httpClient.BaseAddress = new Uri("http://localhost:55824/");
			var tokenResponse = GetToken("client_credentials").Result; //获取 access_token

			Console.WriteLine("0. " + tokenResponse);

			// 提取access_token, 实际不用正则提取, 不知方法 ..
			Match access_1 = new Regex(@"(?<=access_token"":"")\S+?(?="")").Match(tokenResponse);
			Console.WriteLine("access_1. " + access_1.Value);

			// 附带 access_token 请求服务器资源
			_httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", access_1.Value);

			var response =  _httpClient.GetAsync($"/api/values").Result;
			if (response.StatusCode != HttpStatusCode.OK)
			{
				Console.WriteLine(response.StatusCode);
				Console.WriteLine(response.Content.ReadAsStringAsync().Result);
			}
			Console.WriteLine("2. " + response.Content.ReadAsStringAsync().Result);

			Match refres_1 = new Regex(@"(?<=refresh_token"":"")\S+?(?="")").Match(tokenResponse);
			var tokenResponseTwo = GetToken("refresh_token", refres_1.Value).Result;
			Console.WriteLine("refres_1. " + refres_1.Value);

			Match access_2 = new Regex(@"(?<=access_token"":"")\S+?(?="")").Match(tokenResponseTwo);
			Console.WriteLine("access_2. " + access_2.Value);
			Match refres_2 = new Regex(@"(?<=refresh_token"":"")\S+?(?="")").Match(tokenResponseTwo);
			Console.WriteLine("refres_2. " + refres_2.Value);

			_httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", access_2.Value);
			var responseTwo =  _httpClient.GetAsync($"/api/values").Result;
			Console.WriteLine("5. " + responseTwo.Content.ReadAsStringAsync().Result);
		}
	}
}
