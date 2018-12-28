/*!
 * Quform jQuery plugin
 * 
 * Copyright 2009 - 2012 ThemeCatcher
 */
;(function($) {
	var Quform = function($form, options) {
		var self = this,	
			submitted = false,
			useProp = !!$.fn.prop;
		
		// Class properties
		self.$form = $form;
		self.options = options;
		self.$container = $(options.container, $form);
		self.$loading = $(options.loading, $form);
		self.$submitButton = $(options.submitButton, $form);
		
		/**
		 * Form reset
		 * 
		 * Resets the form to it's original state
		 * 
		 * @param boolean resetValues If true it also resets form values
		 */
		self.reset = function (resetValues) {
			// Recaptcha can only be used once, so refresh it if it's there
			if (typeof Recaptcha === 'object') {
				Recaptcha.reload();
			}
			
			// Allow the form to be submitted again						
			submitted = false;
			self.$submitButton[useProp ? 'prop' : 'attr']('disabled', false);
			
			// Hide the loading text/gif
			self.$loading.hide();
			
			// Remove any previous errors/success messages from the form
            $('.quform-success-message', $form).remove();
            $('.quform-error-message', $form).remove();
            $('.quform-element-error', $form).removeClass('quform-element-error');
            $('.quform-errors', $form).remove();
            
            if (options.reset && resetValues) {
	            // Reset the form
	            $form.resetForm();
	            
				// Call blur on element to reset inline labels
				$('input[type="text"], textarea', $form).blur();
			}
		};
		
		/**
		 * Display an error message above the form
		 * 
		 * @param string html The error message HTML
		 */
		self.errorMessage = function (html) {			
			// Display the message
			var $message = $('<div class="quform-error-message" />').append($('<div class="quform-error-title"/>').html(options.errorTitle)).append(html).hide().insertBefore(self.$container).fadeIn('slow');

			// Scroll to the message if it's not visible
        	if (options.scrolling && $(window).scrollTop() >= ($message.offset().top - options.scrollThreshold)) {
                $.smoothScroll({
                	offset: -50,
                	scrollTarget: $message,
                	speed: options.scrollSpeed
                });
        	}
		};
		
		// Bind on submit to submit via Ajax
		$form.bind('submit', function (event) {
			// Prevent double submit
			if (submitted) {
				return false;
			} else {
				submitted = true;
				self.$submitButton[useProp ? 'prop' : 'attr']('disabled', true);
			}

			// Prevent the browser submitting the form normally
			event.preventDefault();
			
			// Show the loading text/gif
			self.$loading.fadeIn('slow');
			
			// Hide any tooltips
			$('.qtip').hide();
						
			// Submit the form
			$form.ajaxSubmit({
				async: false,
				dataType: 'json',
				data: { 'quform_ajax': 1 },
				iframe: true,
				success: function(response) {										
					// Check if the form submission was successful
					if (response === null || typeof response === 'undefined') {
						self.reset();
						
						self.errorMessage(options.errorResponseEmpty);
					} else if (typeof response === 'object') {
						if (response.type === 'success') {
							if (typeof response.redirect === 'string') {
								self.reset(true);
								window.location = response.redirect;
								return;
							}							
							
							// successStart function
							if (typeof options.successStart === 'function') {
								options.successStart.call(self, response);
							}
							
							// Check for a custom success function
							if (typeof options.success === 'function') {
								options.success.call(self, response);
							} else {								
								var success = function () {
									// Reset the form
									self.reset(true);
									
			                        // Create a new success message
			                        var $successMessage = $('<div class="quform-success-message"/>').html(response.message).hide().insertBefore(self.$container).fadeIn(options.successFadeInSpeed).show(0, function() {
		                                // successEnd function
		                                if (typeof options.successEnd === 'function') {
	                                        options.successEnd.call(self, response, $successMessage);
		                                }
			                        });
			                        
			                        // Scroll to the success message if it's not visible
		                        	if (options.scrolling && $(window).scrollTop() >= ($successMessage.offset().top - options.scrollThreshold)) {
		                                $.smoothScroll({
		                                	offset: options.scrollOffset,
		                                	scrollTarget: $successMessage,
		                                	speed: options.scrollSpeed
		                                });
		                        	}
			                        
			                        // Fade out the success message after some time
			                        if (options.successTimeout > 0) {
				                        setTimeout(function () {
				                            $successMessage.fadeOut(options.successFadeOutSpeed).hide(0, function () {
				                            	$successMessage.remove();
				                            });
				                        }, options.successTimeout);
			                        }
								};
								
								if (options.hideFormSpeed) {
									self.$container.fadeOut(options.hideFormSpeed).hide(0, function () {
										success();
									});
								} else {
									success();
								}
							}
						} else if (response.type == 'error') {
							// errorStart callback
							if (typeof options.errorStart === 'function') {
								options.errorStart.call(self, response);
							}
							
							// Check for a custom error function
							if (typeof options.error === 'function') {
								options.error.call(self, response);
							} else {
								// Reset the form
								self.reset();
								
								var $firstError;
								
								// Go through each element containing errors					
								$.each(response.data, function(index, info) {				
									// If there are errors for this element
									if (typeof info.errors === 'object' && info.errors.length > 0) {
										// Save a reference to this element									
										var $element = $("[name='" + index + "']", $form);
										
										// If the returned element exists
										if ($element.size()) {
											// Create a blank error list
											var $errorList = $('<ul class="quform-errors"></ul>');
											
											// Append the error
											$errorList.append('<li>' + info.errors[0] + '</li>');
																						
											// Add the error list after the element's wrapper
											$element.addClass('quform-element-error').parents('.element-wrapper').append($errorList);
																						
											// Save the first error so we can scroll to it
											if (!$firstError) $firstError = $element;
										} else {
											alert("Element '" + index + "' does not exist in the HTML but is being validated, you must also remove the element configuration from process.php");
										}
									}
								});
								
								// Fade all errors in
								$('.quform-errors', $form).fadeIn('slow');
																
								// Scroll to the first error
								if ($firstError && $firstError.length && options.scrolling && $(window).scrollTop() >= ($firstError.offset().top - options.scrollThreshold)) {
	                                $.smoothScroll({
	                                	offset: options.scrollOffset,
	                                	scrollTarget: $firstError,
	                                	speed: options.scrollSpeed
	                                });
								}
								
								// errorEnd callback
								if (typeof options.errorEnd === 'function') {
									options.errorEnd.call(self, response);
								}
							}
						} // response.type == 'error'
					} // typeof response === 'object'
				},				
				error: function (response) {
					// Reset the form
					self.reset();

					if (typeof response.responseText === 'string' && response.responseText.length > 0) {
						self.errorMessage('<pre>' + response.responseText + '</pre>');		
					} else {
						self.errorMessage(options.errorAjax);
					}
				}
			}); // $form.ajaxSubmit()			
		}); // $form.bind('submit')	
	}; // var Quform
	
	$.fn.Quform = function(options) {
		var defaults = {
			container: '.quform-elements',
			loading: '.quform-loading-wrap .loading',
			submitButton: '.quform-submit-button',
			reset: true,
			hideFormSpeed: false,
			successFadeInSpeed: 'slow',
			successFadeOutSpeed: 'slow',
			successTimeout: 38000,
			scrolling: true,
			scrollSpeed: 400,
			scrollThreshold: 20,
			scrollOffset: -50,
			errorTitle: 'There was a problem',
			errorResponseEmpty: 'An error occurred and the response from the server was empty.',
			errorAjax: 'An Ajax error occurred.'
		};
		
		return this.each(function () {
			$(this).data('quform', new Quform($(this), $.extend({}, defaults, options)));
		});
	}; // End $.fn.Quform
})(jQuery); // End jQuery wrapper

