<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="insert.aspx.cs" Inherits="WebApplication5.insert" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Label runat="server" ID="result"></asp:Label>
        <input type="text" runat="server" id="txtname" />
        <asp:Button runat="server"  Text="CommonDAL:ExecuteTable" OnClick="btn3_click" />
        <asp:Button runat="server"  Text="CommonDAL:Add" OnClick="btn4_click" />
        <asp:Button runat="server"  Text="CommonDAL:Update(IModel.IModel model)" OnClick="btn5_click" />
        <asp:Button runat="server"  Text="CommonDAL:Update(IModel.IModel model, string where)" OnClick="btn6_click" />
        <asp:Button runat="server"  Text="CommonDAL:ExecuteNonQuery(string sql)" OnClick="btn7_click" />
        <asp:Button runat="server"  Text="CommonDAL:ExecuteScalar(string sql)" OnClick="btn8_click" />
        <br />
        ---------------------------------------------------------------- 存储过程测试 --------------------------------------------------------
        <br />
        <asp:Button runat="server"  Text="produre_click_1" OnClick="produre_click_1" />
        <asp:Button runat="server"  Text="produre_click_3" OnClick="produre_click_3" />
        <asp:Button runat="server"  Text="produre_click_4" OnClick="produre_click_4" />
        <asp:Button runat="server"  Text="produre_click_5" OnClick="produre_click_5" />
        <asp:Button runat="server"  Text="produre_click_6" OnClick="produre_click_6" />
        <br />
        ---------------------------------------------------------------- 事务测试 --------------------------------------------------------
        <br />
        <asp:Button runat="server" ID="Button1" Text="CommonTransDAL:AddTrans(IModel.IModel model, bool isBackIdentity)" OnClick="trans_click_1" /><br />
        <asp:Button runat="server" ID="Button3" Text="CommonTransDAL:AddList()" OnClick="trans_click_2" /><br />
        <asp:Button runat="server" ID="Button2" Text="CommonTransDAL:TransactionModel()" OnClick="trans_click_3" /><br />
        <asp:Button runat="server" ID="Button5" Text="CommonTransDAL:TransactionSql(string[] sqlList)" OnClick="trans_click_4" /><br />
        <asp:Button runat="server" ID="Button6" Text="CommonTransDAL:Update(IModel.IModel model)" OnClick="trans_click_5" /><br />
        <asp:Button runat="server" ID="Button4" Text="CommonTransDAL:ExecuteScalarTrans(string sql)" OnClick="trans_click_6" /><br />
        <asp:Button runat="server" ID="Button7" Text="CommonTransDAL:Update(IModel.IModel model, string strWhrere)" OnClick="trans_click_7" /><br />
        <asp:Button runat="server" ID="Button8" Text="CommonTransDAL:Delete(string tableName, string where)" OnClick="trans_click_8" /><br />
        <asp:Button runat="server" ID="Button9" Text="CommonTransDAL:ExecuteScalarTrans(string sql)" OnClick="trans_click_9" /><br />
    </div>
    </form>
</body>
</html>
