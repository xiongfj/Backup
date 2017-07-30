

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














