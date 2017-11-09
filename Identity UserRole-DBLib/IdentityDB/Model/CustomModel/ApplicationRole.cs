using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.Model.CustomModel
{
	public class ApplicationRole : IdentityRole, IModel
	{
		#region 扩展字段
		private string _Description = null;

		[Display(Name = "角色描述")]
		public string Description
		{
			get { return _Description; }
			set { _Description = value; }
		}
		#endregion

		public string mTableName
		{
			get
			{
				return "AspNetRoles";
			}
		}

		public ApplicationRole()
			: base()
		{
			//Permissions = new List<ApplicationRolePermission>();
		}
		public ApplicationRole(string roleName)
			: this()
		{
			base.Name = roleName;
		}

		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			if (_Id != default(string))
				dic.Add("Id", new FieldInfo(SqlDbType.NVarChar, _Id.ToString(), true));            // true 该字段是主键
			if (_Name != null)
				dic.Add("Name", new FieldInfo(SqlDbType.NVarChar, _Name.ToString()));
			if (_Description != null)
				dic.Add("Description", new FieldInfo(SqlDbType.NVarChar, _Description.ToString()));

			return dic;
		}
	}
}
