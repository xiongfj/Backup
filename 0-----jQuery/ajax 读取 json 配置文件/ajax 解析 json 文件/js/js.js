
$(function () {
    $.ajax({
        url: "./data/json.json?a=" + Math.random(),
        dataType: "json",
        async: false,
        success: function (a) {
            $('#result').text(a.DELETEDIR);  // 获取值, 可以不带引号或者带引号
        },
        error: function (a) {
            alert("E_LoadingConf" + a.responseText + " - " + a.error.text);
        }
    })
});
