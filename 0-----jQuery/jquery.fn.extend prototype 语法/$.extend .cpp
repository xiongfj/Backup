
$(function(){
	$.fn.extend({
		SimpleTree:function(options){
			
			//��ʼ������
			var option = $.extend({
				run:function(a){ }
			},options);




������չ option �ĺ���:
�Ϳ�������������:
$('fliter').SimpleTree({
	run: function(a){ .. �ص����� }
})


// ��չ�������

var option = $.extend({
			itemClick: function (url) {
			}
		}, {
			searchInputChanged: function (data) {			// �����ֵ�仯
			}}, options);