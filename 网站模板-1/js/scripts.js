;(function($, window) {
	/** Settings **/

	// List of background images to use, the default image will be the first one in the list
	var backgrounds = [
	    
	],
	
	// Background options - see documentation
	backgroundOptions = {
		slider: '#fs-slider'
	},
	
	// Full Screen gallery options - see documentation
	sereneOptions = {
		
	},
	
	// Twitter username
	twitterUsername = 'ThemeCatcher',
		
	// Number tweets to show, set to 0 to disable fetching tweets
	tweetCount = 5,	
	
	// Sharrre translations
	sharrre = {
		twitter: 'Tweet',
		facebook: 'Like',
		google: '+1'
	},
	
	// Enable or disable the "Popdown" message by settings this to true or false
	enablePopdown = true;
	
	/** End settings **/
			
	$(document).ready(function() {
		var $body = $('body');
		
		// Fullscreen background
		$.fullscreen(
			$.extend({}, backgroundOptions, window.backgroundOptions || {}, {
				backgrounds: window.backgrounds || backgrounds,
				backgroundIndex: window.backgroundIndex
			})
		);

		// Initialise the menu
		$('ul.sf-menu').superfish({ speed: 0 });
		
		if ($.isFunction($.fn.fptabs)) {
			// Slide up / slide down effect
			$.tools.tabs.addEffect('slide-slide',function(tabIndex, done) { 
		        this.getPanes().slideUp(400).eq(tabIndex).delay(400).slideDown(400, done);           
		    });
						
			// Tabs
			$('.tabs').each(function () {
				var $root = $(this),
				effect = $root.hasClass('sliding') ? 'slide-slide' : 'default';
				$root.fptabs('.tab-content', {
					tabs: '> .tabs-nav > li',
					current: 'active',
					effect: effect
				});
			});
		}
		
		// Accordion & toggles		
		$('.accordion').each(function () {
			var $root = $(this),
			$triggers = $root.find('> h3').prepend('<span class="acc-icon"/>');
			
			if ($root.hasClass('toggle')) {
				$triggers.click(function () {
					var $this = $(this);
					
					if ($this.hasClass('active')) {
						$this.next().slideUp(400, function () {
							$this.removeClass('active');
						});
					} else {
						$this.addClass('active');
						$this.next().slideDown(400);
					}
				});
			} else {
				$triggers.click(function (e) {
					var $this = $(this);
					if ($this.next().is(':hidden')) {
						$triggers.removeClass('active').next().slideUp();
						$this.toggleClass('active').next().slideDown();
					}
				});
			}
		});
			
		// Open links with class popup-link in new window
		$('a.popup-link').click(function() {
			var href = $(this).attr('href');
			if (href.length > 0) {
				window.open(href);
			}
			return false;
		});
		
		// Nav fixed
		if ($body.hasClass('scroll-nav')) {
			var $nav = $('.nav-inner');
			
			$(window).bind('scroll.stickynav resize.stickynav', function () {
				var scrollY = $(window).scrollTop(),
					isFixed = $nav.css('position') == 'fixed';
				
				if ($body.hasClass('stretch-header')) {
					var css = {
						position: 'fixed',
	    	            left: 0,
	    	            top: '5px', // -5px top margin
    	            	width: '100%'
					};
				} else {
					var css = {
						position: 'fixed',
	    	            left: '50%',
	    	            marginLeft: '-481px',
	    	            top: '5px' // -5px top margin
					};
				}
				
				if (!isFixed) {
					minY = $nav.offset().top; 
				}
				
		    	if (scrollY > minY && !isFixed) {
		    		$nav.css(css).addClass('fixed');
		    	} else if (scrollY < minY && isFixed) {
		    		$nav.css({
		    			position: 'relative',
	    	            left: 'auto',
	    	            top: 'auto',
	    	            marginLeft: 0
		    		}).removeClass('fixed');
		    	}
			});
		}
				
		// Piecemaker slider
		if ($('#piecemaker').length) {			
			var flashvars = {
				cssSource: 'js/piecemaker/piecemaker.css',
				xmlSource: 'js/piecemaker/piecemaker.xml'
			};
			
			var params = {
				play: 'true',
				menu: 'false',
				scale: 'showall',
				wmode: 'transparent',
				allowfullscreen: 'true',
				allowscriptaccess: 'always',
				allownetworking: 'all'
			};
			
			swfobject.embedSWF('js/piecemaker/piecemaker.swf', 'piecemaker', '100%', '425', '10', null, flashvars, params, null);
		}
				
		// Quick contact
		var $qcTrigger = $('.quick-contact'),
			$qcForm = $('.quick-contact-pop-out'),
			mouseInsideQCTrigger = false,
			mouseInsideQCForm = false;
		
		$qcTrigger.hover(function () { mouseInsideQCTrigger = true; }, function () { mouseInsideQCTrigger = false; });
		$qcForm.hover(function () { mouseInsideQCForm = true; }, function () { mouseInsideQCForm = false; });	

		$body.mousedown(function () {
			if ($qcForm.is(':visible') && !mouseInsideQCTrigger && !mouseInsideQCForm) {
				$qcTrigger.removeClass('quick-contact-open');
				$qcForm.hide();
			}
		});
		
		$qcTrigger.bind('click', function () {			
			if ($qcForm.is(':visible')) {
				$qcTrigger.removeClass('quick-contact-open');
				$qcForm.hide();
			} else {
				$qcTrigger.addClass('quick-contact-open');
				$qcForm.show();
			}
			return false;
		});
		
		// Mini horizontal accordion
		$('.mma-trigger').each(function () {
			var $this = $(this),
		    	$next = $this.siblings('.mma-content'),
		   		w = $next.actual('width')+1; // +1px accounts for rounding inconsistencies in browsers

	        $next.css({width: 0}).find('.mma-content-inner').css('width', w + 'px');

	        $this.click(function () {
	        	var $otherBoxes = $('.mma-content').not($next);

	        	if ($otherBoxes.is(':visible')) {
	        		$otherBoxes.css({ overflow: 'hidden' }).animate({width: '1px'}, function () {
	        			$otherBoxes.css({display: 'none', width: 0}).siblings('.mma-trigger').removeClass('mma-active');	        			
        			});
	        		
	        		$next.css({width: '1px', display: 'block'}).animate({width: w + 'px'}, function () {
	        			$next.css({ overflow: 'visible' });
        			}).siblings('.mma-trigger').addClass('mma-active');
	        	} else {   
	        		if ($next.is(':visible')) {
	        			$next.css({ overflow: 'hidden' }).animate({width: '1px'}, function () {
	        				$next.css({display: 'none', width: 0}).siblings('.mma-trigger').removeClass('mma-active');
        				});
	        		} else {
	        			$next.css({width: '1px', display: 'block'}).animate({width: w + 'px'}, function () {
	        				$next.css({ overflow: 'visible' });
        				}).siblings('.mma-trigger').addClass('mma-active');
	        		}
	        	}
	        });
		});
		
		// Form infield labels
		if ($.isFunction($.fn.inFieldLabels)) {
			$('.quform').each(function (quformCount) {
				$(this).find('.inside-label').each(function (i) {
					var $root = $(this),
					$label = $root.find('> label'),
					$element = $root.find('input[type="text"], textarea');
					
					if ($label.length && $element.length) {
						var id =  'quform-' + quformCount + '-' + i;
						$label.attr('for', id);
						$element.attr('id', id);
					}
					
					$label.inFieldLabels();
				});
			});
			
			if ($('#comment_form').length) {
				$('#comment_form').find('.inside-label').each(function (i) {
					var $root = $(this),
					$label = $root.find('> label'),
					$element = $root.find('input[type="text"], textarea');
					
					if ($label.length && $element.length) {
						var id =  'comment-label-' + i;
						$label.attr('for', id);
						$element.attr('id', id);
					}
					
					$label.inFieldLabels();
				});
			}
		}
		
		// Tooltips
		if ($.isFunction($.fn.qtip)) {
			$('.tooltip').qtip({
				text: false,
				style: {
					classes: 'ui-tooltip-youtube'
				},
				position: {
					my: 'bottom center',
					at: 'top center'
				}
			});
		}
		
		// Child selectors for older browsers
		$('#content-body-inner .box-border:last-child, #horz-nav-ul ul li:last-child, #horz-nav-ul ul li ul li:last-child, .mtt-links ul.mtt-contact-details li:last-child, ul.vert-menu li:last-child a').addClass('last-child');
		$('.mma-pane:first-child, ul.horz-mini-menu li:first-child, ul.horz-mini-menu.sliding li:first-child > ul, #horz-nav-ul ul li:first-child, #horz-nav-ul ul li ul li:first-child').addClass('first-child');
		$('#horz-nav-ul > li > ul > li:only-child').addClass('only-child');
		
		// Set up lightboxes
		var lightboxes = function (context) {
			if (!context) context = document;
			
			$('.lightbox', context).each(function () {
				var href = $(this).attr('href');
				
				if (href.match(/vimeo\.com/i)) {
					if (href.match(/http:\/\/(www\.)?vimeo\.com/i)) {
						$(this).attr('href', href.replace(/(www\.)?vimeo.com/, 'player.vimeo.com/video'));
					}					
					$(this).removeClass('lightbox')
					       .addClass('lightbox-video');
				} else if (href.match(/youtube\.com/i)) {
					if (href.match(/youtube\.com\/watch/i)) {						
						href = href.replace(/watch\?v=/i, 'embed/');						
						var params = [];
						
						// Set to autoplay
						if (!href.match(/autoplay=/)) {
							params.push('autoplay=1');
						}
						
						// Set fullscreen active
						if (!href.match(/fs=/)) {
							params.push('fs=1');
						}
													                    
						if (href.match(/&/)) {
	                        href = href.replace(/&/, '?');
	                        href += '&';
	                    } else {
	                        href += '?';
	                    }
						
						params.push('wmode=transparent');
						
						href += params.join('&');
	                    
	                    $(this).attr('href', href);
					}
					$(this).removeClass('lightbox')
					   	   .addClass('lightbox-video');
				} else if (href.match(/\b.swf\b/i)) {
					$(this).removeClass('lightbox')
				   	       .addClass('lightbox-swf');
				}
			});
						
			if ($.isFunction($.fn.fancybox)) {
				// Normal lightbox
				$('.lightbox').each(function () {
					var $this = $(this),
					options = $this.data('options') || {};	
					
					$this.fancybox($.extend({}, {
						transitionIn: 'elastic',
						transitionOut: 'elastic',
						titlePosition: 'inside',
						padding: 1
					}, options));
				});
				
				// Swf lightbox
				$('.lightbox-swf').each(function () {
					var $this = $(this),
					options = $this.data('options') || {};	
					
					$this.fancybox($.extend({}, {
						transitionIn: 'elastic',
						transitionOut: 'fade',  // elastic is not good here
						titlePosition: 'inside',
						padding: 1,
						type: 'swf',
						swf: { wmode: 'transparent', autoplay: 'true', allowFullScreen: 'true' },
						width: 640,
						height: 385
					}, options));
				});
				
				// Video lightbox (iframe - Vimeo, YouTube etc)
				$('.lightbox-video').each(function () {
					var $this = $(this),
					options = $this.data('options') || {};	
					
					$this.fancybox($.extend({}, {
						transitionIn: 'elastic',
						transitionOut: 'fade',  // elastic is not good here
						titlePosition: 'inside',
						padding: 1,
						type: 'iframe',
						width: 640,
						height: 360
					}, options));
				});
			}
			
			if ($.isFunction($.fn.serene)) {
				$('.serene', context).each(function () {
					var $this = $(this),
					options = $this.data('options') || {};
					
					$this.serene($.extend({}, sereneOptions, options));
				});
			}
		};
		
		lightboxes();
		
		// Fixed scroll to top
		if ($.isFunction($.fn.smoothScroll)) {
			var $fixedScrollTop = $('<div id="fixed-scroll-top"/>').click(function (e) {
				$.smoothScroll({ speed: 1000 });
			}).appendTo($body);			
			
			$(window).bind('scroll.fixed-scroll-top resize.fixed-scroll-top', function () {
				if ($(window).scrollTop() > 400) {
					$fixedScrollTop.fadeIn('slow');
				} else {
					$fixedScrollTop.fadeOut('slow');
				}
			});
			
			// Bind any links with the class scroll-top or href=#top to scroll to page top
			$('a.scroll-top, a[href="#top"]').click(function () {			
				$.smoothScroll({ speed: 1000 });
				return false;
			});
		}
				
		// Logo slider carousel
		if ($.isFunction($.fn.jcarousel)) {
			$('.logo-slider-wrapper').each(function () {
				var $root = $(this),
				$slider = $root.find('.logo-slider-inner');
				
				$slider.jcarousel({
					scroll: 1,
					wrap: 'circular'
				});
				
				$root.find('.logo-slider-prev').click(function() {
					$slider.jcarousel('scroll', '-=1');
				});
				
				$root.find('.logo-slider-next').click(function() {
					$slider.jcarousel('scroll', '+=1');
				});
			});			
		}
		
		// Twitter feed
		$(document).on('tweets', function (e, tweets) {
			// Twitter slider widget
			$('.twitter-widget-slider').each(function () {
				var $root = $(this),
				$slidesWrap = $root.find('.slides'),
				$next = $root.find('.forward'),
				$prev = $root.find('.backward'),
				options = $root.data('options') || {};
				
				$root.find('.bubble-content-load').css('background', 'none');
				
				for (var i = 0; i < tweets.length; i++) {					
					$slidesWrap.append('<div class="slide"><p class="tweet-content">' + tweets[i].content + '</p> <a class="tweet-time" href="../../../twitter.com/' + tweets[i].username + '/statuses/' + tweets[i].id + '">' + tweets[i].time + '</a></div>');
				}
				
				var $slides = $slidesWrap.children();				
				$slides.each(function () {
					$(this).width($(this).actual('width'));
				});

				if ($slides.length) {
					$slidesWrap.cycle($.extend({}, {
						next: $next,
						prev: $prev,
						fx: 'fade',
						speedOut: 1,
						cleartype: true,
						cleartypeNoBg: true,
						before: function (curr, next, opts, fwd) {
						    var $ht = $(this).height();

						    //set the container's height to that of the current slide
						    $(this).parent().stop().animate({height: $ht});
						}
					}, options));
				}
			});
		});
		
		$('.portfolio').each(function () {
			// Portfolio Quicksand filter
			var $portfolio = $(this),
			$portfolioItems = $('.portfolio-items', $portfolio);
						
			if ($('.portfolio-filter', $portfolio).length && $.isFunction($.fn.quicksand)) {		
				var $data = $('.portfolio-items', $portfolio).clone();
				
				$('.portfolio-filter a', $portfolio).click(function () {
					var $clicked = $(this),
					filter = '' + $clicked.data('filter');
					
					$('.portfolio-filter a', $portfolio).removeClass('active-filter');
					
					if (filter == 'all') {
						var $filteredData = $data.find('.portfolio-item');
					} else {
						var $filteredData = $data.find('.portfolio-item').filter(function () {
							var types = ($(this).data('types') || '').split(',');
							return $.inArray(filter, types) > -1;
						});
					}

					$portfolioItems.quicksand($filteredData, {
					    duration: 800,
					    easing: 'easeInOutQuad',
					    enhancement: function () {
							//Cufon.replace($('.portfolio-item-title', $portfolio));
						}
					}, function () {
						lightboxes($portfolioItems);
					});
					
					$clicked.addClass('active-filter');
					return false;
				});
			}
		});
		
		// Popdown message
		var $popdown = $('#popdown'),
		togglePopdown = function (callback) {
			$popdown.animate({
				opacity: 'toggle',
				height: 'toggle'
			}, {
				duration: 600,
				complete: function () {
					if (typeof callback === 'function') {
						callback();
					}
				}
			});
		};
		
		if (typeof window.enablePopdown === 'boolean') {
			enablePopdown = window.enablePopdown;
		}
		
		if (enablePopdown && $popdown.length) {
			var $popdownTrigger = $('#popdown-trigger'),
			showTrigger = function () {
				$popdownTrigger.animate({top: '10px', opacity: 'show'}, 600);
			},
			hideTrigger = function (callback) {
				$popdownTrigger.hide().css({top: '-25px'});
				if (typeof callback === 'function') {
					callback();
				}
			};
						
			$('#popdown-hide').click(function () {
				$.cookie('hidePopdown', true, { expires: 7 });
				togglePopdown(showTrigger);
			});
			
			$popdownTrigger.click(function () {
				$.cookie('hidePopdown', null);
				hideTrigger(togglePopdown);
			});
			
			setTimeout(function () {
				if (!$.cookie('hidePopdown')) {
					togglePopdown();
				} else {
					showTrigger();
				}
			}, 3000);
		}		
		
		// Trigger resize event
		$(window).resize();
	}); // End (document).ready
	
	$(window).load(function() {
		// Nivo slider
		if ($('#nivo-slider').length && $.isFunction($.fn.nivoSlider)) {
			$('#nivo-slider').nivoSlider();
		}
		
		// Orbit slider
		if ($('#orbit-slider').length && $.isFunction($.fn.orbit)) {
			$('#orbit-slider').orbit({
				bullets: true
			});
		}
		
		// Generic sliders
		if ($.isFunction($.fn.cycle)) {
			$('.slider').each(function () {
				var $root = $(this),
					$slidesWrap = $root.find('.slides'),
					$slides = $slidesWrap.children(),
					$next = $root.find('.forward'),
					$prev = $root.find('.backward'),
					options = $root.data('options') || {};
					
				$slides.each(function () {
					$(this).width($(this).actual('width'));
				});

				if ($slidesWrap.children().length) {
					$slidesWrap.cycle($.extend({}, {
						next: $next,
						prev: $prev,
						fx: 'fade',
						speedOut: 1,
						cleartype: true,
						cleartypeNoBg: true,
						before: function (curr, next, opts, fwd) {
						    var ht = $(next).height();
						    $(this).parent().stop().animate({height: ht});
						}
					}, options));
				}
			});
		}
		
		// Load the Twitter feed
		if (twitterUsername && tweetCount > 0) {
			(function() {
				var t = document.createElement('script'); t.type = 'text/javascript'; t.src = '../../../api.twitter.com/1/statuses/user_timeline.json@screen_name=' + twitterUsername + '&count=' + tweetCount + '&include_rts=1&callback=tcrTwitterCallback';
				var h = document.getElementsByTagName('head')[0]; h.appendChild(t);
			})();
		}
				
		// Sharrre buttons
		$('.sharrre-twitter').sharrre({
		    share: {
		        twitter: true
		    },
		    url: window.location.href,
		    text: document.title,
		    title: sharrre.twitter,
		    enableHover: false,
		    buttons: {
		        twitter: {}
		    },
		    click: function(api, options) {
		        api.simulateClick();
		        api.openPopup('twitter');
		    }
		});

		$('.sharrre-facebook').sharrre({
		    share: {
		        facebook: true
		    },
		    url: window.location.href,
		    text: document.title,
		    title: sharrre.facebook,
		    enableHover: false,
		    click: function(api, options) {
		        api.simulateClick();
		        api.openPopup('facebook');
		    }
		});

		$('.sharrre-googleplus').sharrre({
		    share: {
		        googlePlus: true
		    },
		    url: window.location.href,
		    text: document.title,
		    title: sharrre.google,
		    enableHover: false,
		    click: function(api, options) {
		        api.simulateClick();
		        api.openPopup('googlePlus');
		    },
		    urlCurl: 'js/sharrre.php'
		});
	}); // End (window).load	

	// Preload images
	$.preloadImages([
     	'images/go-to-top-arrow.png',
     	'images/nav-quick-contact-button-on.png',
     	'images/nav-quick-contact-button-hover.png',
 		'images/loading.gif',
 		'images/quick-contact-submit-button-right.png',
 		'images/quick-contact-submit-button-left.png',
 		'images/quick-contact-submit-button-right-hover.png',
 		'images/quick-contact-submit-button-left-hover.png',
 		'images/big-impact-button-left-hover.png',
 		'images/big-impact-button-right-hover.png',
 		'images/mini-slider-arrow-right-hover.png',
 		'images/mini-slider-arrow-left-hover.png',
 		'images/expand-image.png',
 		'images/play-image.png',
 		'images/link-image.png',
 		'images/icons/photos.png',
 		'images/icons/movie.png',
 		'images/icons/doc.png',
 		'images/icons/music.png',
 		'images/button-gradient-hover.png',
 		'images/background-controls-back.png',
 		'images/background-controls-forward.png',
 		'images/background-controls-play.png',
 		'images/background-controls-pause.png',
 		'images/fullscreen-icon.png',
 		'images/serene-back.png',
 		'images/serene-play.png',
 		'images/serene-pause.png',
 		'images/serene-forward.png',
 		'images/close-icon.png', 		
 		'images/close-icon-hover.png', 	
 		'images/background/transparent/plain-light-90.png',
 		'images/background/transparent/plain-dark-90.png',
 		'images/little-link-icon-hover.png',
 		'images/dark-link-hover.png',
 		'images/light-link-hover.png',
 		'images/little-link-icon-hover-footer.png',
 		'images/close-icon-hover.png',
 		'images/info-icon-on-black.png',
 		'images/fs-bullet-hover.png'
	]);
})(jQuery, window);

// Cufon font replacement
if (window.Cufon) {
	Cufon.replace('h1, h2, h3, .date-overlay .day-month, .comments-overlay .number-of-comments, .logo-slider-wrapper .logo-slider-title, .impress-slider-title, .fullscreen-caption h1, .fs-slider-caption h1, .serene-caption h1, .orbit-wrapper .orbit-caption h1');
	Cufon.now();
}