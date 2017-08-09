

*** 貌似属性写法 ng-xxx="abc" 可以写成： class="ng-xxx:abc" ??




ng-app	定义应用程序的根元素。
{
/*
* 必须有一个根元素，
* 如果有多个，只有第一个会被使用。
* 只有根元素里面的内容才能包含 AngularJS 代码。
*** 
<body ng-app="">
<p>我的第一个表达式: {{ 5 + 5 }}</p>	// 根元素里面才能使用 Aglarjs 代码，最后显示 10
</body>
*/
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">
{{ firstName + " " + lastName }}
	
	<p ng-controller="ctrl2">
	{{ name }}
	</p>
</div>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {		// 必须使用 $scope !!!!!
    $scope.firstName = "John";
    $scope.lastName = "Doe";
});
app.controller("ctrl2", function($scope){
	$scope.name = "hello world!";
});
</script>

</body>
</html>


**/
}

ng-bind			// 调用变量或者表达式，值会表达式变化而变化,貌似与 {{}}  等效
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="" ng-init="myText='Hello World!'">	<script>// init 用于定义变量 </script>
	<p ng-init="param='fammy-43'"></p>

<h1>{{myText}}</h1>
<h2 class="ng-bind:myText"></h2>				<script>// 有多种使用方法 </script>
<h3 ng-bind="myText"></h3>
	<p>{{param}}</p>

<p> ng-init 指令创建了 AngularJS 变量，你可以在应用中使用它。</p>

</div>

</body>
</html>

***********************************************************/

/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<script src="http://apps.bdimg.com/libs/angular.js/1.5.0-beta.0/angular-sanitize.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">
<p ng-bind-html="myText"></p>
	<b ng-bind="test"></p>
</div>

<script>
var app = angular.module("myApp", ['ngSanitize']);		// 调用的是包里面的函数 ngSanitize，貌似会转移标签
app.controller("myCtrl", function($scope) {
    $scope.myText = "My name is: <h1>John Doe</h1>";		// 显示标签
	$scope.test = "<h3>nihao !</h3>"					// 显示 <h3>nihao !</h3>
});
</script>

<p><b>注意:</b> 该实例包含了 "angular-sanitize.js" 文件,
该文件移除 HTML 中的危险代码。</p>

</body>
</html>
**/
}

ng-bind-html		//绑定 HTML 元素的 innerHTML 到应用程序数据，并移除 HTML 字符串中危险字符
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<script src="http://apps.bdimg.com/libs/angular.js/1.5.0-beta.0/angular-sanitize.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<p ng-bind-html="myText"></p>
	<b ng-bind="test"></p>

</div>

<script>
var app = angular.module("myApp", ['ngSanitize']);		// 调用的是包里面的函数 ngSanitize，貌似会转移标签
app.controller("myCtrl", function($scope) {
    $scope.myText = "My name is: <h1>John Doe</h1>";		// 显示标签
	$scope.test = "<h3>nihao !</h3>"					// 显示 <h3>nihao !</h3>
});
</script>

<p><b>注意:</b> 该实例包含了 "angular-sanitize.js" 文件,
该文件移除 HTML 中的危险代码。</p>

</body>
</html>

*/
}

ng-bind-template	// 一般用于绑定多个表达式
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-bind-template="{{firstName}} {{lastName}}" ng-controller="myCtrl">

</div>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
    $scope.firstName = "John";			// div 之间的内容将被 Jhon 。。 替换
    $scope.lastName = "Doe";
});
</script>

</body>
</html>
*/
}

ng-blur			// 输入框失去焦点时触发该属性事件，原生的 onblur 事件也会被触发
{
** <a>, <input>, <select>, <textarea>,窗口对象支持。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<input ng-blur="count = count + 1" ng-init="count=0" />

<h1>{{count}}</h1>

<p>实例中 "count" 变量记录了失去焦点的次数。</p>

</body>
</html>
**/
}

