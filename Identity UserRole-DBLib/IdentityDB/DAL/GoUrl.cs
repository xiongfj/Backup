using IdentityDB.Model.CustomModel;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.DAL
{
	public class GoUrl : Base
	{
		public List<Url> QueryTable()
		{
			List<Url> list = new List<Url>();
			string sql = "select * from Urls";
			DataTable table = ExecuteTable(sql);

			foreach (DataRow row in table.Rows)
			{
				list.Add(new Url()
				{
					UrlKey = Convert.ToString(row["UrlKey"]),
					UrlValue = Convert.ToString(row["UrlValue"]),
				});
			}
			return list;
		}
	}
}
