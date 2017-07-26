<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="aspP.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .新建样式1 {
            background-color: #0066FF;
            color: #FF00FF;
        }

        .新建样式2 {
            background-color: #C0C0C0;
        }

        .新建样式3 {
            background-color: #0000CC;
            color: #FFFFFF;
        }

        .新建样式4 {
            border-width: 1px;
            border-color: White;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <table style="width: 257px; text-align: center; color: #000000; background-color: #66FF33;"
            cellpadding="0" cellspacing="0" border="1px" class="新建样式4">
            <tr>
                <td colspan="3" style="height: 31px" class="新建样式1">
                    <strong>用户登录</strong></td>
            </tr>
            <tr>
                <td style="width: 154px">
                    <span style="font-size: 9pt; font-weight: bold;">用户名</span></td>
                <td style="width: 97px; text-align: left; color: #66FF33;">
                    <asp:TextBox ID="txtUid" runat="server" Font-Size="9pt" Width="150px"
                        CssClass="新建样式2"></asp:TextBox></td>
                <td style="width: 70px"></td>
            </tr>
            <tr>
                <td style="width: 154px">
                    <span style="font-size: 9pt; font-weight: bold;">密 &nbsp;&nbsp;码</span></td>
                <td>
                    <asp:TextBox ID="txtPwd" runat="server" Font-Size="9pt" Width="150px"
                        CssClass="新建样式2" TextMode="Password"></asp:TextBox>
                </td>
                <td style="width: 70px"></td>
            </tr>
            <tr>
                <td style="width: 154px; height: 1px">
                    <span style="font-size: 9pt; font-weight: bold;">验证码</span></td>
                <td colspan="2" style="height: 1px; text-align: center; vertical-align: top;">
                    <table style="width: 101%" cellpadding="0" cellspacing="0">
                        <tr>
                            <td style="width: 34px; text-align: left;">
                                <asp:TextBox ID="txtCode" runat="server" Font-Size="9pt" Width="65px"
                                    CssClass="新建样式2"></asp:TextBox></td>
                            <td style="width: 51px">
                                <asp:Image ID="Image1" src="CheckCode.aspx" runat="server" Height="21px" Width="85px" /></td>
                            <td style="width: 32px"></td>
                        </tr>
                    </table>
                </td>
            </tr>
            <tr>
                <td colspan="3">
                    <asp:Button ID="btnOK" runat="server" Font-Size="9pt" Text="确定"
                        OnClick="Button1_Click" CssClass="新建样式3" />
                    <asp:Button ID="btnCancel" runat="server" Font-Size="9pt" Text="取消"
                        OnClick="btnCancel_Click" CssClass="新建样式3" /></td>
            </tr>
        </table>


    </form>

</body>
</html>



