using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using Microsoft.Owin;
using Microsoft.Owin.Security.Cookies;
using Microsoft.Owin.Security.Google;
using Microsoft.Owin.Security.OAuth;
using Owin;
using Authorization.Providers;
using Authorization.Models;
using Microsoft.Owin.Security;

namespace Authorization
{
    public partial class Startup
    {
        public static OAuthAuthorizationServerOptions OAuthOptions { get; private set; }

        public static string PublicClientId { get; private set; }

        // For more information on configuring authentication, please visit https://go.microsoft.com/fwlink/?LinkId=301864
        public void ConfigureAuth(IAppBuilder app)
        {
            // Configure the db context and user manager to use a single instance per request
            app.CreatePerOwinContext(ApplicationDbContext.Create);
            app.CreatePerOwinContext<ApplicationUserManager>(ApplicationUserManager.Create);

            // Enable the application to use a cookie to store information for the signed in user
            // and to use a cookie to temporarily store information about a user logging in with a third party login provider
            app.UseCookieAuthentication(new CookieAuthenticationOptions());
            app.UseExternalSignInCookie(DefaultAuthenticationTypes.ExternalCookie);

            // Configure the application for OAuth based flow
            PublicClientId = "self";
            OAuthOptions = new OAuthAuthorizationServerOptions
            {
                //TokenEndpointPath = new PathString("/Token"),
                //Provider = new ApplicationOAuthProvider(PublicClientId),
                //AuthorizeEndpointPath = new PathString("/api/Account/ExternalLogin"),
                //AccessTokenExpireTimeSpan = TimeSpan.FromDays(14),
                //// In production mode set AllowInsecureHttp = false
                //AllowInsecureHttp = true

				AllowInsecureHttp = true,
				AuthenticationMode = AuthenticationMode.Active,
				TokenEndpointPath = new PathString("/token"), //获取 access_token 授权服务请求地址
				AuthorizeEndpointPath = new PathString("/authorize"), //获取 authorization_code 授权服务请求地址
				AccessTokenExpireTimeSpan = TimeSpan.FromSeconds(10), //access_token 过期时间

				Provider = new OpenAuthorizationServerProvider(), //access_token 相关授权服务
				AuthorizationCodeProvider = new OpenAuthorizationCodeProvider(), //authorization_code 授权服务
				RefreshTokenProvider = new OpenRefreshTokenProvider() //refresh_token 授权服务
			};

            // Enable the application to use bearer tokens to authenticate users
            app.UseOAuthBearerTokens(OAuthOptions);

            // Uncomment the following lines to enable logging in with third party login providers
            //app.UseMicrosoftAccountAuthentication(
            //    clientId: "",
            //    clientSecret: "");

            //app.UseTwitterAuthentication(
            //    consumerKey: "",
            //    consumerSecret: "");

            //app.UseFacebookAuthentication(
            //    appId: "",
            //    appSecret: "");

            //app.UseGoogleAuthentication(new GoogleOAuth2AuthenticationOptions()
            //{
            //    ClientId = "",
            //    ClientSecret = ""
            //});
        }
    }
}
