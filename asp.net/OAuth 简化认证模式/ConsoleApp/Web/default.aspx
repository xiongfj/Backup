<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="default.aspx.cs" Inherits="Web.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
<script src="http://cdn.static.runoob.com/libs/jquery/1.10.2/jquery.min.js">
</script>
</head>
<body>
    <form id="form1">
		<div>
			Access Token<br />
			<input id="Authorize" type="button" name="signin.AccessToken" value="向认证服务器申请授权" />
		</div>
	</form>

	<script>
		$(function () {
			var authorizeUri = 'http://localhost:55650/authorize';
			var returnUri = 'http://localhost:57702/SignIn.html';

			$('#Authorize').click(function () {
				var uri = authorizeUri + "?state=nonce&response_type=token&client_id=xishuai&redirect_uri=" + returnUri;

				window.open(uri, 'Authorize', 'width=640,height=480');
			});
		});
	</script>

	<script>

	</script>
</body>
</html>
