
** 被验证的控件需要使用 ng-model 属性!!

$error
$dirty		// 表单有填写记录
$valid		// 字段内容合法的
$invalid	// 字段内容是非法的
$pristine	// 表单没有填写记录
$touched	// 如果通过触摸屏点击、或者鼠标点击-true
$index 		// 貌似用于表格显示序号。
$odd		// 偶数行
$even		// 奇数行

----- 验证 -----------------------------------------------
{
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
</head>
<body>

<h2>验证实例</h2>

<form ng-app="myApp" ng-controller="validateCtrl" 
	name="myForm" novalidate>							// novalidate 用于禁用浏览器的表单验证

	<p>用户名:<br>
		<input type="text" name="user" ng-model="user" required>		// required，表示必须输入不能为空。
		<span style="color:red" ng-show="myForm.user.$dirty && myForm.user.$invalid">
			<span ng-show="myForm.user.$error.required">用户名是必须的。</span>
		</span>
	</p>

	<p>邮箱:<br>
		<input type="email" name="email" ng-model="email" required>
		<span style="color:red" ng-show="myForm.email.$dirty && myForm.email.$invalid">
			<span ng-show="myForm.email.$error.required">邮箱是必须的。</span>
			<span ng-show="myForm.email.$error.email">非法的邮箱地址。</span>
		</span>
	</p>

	<p>
		<input type="submit" ng-disabled="myForm.user.$dirty && myForm.user.$invalid ||  
			myForm.email.$dirty && myForm.email.$invalid">
	</p>

</form>

<script>
	var app = angular.module('myApp', []);
	app.controller('validateCtrl', function($scope) {
		$scope.user = 'John Doe';
		$scope.email = 'john.doe@gmail.com';
	});
</script>

</body>
</html>
}

--- $odd、$even ------------------ 
{
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<style>
table, td  {
  border: 1px solid grey;
  border-collapse: collapse;
  padding: 5px;
}
</style>
</head>
<body>

<div ng-app="myApp" ng-controller="customersCtrl"> 
<!-- ng-if=false 的元素不会被显示 -->
<table>
  <tr ng-repeat="x in names">
    <td ng-if="$odd" style="background-color:#f1f1f1">
    {{ x.Name }}</td>
    <td ng-if="$even">
    {{ x.Name }}</td>
    <td ng-if="$odd" style="background-color:#f1f1f1">
    {{ x.Country }}</td>
    <td ng-if="$even">
    {{ x.Country }}</td>
  </tr>
</table>

</div>

<script>
var app = angular.module('myApp', []);
app.controller('customersCtrl', function($scope, $http) {
    $http.get("/try/angularjs/data/Customers_JSON.php")
    .success(function (response) {$scope.names = response.records;});
});
</script>

</body>
</html>

}
































