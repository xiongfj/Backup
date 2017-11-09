using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.Model.CustomModel
{
	public class ApplicationUser : IdentityUser, IModel
	{
		public async Task<ClaimsIdentity> GenerateUserIdentityAsync(UserManager<ApplicationUser> manager)
		{
			// Note the authenticationType must match the one defined in CookieAuthenticationOptions.AuthenticationType
			var userIdentity = await manager.CreateIdentityAsync(this, DefaultAuthenticationTypes.ApplicationCookie);
			// Add custom user claims here
			return userIdentity;
		}

		#region 扩展字段
		/// <summary>
		/// 自定义添加的字段
		/// </summary>     
		private string _Password;
		public string Password { get { return _Password; } set { _Password = value; } }
		#endregion

		// 指明数据库中的表名称
		public string mTableName
		{
			get
			{
				return "AspNetUsers";
			}
		}

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			if (_Id != default(string))
				dic.Add("Id", new FieldInfo(SqlDbType.NVarChar, _Id.ToString(), true));            // true 该字段是主键
			if (_Password != null)
				dic.Add("Password", new FieldInfo(SqlDbType.NVarChar, _Password.ToString()));
			if (_Email != null)
				dic.Add("Email", new FieldInfo(SqlDbType.NVarChar, _Email.ToString()));
			//if (_EmailConfirmed != null)
				dic.Add("EmailConfirmed", new FieldInfo(SqlDbType.Bit, _EmailConfirmed.ToString()));
			if (_PasswordHash != null)
				dic.Add("PasswordHash", new FieldInfo(SqlDbType.NVarChar, _PasswordHash.ToString()));
			if (_SecurityStamp != null)
				dic.Add("SecurityStamp", new FieldInfo(SqlDbType.NVarChar, _SecurityStamp.ToString()));
			if (_PhoneNumber != null)
				dic.Add("PhoneNumber", new FieldInfo(SqlDbType.NVarChar, _PhoneNumber.ToString()));
			//if (_PhoneNumberConfirmed != null)
				dic.Add("PhoneNumberConfirmed", new FieldInfo(SqlDbType.Bit, _PhoneNumberConfirmed.ToString()));
			//if (_TwoFactorEnabled != null)
				dic.Add("TwoFactorEnabled", new FieldInfo(SqlDbType.Bit, _TwoFactorEnabled.ToString()));
			if (_LockoutEndDateUtc != null)
				dic.Add("LockoutEndDateUtc", new FieldInfo(SqlDbType.DateTime, _LockoutEndDateUtc.ToString()));
			//if (_LockoutEnabled != null)
				dic.Add("LockoutEnabled", new FieldInfo(SqlDbType.Bit, _LockoutEnabled.ToString()));
			//if (_AccessFailedCount != null)
				dic.Add("AccessFailedCount", new FieldInfo(SqlDbType.Int, _AccessFailedCount.ToString()));
			if (_UserName != null)
				dic.Add("UserName", new FieldInfo(SqlDbType.NVarChar, _UserName.ToString()));

			return dic;
		}
	}
}
