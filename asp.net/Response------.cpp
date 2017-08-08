
* 设置客户端 cookies
* 提供下载文件, 即发送文件到客户端
* 向浏览器输出信息流

/* 类说明
* Response代表了服务器响应对象。每次客户端发出一个请求的时候，
* 服务器就会用一个响应对象来处理这个请求，处理完这个请求之后，服务器就会销毁这个相应对象，以便继续接受其它客服端请求。
*/

// 发送文件到客户端
/*
public static void ResponseStream(Stream stream, string fileName)
{
	if (stream.Length > 0)
	{
		try
		{
			long fileSize = stream.Length;
			System.Web.HttpContext.Current.Response.ContentType = "application/octet-stream";   //控制送出的文件类型
			System.Web.HttpContext.Current.Response.AppendHeader("Content-Disposition", " attachment;filename=" + HttpUtility.UrlEncode(fileName, System.Text.Encoding.UTF8));//向响应输出流增加HTTP头信息
			System.Web.HttpContext.Current.Response.AddHeader("Content-Length", fileSize.ToString());
			byte[] fileBuffer = new byte[fileSize];
			stream.Read(fileBuffer, 0, (int)fileSize);
			stream.Close();
			System.Web.HttpContext.Current.Response.BinaryWrite(fileBuffer);
			System.Web.HttpContext.Current.Response.End();

		}
		catch (Exception ex)
		{
			throw;
		}
	}
}
*/

// 设置客户端 cookies
/*
HttpCookie ck = new HttpCookie("HttpDemo");
ck.Values.Add("UserID", "踏浪帅");
Response.SetCookie(ck);
Response.Redirect("Default.aspx");
*/

------------------------ 属性 --------------------------------

* Buffer	// 获取或设置一个值，指示是否缓冲输出，并在完成处理整个响应之后将其发送

* BufferOutput	// 获取或设置一个值，该值指示是否缓冲输出，并在完成处理整个页之后将其发送

* Cache	// 获取 web 也得缓冲策略：过期时间、保密性、变化子句

* CacheControl	// 获取或设置输出流的 HTTP 字符集

* Charset	// 获取或设置输出流的 HTTP 字符集

* ContentEncoding	// 获取或设置输出流的 HTTP 字符集

* ContentType	// 获取或设置输出流的 HTTP MIME 类型
/*
'doc' => 'application/msword', 
'bin' => 'application/octet-stream',  
'exe' => 'application/octet-stream', 
'dll' => 'application/octet-stream',  
'pdf' => 'application/pdf',  
'xls' => 'application/vnd.ms-excel', 
'ppt' => 'application/vnd.ms-powerpoint', 
'zip' => 'application/zip', 
'mp3' => 'audio/mpeg', 
'wav' => 'audio/x-wav', 
'pdb' => 'chemical/x-pdb', 
'bmp' => 'image/bmp', 
'gif' => 'image/gif', 
'ief' => 'image/ief', 
'jpeg' => 'image/jpeg', 
'jpg' => 'image/jpeg', 
'jpe' => 'image/jpeg', 
'png' => 'image/png',
*/

* public HttpCookieCollection Cookies { get; }	// 获取响应 Cookies 集合

* Expires	// 获取或设置在浏览器上缓冲的页过期之前的分钟数。如果用户在页过期之前返回同一页，则显示缓存的版本

* ExpiresAbsolute	// 获取或设置将缓存信息从缓存中移除是的绝对日期时间

* Filter	// 获取或设置一个包装筛选器对象，该对象用于在传输之前修改 HTTP 实体主体

* IsClientConnected	// 获取一个值，通过该值指示客户端是否仍然链接在服务器上

* Output	// 启用到输出 HTTP 响应流的文本输出

* OutputStream	// 启用到输出 HTTP 内容主体的二进制输出

* RedirectLocation	// 获取或设置 HTTP 位置标头的值

* Status	// 设置返回到客户端的 Status 栏

* StatusCode	// 获取或设置返回客户端的输出的 HTTP 状态代码

* StatusDescription	// 获取或设置返回客户端的输出的 HTTP 状态字符串

* SuppressContent	// 获取或设置一个值，该值指示是否将 HTTP 内容发送到客户端.



----------------方法-----------------------------

* void Redirect(string url, bool endResponse)	// 页面跳转, 会销毁当前的 HttpContext, 
// 使用 HttpContext.Server.Transfer() 则不会
/*
* url: 跳转的页面文件路径
* endResponse:	可选，是否终止当前页面

* 地址栏的 uri 会改变,页面刷型, 而 Server.Transfer 地址栏不会比变化, 貌似页面不会刷新!?
*/

public static void RemoveOutputCacheItem(string path, string providerName);
public static void RemoveOutputCacheItem(string path);
public void AddCacheDependency(params CacheDependency[] dependencies);
public void AddCacheItemDependencies(ArrayList cacheKeys);
public void AddCacheItemDependencies(string[] cacheKeys);
public void AddCacheItemDependency(string cacheKey);
public void AddFileDependencies(ArrayList filenames);
public void AddFileDependencies(string[] filenames);
public void AddFileDependency(string filename);

