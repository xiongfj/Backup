
Controller.cs �ڴ���

public ActionResult Index()
{
	// �ַ�����ʽ��ҳ�����
	ViewData["data"] = HttpContext.Server.HtmlDecode("<html> ... </html>");
	return View("Index");
}



��ͼ�ļ���ʹ��: ������ʾҳ��

	@Html.Raw(ViewData["data"])
