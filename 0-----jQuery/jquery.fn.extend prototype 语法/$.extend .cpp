
$(function(){
	$.fn.extend({
		SimpleTree:function(options){
			
			//初始化参数
			var option = $.extend({
				run:function(a){ }
			},options);




可以扩展 option 的函数:
就可以这样调用了:
$('fliter').SimpleTree({
	run: function(a){ .. 回调代码 }
})


// 扩展多个函数

var option = $.extend({
			itemClick: function (url) {
			}
		}, {
			searchInputChanged: function (data) {			// 输入框值变化
			}}, options);