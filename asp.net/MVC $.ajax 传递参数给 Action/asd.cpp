cshtml: ��ͼ�ļ�:
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
		/// �л�����, �޸� cookies �� Session
		/// </summary>
		/// <param name="newlang">en-US zh-CN ����ʽ</param>
		/// <returns></returns>
		public string LanguageChanged(string newlang, string index)
		{
		..............
			return "hello world!";
		}