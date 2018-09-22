
var routeApp = angular.module('routeApp', ['ngRoute']);
routeApp.config(['$routeProvider', function ($routeProvider) {
	$routeProvider
		.when('/list', {								// path 是 # 后面的部分
			templateUrl: 'views/route/list.html',
			controller: 'RouteListCtl'
		})
		.when('/list/:id', {
			templateUrl: 'views/route/detail.html',		// 路劲从 ng-view 所在的页面开始算； 也可以是 MVC 的 /Areas/Controller/Action 格式的 url； 但是好像不能使用 @section scripts{..}
			controller: 'RouteDetailCtl'
		})
		.otherwise({
			redirectTo: '/list'
		});
}]);