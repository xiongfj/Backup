
* ��ȡ�ͻ��� cookies
* ���տͻ����ϴ����ļ�
* ��ȡ post get ����

/*
* Request ��װ�˿ͻ���������Ϣ���Ǵӿͻ��˵õ�����(���������ȡ����);
* ���õ�����ȡ�����ݵķ����ǣ�Request.Form��Request.QueryString��Request���������ǰ���ֵ�һ����д������ȡ��ǰ�������

StringBuilder strBuider = new StringBuilder();
strBuider.Append("�ͻ���������IP��ַ��" + HttpContext.Current.Request.UserHostAddress + "</br>");
strBuider.Append("�ͻ���������汾:" + 				Request.UserAgent + "</br>");
strBuider.Append("��ǰ���ĸ�ҳ��URL��ת����:" + 	Request.UrlReferrer+ "</br>");
strBuider.Append("��ǰҪ���URL:" + 				Request.Url + "</br>");
strBuider.Append("��ǰҪ���URL���Ե�ַ:" + 		Request.Url.AbsolutePath + "</br>");
strBuider.Append("��ǰҪ���URL����URI:" + 			Request.Url.AbsoluteUri + "</br>");
strBuider.Append("��ǰҪ���URL���������˿�:" + 	Request.Url.Authority + "</br>");
strBuider.Append("��ǰҪ���URLʵ��������һ����:" + Request.Url.Host + "</br>");
strBuider.Append("��ǰҪ���URL�˿�:" + 			Request.Url.Port + "</br>");
strBuider.Append("��ǰҪ���URL�����ݵ�һ����:" + 	Request.Url.Segments[0] + "</br>");
strBuider.Append("��ǰҪ���URL�����ݵڶ�����:" + 	Request.Url.Segments[1] + "</br>");
strBuider.Append("��ǰҪ���URL�����ݵ�������:" + 	Request.Url.Segments[2] + "</br>");
strBuider.Append("�������ַ����Ĳ���"+			Request.QueryString + "</br>");
strBuider.Append("��ǰ��ҳ�ڷ������˵�ʵ��·��:" + 	Request.PhysicalPath + "</br>");
strBuider.Append("��ǰ�ļ��������ַ:" + 			Request.PhysicalApplicationPath + "</br>");
strBuider.Append("��ǰ��ҳ����Ե�ַ:" + 			Request.Path + "<br/>");
strBuider.Append("��ǰҳ���URL:" + 				Request.RawUrl + "<br/>");
strBuider.Append("�ͻ����ϴ����ļ���������:" + 		Request.Files.Count + "<br/>");
strBuider.Append("��ǰִ����ҳ����Ե�ַ:" + 		Request.FilePath + "<br/>");
strBuider.Append("�ͻ������������Ϣ:" + 			Request.Browser + "<br/>");
strBuider.Append("��ǰ���г���ķ�����������Ŀ¼:"+ Request.ApplicationPath + "<br/>");
strBuider.Append("�ͻ�����������ַ�����:" + 		Request.ContentEncoding + "<br/>");
*/

* AcceptTypes	// ��ȡ�ͻ���֧�ֵ� MIME �������͵��ַ�������

* ApplicationPath	// ��ȡ�������� ASP.NET Ӧ�ó��������Ӧ�ó����·��

* Browser	// ��ȡ�й���������Ŀͻ��˵���������ܵ���Ϣ

* Cookies	// ��ȡ�ͻ��˵� cookies
/*
HttpCookie cookie = HttpContext.Current.Request.Cookies["HttpDemo"];
*/

* CurrentExceptionFilePath	// ��ȡ������������� HTTP �ַ���

* FilePath	// ��ȡ��ǰ���������·��

* Files 	// ��ȡ������ͻ����ϴ����ļ�

* Form	// Form['name'] ��ȡ Post ��ʽ������
/*
* �� asp ��  Form һ������ȡ Post ��ʽ��  <Form ����s
*/

* Header	// ��ȡ HTTP ͷ����

* InputStream	// ��ȡ����� HTTP ʵ�����������

* Item 	// ��ȡ Cookies��Form��QueryString��ServerVariables ������ָ���Ķ����� C#�У�������ΪHttpRequet �����������

* Path	// ��ȡ��ǰ���������·��

* PathInfo	// ��ȡ���� URL ��չ������Դ�ĸ���·����Ϣ

* PhysicalPath	// ��ȡ������� URL ���Ӧ�������ļ�ϵͳ·��

* QueryString["name"]	// ��ȡ HTTP GET ��ʽ��ѯ�ַ�����������
/*
*
* ���� asp �� QuerySting() �� Get ��ʽ��Ӧ
*/

* RawUrl	// ��ȡ��ǰ�����ԭʼ URL

* ServerVariables	// ��ȡ web ��������������

* BinaryRead	// ִ�жԵ�ǰ����������ָ���ֽ����Ķ����ƶ�ȡ

* MapImageCoordinates	// ������ͼ���ֶδ������Ӱ��Ϊ�ʵ��� x/y ����ֵ

* MapPath��string path��	// Ϊ��ǰ��������� URL �е�����·��ӳ�䵽�������ϵ�����·��
/*
* path: ��һ�����·������Ե�ǰӦ�ó����·������������øú����Ļ���path ����ϵͳ����Ϊʱvs��������·��
* ��������һ��������·��
*/

* SaveAs	// �� HTTP ���󱣴浽����

* ValidateInput	// ��֤�ɿͻ���������ύ�����ݣ�������ھ���Ǳ��Σ�յ����ݣ��������쳣

* Url	// ��ȡ�йص�ǰ����� URL ��Ϣ


























