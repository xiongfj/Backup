cshtml: 视图文件:
-------------------------------
 <script>

        $(function () {
            $('footer.copyright_footer .other_language').click(function () {
                $.ajax({
                    async: false,
                    type: 'POST',
                    url: "/Home/LanguageChanged",
                    data: { newlang: $('footer.copyright_footer .other_language a').html(), index: "100" },
                    success: function (data) {
                        alert(data);	// hello world!
                    }
                })
            })
        })
    </script>
	
--------------------------------

HomeController.cs :
----------------------------------
/// <summary>
		/// 切换语言, 修改 cookies 和 Session
		/// </summary>
		/// <param name="newlang">en-US zh-CN 的形式</param>
		/// <returns></returns>
		public string LanguageChanged(string newlang, string index)
		{
		..............
			return "hello world!";
		}