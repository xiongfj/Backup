
<<<<<<<<<<<<大多数事件函数都可以显式调用<<<<<<<<<<<<<<<<<<<<>


bind()		// 向匹配元素附加一个或更多事件处理器,该绑定对后面创建的元素无效
/*
* $(selector).bind("event',data,function) 	// 需要引号
	event	
		必需。规定添加到元素的一个或多个事件。
		由空格分隔多个事件。必须是有效的事件。
	data	可选。规定传递到函数的额外数据。
	function	必需。规定当事件发生时运行的函数。
	
* 替代语法
$(selector).bind({event:function, event:function, ...}) 	// event 不需要引号!!!
{event:function, event:function, ...}	必需。规定事件映射，其中包含一个或多个添加到元素的事件，
-																			以及当事件发生时运行的函数。

* 绑定多个事件：
$(document).ready(function(){
  $("p").bind('click dblclick mouseover mouseout',function(event){
    $("div").html("事件：" + event.type);
  });
 });

*/

blur()		// 失去焦点时，比如输入框外点击了一下鼠标，输入框就失去焦点了
/*
* 用法一： 可以显示调用，是某个标签获取焦点:  $("input.pid").blur();   与 focus() 对应
* 用法二： 用于事件自动调用
*/

change(function())	// 文本内容发生变化的时候，触发该事件
/*
当元素的值发生改变时，会发生 change 事件。
该事件仅适用于文本域（text field），以及 textarea 和 select 元素。
change() 函数触发 change 事件，或规定当发生 change 事件时运行的函数。
注释：当用于 select 元素时，change 事件会在选择某个选项时发生。当用于 text field 或 text area 时，该事件会在元素失去焦点时发生。

* function 可选。

--- 另一种监听实时变化的值
<script>
$(function(){
	$("input").on('input propertychange', function () {
		alert("asd");
	})
});
</script>


*/

click(function())		// 类似 change，可以显式调用点击，function可选

dblclick(function())		// 双击事件，类似 click()
/*
当双击元素时，会发生 dblclick 事件。
当鼠标指针停留在元素上方，然后按下并松开鼠标左键时，就会发生一次 click。
在很短的时间内发生两次 click，即是一次 double click 事件。
dblclick() 方法触发 dblclick 事件，或规定当发生 dblclick 事件时运行的函数。
提示：如果把 dblclick 和 click 事件应用于同一元素，可能会产生问题。
*/

delegate(childSelector,event,data,function(event) )// 可以向后面创建的元素添加响应事件函数，而不一定要求元素事先存在
/* 详细见手记： 委托delegate.html
* 可以多次调用这个函数将同一事件绑定多个函数.
childSelector	// 必须.在当前被选择元素的《子元素集合》内部再赛选，而不是被选择元素里面赛选。live() 则是操作被选元素的

event	
	必需。规定附加到元素的一个或多个事件。
	由空格分隔多个事件值。必须是有效的事件。
data		// 可选。规定传递到函数的额外数据。传递到下面函数的 event.data 内
function(event)	必需。规定当事件发生时运行的函数。
*/

die((event,function))		移除所有通过 live() 函数添加的事件处理程序。
/*
event	
	可选。规定要移除的一个或多个事件处理程序。
	由空格分隔多个事件值。必须是有效的事件。
function	可选。规定要移除的特定函数。
*/

error(function())	触发、或将函数绑定到指定元素的 error 事件
/*
* 可以显式调用

* 例如图片没有找到，就会触发该事件

* 当元素遇到错误（没有正确载入）时，发生 error 事件。
	error() 方法触发 error 事件，或规定当发生 error 事件时运行的函数。
	提示：该方法是 bind('error', handler) 的简写方式。
*/

event.isDefaultPrevented()	返回 event 对象上是否调用了 event.preventDefault()。
/*
<html>
<head>
<script type="text/javascript" src="jquery.js"></script>
<script type="text/javascript">
$(document).ready(function(){
  $("a").click(function(event){
    event.preventDefault();
    alert("Default prevented: " + event.isDefaultPrevented());
  });
});
</script>
</head>
<body>
<a href="http://w3school.com.cn/">W3School</a>
<p>preventDefault() 方法将防止上面的链接打开 URL。</p>
<p>请点击该链接，检查是否阻止了默认动作。</p>
</body>
</html>

*/

event.pageX				相对于文档左边缘的鼠标位置。

event.pageY				相对于文档上边缘的鼠标位置。

event.preventDefault()	// 阻止打开连接、提交表单之类的默认事件
/*
<html>
<head>
<script type="text/javascript" src="jquery.js"></script>
<script type="text/javascript">
$(document).ready(function(){
  $("a").click(function(event){
    event.preventDefault();
  });
});
</script>
</head>
<body>
<a href="http://w3school.com.cn/">W3School</a>
<p>preventDefault() 方法将防止上面的链接打开 URL。</p>
</body>
</html>

*/

