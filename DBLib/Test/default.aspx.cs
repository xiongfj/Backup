using DBLib.BLL;
using Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Test
{
	public partial class WebForm1 : System.Web.UI.Page
	{
		protected void Page_Load(object sender, EventArgs e)
		{

		}

		protected void button_click(object sender, EventArgs e)
		{
			UserBLL bll = new UserBLL();
			List<UserModel> list = bll.QueryTable();

			foreach (UserModel m in list)
			{
				result.Text += m.ID;
				result.Text += m.GroupID;
				result.Text += m.Name;
				result.Text += m.Address;
			}
		}
	}
}