ng-change		// 规定在内容改变时要执行的表达式，原生事件同时也会被触发
{
* ng-change 指令需要搭配 ng-model 指令使用。？？？
* <input>, <select>, 和  <textarea> 元素支持。
* 通过代码修改输入框的内容不会触发该事件，
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="myApp">
<div ng-controller="myCtrl">
  <p>在输入框中输入一些信息:</p>
  <input type="text" ng-change="myFunc()" ng-model="myValue" />
  <p>输入框已经修改了 {{count}} 次。</p>
</div>

<script> 
  angular.module('myApp', [])
    .controller('myCtrl', ['$scope', function($scope) {
      $scope.count = 0;
      $scope.myFunc = function() {
        $scope.count++;
      };
    }]);
</script>
</body>
</html>
**/
}

ng-checked		// 规定元素是否被选中
{
** type 为 checkbox 或 radio 的 <input> 元素支持。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
    <p>My cars:</p>
    <input type="checkbox" ng-model="all"> Check all<br><br>		<!-- 会选择所有的 checkbox  -->
    <input type="checkbox" ng-checked="all">Volvo<br>
    <input type="checkbox" ng-checked="all">Ford<br>
    <input type="checkbox" ng-checked="all">Mercedes
    <p>点击 "Check all" 选择所有的车。</p>
</body>
</html>
*/
}

ng-class	//	指定 HTML 元素使用的 CSS 类
{
* ng-class 指令的值可以是字符串，对象，或一个数组。
* 如果是字符串，多个类名使用空格分隔。
* 如果是对象，需要使用 key-value 对，key 是一个布尔值，value 为你想要添加的类名。只有在 key 为 true 时类才会被添加。
* 如果是数组，可以由字符串或对象组合组成，数组的元素可以是字符串或对象。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<style>
.sky {
    color:white;
    background-color:lightblue;
    padding:20px;
    font-family:"Courier New";
}
.tomato {
    background-color:coral;
    padding:40px;
    font-family:Verdana;
}
</style>
</head>
<body ng-app="">

<p>选择一个类:</p>

<select ng-model="home">
<option value="sky">天空色</option>
<option value="tomato">番茄色</option>
</select>

<div ng-class="home">
  <h1>Welcome Home!</h1>
  <p>I like it!</p>
</div>

</body>
</html>
**/
}

ng-class-even	// 类似 ng-class，但只在偶数行起作用
{
//ng-class-even 指令用于为 HTML 元素动态的绑定一个或多个 CSS 类，但只作用于偶数行。
//ng-class-even 指令需要与 ng-repeat 指令搭配使用。
//ng-class-even 指令建议用在表格的样式渲染中，但是所有HTML元素都是支持的。
***** 不知什么鸟，一定要 ng-class-even="'striped'" 才有效？！！？！？
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<style>
.striped {
    color:white;
    background-color:black;
}
</style>
</head>
<body ng-app="myApp">

<table ng-controller="myCtrl">
<tr ng-repeat="x in records" ng-class-even="'striped'">
  <td>{{x.Name}}</td>
  <td>{{x.Country}}</td>  
</tr>
</table>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.records = [
    {
      "Name" : "Alfreds Futterkiste",
      "Country" : "Germany"
    },
    {
      "Name" : "Berglunds snabbk",
      "Country" : "Sweden"
    },
    {
      "Name" : "Centro comercial Moctezuma",
      "Country" : "Mexico"
    },
    {
      "Name" : "Ernst Handel",
      "Country" : "Austria"
    }
  ]
});
</script>

</body>
</html>
*/
}

ng-class-odd	// 类似 ng-class，但只在奇数行起作用
{
//ng-class-odd 指令用于为 HTML 元素动态的绑定一个或多个 CSS 类，但只作用于奇数行。
//ng-class-odd 指令需要与 ng-repeat 指令搭配使用。
//ng-class-odd 指令建议用在表格的样式渲染中，但是所有HTML元素都是支持的。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<style>
.striped {
    color:white;
    background-color:black;
}
</style>
</head>
<body ng-app="myApp">

<table ng-controller="myCtrl">
<tr ng-repeat="x in records" ng-class-odd="'striped'">
  <td>{{x.Name}}</td>
  <td>{{x.Country}}</td>
</tr>
</table>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.records = [
    {
      "Name" : "Alfreds Futterkiste",
      "Country" : "Germany"
    },
    {
      "Name" : "Berglunds snabbk",
      "Country" : "Sweden"
    },
    {
      "Name" : "Centro comercial Moctezuma",
      "Country" : "Mexico"
    },
    {
      "Name" : "Ernst Handel",
      "Country" : "Austria"
    }
  ]
});
</script>