event.data		// delegate(childSelector, 'event', data, function(event) ), data 传递给event.data

event.result			包含由被指定事件触发的事件处理器返回的最后一个值。
/* 用于多个同一个事件函数之间数据的交换..

$("button").click(function(e) {
    return ("最后一次点击的鼠标位置是： X" +e.pageX + ", Y" + e.pageY);
  });
  $("button").click(function(e) {
    $("p").html(e.result);			// e.result 是上面一个函数的 return 返回值
  });  
*/

event.target		// 区分响应事件的元素,是一个 DOM 元素
/*
$(document).ready(function(){
  $("p, button, h1, h2").click(function(event){
    $("div").html("点击事件由一个 " + event.target.nodeName + " 元素触发");
  });
});
*/

event.timeStamp		该属性返回从 1970 年 1 月 1 日到事件发生时的毫秒数。
/*
$(document).ready(function(){
  $("button").click(function(e){
    $("span").text(e.timeStamp);		// 从 1970 年开始计算的毫秒数
  });
});
*/

event.type		// 获取事件类型：单击、双击、移入、移出..

event.which	// 检测按键	指示按了哪个键或按钮。

focus(function())		//	触发、或将函数绑定到指定元素的 focus 事件
/* 参考手记 事件焦点xx.html
*/

* keydown(function(event))		// 按键按下时触发该函数，可以显式调用，参数可选
/**
event.which:	// 按下的是哪个键,ASIIC 码值.
*/

* keypress(function(event))		// 当有内容输入时，比如输入了一个字母。但是中文输入的话不会响应该函数
/**
event.which:	// 按下的是哪个键,ASIIC 码值.
*/

* keyup(function(event))			// 按键弹起时触发该函数，可以显式调用，参数可选
/**
event.which:	// 按下的是哪个键,ASIIC 码值.
*/
live(event,data,function)		// 为了响应事后用脚本创建的动态元素的事件，与 delegate 类似，只是语法不一样
/* 参考手记 事件绑定未来事件live.html
event	
	必需。规定附加到元素的一个或多个事件。
	由空格分隔多个事件。必须是有效的事件。
data	可选。规定传递到该函数的额外数据。传递到function(event) 中的 event.data
function	必需。规定当事件发生时运行的函数。
*/

load(function())	// img 元素加载图片完成后触发该事件，如果图片是被缓存的就不会触发该事件,参数可选
/*
当指定的元素（及子元素）已加载时，会发生 load() 事件。
该事件适用于任何带有 URL 的元素（比如图像、脚本、框架、内联框架）。
根据不同的浏览器（Firefox 和 IE），如果图像已被缓存，则也许不会触发 load 事件。
注释：还存在一个名为 load() 的 jQuery Ajax 方法，根据不同的参数而定。
*/

mousedown(function())	 	// 鼠标按下即触发该事件
mouseenter(function())	// 鼠标进入当前被选元素触发该事件，进入备选元素的子元素不会触发。
/* mouseover()   子元素也会触发，与该事件不一样
*/
mouseleave(function())		// 与 mouseenter 对应，被选元素的子元素不会触发该事件
mousemove(function(e))	触发、或将函数绑定到指定元素的 mouse move 事件
/*
* e 里面存储了一些鼠标信息：坐标之类的
*/
mouseout(function())		// 被选元素及其子元素都可以触发该事件.
mouseover(function())	// 被选元素及其子元素都可以触发该事件.
mouseup(function())		// 鼠标弹起响应该事件

one(event,data,function)		// 绑定事件与函数，但是事件只会响应一次
/*
event	
		必需。规定添加到元素的一个或多个事件。
		由空格分隔多个事件。必须是有效的事件。
data		可选。规定传递到函数的额外数据。
function	必需。规定当事件发生时运行的函数。
*/

ready()		文档就绪事件（当 HTML 文档就绪可用时）
/*
提示：ready() 函数不应与 <body onload=""> 一起使用。
语法 1
	$(document).ready(function)
语法 2
	$().ready(function)
语法 3
	$(function) 	?/
*/

resize(function)		// 窗口大小变化时响应该函数.可以显式调用

scroll(functoin)	// 内容发生滚动时候

select(function)	// 当有文本被选择的时候触发该事件
/* 当 textarea 或文本类型的 input 元素中的文本被选择时，会发生 select 事件。
*/

