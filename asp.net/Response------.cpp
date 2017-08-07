
* 设置客户端 cookies
* 提供下载文件, 即发送文件到客户端

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

* void Redirect(string url, bool endResponse)	// 页面跳转, 会销毁当前的 HttpContext, 使用 HttpContext.Server.Transfer() 则不会
/*
* url: 跳转的页面文件路径
* endResponse:	可选，是否终止当前页面

* 地址栏的 uri 会改变,页面刷型, 而 Server.Transfer 地址栏不会比变化, 貌似页面不会刷新!?
*/

// 将内容输出到页面
* void Write(char[], int, int )
* void Write(string)
* void Write(object)
* void Write(char)

* void WriteFile(string filename)
* void WriteFile(string filename, long offset, long size)
* void WriteFile(IntPtr fileHandle, long offset, long size);
* void WriteFile(string filaname, bool readIntoMemory);

* BinaryWrite	// 将一个二进制字符串写入 HTTP 输出流

* Clear	// 清除缓冲区流中的所有内容输出

* ClearContent	// 清除缓冲区流中的所有内容输出

* ClearHeaders	//清除缓冲区流中的所有头信息

* Close	// 关闭客户端的套接字连接

* End	// 将当前所有缓冲的输出发送到客户端。停止该页的执行，并引发 Applicaiton_EndRequest 事件

* Flush	// 向客户端发送当前所有缓冲的输出，Flush 方法和 End 方法都可以将缓冲
		// 的内容发送到客户端，但是 Flush 与 End 不同之处在于，Flush 不停止页面的执行。
		


















