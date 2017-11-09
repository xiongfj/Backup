using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.Model.CustomModel
{
	public class AppUserClaim : IdentityUserClaim, IModel
	{
		public string mTableName
		{
			get
			{
				return "AspNetUserClaims";
			}
		}

		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			// id 自动增长
			//if (Id != 0)
				//dic.Add("Id", new FieldInfo(SqlDbType.Int, Id.ToString(), true));
			if (UserId != null)
				dic.Add("UserId", new FieldInfo(SqlDbType.NVarChar, UserId.ToString()));
			if (ClaimType != null)
				dic.Add("ClaimType", new FieldInfo(SqlDbType.NVarChar, ClaimType.ToString()));
			if (ClaimValue != null)
				dic.Add("ClaimValue", new FieldInfo(SqlDbType.NVarChar, ClaimValue.ToString()));

			return dic;
		}
	}
}