submit(function)	//	触发、或将函数绑定到指定元素的 submit 事件
/*
当提交表单时，会发生 submit 事件。
*该事件只适用于表单元素。
* 阻止提交：
$(document).ready(function(){
  $("form").submit(function(e){
    e.preventDefault();
    alert("Submit prevented");
  });
});
*/

toggle(func1,func2,func3..)			绑定两个或多个事件处理器函数，当发生轮流的 click 事件时执行。
/* 每次按顺序执行一个函数，循环
function1()	必需。规定当元素在每偶数次被点击时要运行的函数。
function2()	必需。规定当元素在每奇数次被点击时要运行的函数。
functionN(),...	可选。规定需要切换的其他函数。
*/

toggle(speed,callback) 
/*
speed	
	可选。规定 hide/show 效果的速度。默认是 "0"。
	可能的值：
	毫秒（比如 1500）
	"slow"
	"normal"
	"fast"
callback	
	可选。当 toggle() 方法完成时执行的函数。 
*/
toggle(switch)		// switch=true 显示，false-隐藏

* jQuery.Event('click')	// 返回一个事件对象

trigger(event, [param1,param2,param3..])			// 所有匹配元素的指定事件
/*
event	// 使用双引号指定事件，   "click" 
	必需。规定指定元素要触发的事件。
	可以使自定义事件（使用 bind() 函数来附加），或者任何标准事件。
[param1,param2,...]	
	可选。传递到事件处理程序的额外参数。
	额外的参数对自定义事件特别有用。

* [{name:"张三",age:13},{name:"李四", age:23}] -> 算两个参数.
* {name:"jkas", age:12} 	// 算一个参数	

------------
$(document).ready(function(){
  $("input").select(function(){
    $("input").after("文本被选中！");
  });
  var e = jQuery.Event("select");
  $("button").click(function(){
    $("input").trigger(e);		// 使用对象做参数
  });
});
-----------
*/

triggerHandler(event, [param1,param2,param3..]))	// 激活被匹配元素中第一个元素的 event 事件
/*
triggerHandler() 方法触发被选元素的指定事件类型。但不会执行浏览器默认动作，也不会产生事件冒泡。
triggerHandler() 方法与 trigger() 方法类似。不同的是它不会触发事件（比如表单提交）的默认行为，而且只影响第一个匹配元素。
与 trigger() 方法相比的不同之处
它不会引起事件（比如表单提交）的默认行为, 或者 input 的 select 选择文本也不会执行.
.trigger() 会操作 jQuery 对象匹配的所有元素，而 .triggerHandler() 只影响第一个匹配元素。
由 .triggerHandler() 创建的事件不会在 DOM 树中冒泡；如果目标元素不直接处理它们，则不会发生任何事情。
该方法的返回的是事件处理函数的返回值，而不是具有可链性的 jQuery 对象。此外，如果没有处理程序被触发，则这个方法返回 undefined。

$(document).ready(function(){
  $("input").select(function(event,arg1,arg2){
    $("input").after(event.target.nodeName + arg1 + arg2);	// 获取传递的参数.
  });
  $("button").click(function(){
    $("input").triggerHandler("select",['hello','world!']);	// 可以传递多个参数,也可以不带参数
  });
});

*/

unbind(event,func)			// 从匹配元素移除一个被添加的事件处理器
/* 具体见手记 事件unbind移除事件.html
* 如果不带参数，那么移除所有事件

* func: 指移除 event 绑定的 func 函数,就是说发生event事件后不会再调用 func 函数.(一个事件可以绑定多个函数??)
*/

undelegate(selector,event,function) 		// 从匹配元素移除一个被添加的事件处理器，现在或将来
/* 
selector	可选。规定需要删除事件处理程序的选择器。
event		必须,不然有些版本无效// 需要移除是事件,'click' 或移除多个事件 'click mouseenter' 用空格隔开
function	// 指定移除具体的函数,当一个事件绑定多个函数的时候用到,如果不写就是移除所有函数
*/

unload()			触发、或将函数绑定到指定元素的 unload 事件
/*  无效？？
当用户离开页面时，会发生 unload 事件。
具体来说，当发生以下情况时，会发出 unload 事件：
点击某个离开页面的链接
在地址栏中键入了新的 URL
使用前进或后退按钮
关闭浏览器
重新加载页面
unload() 方法将事件处理程序绑定到 unload 事件。
unload() 方法只应用于 window 对象。
语法
*/


on(event, function)		// 监听事件
/*

*input 事件: focus; blur; change; keydown; keyup; click; select; input; 
* 可以使用 jQuery.change() 激发对应事件 .blur() .. 等

<script>
$(function(){
	$("input").on('input propertychange', function () {		// input 值发生变化马上发生
		alert("asd");
	})
});
</script>
*/






















