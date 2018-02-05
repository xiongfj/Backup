$(function () {
            $('.easyslider-img li').eq(0).siblings().hide();
            $('.easyslider-text .text-item').eq(0).siblings().hide();
            $(".easyslider-page li").eq(0).css({ "background": "red" });

            var size = $(".easyslider-img img").length;

            var timer = null;
            autoChange();
            function autoChange() {
                timer = setInterval(function () {
                    $(".easyslider-control .next").click();
                }, 2500)
            }

            $(".easyslider-page li").click(function () {
                clearInterval(timer);

                var next_index = $(this).index();
                var cur_index = $('.easyslider-img li:visible').index();
                if (cur_index == next_index)
                    return;

                var img_left_start = "-15px";
                var img_left_dest = "0px";
                var text_left_start = "-40px";

                if (cur_index < next_index) {
                    img_left_start = "0px";
                    img_left_dest = "-15px";
                    text_left_start = "40px";
                }

                $('.easyslider-img li').hide();
                $('.easyslider-img li').eq(next_index).show();

                $('.easyslider-text .text-item').hide();
                $('.easyslider-text .text-item').eq(next_index).show();

                $(".easyslider-page li").css({ "background": "#999" });
                $(".easyslider-page li").eq(next_index).css({ "background": "red" });

                // moving
                $('.easyslider-img').css({ 'left': img_left_start })
                    .animate({ left: img_left_dest }, 250, 'swing');
                $('.easyslider-text .text-item:visible .move-part').css({ 'left': text_left_start, "opacity":"0.5" })
                    .animate({ left: '0px', "opacity":"1.0" }, 250, 'swing' ); 

                autoChange();
            })

            $(".easyslider-control button").click(function () {
                clearInterval(timer);

                var next_index;
                var cur_index = $('.easyslider-img li:visible').index();
                var img_left_start = "-15px";
                var img_left_dest = "0px";
                var text_left_start = "-40px";

                if ($(this).hasClass("prev")) {
                    next_index = cur_index - 1 >= 0 ? cur_index - 1 : size - 1;
                }
                if ($(this).hasClass("next")) {
                    next_index = cur_index + 1 <= size - 1 ? cur_index + 1 : 0;

                    img_left_start = "0px";
                    img_left_dest = "-15px";
                    text_left_start = "40px";
                }

                // show the next-img first
                $('.easyslider-img li').hide();
                $('.easyslider-img li').eq(next_index).show();
                $('.easyslider-text .text-item').hide();
                $('.easyslider-text .text-item').eq(next_index).show();
                $(".easyslider-page li").css({ "background": "#999" });
                $(".easyslider-page li").eq(next_index).css({ "background": "red" });

                // moving
                $('.easyslider-img').css({ 'left': img_left_start })
                    .animate({ left: img_left_dest }, 250, 'swing');
                $('.easyslider-text .text-item:visible .move-part').css({ 'left': text_left_start, "opacity": "0.5" })
                    .animate({ left: '0px', "opacity": "1.0" }, 250, 'swing'); 

                autoChange();
            })
        })