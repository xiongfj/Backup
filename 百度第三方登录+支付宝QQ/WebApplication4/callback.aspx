<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="callback.aspx.cs" Inherits="WebApplication4.callback" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
	<script type="text/javascript" src="http://qzonestyle.gtimg.cn/qzone/openapi/qc_loader.js" charset="utf-8" data-callback="true"></script>
	<script>
		QC.Login.getMe(function (openId, accessToken) {
			alert(openId + " - " + accessToken);
		});
	</script>
</head>
<body>
    <form id="form1" runat="server">
		<asp:Label ID="label" runat="server"/>
    </form>
</body>
</html>
