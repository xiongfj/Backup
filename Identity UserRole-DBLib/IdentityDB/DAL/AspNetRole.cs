using IdentityDB.DAL;
using IdentityDB.Model;
using IdentityDB.Model.CustomModel;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.DAL
{
	public class AspNetRole : Base
	{
		public IQueryable<object> QueryRoles()
		{
			List<ApplicationRole> list = new List<ApplicationRole>();
			string sql = "select * from AspNetRoles";
			DataTable table = ExecuteTable(sql);

			foreach (DataRow row in table.Rows)
			{
				list.Add(TransToRole(row));
			}
			return list.AsQueryable();
		}

		public object FindByIdAsync(object id)
		{
			ApplicationRole u = new ApplicationRole
			{
				Id = id.ToString()
			};

			DataTable table = ExecuteTableWhere(u, "Id=@Id");
			foreach (DataRow row in table.Rows)
			{
				return TransToRole(row);
			}
			return null;
		}
		public object FindByNameAsync(string roleName)
		{
			ApplicationRole u = new ApplicationRole
			{
				Name = roleName
			};

			DataTable table = ExecuteTableWhere(u, "Name=@Name");
			foreach (DataRow row in table.Rows)
			{
				return TransToRole(row);
			}
			return null;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="roelName"></param>
		/// <returns></returns>
		public string FindIdByRoleName(string roleName)
		{
			ApplicationRole role = new ApplicationRole {
				Name = roleName
			};
			object id = ExecuteScalarWhere(role, "Name=@Name");

			return id.ToString();
		}

		#region 更新操作
		/// <summary>
		/// 
		/// </summary>
		/// <param name="u"></param>
		/// <returns></returns>
		public void UpdateAsync(ApplicationRole role)
		{
			Update(role);
		}
		#endregion

		#region 插入操作
		/// <summary>
		/// 
		/// </summary>
		/// <param name="user"></param>
		/// <returns></returns>
		public void InsertAsync(ApplicationRole role)
		{
			Insert(role);
		}
		#endregion

		#region 删除操作
		public void DeleteAsync(ApplicationRole role)
		{
			Delete(role);
		}
		#endregion

		/// <summary>
		/// 
		/// </summary>
		/// <param name="row"></param>
		/// <returns></returns>
		private ApplicationRole TransToRole(DataRow row)
		{
			return new ApplicationRole()
			{
				Id = Convert.ToString(row["Id"]),
				Name = Convert.ToString(row["Name"]),
				Description = row["Description"] is DBNull ? null : Convert.ToString(row["Description"]),
			};
		}
	}
}
