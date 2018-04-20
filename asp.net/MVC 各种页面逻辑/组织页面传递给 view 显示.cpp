
Controller.cs 内代码

public ActionResult Index()
{
	// 字符串形式的页面编码
	ViewData["data"] = HttpContext.Server.HtmlDecode("<html> ... </html>");
	return View("Index");
}



视图文件内使用: 可以显示页面

	@Html.Raw(ViewData["data"])