</body>
</html>
*/
}

ng-click		// 定义元素被点击时的行为,类似 ng-change

ng-cloak		// 在应用正要加载时防止其闪烁，该指令没有参数，直接 <p ng-cloak>asda</p>

ng-controller	// 定义一个对象，区分变量作用域
{
/***
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">
{{ firstName + " " + lastName }}
	
	<p ng-controller="ctrl2">
	{{ firstName }}
	</p>
</div>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {		// 必须使用 $scope !!!!!
    $scope.firstName = "John";
    $scope.lastName = "Doe";
});
app.controller("ctrl2", function($scope){
	$scope.firstName = "hello world!";
});
</script>

</body>
</html>
*/
}

ng-copy			// 标签的文字被拷贝了会触发该事件
{
* 存在原始的 onCopy 事件，两个都会触发
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<input ng-copy="count = count + 1" ng-init="count=0" value="拷贝这个文本" />
	<p ng-copy="num=num+1" ng-init="num=0">dasdas</p>

<p>文本被拷贝 {{count}} 次。{{num}}</p>

<p>实例中变量 "count" 的值在输入框的文本被拷贝时会自动增加 1。</p>

</body>
</html>
**/
}

ng-csp			//修改内容的安全策略
{
//如果使用了 ng-csp 指令， AngularJS 将不会执行eval 函数，这样就无法注入内联样式。
//设置 ng-csp 指令为 no-unsafe-eval, 将阻止 AngularJS 执行 eval 函数，但允许注入内联样式。
//设置 ng-csp 指令为 no-inline-style, 将阻止 AngularJS 注入内联样式，但允许 执行 eval 函数。
//如果开发 Google Chrome 扩展或 Windows 应用 ng-csp 指令是必须的。
//注意:ng-csp 指令不会影响 JavaScript,但会修改 AngularJS 的工作方式，这就意味着: 你仍然可以编写 eval 函数, 
		// 且也可以正常执行, 但是 AngularJS 不能执行它自己的 eval 函数。如果采用兼容模式，会降低 30% 的性能。
//值可设置为空，意味着 eval 和 内联样式都不被允许。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="" ng-csp>

<div>
<p>我的第一个表达式: {{ 5 + 5 }}</p>
</div>

<p>使用 ng-csp 指令, 你可以修改 AngularJS 执行代码的方式。</p>
<p>AngularJS 的执行方式提高了 30% 的性能</p>

</body>
</html>
**/
}

ng-cut		//	规定剪切事件的行为，对应原生事件 onCut
{
// <a>, <input>, <select>, <textarea>, 及窗口对象都支持该指令。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<input ng-cut="count = count + 1" ng-init="count=0" value="剪切这个文本" /> 
<p>文本被剪切了 {{count}} 次。{{num}}</p>

<p>实例中计数变量 "count" 在每次剪切后自动增加 1。</p>

</body>
</html>
**/	
}

ng-dblclick		// 规定双击事件的行为

ng-disabled		// 设置表单输入字段的 disabled 属性(input, select, 或 textarea)。
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
点击这里禁用所有表单输入域:<input type="checkbox" ng-model="all"><br>
<br>

<input type="text" ng-disabled="all">
<input type="radio" ng-disabled="all">
<select ng-disabled="all">
  <option>Female</option>
  <option>Male</option>  
</select>

</body>
</html>
**/
}

ng-focus		// 规定聚焦事件的行为
{//<a>, <input>, <select>, <textarea>, 和 window 对象都支持该指令。
}

ng-form			//指定 HTML 表单继承控制器表单

ng-hide			// 隐藏或显示 HTML 元素
{
// 是 AngularJS 的预定义类，设置元素的 display 为 none。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

隐藏 HTML: <input type="checkbox" ng-model="myVar">

<div ng-hide="myVar">
<h1>Welcome</h1>
<p>Welcome to my home.</p>
</div>

</body>
</html>
**/
}

ng-href			// 为 the <a> 元素指定链接
{
	// 覆盖了原生的 href，
	// 可以在 angukarJS 代码前点击链接?!!?
	// 只针对 <a>
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<div ng-init="myVar = 'http://www.runoob.com'">
<h1>菜鸟教程</h1>
<p>访问 <a ng-href="{{myVar}}">{{myVar}}</a> 学习!</p>
</div>

<p>该实例可以使用了原生的 href 属性，但在 AngularJS 中， ng-href 属性更安全。</p>

</body>
</html>
**/
}

