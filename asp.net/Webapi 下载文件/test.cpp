
[HttpGet]
.....
using (MemoryStream stream = new MemoryStream())
{
	var resp = new HttpResponseMessage(HttpStatusCode.OK)
	{
		Content = new ByteArrayContent(System.Text.Encoding.Unicode.GetBytes("asdhakshdashdasdhjs"))
	};
	resp.Content.Headers.ContentType = new MediaTypeHeaderValue("application/octet-stream");
	resp.Content.Headers.ContentDisposition = new ContentDispositionHeaderValue("attachment")
	{
		FileName = "privatekey.txt"		// 指定文件名
	};
	return resp;
}