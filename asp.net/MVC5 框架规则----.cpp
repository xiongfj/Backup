
* �������ļ� MapController.cshtml �����Ӧ Views/Map/
* MapController.cshtml �ڵĺ����������� Views/Map/xx.cshtml ͬ��
	- ���� ���� return View() ��ʱ��Ż�������ύ�� xx.cshtml ��
	
/*
* ��<%:%>�� �� ��<%=%>�� ������ <%: %>���������ݽ���htmlEncode�����ˣ����Է�ֹ��վ�ű�����������XSS��������
* <%:<div>��ʾdiv<div> %> ��  <div>��ʾdiv<div>  ��  <%= <div>��ʾdiv<div> %> ��  ��ʾdiv
* <%: %>���ú���ʱ���ú���һ��Ҫ�з���ֵ�����򣬻ᱨ��
*/

* htmlAttributes:		// new{ target="_blank", @class="className"}
* method:		// FormMethod.Get/ Post
* routeValues:	// new { id=1}
* controllerName:		// ������ǰ������, HelloController �� Hello ������
* actionName:		// �������ڵķ�����

****** BeginForm(string actionName, string controllerName, object routeValues, FormMethod method, object htmlAttributes);
{
/*
* routeValues: new {id=12}
 ��Ч <form action="controllerName/actionName/12" method="method" />
*/
}
	
****** Html.ActionLink(..) --------------------------------
{
* linkText: 		//������ʾ��ҳ���ϵ��ı�

* actionName: 			//�������ڵķ�����

* controllerName:	//����������

* routeValues:		//���ݵ�action�Ĳ���
{/*
	Html.ActionLink("detail","Detail",new { id=1})
	ʵ���Ͼ��� : <a href="Products/Detail/1">detail</a>
*/}

* htmlAttributes:	// ���ñ�ǩ�� ����
/*
	Html.ActionLink("detail","Detail",new{id=1},new{ target="_blank", @class="className"})
������: <a href="Products/Detail/1" target="_blank" class="className">detail</a>

*class �ǹؼ���, ��Ҫʹ�� @class
*/
}


***** Html.ValidationSummary(true, "", new { @class = "text-danger" })		// ��֤�ؼ�
{
	true: ��ʾ��������ʾ��֤ʧ���б���Ϣ;
	"":		�Զ���� message
}

**** Html.LabelFor			// ��ʾһ�� <Label ../>

**** Html.EditorFor		// <input ../>

**** Html.ValidationMessageFor()		// <Span>, ������ input ������ʾ��֤ʧ�ܽ��
/*
@Html.ValidationMessageFor(model => model.Title, "", new { @class = "text-danger" })
*/

**** Html.DropDownList(string name, string optionLabel)			// ��ʾ <select>
/*
* name:		// ����Դ, �Ƿ����ڵ� ViewBag.name �� Session["name"] �� ViewData["name"]
* optionLabel:		// �Ƿ񴴽�һ�� <option value="">optionLabel<option>; ����=NULL
*/

*** Html.TextBox()			// <input>


*** Html.DisplayName
*** Html.DisplayNameFor(model => model.Title)		// ����ʾ������
*** Html.DisplayNameForModel


** Html.Display
**** Html.DisplayFor(modelItem => item.Title)		// ����ʾ�е�����
*** Html.DisplayForModel



}
	




























/
}
