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
			label.Text = RouteData.Values["action"].ToString() + " - " + RouteData.Values["id"].ToString();
		}
	}
}