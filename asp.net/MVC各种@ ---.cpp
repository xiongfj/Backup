

* @Styles.Render("~/Content_1/css")		// 使用别名批量加载css
/* 对应 App_Start 文件夹下 BundleConfig.cs 

bundles.Add(new StyleBundle("~/Content_1/css").Include(
		  "~/Content/bootstrap.css",
		  "~/Content/site.css"));
*/				  
@Scripts.Render("~/bundles/modernizr")	// 
/* 加载 对应 App_Start 文件夹下 BundleConfig.cs 内指定的脚本
bundles.Add(new ScriptBundle("~/bundles/modernizr").Include(
  "~/Scripts/bootstrap.js",
  "~/Scripts/respond.js"));
 */

/


* @RenderBody()		// 用于 _Layout.cshtml 中, 表示用视图填充该标签所在的位置.
* @RenderPage(“~/Views/Shared/_Header.cshtml”) // 引用某个 .cshtml 到当前位置
* @RenderSection("abc", required: false)
/*
* 用在布局 _Layout.cshtml 中, 
* 占位符, 实际内容被使用这个布局的子页面 @section abc{@{Html.RegisterMvcPagerScriptResource();}} 大括号的内容代替
*/

* @Html.Partial("_LoginPartial")
/*
* <!-- 加载主 Views 的 /Shared/_LoginPartial.cshtml 到当前位置显示 -->
*/

* @Html.RenderPartial 与 @Html.Partial 区别
/*
Html.partial和RenderPartial的用法与区别
Html.partial和RenderPartial都是输出html片段，区别在于
Partial是将视图内容直接生成一个字符串并返回（相当于有个转义的过程），RenderPartial方法是直接输出至当前 HttpContext（因为是直接输出，所以性能好）。因此它们在视图中的使用方式是不同的：
MVC2：
<%Html.RenderPartial("PartialView");%>输出到 HttpContext
<%=Html.Partial("PartialView")%> 输出为string 直接到页面
MVC3：
@Html.Partial("BasicChart")
@{
Html.RenderPartial("BasicChart");
}
Html.partial和RenderPartial的其它三个重载很有用，第二个重载@{Html.RenderPartial("BasicChart",model);}
用这个重载可以在部分视图里使用强类型，然后在主视图中使用第二个参数传model过去，而不用controller
比如从list中传其中一项myClass过去
第三个重载用来传ViewData同理，如：@{Html.RenderPartial("BasicChart",ViewData["myData"]);}

(1).此方法内调用 htmlHelper.ViewContext.Writer 进行输出, 通俗的理解, Html.RenderPartial方法是直接绚烂模板, 将结果直接Reponse到浏览器, 所以在视图语法中需要用大括号{}”接住”RenderPartial方法的返回值. 所以又有人就这样说:RenderXXX的方法返回值是void, 在方法内部进行输出;

(2).强调一点, RenderPartial带"计算"功能, 可以直接"拿到"父View中传入的model,即不用单独为RenderPartial传入model

*/

* @RenderSection("css", required: false)	// 将子页面的 <style> 放到预留的位置
/*
* 
------------------------------
1. Index.cshtml:		// 必须是直接子页面!! 如果Index.cshtml 有 @{Html.RenderPartial("AppList");}, 那么在AppList.cshtml 内使用 2section css{..} 是无效的
@{
    ViewBag.Title = "Index";
    Layout = "~/Views/Shared/_SearchNavbar.cshtml";
}
@section css{
    <style>
        .software_environment {
            line-height: 25px;
        }

            .software_environment .item_name {
                font-family: 'Arial Unicode MS';
                font-size: 16px;
                color: #a59f9f;
            }

            .software_environment .item_value {
                font-family: 'Arial Unicode MS';
                margin-left: 20px;
                font-size: 14px;
            }
    </style>
}
--------------------------------
2.~/Views/Shared/_SearchNavbar.cshtml:
<!DOCTYPE html>
<html>
<head>
    @*<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />*@
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <link rel="search" href="/opensearchdescription.xml" type="application/opensearchdescription+xml" title="AppZip" />
    <title>@ViewBag.Title</title>
    @Styles.Render("~/Content/css")
    @Scripts.Render("~/bundles/modernizr")
    @Scripts.Render("~/bundles/jquery")
    @Scripts.Render("~/bundles/bootstrap")
    @Scripts.Render("~/bundles/custom")
    @RenderSection("css", required: false)		// 
</head>
.....

*/











