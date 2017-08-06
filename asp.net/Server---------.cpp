

* Execute	// 在当前请求的上下文中执行指定路径的处理程序，例如运行某个 exe文件

* GetLastError	// 返回前一个异常

* HtmlDecode(string s)	// 对 HTML 编码的字符串进行解码，并将解码发送到 System.IO.TextWriter 输出流
* HtmlDecode(string s, TextWriter output)
/*
* output:包含已解码的字符串
*/

* HtmlEncode( string s )	// 对字符串进行 HTML 编码，并将编码输出发送到 System.IO.TextWriter 输出流
* HtmlEncode( string s, TextWriter output)
/*
* output: 包含已经编码的字符串

* 例如要在页面上显示 "<p></p>xxx你好"，如果直接 Response.Write("<p></p>xxx你好"); -->结果 <p></p> 被编译消失了。
* 使用 Response'.Write( HtmlEncode("<p></p>xxx你好") );		输出结果则是： <p></p>xxx你好
*/

* MapPath（path）	// 返回与web服务器上指定虚拟路径相对的物理文件路径。
/*
* 参数接收一个路径，该函数将这个路径以相对路径解析，获取绝对路径返回。
* 具体见 0-----asp 手记中的 0------Server.asp
*/

* Transfer(string path ) 	// 终止当前页的执行，并为当前请求开始执行新页
* Transfer(string path, bool saveForm)
/*
* saveForm:	true-则保存QueryString 和 Form 集合，false-不保存
*/

* UrlDecode(sting s )	// 对字符串进行编码，该字符串为了进行 HTTP 传输而进行编码并且在 URL 中发送到服务端
* UrlDecode(string s, TextWriter output )


* UrlEncode(string s)	// 编码字符串，以便通过 URL 从 Web 服务端到客户端进行可靠的 HTTP 传输而进行编码并且在
* UrlEncode(string s, TextWriter output)

* ScriptTimeout	// 获取和设置请求超时

* MachineName	// 获取服务器的计算机名称
 
* UrlPathEncode	// 对 URL 字符串的路径部分进行 URL 编码，并返回已编码的字符串。
























