cshtml: 视图文件:
-------------------------------
 <script>

        $(function () {
            $('footer.copyright_footer .other_language').click(function () {
                $.ajax({
                    async: false,
                    type: 'POST',
                    url: "/Home/LanguageChanged",
                    data: { newlang: $('footer.copyright_footer .other_language a').html() },
                    success: function (state) {
                        var temp = $('footer.copyright_footer .cur_language').html();
                        $('footer.copyright_footer .cur_language').html($('footer.copyright_footer .other_language').html());
                        $('footer.copyright_footer .other_language').html(temp);
                        window.location.reload(true);
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
		public bool LanguageChanged(string newlang)
		{
			Response.Cookies["Web.Language.CurrentUICulture"].Value = CultureInfo.CreateSpecificCulture(newlang).Name;	// 与url相关
			Response.Cookies["Web.Language.CurrentUICulture"].Expires = DateTime.Now.AddDays(180);

			Session["language"] = newlang;
			if (Session["language"].ToString().ToLower().StartsWith("en"))
				Session["other_language"] = "zh-CN";
			else
				Session["other_language"] = "en-US";

			/// 把设置保存进cookie
			//HttpCookie _cookie = new HttpCookie("Web.Language.CurrentUICulture", CultureInfo.CreateSpecificCulture(newlang).Name);
			//_cookie.Expires = DateTime.Now.AddDays(180);
			//Response.SetCookie(_cookie);

			//Response.Cookies["Web.Language.CurrentUICulture"].Name = "Web.Language.CurrentUICulture";
			//	Redirect("/" + newlang + "/Home/Index?id=" + new Random().Next());

			return true;
		}