ng-if			// 如果条件为 false 移除 HTML 元素
{
	// 不同于 ng-hide， ng-hide 隐藏元素，而 ng-if 是从 DOM 中移除元素。
	// 如果 if 语句执行的结果为 true，会添加移除元素，并显示。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

保留 HTML: <input type="checkbox" ng-model="myVar" ng-init="myVar = true">

<div ng-if="myVar">
<h1>Welcome</h1>
<p>Welcome to my home.</p>
<hr>
</div>

<p>当复选框取消选中时 DIV 元素将移除。</p>
<p>当重新选中复选框，DIV 元素会重新显示。</p>

</body>
</html>
**/
}

ng-include		// 在应用中包含 HTML 文件
{
	// 引用的文件将被作为子节点
	// <element ng-include="filename" onload="expression" autoscroll="expression" ></element>
	// <ng-include src="filename" onload="expression" autoscroll="expression" ></ng-include>
		// onload	可选， 文件载入后执行的表达式。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<div ng-include="'myFile.htm'"></div>

</body>
</html>
**/
}

ng-init			// 定义应用的初始化值
{
	// 添加一些不必要的逻辑到 scope 中，建议你可以在控制器中 ng-controller 指令执行它 。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="" ng-init="myText='Hello World!'">	<script>// init 用于定义变量 </script>
	<p ng-init="param='fammy-43'"></p>

<h1>{{myText}}</h1>
<h2 class="ng-bind:myText"></h2>				<script>// 有多种使用方法 </script>
<h3 ng-bind="myText"></h3>
	<p>{{param}}</p>

<p> ng-init 指令创建了 AngularJS 变量，你可以在应用中使用它。</p>

</div>

</body>
</html>
**/
}

ng-jq			//定义应用必须使用到的库，如：jQuery

ng-keydown		// 规定按下按键事件的行为，原生事件同时被执行。
{
//	<input>, <select>, <textarea>, 和其他可编辑元素支持该指令。
// 事件触发顺序：
	1、Keydown
	2、Keypress
	3、Keyup
}
ng-keypress		//规定按下按键事件的行为
ng-keyup		//规定松开按键事件的行为

ng-list			//将文本转换为列表 (数组)
{
	// <input>, <select>, <textarea>, 和其他可编辑元素支持该指令。
	// ng-list 指令将字符串转换为数组，并使用逗号分隔。
	// ng-list 指令还有另外一种转换方式，如果你有字符串数组希望在输入框中显示，你可以在 input 上使用 ng-list 指令。
/** 默认使用都好作为分隔符
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="">
<p>在输入框中，输入一些文本，并使用逗号分隔它们：</p>
<input ng-model="customers" ng-list/>
<p>当使用 ng-list 指令时，你的输入信息会转换为数组，如下所示：</p>
<pre>{{customers}}</pre>

</div>

</body>
</html>
***/
}

ng-model		//	绑定 HTML 控制器输入控件的值到应用数据
{
// 绑定的是一个变量，该指令通常使用在可以与用户交互的标签上：input、select.. 从这些控件获取值存放入变量中。
// 为应用程序数据提供类型验证（number、email、required）。
// 为应用程序数据提供状态（invalid、dirty、touched、error）。
// 为 HTML 元素提供 CSS 类。
// 绑定 HTML 元素到 HTML 表单。
// <input>, <select>, <textarea>, 元素支持该指令。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<input ng-model="name">
	<input ng-bind="test">

<p>input 输入框的值绑定了变量 "name" :</p>
{{name}}

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.name = "John Doe";
	$scope.test="nidhaksdasd";		// 该值设置无效！只针对输入控件！！！！！
});
</script>

<p>该实例演示了如何使用 ng-model 指令绑定输入框的值到 scope 变量中。</p>

</body>
</html>

**/

/************************************** 全选
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
    <p>My cars:</p>
    <input type="checkbox" ng-model="all"> Check all<br><br>		<!-- 会选择所有的 checkbox  -->
    <input type="checkbox" ng-checked="all">Volvo<br>
    <input type="checkbox" ng-checked="all">Ford<br>
    <input type="checkbox" ng-checked="all">Mercedes
    <p>点击 "Check all" 选择所有的车。</p>
</body>
</html>
***/

