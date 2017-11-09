using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.Model.CustomModel
{
	public class AppUserRole : IdentityUserRole, IModel
	{
		public string mTableName
		{
			get { return "AspNetUserRoles"; }
		}

		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			if (_UserId != default(string))
				dic.Add("UserId", new FieldInfo(SqlDbType.NVarChar, _UserId.ToString(), true));            // true 该字段是主键
			if (_RoleId != default(string))
				dic.Add("RoleId", new FieldInfo(SqlDbType.NVarChar, _RoleId.ToString(), true));

			return dic;
		}
	}
}
