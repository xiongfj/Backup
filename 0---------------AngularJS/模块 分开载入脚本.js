

----------------

<!DOCTYPE html>
<html>
<script src="http://apps.bdimg.com/libs/angular.js/1.4.6/angular.min.js"></script>
<body>

<div ng-app="myApp" ng-controller="myCtrl">
{{ firstName + " " + lastName }}
</div>

<script src="myApp.js"></script>			// 脚本放在body 后面可以加快网页加载速度
<script src="myCtrl.js"></script>

</body>
</html>


-------------------- myApp.js

var app = angular.module("myApp", []);



-------------------- myCtrl.js


app.controller("myCtrl", function($scope) {
    $scope.firstName	= "John";
    $scope.lastName= "Doe";
});