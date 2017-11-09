using DBLib.DAL;
using DBLib.Model;
using IdentityDB.DAL;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBLib.DAL
{
	/// <summary>
	/// 一些公共的数据库操作, 插入数据, 查找数据
	/// </summary>
	public class UserDAL : BaseDAL
	{
		public List<UserModel> QueryUser()
		{
			List<UserModel> list = new List<UserModel>();
			string sql = "select * from NetUser";
			DataTable table = ExecuteTable(sql);

			foreach (DataRow row in table.Rows)
			{
				list.Add(new UserModel()
				{
					ID = Convert.ToUInt32(row["ID"]),
					GroupID = Convert.ToUInt32(row["GroupID"]),
					Name = Convert.ToString(row["Name"]),
					Address = Convert.ToString(row["Address"])
				});
			}
			return list;
		}

		public List<UserModel> QueryUserWhere(UserModel user, string where)
		{
			List<UserModel> list = new List<UserModel>();
			DataTable table = ExecuteTableWhere(user, where);

			foreach (DataRow row in table.Rows)
			{
				list.Add(new UserModel()
				{
					ID = Convert.ToUInt32(row["ID"]),
					GroupID = Convert.ToUInt32(row["GroupID"]),
					Name = Convert.ToString(row["Name"]),
					Address = Convert.ToString(row["Address"])
				});
			}

			return list;
		}
	}
}
