



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

----------------------------------------------------------

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
    .controller('myCtrl', ['$scope', function($scope) {		// ????!
      $scope.count = 0;
      $scope.myFunc = function() {
        $scope.count++;
      };
    }]);
</script>
</body>
</html>



