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

		private async Task<string> GetToken(string grantType, string refreshToken = null, string authorizationCode = null)
		{
			var clientId = "xishuai";
			var clientSecret = "123";
			var parameters = new Dictionary<string, string>();
			parameters.Add("client_id", clientId);
			parameters.Add("client_secret", clientSecret);
			parameters.Add("grant_type", grantType);

			if (!string.IsNullOrEmpty(authorizationCode))
			{
				parameters.Add("code", authorizationCode);
				parameters.Add("redirect_uri", "http://localhost:55211/api/authorization_code"); //和获取 authorization_code 的 redirect_uri 必须一致，不然会报错
			}
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

		private async Task<string> GetAuthorizationCode()
		{
			var clientId = "xishuai";
			_httpClient.BaseAddress = new Uri("http://localhost:55211/");

			var response = await _httpClient.GetAsync($"/authorize?response_type=code&client_id={clientId}&redirect_uri={HttpUtility.UrlEncode("http://localhost:55211/api/authorization_code")}");
			var authorizationCode = await response.Content.ReadAsStringAsync();
			if (response.StatusCode != HttpStatusCode.OK)
			{
				return null;
			}
			return authorizationCode;
		}

		public void OAuth_AuthorizationCode_Test()
		{
			// 获取 code 
			var authorizationCode = GetAuthorizationCode().Result; //获取 authorization_code

			// 使用 code 获取 令牌
			var tokenResponse = GetToken("authorization_code", null, authorizationCode).Result; //根据 authorization_code 获取 access_token
			Match access_1 = new Regex(@"(?<=access_token"":"")\S+?(?="")").Match(tokenResponse);
			Console.WriteLine("access_1. " + access_1.Value);

			Match refres_1 = new Regex(@"(?<=refresh_token"":"")\S+?(?="")").Match(tokenResponse);
			Console.WriteLine("refres_1. " + refres_1.Value);

			// 使用令牌访问资源
			_httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", access_1.Value);
			var response = _httpClient.GetAsync($"/api/values").Result;
			if (response.StatusCode != HttpStatusCode.OK)
			{
				Console.WriteLine(response.StatusCode);
				Console.WriteLine( response.Content.ReadAsStringAsync().Result);
			}
			Console.WriteLine(response.Content.ReadAsStringAsync().Result);

			// 获取新的令牌
			var tokenResponseTwo = GetToken("refresh_token", refres_1.Value).Result; //根据 refresh_token 获取 access_token

			Match access_2 = new Regex(@"(?<=access_token"":"")\S+?(?="")").Match(tokenResponseTwo);
			Console.WriteLine("access_2. " + access_2.Value);
			Match refres_2 = new Regex(@"(?<=refresh_token"":"")\S+?(?="")").Match(tokenResponseTwo);
			Console.WriteLine("refres_2. " + refres_2.Value);

			// 使用新令牌访问资源
			_httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", access_2.Value);
			var responseTwo =  _httpClient.GetAsync($"/api/values").Result;
			Console.WriteLine(responseTwo.Content.ReadAsStringAsync().Result);
		}

	}
}
