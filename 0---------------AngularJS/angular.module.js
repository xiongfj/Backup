

// ** angular.module(name, [requires], [configFn]);
/**
name：字符串类型，代表模块的名称；
requires：字符串的数组，代表该模块依赖的其他模块列表，如果不依赖其他模块，用空数组即可；
			// 也就是可以被注入到模块中的对象列表
			// 字符串数组，每个元素都是一个模块名称，
			// 如果本模块要要用到其他模块的东西，需要提前用注入器加载
configFn：用来对该模块进行一些配置。
*/


// Create a new module
var myModule = angular.module('myModule', []);

angular.module('myModule');	// 引用某个模块，不是创建模块，与 getter() 一样

// register a new service
myModule.value('appName', 'MyCoolApp');

// configure existing services inside initialization blocks.
myModule.config(['$locationProvider', function($locationProvider) {
  // Configure existing providers
  $locationProvider.hashPrefix('!');
}]);
Then you can create an injector and load your modules like this:

var injector = angular.injector(['ng', 'myModule'])

//However it's more likely that you'll just use ngApp or angular.bootstrap to simplify this process for you.