using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Webf.samples
{
	public partial class view : System.Web.UI.Page
	{
		protected void Page_Load(object sender, EventArgs e)
		{
			/*
					 方法一：在后台.CS文件写如下代码：
						 if (Page.RouteData.Values.ContainsKey("id"))
								this.lb.Text = Page.RouteData.Values["id"].ToString();

						方法二：在页面中直接使用RouteValue，如下：
						  <asp:Label ID="lb1" runat="server" Text="<%$RouteValue:id%>"></asp:Label>
				  */
			label.Text = Request.QueryString["id"] + Request.QueryString["catelog"]; //RouteData.Values["action"].ToString() + " - " + RouteData.Values["id"].ToString();
		}
	}
}