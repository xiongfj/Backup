<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="login.aspx.cs" Inherits="WebApplication5.login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <script>
        function clientCheck() {
            if (document.getElementById("userAccount").value == '' || document.getElementById("password").value == '' || document.getElementById("checkcode").value == '') {
                alert("用户名、密码、验证码均不能为空！");
                return false;
            }
            return true;       // 返回 true 会提交页面.返回 false 则不会提交页面.
        }
    </script>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        用户名:<input id="userAccount" runat="server" type="text" style="width:100px;height:20px;" value="admin" />
        密码:<input id="password" runat="server" type="password" style="width:100px;height:20px;" value="666666"/>
        验证码:<input id="checkcode" runat="server" type="text" style="width:50px;height:20px;" />
        <!-- asp:Image 没有 OnClick 事件提示,但是可以照常使用!! -->
        <!-- CheckCode.aspx?a=... 后面为了防止页面缓存,然后得到相同的验证码. -->
        <asp:Image runat="server" width="120px" Height="22px" src="CheckCode.aspx"
                             onclick="this.src='CheckCode.aspx?a=' + Math.random()"/>

        <asp:Button runat="server" Text="登录" OnClientClick="return clientCheck();" OnClick="btnLogin_Click"/>
    </div>
        <p>用户名: admin 或 guest 或 anglebaby</p>
        <p>默认密码: 000000 </p> 
    </form>
</body>
</html>