public void AddHeader(string name, string value);
{
文件下载，指定默认名
// Response.AddHeader(”content-type”,”application/x-msdownload”);
// Response.AddHeader(”Content-Disposition”,”attachment;filename=要下载的文件名.rar”);

刷新页面
// Response.AddHeader “REFRESH”, ”60;URL=newpath/newpage.asp”
这等同于客户机端元素：
// <META HTTP-EQUIV=”REFRESH”, “60;URL=newpath/newpage.asp”

页面转向
// Response.Status = “302 Object Moved”
// Response.Addheader “Location”, “newpath/newpage.asp”
这等同于使用Response.Redirect方法：
// Response.Redirect “newpath/newpage.asp”

强制浏览器显示一个用户名/口令对话框
// Response.Status= “401 Unauthorized”
// Response.Addheader “WWW-Authenticate”, “BASIC”

强制浏览器显示一个用户名/口令对话框，然后使用BASIC验证把它们发送回服务器（将在本书后续部分看到验证方法）。
如何让网页不缓冲
// Response.Expires = 0
// Response.ExpiresAbsolute = Now() - 1
// Response.Addheader “pragma”,”no-cache”
// Response.Addheader “cache-control”,”private”
// Response.CacheControl = “no-cache

应用实例：文件下载
做下载中文显示乱码怎么办
在网站上文件下载都是直接点击文件联接就行了，这种方法有几个弊端:
1. 有些文件不会下载会直接调用相应的程序打开该文件
2. 不能隐藏实际文件地址。
3. 不能够从数据库中动态读取文件名进行改名下载
下面是asp.net,c#代码:
string fileName;//文件在数据库中的名称
string dir ;//文件在服务器的物理路径(如c:\aa\ddd\wj0000222.zdo)
long size ;//文件的大小
Response.AddHeader(”content-type”, “application/x-msdownload;”);
Response.AddHeader(”Content-Disposition”,”attachment;filename=”+fileName[自己定义的]);
Response.AddHeader(”content-length”, size.ToString());
Response.WriteFile(dir,0,size);

这种方法可以实现以上的目的，但是当文件名（fileName）为中文时在ie下载端显示的是乱码，有谁知道怎么解决。
我来做个总结吧 
其实楼上的方法是可行的，但有局限性 

关键在于UrlEncode这个东东，在下面不同情况下的结果是不一样的 
1。web.config 里responseEncoding=”gb2312″ 
2。web.config 里responseEncoding=”utf-8″ 
使用Server.UrlEncode的话必须responseEncoding=”utf-8″才会正确 

所以不要用Server.UrlEncode，换HttpUtility.UrlEncode 
string s=HttpUtility.UrlEncode(System.Text.UTF8Encoding.UTF8.GetBytes(”中文.txt”)); 
Response.AppendHeader(”Content-Disposition”, “attachment; filename=” + s);
}

public void AppendCookie(HttpCookie cookie);
public void AppendHeader(string name, string value);
public void AppendToLog(string param);
public string ApplyAppPathModifier(string virtualPath);
public IAsyncResult BeginFlush(AsyncCallback callback, object state);
public void BinaryWrite(byte[] buffer);	// 将一个二进制字符串写入 HTTP 输出流
public void Clear();	// 清除缓冲区流中的所有内容输出
public void ClearContent();	// 清除缓冲区流中的所有内容输出
public void ClearHeaders();	//清除缓冲区流中的所有头信息
public void Close();	// 关闭客户端的套接字连接
public void DisableKernelCache();
public void DisableUserCache();
public void End();	// 将当前所有缓冲的输出发送到客户端。停止该页的执行，并引发 Applicaiton_EndRequest 事件
public void EndFlush(IAsyncResult asyncResult);
public void Flush();	// 向客户端发送当前所有缓冲的输出，Flush 方法和 End 方法都可以将缓冲
		// 的内容发送到客户端，但是 Flush 与 End 不同之处在于，Flush 不停止页面的执行。
		
public void Pics(string value);
public void Redirect(string url, bool endResponse);
public void Redirect(string url);
public void RedirectPermanent(string url, bool endResponse);
public void RedirectPermanent(string url);
public void RedirectToRoute(string routeName);
public void RedirectToRoute(RouteValueDictionary routeValues);
public void RedirectToRoute(string routeName, object routeValues);
public void RedirectToRoute(string routeName, RouteValueDictionary routeValues);
public void RedirectToRoute(object routeValues);
public void RedirectToRoutePermanent(object routeValues);
public void RedirectToRoutePermanent(string routeName);
public void RedirectToRoutePermanent(RouteValueDictionary routeValues);
public void RedirectToRoutePermanent(string routeName, object routeValues);
public void RedirectToRoutePermanent(string routeName, RouteValueDictionary routeValues);
public void SetCookie(HttpCookie cookie);
public void TransmitFile(string filename, long offset, long length);
public void TransmitFile(string filename);
public void Write(object obj);
public void Write(char[] buffer, int index, int count);
public void Write(char ch);
public void Write(string s);
public void WriteFile(string filename);
public void WriteFile(string filename, bool readIntoMemory);
public void WriteFile(string filename, long offset, long size);
public void WriteFile(IntPtr fileHandle, long offset, long size);
public void WriteSubstitution(HttpResponseSubstitutionCallback callback);


