/************************************** 设置块的 css
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<style>
.sky {
    color:white;
    background-color:lightblue;
    padding:20px;
    font-family:"Courier New";
}
.tomato {
    background-color:coral;
    padding:40px;
    font-family:Verdana;
}
</style>
</head>
<body ng-app="">

<p>选择一个类:</p>

<select ng-model="home">
<option value="sky">天空色</option>
<option value="tomato">番茄色</option>
</select>

<div ng-class="home">
  <h1>Welcome Home!</h1>
  <p>I like it!</p>
</div>

</body>
</html>
**/

/************************************ 禁用元素
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
点击这里禁用所有表单输入域:<input type="checkbox" ng-model="all"><br>
<br>

<input type="text" ng-disabled="all">
<input type="radio" ng-disabled="all">
<select ng-disabled="all">
  <option>Female</option>
  <option>Male</option>  
</select>

</body>
</html>
***/

/************************************ 隐藏元素
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

隐藏 HTML: <input type="checkbox" ng-model="myVar">

<div ng-hide="myVar">
<h1>Welcome</h1>
<p>Welcome to my home.</p>
</div>

</body>
</html>
***/

/************************************ 绑定变量，通过修改变量修改编辑框的内容
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<input ng-model="name">

<p>input 输入框的值绑定了变量 "name" :</p>
{{name}}

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.name = "John Doe";
});
</script>

<p>该实例演示了如何使用 ng-model 指令绑定输入框的值到 scope 变量中。</p>

</body>
</html>
****/
}

ng-model-options	// 规定如何更新模型
{
	// <input>, <select>, <textarea>, 元素支持该指令。
	
{updateOn: 'event'}		// 规则指定事件 event 发生后绑定数据

{debounce : 1000} 		// 规定等待多少毫秒后绑定数据

{allowInvalid : true|false} 	// 规定是否需要验证后绑定数据

{getterSetter : true|false} 	// 规定是否作为 getters/setters 绑定到模型

{timezone : '0100'} 			// 规则是否使用时区

/***************** 失去焦点的时候更新 name
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<p>更新输入框:</p>
<input ng-model="name" ng-model-options="{updateOn: 'blur'}">

<p>在失去焦点时绑定输入框的值到 scope 变量中:</p>

{{name}}

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.name = "John Doe";
});
</script>

<p>该实例演示了如何使用 ng-model-options 指令绑定在失去焦点时输入框的值到 scope 变量中。</p>

</body>
</html>
**/
}

ng-mousedown	// 规定按下鼠标按键时的行为,事件顺序： down->up->click 
ng-mouseenter	//规定鼠标指针穿过元素时的行为
ng-mouseleave	//规定鼠标指针离开元素时的行为
ng-mousemove	//规定鼠标指针在指定的元素中移动时的行为
ng-mouseover	//规定鼠标指针位于元素上方时的行为，貌似与 enter 类似
ng-mouseup		//规定当在元素上松开鼠标按钮时的行为

ng-non-bindable		// 规定元素或子元素不能绑定数据，就是不会当成 angularJS 代码执行
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="">

<p>使用 AngularJS: {{ 5+5 }}</p>
<p ng-non-bindable>不使用 AngularJS: {{ 5+5 }}</p>

</div>

<p>如果你不想使用 AngularJS 执行表达式可以使用 ng-non-bindable 。</p>

</body>
</html>
*/
}

ng-open			// 指定元素的 open 属性
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

点击这里显示 details 列表: <input type="checkbox" ng-model="showDetails"><br>
<br>

<details ng-open="showDetails">
  <summary>学的不仅是技术，更是梦想！</summary>
  <p> - 菜鸟教程</p>
</details>

<p><b>注意：</b> 目前只有 Opera, Chrome, 和 Safari 浏览器支持 details 标签。</p>

</body>
</html>
***/
}

