$(function () {
		var timer = null;
		var timer1 = null;
		var idx = 0;

		//bannerÍ¼ÇÐ»»
		$('.ioi > li').click(function () {
			$(this).css({ 'background': '#cc1313' }).siblings().css({ 'background': '#999' })
			clearInterval(timer);
			$('.banners').css({ 'left': 1126-1126 * ($(this).index() + 1) + 'px'})
			.animate( {left: 1126-1126 * ($(this).index() + 1) - 13 + 'px'},300, 'swing');
			
			$('.banners_text').css({ 'left': 1126-1126 * ($(this).index() + 1) + 60 + 'px', opacity : '0.7' })
			.animate( { left: 1126-1126 * ($(this).index() + 1) + 30 + 'px', opacity : '1.0' }, 300, 'swing');
			autoChange();
		})
		autoChange();
		function autoChange() {
			timer = setInterval(function ()
			{
				$('.ioi > li').eq(idx % 4).click()
				idx++;
			}, 2500)
		}
	})