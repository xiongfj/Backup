
* 读取客户端 cookies
* 接收客户端上传的文件
* 获取 post get 数据

/*
* Request 封装了客户端请求信息，是从客户端得到数据(从浏览器获取数据);
* 常用的三种取得数据的方法是：Request.Form、Request.QueryString、Request其第三种是前两种的一个缩写，可以取代前两种情况

StringBuilder strBuider = new StringBuilder();
strBuider.Append("客户端主机的IP地址：" + HttpContext.Current.Request.UserHostAddress + "</br>");
strBuider.Append("客户端浏览器版本:" + 				Request.UserAgent + "</br>");
strBuider.Append("当前由哪个页面URL跳转过来:" + 	Request.UrlReferrer+ "</br>");
strBuider.Append("当前要求的URL:" + 				Request.Url + "</br>");
strBuider.Append("当前要求的URL绝对地址:" + 		Request.Url.AbsolutePath + "</br>");
strBuider.Append("当前要求的URL绝对URI:" + 			Request.Url.AbsoluteUri + "</br>");
strBuider.Append("当前要求的URL主机名跟端口:" + 	Request.Url.Authority + "</br>");
strBuider.Append("当前要求的URL实例主机的一部分:" + Request.Url.Host + "</br>");
strBuider.Append("当前要求的URL端口:" + 			Request.Url.Port + "</br>");
strBuider.Append("当前要求的URL的内容第一个段:" + 	Request.Url.Segments[0] + "</br>");
strBuider.Append("当前要求的URL的内容第二个段:" + 	Request.Url.Segments[1] + "</br>");
strBuider.Append("当前要求的URL的内容第三个段:" + 	Request.Url.Segments[2] + "</br>");
strBuider.Append("浏览器地址栏后的参数"+			Request.QueryString + "</br>");
strBuider.Append("当前网页在服务器端的实际路径:" + 	Request.PhysicalPath + "</br>");
strBuider.Append("当前文件的物理地址:" + 			Request.PhysicalApplicationPath + "</br>");
strBuider.Append("当前网页的相对地址:" + 			Request.Path + "<br/>");
strBuider.Append("当前页面的URL:" + 				Request.RawUrl + "<br/>");
strBuider.Append("客户端上传的文件（个数）:" + 		Request.Files.Count + "<br/>");
strBuider.Append("当前执行网页的相对地址:" + 		Request.FilePath + "<br/>");
strBuider.Append("客户端浏览器的信息:" + 			Request.Browser + "<br/>");
strBuider.Append("当前运行程序的服务器端虚拟目录:"+ Request.ApplicationPath + "<br/>");
strBuider.Append("客户端浏览器的字符设置:" + 		Request.ContentEncoding + "<br/>");
*/

* AcceptTypes	// 获取客户端支持的 MIME 接受类型的字符串数组

* ApplicationPath	// 获取服务器上 ASP.NET 应用程序的虚拟应用程序根路径

* Browser	// 获取有关正在请求的客户端的浏览器功能的信息

* Cookies	// 获取客户端的 cookies
/*
HttpCookie cookie = HttpContext.Current.Request.Cookies["HttpDemo"];
*/

* CurrentExceptionFilePath	// 获取或设置输出流的 HTTP 字符集

* FilePath	// 获取当前请求的虚拟路径

* Files 	// 获取浏览器客户端上传的文件

* Form	// Form['name'] 获取 Post 方式的数据
/*
* 与 asp 的  Form 一样，获取 Post 方式的  <Form 数据s
*/

* Header	// 获取 HTTP 头集合

* InputStream	// 获取传入的 HTTP 实体主体的内容

* Item 	// 获取 Cookies、Form、QueryString、ServerVariables 集合中指定的对象。在 C#中，该属性为HttpRequet 泪的索引器。

* Path	// 获取当前请求的虚拟路径

* PathInfo	// 获取具有 URL 扩展名的资源的附加路径信息

* PhysicalPath	// 获取与请求的 URL 相对应的物理文件系统路径

* QueryString["name"]	// 获取 HTTP GET 方式查询字符串变量集合
/*
*
* 类似 asp 的 QuerySting() 与 Get 方式对应
*/

* RawUrl	// 获取当前请求的原始 URL

* ServerVariables	// 获取 web 服务器变量集合

* BinaryRead	// 执行对当前输入流进行指定字节数的二进制读取

* MapImageCoordinates	// 将传入图像字段窗体参数影射为适当的 x/y 坐标值

* MapPath（string path）	// 为当前请求将请求的 URL 中的虚拟路径映射到服务器上的物理路径
/*
* path: 是一个相对路径，相对当前应用程序的路径，如果不是用该函数的话，path 将被系统误认为时vs的主程序路径
* 函数返回一个完整的路径
*/

* SaveAs	// 将 HTTP 请求保存到磁盘

* ValidateInput	// 验证由客户端浏览器提交的数据，如果存在具有潜在危险的数据，则引发异常

* Url	// 获取有关当前请求的 URL 信息


