ng-options		// 在 <select> 列表中添加元素 item
{
	// <details> 元素支持该指令。
/*************** 填充下拉列表
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<select ng-model="selectedName" ng-options="item for item in names">
</select>
<p>{{selectedName}}</p>
</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.names = ["Emil", "Tobias", "Linus"];
});
</script>

<p>该实例演示了如何使用 ng-options 指令填充下拉列表。</p>

</body>
</html>
**/
/************************ 另一种填充方式
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<select>
<option ng-repeat="x in names">{{x}}</option>
</select>

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.names = ["Google", "Runoob", "Taobao"];
});
</script>

<p>该实例演示了使用 ng-repeat 指令来创建下拉列表。</p>

</body>
</html>

***/
/***************************** ng-repeat 填充
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<p>选择网站:</p>

<select ng-model="selectedSite">
<option ng-repeat="x in sites" value="{{x.url}}">{{x.site}}</option>
</select>

<h1>你选择的是: {{selectedSite}}</h1>

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
   $scope.sites = [
	    {site : "Google", url : "http://www.google.com"},
	    {site : "Runoob", url : "http://www.runoob.com"},
	    {site : "Taobao", url : "http://www.taobao.com"}
	];
});
</script>

<p>该实例演示了使用 ng-repeat 指令来创建下拉列表，选中的值是一个字符串。</p>
</body>
</html>

**/
}

ng-paste		// 规定粘贴事件的行为，<input>, <select>, <textarea> 及其他可编辑元素支持该指令。

ng-pluralize	// 根据本地化规则显示信息

ng-readonly		// 指定元素的 readonly 属性，<input> <textarea> 元素支持该指令。
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
勾选复选框设置输入框为只读:<input type="checkbox" ng-model="all"><br>
<br>

<input type="text" ng-readonly="all">

</body>
</html>
**/
}

ng-repeat		//ng-repeat 指令用于循环输出指定次数的 HTML 元素。 
{

//集合必须是数组或对象。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<style>
.striped {
    color:white;
    background-color:black;
}
</style>
</head>
<body ng-app="myApp">

<table ng-controller="myCtrl">
<tr ng-repeat="x in records" ng-class-even="'striped'">
  <td>{{x.Name}}</td>
  <td>{{x.Country}}</td>  
</tr>
</table>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.records = [
    {
      "Name" : "Alfreds Futterkiste",
      "Country" : "Germany"
    },
    {
      "Name" : "Berglunds snabbk",
      "Country" : "Sweden"
    },
    {
      "Name" : "Centro comercial Moctezuma",
      "Country" : "Mexico"
    },
    {
      "Name" : "Ernst Handel",
      "Country" : "Austria"
    }
  ]
});
</script>

</body>
</html>
***********************************/
/*************************
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="myApp" ng-controller="myCtrl">

<h1 ng-repeat="x in records">{{x}}</h1>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.records = [
    "菜鸟教程1",
    "菜鸟教程2",
    "菜鸟教程3",
    "菜鸟教程4",
  ]
});
</script>

</body>
</html>
***********************************************/
/*********************** 循环对象数组
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="myApp">

<table ng-controller="myCtrl" border="1">
<tr ng-repeat="(x, y) in myObj">
  <td>{{x}}</td>
  <td>{{y}}</td>  
</tr>
</table>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.myObj = {
    "Name" : "Alfreds Futterkiste",
    "Country" : "Germany",
    "City" : "Berlin"
  }
});
</script>

</body>
</html>
****************************************************/

/******************8 创建下拉列表
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<select>
<option ng-repeat="x in names">{{x}}</option>
</select>

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.names = ["Google", "Runoob", "Taobao"];
});
</script>

<p>该实例演示了使用 ng-repeat 指令来创建下拉列表。</p>

</body>
</html>
***/
/********************
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<p>选择网站:</p>

<select ng-model="selectedSite">
<option ng-repeat="x in sites" value="{{x.url}}">{{x.site}}</option>
</select>

<h1>你选择的是: {{selectedSite}}</h1>

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
   $scope.sites = [
	    {site : "Google", url : "http://www.google.com"},
	    {site : "Runoob", url : "http://www.runoob.com"},
	    {site : "Taobao", url : "http://www.taobao.com"}
	];
});
</script>

<p>该实例演示了使用 ng-repeat 指令来创建下拉列表，选中的值是一个字符串。</p>
</body>
</html>
******/
}

ng-selected		// 指定下拉列表当前被选中的是哪个，<option> 元素支持该指令。
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
点击复选框选择 BMW 选项:
<input type="checkbox" ng-model="mySel">

