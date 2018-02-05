<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="default.aspx.cs" Inherits="WebApplication4._default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
	<script>
		// 支付宝第三方跳转
		//window.location.href = "https://openauth.alipaydev.com/oauth2/publicAppAuthorize.htm?app_id=2016091200494991&scope=auth_user&redirect_uri=http://sso.easyx.cn/callback.aspx&state=init";

		// 百度第三方登录
		window.location.href = "http://openapi.baidu.com/oauth/2.0/authorize?response_type=code&client_id=6tSitMHLktVopCoO8D0Z1tAq&redirect_uri=http://sso.easyx.cn/callback.aspx&display=popup";
	</script>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
    </form>
</body>
</html>
