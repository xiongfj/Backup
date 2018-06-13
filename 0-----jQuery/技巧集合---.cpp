
1. 使用下面这个监听输入框变化的时候, 会导致其它元素的点击事件异常: 第一次点击无效,第二次之后点击才能响应点击事件
/*
	$("input#xx").on('input propertychange change', function () {
	});

- 正确处理方法是去掉 change
*/