<p>我喜欢的车:</p>

<select>
  <option>Volvo</option>
  <option ng-selected="mySel">BMW</option>
  <option>Ford</option>    
</select>

</body>
</html>
***/
}

ng-show			// 显示或隐藏 HTML 元素
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

显示 HTML: <input type="checkbox" ng-model="myVar">

<div ng-show="myVar">
<h1>Welcome</h1>
<p>Welcome to my home.</p>
</div>

</body>
</html>
***/
}

ng-src			// 指定 <img> 元素的 src 属性，angularJS 代码执行前不会显示图片
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<div ng-init="myVar = 'http://www.runoob.com/wp-content/uploads/2014/06/angular.jpg'">
<h1>Angular</h1>
<img ng-src="{{myVar}}">
</div>

<p>该实例可以使用原生的 src 输出，但是使用 AngularJS 代码插入值，使用 ng-src 属性更好。</p>

</body>
</html>
**/
}

ng-srcset		// 指定 <img> 元素的 srcset 属性,与 src 属性相同？？？？！！
{ // <img> 和 <source> 元素支持该属性。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">

<div ng-init="myVar = 'http://www.runoob.com/wp-content/uploads/2014/06/angular.jpg'">
<h1>Angular</h1>
<img ng-srcset="{{myVar}}">
</div>

<p>该实例可以使用原生的 srcset 输出，但是使用 AngularJS 代码插入值，使用 ng-srcset 属性更好。</p>

</body>
</html>
**/
}

ng-style		// 指定元素的 style 属性
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="myApp" ng-controller="myCtrl">

<h1 ng-style="myObj">菜鸟教程</h1>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.myObj = {
    "color" : "white",
    "background-color" : "coral",
    "font-size" : "60px",
    "padding" : "50px"
  }
});
</script>

</body>
</html>
**/
}

ng-submit		// 规定 onsubmit 事件发生时执行的表达式,<form> 元素支持该属性。
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="myApp" ng-controller="myCtrl">

<form ng-submit="myFunc()">
  <input type="text">
  <input type="submit">
</form>

<p>{{myTxt}}</p>

<p>以下实例演示了表单提交后 AngularJS 执行行。</p>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
  $scope.myTxt = "你还没有点击提交!";
  $scope.myFunc = function () {
      $scope.myTxt = "你点击了提交!";
  }
});
</script>

</body>
</html>
***/
}

ng-switch		// 规定显示或隐藏子元素的条件
{
	// 对应的子元素使用 ng-switch-when 指令，如果匹配选中选择显示，其他为匹配的则移除。
	// 你可以通过使用 ng-switch-default 指令设置默认选项，如果都没有匹配的情况，默认选项会显示。
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body ng-app="">
我喜欢的网站
<select ng-model="myVar">
  <option value="runoob">www.runoob.com
  <option value="google">www.google.com
  <option value="taobao">www.taobao.com
  <option value="taobaso">www.taobao.com
</select>

<hr>
<div ng-switch="myVar">
  <div ng-switch-default>
     <h1>菜鸟教程</h1>
     <p>默认默认默认..</p>
  </div>
  <div ng-switch-when="runoob">
     <h1>菜鸟教程</h1>
     <p>欢迎访问菜鸟教程</p>
  </div>
  <div ng-switch-when="google">
     <h1>Google</h1>
     <p>欢迎访问Google</p>
  </div>
  <div ng-switch-when="taobao">
     <h1>淘宝</h1>
     <p>欢迎访问淘宝</p>
  </div>
  <div ng-switch-default>
     <h1>切换</h1>
     <p>选择不同选项显示对应的值。</p>
  </div>
</div>
<hr>

<p> ng-switch 指令根据当前的值显示或隐藏对应部分。</p>

</body>
</html>

**/
}

ng-transclude	// 规定填充的目标位置

ng-value		// 使用代码修改 input 的值， <input> 和 <select> 元素支持该属性。
{
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<div ng-app="myApp" ng-controller="myCtrl">

<input ng-value="myVar">

</div>

<script>
var app = angular.module('myApp', []);
app.controller('myCtrl', function($scope) {
    $scope.myVar = "Hello World!";
});
</script>

<p>该实例演示了如何使用 AngularJS 表达式来设置输入框的值。</p>

</body>
</html>
*/
}
























