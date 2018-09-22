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
/*一.CSRF是什么？
　　CSRF（Cross-site request forgery），中文名称：跨站请求伪造，也被称为：one click attack/session riding，缩写为：CSRF/XSRF。

二.CSRF可以做什么？
　　你这可以这么理解CSRF攻击：攻击者盗用了你的身份，以你的名义发送恶意请求。CSRF能够做的事情包括：以你名义发送邮件，发消息，盗取你的账号，甚至于购买商品，虚拟货币转账......造成的问题包括：个人隐私泄露以及财产安全。

三.CSRF漏洞现状
　　CSRF这种攻击方式在2000年已经被国外的安全人员提出，但在国内，直到06年才开始被关注，08年，国内外的多个大型社区和交互网站分别 爆出CSRF漏洞，如：NYTimes.com（纽约时报）、Metafilter（一个大型的BLOG网站），YouTube和百度HI......而 现在，互联网上的许多站点仍对此毫无防备，以至于安全业界称CSRF为“沉睡的巨人”。

四.CSRF的原理
　从上图可以看出，要完成一次CSRF攻击，受害者必须依次完成两个步骤：
　　1.登录受信任网站A，并在本地生成Cookie。
　　2.在不登出A的情况下，访问危险网站B。
　　
看到这里，你也许会说：“如果我不满足以上两个条件中的一个，我就不会受到CSRF的攻击”。是的，确实如此，但你不能保证以下情况不会发生：
　　1.你不能保证你登录了一个网站后，不再打开一个tab页面并访问另外的网站。
　　2.你不能保证你关闭浏览器了后，你本地的Cookie立刻过期，你上次的会话已经结束。（事实上，关闭浏览器不能结束一个会话，但大多数人都会错误的认为关闭浏览器就等于退出登录/结束会话了......）
　　3.上图中所谓的攻击网站，可能是一个存在其他漏洞的可信任的经常被人访问的网站。

具体步骤：

1、在Html表单里面使用了@Html.AntiForgeryToken()就可以阻止CSRF攻击。
2、相应的我们要在Controller中也要加入[ValidateAntiForgeryToken]过滤特性。该特性表示检测服务器请求是否被篡改。注意：该特性只能用于post请求，get请求无效。
3、至于JS，我们的项目中引用的是<script src="@Url.Content("~/Content/js/jqueryToken-1.4.2.js")" type="text/javascript"></script>

在JS时要使用： $.ajaxAntiForgery才行，
如：
 $.ajaxAntiForgery({
            type: "post",
            data: { GroupName: $("#GroupName").val(), GroupPhones: $("#GroupPhones").val() },
            dataType: "json",
            url: "/Event/Mass/AddGroup",
            success: function (data) {
                if (data) {

                    alert("添加成功 ");
                    $.unblockUI();
                }
                else {
                    alert("添加失败 ");
                }
         }
 })

注：对数据进行增删改时要防止csrf攻击！
*/



































