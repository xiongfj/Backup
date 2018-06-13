using Autofac;
using System;
using System.Globalization;
using System.Net.Http;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Net.Http.Headers;
using System.Text;
using System.Net;
using ConsoleApp;

public class Program
{
	static void Main(string[] args)
	{
		//new OAuthClientTest().Get_Accesss_Token_By_Client_Credentials_Grant();

		//new OAuthClientTest().OAuth_Implicit_Test();

		new OAuthClientTest().OAuth_AuthorizationCode_Test();
	}

}

