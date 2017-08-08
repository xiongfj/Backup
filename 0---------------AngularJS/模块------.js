
模块定义了一个应用程序，
是应用程序不同部分的容器
是应用控制器的容器
控制器通常属于一个模块

** 创建模块：
//////// 在模块定义中 [] 参数用于定义模块的依赖关系。
//////// 中括号[]表示该模块没有依赖，如果有依赖的话会在中括号写上依赖的模块名字。
/*

<div ng-app="myApp">...</div>
<script>
var app = angular.module("myApp", []); 
</script>

**/

** 添加控制器
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
</div>

<script>
var app = angular.module("myApp", []);
app.controller("myCtrl", function($scope) {
    $scope.firstName = "John";
    $scope.lastName = "Doe";
});
</script>

</body>
</html>
**/


** 创建指令
/**
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script> 
</head>
<body>

<div ng-app="myApp" runoob-directive></div>		// 必须使用 xx-yyyy 的方式调用指令!!

<script>

var app = angular.module("myApp", []);

app.directive("runoobDirective", function() {	// 必须使用 xxYyyyy的方式创建指令
    return {
        template : "我在指令构造器中创建!"
    };
});
</script>

</body>
</html>
**/



















