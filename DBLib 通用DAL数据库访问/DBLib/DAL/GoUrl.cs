using DBLib.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBLib.DAL
{
	public class GoUrl : Base
	{
		public string FindUrlByKey(string key)
		{
			Url u = new Url {
				UrlKey = key
			};
			DataTable table = ExecuteTable(u);
			foreach (DataRow row in table.Rows)
			{
				return row["UrlValue"].ToString();
			}
			return null;
		}
	}
}