/*!
 * Image preloader
 * 
 * Copyright 2009 - 2012 ThemeCatcher
 */
(function ($) {
	$.preloadImages = function (images) {
		var loaded = [];
		for (var i = 0; i < images.length; i++) {
	        var elem = new Image();
	        elem.src = images[i];
	        loaded.push(elem);
	    }
	};
})(jQuery);

/*!
 * jQuery Smooth Scroll Plugin v1.4.1
 *
 * Date: Tue Nov 15 14:24:14 2011 EST
 * Requires: jQuery v1.3+
 *
 * Copyright 2010, Karl Swedberg
 * Dual licensed under the MIT and GPL licenses (just like jQuery):
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 */
(function(b){function l(c){return c.replace(/^\//,"").replace(/(index|default).[a-zA-Z]{3,4}$/,"").replace(/\/$/,"")}function m(c){return c.replace(/(:|\.)/g,"\\$1")}var n=l(location.pathname),o=function(c){var e=[],a=false,d=c.dir&&c.dir=="left"?"scrollLeft":"scrollTop";this.each(function(){if(!(this==document||this==window)){var g=b(this);if(g[d]()>0)e.push(this);else{g[d](1);a=g[d]()>0;g[d](0);a&&e.push(this)}}});if(c.el==="first"&&e.length)e=[e.shift()];return e};b.fn.extend({scrollable:function(c){return this.pushStack(o.call(this,
{dir:c}))},firstScrollable:function(c){return this.pushStack(o.call(this,{el:"first",dir:c}))},smoothScroll:function(c){c=c||{};var e=b.extend({},b.fn.smoothScroll.defaults,c);this.die("click.smoothscroll").live("click.smoothscroll",function(a){var d={},g=b(this),h=location.hostname===this.hostname||!this.hostname,f=e.scrollTarget||(l(this.pathname)||n)===n,j=m(this.hash),i=true;if(!e.scrollTarget&&(!h||!f||!j))i=false;else{h=e.exclude;f=0;for(var k=h.length;i&&f<k;)if(g.is(m(h[f++])))i=false;h=e.excludeWithin;
f=0;for(k=h.length;i&&f<k;)if(g.closest(h[f++]).length)i=false}if(i){a.preventDefault();b.extend(d,e,{scrollTarget:e.scrollTarget||j,link:this});b.smoothScroll(d)}});return this}});b.smoothScroll=function(c,e){var a,d,g,h=0;d="offset";var f="scrollTop",j={};if(typeof c==="number"){a=b.fn.smoothScroll.defaults;g=c}else{a=b.extend({},b.fn.smoothScroll.defaults,c||{});if(a.scrollElement){d="position";a.scrollElement.css("position")=="static"&&a.scrollElement.css("position","relative")}g=e||b(a.scrollTarget)[d]()&&
b(a.scrollTarget)[d]()[a.direction]||0}a=b.extend({link:null},a);f=a.direction=="left"?"scrollLeft":f;if(a.scrollElement){d=a.scrollElement;h=d[f]()}else d=b("html, body").firstScrollable();j[f]=g+h+a.offset;b.isFunction(a.beforeScroll)&&a.beforeScroll.call(d,a);d.animate(j,{duration:a.speed,easing:a.easing,complete:function(){a.afterScroll&&b.isFunction(a.afterScroll)&&a.afterScroll.call(a.link,a)}})};b.smoothScroll.version="1.4.1";b.fn.smoothScroll.defaults={exclude:[],excludeWithin:[],offset:0,
direction:"top",scrollElement:null,scrollTarget:null,beforeScroll:null,afterScroll:null,easing:"swing",speed:400}})(jQuery);

