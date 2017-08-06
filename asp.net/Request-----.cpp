

* AcceptTypes	// 获取客户端支持的 MIME 接受类型的字符串数组

* ApplicationPath	// 获取服务器上 ASP.NET 应用程序的虚拟应用程序根路径

* Browser	// 获取有关正在请求的客户端的浏览器功能的信息

* Cookies	// 获取客户端发送的 cookies 的集合

* CurrentExceptionFilePath	// 获取或设置输出流的 HTTP 字符集

* FilePath	// 获取当前请求的虚拟路径

* Files 	// 获取客户端上载的文件(多部分 MIME 格式)集合

* Form	// 获取窗体变量集合
/*
* 与 asp 的  Form 一样，获取 Post 方式的  <Form 数据s
*/

* Header	// 获取 HTTP 头集合

* InputStream	// 获取传入的 HTTP 实体主体的内容

* Item 	// 获取 Cookies、Form、QueryString、ServerVariables 集合中指定的对象。在 C#中，该属性为HttpRequet 泪的索引器。

* Path	// 获取当前请求的虚拟路径

* PathInfo	// 获取具有 URL 扩展名的资源的附加路径信息

* PhysicalPath	// 获取与请求的 URL 相对应的物理文件系统路径

* QueryString["name"]	// 获取 HTTP 查询字符串变量集合
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


























