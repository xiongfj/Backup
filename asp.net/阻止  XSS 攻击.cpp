\

1.对所有内容进行HTML编码:
/*
* Html.Encode() 

* 例如: <% Html.Encode(Model.FirstName) %>
* 或 在 ASP.NET 4.0 中 <%:Model.FirstName %> 使用封装好的特定格式*
* 或在 Razor 视图引擎默认使用 Html 编码:  @Model.FirstName
*/

2.Html.AttributeEncode(..) 或 Url.Encode() 防止 XSS 攻击
/*
<a href="<%=Url.Action("index", "home", new {name=Html.AttributeEncode(ViewBag.name)})%>">click here</a>

或者 <a href="<%Url.Encode(Url.Action("idnex", "name", new {name=ViewBag.name}))%>">clike here </a>
*
*/

3.JavaScript编码用户输入 @Encoder.JavaScriptEncode(ViewBag.UserName, false)
/*
* 需要引用 @using Microsoft.Security.Application
* 为了防止 16 进制的脚本代码攻击, 16进制的代码 HTML 编码无法检测. 
例如:
	\x3cscript\x3e%20alert(\x27pwnd\x27)%20\x3c/script\x3e
	依然会执行成 <script> alert("pwnd") </script>
	

*/



4.威胁,跨站请求伪造




































