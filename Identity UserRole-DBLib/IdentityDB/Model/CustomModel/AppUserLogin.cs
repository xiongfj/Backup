//using System;
//using System.Collections.Generic;
//using System.Data;
//using System.Linq;
//using System.Security.Claims;
//using System.Text;
//using System.Threading.Tasks;

//namespace IdentityDB.Model.CustomModel
//{
//	public class ApplicationUserLogin : IdentityUserLogin, IModel
//	{
//		public string mTableName
//		{
//			get
//			{
//				return "AspNetUserLogins";
//			}
//		}

//		public Dictionary<string, FieldInfo> getModelInfo()
//		{
//			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

//			if (UserId != null)
//				dic.Add("UserId", new FieldInfo(SqlDbType.NVarChar, UserId.ToString(), true));
//			if (LoginProvider != null)
//				dic.Add("LoginProvider", new FieldInfo(SqlDbType.NVarChar, LoginProvider.ToString(), true));
//			if (ProviderKey != null)
//				dic.Add("ProviderKey", new FieldInfo(SqlDbType.NVarChar, ProviderKey.ToString(), true));

//			return dic;
//		}
//	}
//}
