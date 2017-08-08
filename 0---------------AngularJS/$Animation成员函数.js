

* enter(element, parent, after, [options]);	// 将元素添加进 DOM
{
element		// 被添加的 元素
parent		// 作为该元素的第一个子元素，如果没有指定 after 元素
after		// 如果指定了这个元素，那么element 将被添加到钙元素后面。
options  	//object	
}

* leave(element, [options]);		// 将 element 元素从 dom 中移除

* move(DOM element, DOM parent, DOM after, Object [options]);	// 移动 element 元素，到 parent 内第一个位置、或者在after 后面。

* addClass( DOM element, string className, Object [options]);	// 给元素 element 添加 className 属性
* removeClass(DOM element, string className, Object [options]);	// 与 addClass() 函数对应

* setClass(DOM element, add, remove, [options]);		// 同时添加、移除 cssClass
/*
element:	DOMElement // the element which will have its CSS classes changed removed from it
add	:		string	// the CSS classes which will be added to the element
remove；	string	// the CSS class which will be removed from the element
options： 	object 	// an optional collection of options that will be applied to the element.
*/
















