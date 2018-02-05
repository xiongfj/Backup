$(function () {
            $('.easyslider .ul-img li').eq(0).siblings().hide();
            $('.easyslider-text .text-item').eq(0).siblings().hide();
            $(".easyslider-page li").eq(0).css({ "background": "red" });

            var size = $(".easyslider .ul-img img").length;

            var timer = null;
            //autoChange();
            function autoChange() {
                timer = setInterval(function () {
                    $(".easyslider-control .next").click();
                }, 2500)
            }


            function moving(next_index, img_left_start, img_left_dest, text_left_start) {
                if (next_index % 2 == 0)
                    $('.easyslider li').css({ "background": "#666" });
                else
                    $('.easyslider li').css({ "background": "#ddd" });

                $('.easyslider .ul-img li').hide();
                $('.easyslider .ul-img li').eq(next_index).show();

                $('.easyslider-text .text-item').hide();
                $('.easyslider-text .text-item').eq(next_index).show();

                $(".easyslider-page li").css({ "background": "#999" });
                $(".easyslider-page li").eq(next_index).css({ "background": "red" });

                // moving
                $('.easyslider .move-img').css({ 'left': img_left_start })
                    .animate({ left: img_left_dest }, 300, 'swing');
                $('.move-text').css({ 'left': text_left_start, "opacity": "0.3" })
                    .animate({ left: '0px', "opacity": "1.0" }, 300, 'swing'); 
            }

            $(".easyslider-page li").click(function () {
                clearInterval(timer);

                var next_index = $(this).index();
                var cur_index = $('.easyslider .ul-img li:visible').index();
                if (cur_index == next_index)
                    return;

                var img_left_start = "-10px";
                var img_left_dest = "0px";
                var text_left_start = "-40px";

                if (cur_index < next_index) {
                    img_left_start = "0px";
                    img_left_dest = "-10px";
                    text_left_start = "40px";
                }
                moving(next_index, img_left_start, img_left_dest, text_left_start);
                autoChange();
            })

            $(".easyslider-control button").click(function () {
                clearInterval(timer);

                var next_index;
                var cur_index = $('.easyslider .ul-img li:visible').index();
                var img_left_start = "-10px";
                var img_left_dest = "0px";
                var text_left_start = "-40px";

                if ($(this).hasClass("prev")) {
                    next_index = cur_index - 1 >= 0 ? cur_index - 1 : size - 1;
                }
                if ($(this).hasClass("next")) {
                    next_index = cur_index + 1 <= size - 1 ? cur_index + 1 : 0;

                    img_left_start = "0px";
                    img_left_dest = "-10px";
                    text_left_start = "40px";
                }

                moving(next_index, img_left_start, img_left_dest, text_left_start);
                autoChange();
            })
        })