/*!
 * jQuery Form Plugin
 * version: 2.95 (30-JAN-2012)
 * @requires jQuery v1.3.2 or later
 *
 * Examples and documentation at: http://malsup.com/jquery/form/
 * Dual licensed under the MIT and GPL licenses:
 *	http://www.opensource.org/licenses/mit-license.php
 *	http://www.gnu.org/licenses/gpl.html
 */
(function(c){function o(){if(c.fn.ajaxSubmit.debug){var a="[jquery.form] "+Array.prototype.join.call(arguments,"");window.console&&window.console.log?window.console.log(a):window.opera&&window.opera.postError&&window.opera.postError(a)}}c.fn.ajaxSubmit=function(a){function f(b){for(var g=new FormData,f=0;f<b.length;f++)"file"!=b[f].type&&g.append(b[f].name,b[f].value);j.find("input:file:enabled").each(function(){var a=c(this).attr("name"),d=this.files;if(a)for(var b=0;b<d.length;b++)g.append(a,d[b])}); if(a.extraData)for(var k in a.extraData)g.append(k,a.extraData[k]);a.data=null;b=c.extend(!0,{},c.ajaxSettings,a,{contentType:!1,processData:!1,cache:!1,type:"POST"});b.data=null;var e=b.beforeSend;b.beforeSend=function(c,b){b.data=g;c.upload&&(c.upload.onprogress=function(a){b.progress(a.position,a.total)});e&&e.call(b,c,a)};c.ajax(b)}function e(b){function f(){function a(){try{var b=(m.contentWindow?m.contentWindow.document:m.contentDocument?m.contentDocument:m.document).readyState;o("state = "+ b);"uninitialized"==b.toLowerCase()&&setTimeout(a,50)}catch(c){o("Server abort: ",c," (",c.name,")"),k(u),s&&clearTimeout(s),s=void 0}}var b=j.attr("target"),h=j.attr("action");e.setAttribute("target",q);g||e.setAttribute("method","POST");h!=d.url&&e.setAttribute("action",d.url);!d.skipEncodingOverride&&(!g||/post/i.test(g))&&j.attr({encoding:"multipart/form-data",enctype:"multipart/form-data"});d.timeout&&(s=setTimeout(function(){v=!0;k(y)},d.timeout));var i=[];try{if(d.extraData)for(var l in d.extraData)i.push(c('<input type="hidden" name="'+ l+'">').attr("value",d.extraData[l]).appendTo(e)[0]);d.iframeTarget||(r.appendTo("body"),m.attachEvent?m.attachEvent("onload",k):m.addEventListener("load",k,!1));setTimeout(a,15);e.submit()}finally{e.setAttribute("action",h),b?e.setAttribute("target",b):j.removeAttr("target"),c(i).remove()}}function k(a){if(!h.aborted&&!z){try{p=m.contentWindow?m.contentWindow.document:m.contentDocument?m.contentDocument:m.document}catch(b){o("cannot access response document: ",b),a=u}if(a===y&&h)h.abort("timeout"); else if(a==u&&h)h.abort("server abort");else if(p&&p.location.href!=d.iframeSrc||v){m.detachEvent?m.detachEvent("onload",k):m.removeEventListener("load",k,!1);var a="success",g;try{if(v)throw"timeout";var e="xml"==d.dataType||p.XMLDocument||c.isXMLDoc(p);o("isXml="+e);if(!e&&window.opera&&(null==p.body||""==p.body.innerHTML)&&--w){o("requeing onLoad callback, DOM not available");setTimeout(k,250);return}var f=p.body?p.body:p.documentElement;h.responseText=f?f.innerHTML:null;h.responseXML=p.XMLDocument? p.XMLDocument:p;e&&(d.dataType="xml");h.getResponseHeader=function(a){return{"content-type":d.dataType}[a]};f&&(h.status=Number(f.getAttribute("status"))||h.status,h.statusText=f.getAttribute("statusText")||h.statusText);var j=(d.dataType||"").toLowerCase(),i=/(json|script|text)/.test(j);if(i||d.textarea){var l=p.getElementsByTagName("textarea")[0];if(l)h.responseText=l.value,h.status=Number(l.getAttribute("status"))||h.status,h.statusText=l.getAttribute("statusText")||h.statusText;else if(i){var q= p.getElementsByTagName("pre")[0],t=p.getElementsByTagName("body")[0];q?h.responseText=q.textContent?q.textContent:q.innerText:t&&(h.responseText=t.textContent?t.textContent:t.innerText)}}else"xml"==j&&!h.responseXML&&null!=h.responseText&&(h.responseXML=C(h.responseText));try{A=D(h,j,d)}catch(B){a="parsererror",h.error=g=B||a}}catch(x){o("error caught: ",x),a="error",h.error=g=x||a}h.aborted&&(o("upload aborted"),a=null);h.status&&(a=200<=h.status&&300>h.status||304===h.status?"success":"error"); "success"===a?(d.success&&d.success.call(d.context,A,"success",h),n&&c.event.trigger("ajaxSuccess",[h,d])):a&&(void 0==g&&(g=h.statusText),d.error&&d.error.call(d.context,h,a,g),n&&c.event.trigger("ajaxError",[h,d,g]));n&&c.event.trigger("ajaxComplete",[h,d]);n&&!--c.active&&c.event.trigger("ajaxStop");d.complete&&d.complete.call(d.context,h,a);z=!0;d.timeout&&clearTimeout(s);setTimeout(function(){d.iframeTarget||r.remove();h.responseXML=null},100)}}}var e=j[0],i,l,d,n,q,r,m,h,v,s;i=!!c.fn.prop;if(b)if(i)for(l= 0;l<b.length;l++)i=c(e[b[l].name]),i.prop("disabled",!1);else for(l=0;l<b.length;l++)i=c(e[b[l].name]),i.removeAttr("disabled");if(c(":input[name=submit],:input[id=submit]",e).length)alert('Error: Form elements must not have name or id of "submit".');else if(d=c.extend(!0,{},c.ajaxSettings,a),d.context=d.context||d,q="jqFormIO"+(new Date).getTime(),d.iframeTarget?(r=c(d.iframeTarget),i=r.attr("name"),null==i?r.attr("name",q):q=i):(r=c('<iframe name="'+q+'" src="'+d.iframeSrc+'" />'),r.css({position:"absolute", top:"-1000px",left:"-1000px"})),m=r[0],h={aborted:0,responseText:null,responseXML:null,status:0,statusText:"n/a",getAllResponseHeaders:function(){},getResponseHeader:function(){},setRequestHeader:function(){},abort:function(a){var b="timeout"===a?"timeout":"aborted";o("aborting upload... "+b);this.aborted=1;r.attr("src",d.iframeSrc);h.error=b;d.error&&d.error.call(d.context,h,b,a);n&&c.event.trigger("ajaxError",[h,d,b]);d.complete&&d.complete.call(d.context,h,b)}},(n=d.global)&&!c.active++&&c.event.trigger("ajaxStart"), n&&c.event.trigger("ajaxSend",[h,d]),d.beforeSend&&!1===d.beforeSend.call(d.context,h,d))d.global&&c.active--;else if(!h.aborted){if(b=e.clk)if((i=b.name)&&!b.disabled)d.extraData=d.extraData||{},d.extraData[i]=b.value,"image"==b.type&&(d.extraData[i+".x"]=e.clk_x,d.extraData[i+".y"]=e.clk_y);var y=1,u=2,b=c("meta[name=csrf-token]").attr("content");if((i=c("meta[name=csrf-param]").attr("content"))&&b)d.extraData=d.extraData||{},d.extraData[i]=b;d.forceSync?f():setTimeout(f,10);var A,p,w=50,z,C=c.parseXML|| function(a,b){window.ActiveXObject?(b=new ActiveXObject("Microsoft.XMLDOM"),b.async="false",b.loadXML(a)):b=(new DOMParser).parseFromString(a,"text/xml");return b&&b.documentElement&&"parsererror"!=b.documentElement.nodeName?b:null},E=c.parseJSON||function(a){return window.eval("("+a+")")},D=function(a,b,d){var g=a.getResponseHeader("content-type")||"",e="xml"===b||!b&&0<=g.indexOf("xml"),a=e?a.responseXML:a.responseText;e&&"parsererror"===a.documentElement.nodeName&&c.error&&c.error("parsererror"); d&&d.dataFilter&&(a=d.dataFilter(a,b));"string"===typeof a&&("json"===b||!b&&0<=g.indexOf("json")?a=E(a):("script"===b||!b&&0<=g.indexOf("javascript"))&&c.globalEval(a));return a}}}if(!this.length)return o("ajaxSubmit: skipping submit process - no element selected"),this;var g,b,j=this;"function"==typeof a&&(a={success:a});g=this.attr("method");b=this.attr("action");(b=(b="string"===typeof b?c.trim(b):"")||window.location.href||"")&&(b=(b.match(/^([^#]+)/)||[])[1]);a=c.extend(!0,{url:b,success:c.ajaxSettings.success, type:g||"GET",iframeSrc:/^https/i.test(window.location.href||"")?"javascript:false":"about:blank"},a);b={};this.trigger("form-pre-serialize",[this,a,b]);if(b.veto)return o("ajaxSubmit: submit vetoed via form-pre-serialize trigger"),this;if(a.beforeSerialize&&!1===a.beforeSerialize(this,a))return o("ajaxSubmit: submit aborted via beforeSerialize callback"),this;var k=a.traditional;void 0===k&&(k=c.ajaxSettings.traditional);var i,l=this.formToArray(a.semantic);a.data&&(a.extraData=a.data,i=c.param(a.data, k));if(a.beforeSubmit&&!1===a.beforeSubmit(l,this,a))return o("ajaxSubmit: submit aborted via beforeSubmit callback"),this;this.trigger("form-submit-validate",[l,this,a,b]);if(b.veto)return o("ajaxSubmit: submit vetoed via form-submit-validate trigger"),this;b=c.param(l,k);i&&(b=b?b+"&"+i:i);"GET"==a.type.toUpperCase()?(a.url+=(0<=a.url.indexOf("?")?"&":"?")+b,a.data=null):a.data=b;var n=[];a.resetForm&&n.push(function(){j.resetForm()});a.clearForm&&n.push(function(){j.clearForm(a.includeHidden)}); if(!a.dataType&&a.target){var w=a.success||function(){};n.push(function(b){var g=a.replaceTarget?"replaceWith":"html";c(a.target)[g](b).each(w,arguments)})}else a.success&&n.push(a.success);a.success=function(b,c,g){for(var e=a.context||a,f=0,k=n.length;f<k;f++)n[f].apply(e,[b,c,g||j,j])};k=c("input:file:enabled[value]",this);i=0<k.length;b="multipart/form-data"==j.attr("enctype")||"multipart/form-data"==j.attr("encoding");k=!(!i||!k.get(0).files||!window.FormData);o("fileAPI :"+k);!1!==a.iframe&& (a.iframe||(i||b)&&!k)?a.closeKeepAlive?c.get(a.closeKeepAlive,function(){e(l)}):e(l):(i||b)&&k?(a.progress=a.progress||c.noop,f(l)):c.ajax(a);this.trigger("form-submit-notify",[this,a]);return this};c.fn.ajaxForm=function(a){if(0===this.length){var f=this.selector,e=this.context;if(!c.isReady&&f)return o("DOM not ready, queuing ajaxForm"),c(function(){c(f,e).ajaxForm(a)}),this;o("terminating; zero elements found by selector"+(c.isReady?"":" (DOM not ready)"));return this}return this.ajaxFormUnbind().bind("submit.form-plugin", function(g){g.isDefaultPrevented()||(g.preventDefault(),c(this).ajaxSubmit(a))}).bind("click.form-plugin",function(a){var b=a.target,e=c(b);if(!e.is(":submit,input:image")){b=e.closest(":submit");if(0==b.length)return;b=b[0]}var f=this;f.clk=b;"image"==b.type&&(void 0!=a.offsetX?(f.clk_x=a.offsetX,f.clk_y=a.offsetY):"function"==typeof c.fn.offset?(e=e.offset(),f.clk_x=a.pageX-e.left,f.clk_y=a.pageY-e.top):(f.clk_x=a.pageX-b.offsetLeft,f.clk_y=a.pageY-b.offsetTop));setTimeout(function(){f.clk=f.clk_x= f.clk_y=null},100)})};c.fn.ajaxFormUnbind=function(){return this.unbind("submit.form-plugin click.form-plugin")};c.fn.formToArray=function(a){var f=[];if(0===this.length)return f;var e=this[0],g=a?e.getElementsByTagName("*"):e.elements;if(!g)return f;var b,j,k,i,l,n;for(b=0,l=g.length;b<l;b++)if(j=g[b],k=j.name)if(a&&e.clk&&"image"==j.type)!j.disabled&&e.clk==j&&(f.push({name:k,value:c(j).val(),type:j.type}),f.push({name:k+".x",value:e.clk_x},{name:k+".y",value:e.clk_y}));else if((i=c.fieldValue(j, !0))&&i.constructor==Array)for(j=0,n=i.length;j<n;j++)f.push({name:k,value:i[j]});else null!==i&&"undefined"!=typeof i&&f.push({name:k,value:i,type:j.type});if(!a&&e.clk&&(a=c(e.clk),g=a[0],(k=g.name)&&!g.disabled&&"image"==g.type))f.push({name:k,value:a.val()}),f.push({name:k+".x",value:e.clk_x},{name:k+".y",value:e.clk_y});return f};c.fn.formSerialize=function(a){return c.param(this.formToArray(a))};c.fn.fieldSerialize=function(a){var f=[];this.each(function(){var e=this.name;if(e){var g=c.fieldValue(this, a);if(g&&g.constructor==Array)for(var b=0,j=g.length;b<j;b++)f.push({name:e,value:g[b]});else null!==g&&"undefined"!=typeof g&&f.push({name:this.name,value:g})}});return c.param(f)};c.fn.fieldValue=function(a){for(var f=[],e=0,g=this.length;e<g;e++){var b=c.fieldValue(this[e],a);null===b||"undefined"==typeof b||b.constructor==Array&&!b.length||(b.constructor==Array?c.merge(f,b):f.push(b))}return f};c.fieldValue=function(a,f){var e=a.name,g=a.type,b=a.tagName.toLowerCase();void 0===f&&(f=!0);if(f&& (!e||a.disabled||"reset"==g||"button"==g||("checkbox"==g||"radio"==g)&&!a.checked||("submit"==g||"image"==g)&&a.form&&a.form.clk!=a||"select"==b&&-1==a.selectedIndex))return null;if("select"==b){var j=a.selectedIndex;if(0>j)return null;for(var e=[],b=a.options,k=(g="select-one"==g)?j+1:b.length,j=g?j:0;j<k;j++){var i=b[j];if(i.selected){var l=i.value;l||(l=i.attributes&&i.attributes.value&&!i.attributes.value.specified?i.text:i.value);if(g)return l;e.push(l)}}return e}return c(a).val()};c.fn.clearForm= function(a){return this.each(function(){c("input,select,textarea",this).clearFields(a)})};c.fn.clearFields=c.fn.clearInputs=function(a){var c=/^(?:color|date|datetime|email|month|number|password|range|search|tel|text|time|url|week)$/i;return this.each(function(){var e=this.type,g=this.tagName.toLowerCase();c.test(e)||"textarea"==g||a&&/hidden/.test(e)?this.value="":"checkbox"==e||"radio"==e?this.checked=!1:"select"==g&&(this.selectedIndex=-1)})};c.fn.resetForm=function(){return this.each(function(){("function"== typeof this.reset||"object"==typeof this.reset&&!this.reset.nodeType)&&this.reset()})};c.fn.enable=function(a){void 0===a&&(a=!0);return this.each(function(){this.disabled=!a})};c.fn.selected=function(a){void 0===a&&(a=!0);return this.each(function(){var f=this.type;"checkbox"==f||"radio"==f?this.checked=a:"option"==this.tagName.toLowerCase()&&(f=c(this).parent("select"),a&&f[0]&&"select-one"==f[0].type&&f.find("option").selected(!1),this.selected=a)})};c.fn.ajaxSubmit.debug=!1})(jQuery);
