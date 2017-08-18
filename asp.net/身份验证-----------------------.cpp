
** 表单验证
{
* 登录成功后需要注册票据:
FormsAuthentication.RedirectFromLoginPage(UserID, false);    //页面注册 关键 UsersID表示登录ID
* 退出系统后需要注销票据:
FormsAuthentication.SignOut();     //撕毁票据 退出登录

* 默认的配置
/*
<authentication mode="Forms">
     <forms
         name=".ASPXAUTH"
         loginUrl="login.aspx"
         defaultUrl="default.aspx"
         protection="All"		// Cookie的保护模式，可取值包括All（同时进行加密和数据验证）、Encryption（仅加密）、Validation（仅进行数据验证）和None。为了安全，该属性通常从不设置为None
         timeout="30"		// Cookie的过期时间。
         path="/"			// Cookie的路径。可以通过FormsAuthentication.FormsCookiePath属性得到该配置值。
         requireSSL="false"	// 在进行Forms Authentication时，与服务器交互是否要求使用SSL。可以通过FormsAuthentication.RequireSSL属性得到该配置值
         slidingExpiration="false"	// false-登录后timeotu时间后过期; true-如果用户有操作,即有与服务器交互数据,又重新计算timeout时间
         enableCrossAppRedirects="false"	// 是否可以将以进行了身份验证的用户重定向到其他应用程序中。通过FormsAuthentication.EnableCrossAppRedirects属性可以得到该配置值。为了安全考虑，通常总是将该属性设置为false
         cookieless="UseDeviceProfile"	// 定义是否使用Cookie以及Cookie的行为。Forms Authentication可以采用两种方式在会话中保存用户凭据信息，一种是使用Cookie，即将用户凭据记录到Cookie中，每次发送请求时浏览器都会将该Cookie提供给服务器。另一种方式是使用URI，即将用户凭据当作URL中额外的查询字符串传递给服务器。该属性有四种取值——UseCookies（无论何时都使用Cookie）、UseUri（从不使用Cookie，仅使用URI）、AutoDetect（检测设备和浏览器，只有当设备支持Cookie并且在浏览器中启用了Cookie时才使用Cookie）和UseDeviceProfile（只检测设备，只要设备支持Cookie不管浏览器是否支持，都是用Cookie）。通过FormsAuthentication.CookieMode属性可以得到该配置值。通过FormsAuthentication.CookiesSupported属性可以得到对于当前请求是否使用Cookie传递用户凭证
         domain=""		// Cookie的域。通过FormsAuthentication.CookieDomain属性可以得到该配置值
     />
</authentication>
*/

* web.config 配置
/*
* 用户打开站点的时候如果没有登录; 会自动跳转到/Manager/login.aspx 页面 -->
* path="/" 表示根目录即整个站点禁止匿名访问; 可以设置某个文件夹禁止匿名访问
* "?" 表示匿名用户; "*" 表示所有用户
* protection="All" 表示采用验证和加密方式
	<authentication mode="Forms">
	<forms name="myTeacher" loginUrl="~/Manager/login.aspx" protection="All" path="/" timeout="60"></forms>
	</authentication>
	<authorization>
	<deny users="?"/>		// 禁止匿名用户;  MVC 中的验证不需要这些
	</authorization>
*/

* 配置个别允许访问目录 
/*允许所有用户访问Script文件夹-->
* 一般这里放 js 脚本之类的
    <location path="Script">
      <system.web>
        <authorization>
          <allow users="*" />
        </authorization>
      </system.web>
    </location>
	  
*/

* 允许所有用户访问Code/ValidateCode.ashx文件，这个是用来生成验证码图片-->
/*
  <location path="Code/ValidateCode.ashx">
    <system.web>
      <authorization>
        <allow users="*" />
      </authorization>
    </system.web>
  </location>
 */
}
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  