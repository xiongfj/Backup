
* 控制器文件 MapController.cshtml 必须对应 Views/Map/
* MapController.cshtml 内的函数名必须与 Views/Map/xx.cshtml 同名
	- 这样 函数 return View() 的时候才会把数据提交到 xx.cshtml 上
	
/*
* “<%:%>” 和 “<%=%>” 的区别： <%: %>对其中内容进行htmlEncode编码了，可以防止跨站脚本攻击（即：XSS攻击）。
* <%:<div>显示div<div> %> →  <div>显示div<div>  而  <%= <div>显示div<div> %> →  显示div
* <%: %>中用函数时，该函数一定要有返回值，否则，会报错。
*/

* htmlAttributes:		// new{ target="_blank", @class="className"}
* method:		// FormMethod.Get/ Post
* routeValues:	// new { id=1}
* controllerName:		// 控制器前段名字, HelloController 则 Hello 是名字
* actionName:		// 控制器内的方法名

****** BeginForm(string actionName, string controllerName, object routeValues, FormMethod method, object htmlAttributes);
{
/*
* routeValues: new {id=12}
 等效 <form action="controllerName/actionName/12" method="method" />
*/
}
	
****** Html.ActionLink(..) --------------------------------
{
* linkText: 		//链接显示在页面上的文本

* actionName: 			//控制器内的方法名

* controllerName:	//控制器名称

* routeValues:		//传递到action的参数
{/*
	Html.ActionLink("detail","Detail",new { id=1})
	实际上就是 : <a href="Products/Detail/1">detail</a>
*/}

* htmlAttributes:	// 设置标签的 属性
/*
	Html.ActionLink("detail","Detail",new{id=1},new{ target="_blank", @class="className"})
则生成: <a href="Products/Detail/1" target="_blank" class="className">detail</a>

*class 是关键字, 需要使用 @class
*/
}


***** Html.ValidationSummary(true, "", new { @class = "text-danger" })		// 验证控件
{
	true: 表示不额外显示验证失败列表信息;
	"":		自定义的 message
}

**** Html.LabelFor			// 显示一个 <Label ../>

**** Html.EditorFor		// <input ../>

**** Html.ValidationMessageFor()		// <Span>, 紧跟在 input 后面显示验证失败结果
/*
@Html.ValidationMessageFor(model => model.Title, "", new { @class = "text-danger" })
*/

**** Html.DropDownList(string name, string optionLabel)			// 显示 <select>
/*
* name:		// 数据源, 是方法内的 ViewBag.name 或 Session["name"] 或 ViewData["name"]
* optionLabel:		// 是否创建一个 <option value="">optionLabel<option>; 可以=NULL
*/

*** Html.TextBox()			// <input>


*** Html.DisplayName
*** Html.DisplayNameFor(model => model.Title)		// 是显示列名，
*** Html.DisplayNameForModel


** Html.Display
**** Html.DisplayFor(modelItem => item.Title)		// 是显示列的内容
*** Html.DisplayForModel



}
	




























/
}
