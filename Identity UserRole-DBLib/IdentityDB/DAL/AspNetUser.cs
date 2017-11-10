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
	public class AspNetUser : Base
	{
		#region 查询操作
		//public Task<IQueryable<object>> QueryUsers()
		//{
		//	List<AppUser> list = new List<AppUser>();
		//	string sql = "select * from AspNetUsers";
		//	DataTable table = ExecuteTable(sql);

		//	foreach (DataRow row in table.Rows)
		//	{
		//		list.Add(TransToUser(row));
		//	}
		//	return Task.FromResult((IQueryable<object>)list.AsQueryable());
		//}
		public IQueryable<object> QueryUsers()
		{
			List<ApplicationUser> list = new List<ApplicationUser>();
			string sql = "select * from AspNetUsers";
			DataTable table = ExecuteTable(sql);

			foreach (DataRow row in table.Rows)
			{
				list.Add(TransToUser(row));
			}
			return list.AsQueryable();
		}

		/// <summary>
		/// 根据 Id 查找 user
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		public object FindByIdAsync(object id)
		{
			ApplicationUser u = new ApplicationUser
			{
				Id = id.ToString()
			};

			DataTable table = ExecuteTableWhere(u, "Id=@Id");
			foreach (DataRow row in table.Rows)
			{
				return TransToUser(row);
			}
			return null;
		}

		/// <summary>
		/// 根据用户名查找用户
		/// </summary>
		/// <param name="username"></param>
		/// <returns></returns>
		public object FindByNameAsync(string username)
		{
			ApplicationUser u = new ApplicationUser {
				UserName = username
			};

			DataTable table = ExecuteTableWhere(u, "UserName=@UserName");
			foreach(DataRow row in table.Rows)
			{
				return TransToUser(row);
			}
			return null;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="email"></param>
		/// <returns></returns>
		public object FindByEmailAsync(string email)
		{
			ApplicationUser u = new ApplicationUser
			{
				Email = email
			};
			DataTable table = ExecuteTableWhere(u, "Email=@Email");
			foreach (DataRow row in table.Rows)
			{
				return TransToUser(row);
			}
			return null;
		}
		#endregion

		#region 更新操作
		/// <summary>
		/// 
		/// </summary>
		/// <param name="u"></param>
		/// <returns></returns>
		public void UpdateAsync(ApplicationUser user)
		{
			Update(user);
		}
		#endregion

		#region 插入操作
		/// <summary>
		/// 
		/// </summary>
		/// <param name="user"></param>
		/// <returns></returns>
		public void InsertAsync(ApplicationUser user)
		{
			Insert(user);
		}
		#endregion

		#region 删除操作
		public void DeleteAsync(ApplicationUser user)
		{
			Delete(user);
		}
		#endregion

		/// <summary>
		/// 将一 row 数据转换成 ApplicationUser 对象
		/// </summary>
		/// <param name="row"></param>
		/// <returns></returns>
		private ApplicationUser TransToUser(DataRow row)
		{
			return new ApplicationUser(){
				Id = Convert.ToString(row["Id"]),
				Password = Convert.ToString(row["Password"]),
				Email = row["Email"] is DBNull ? null : Convert.ToString(row["Email"]),
				EmailConfirmed = Convert.ToBoolean(row["EmailConfirmed"]),
				PasswordHash = row["PasswordHash"] is DBNull ? null : Convert.ToString(row["PasswordHash"]),
				SecurityStamp = row["SecurityStamp"] is DBNull ? null : Convert.ToString(row["SecurityStamp"]),
				PhoneNumber = row["PhoneNumber"] is DBNull ? null : Convert.ToString(row["PhoneNumber"]),
				PhoneNumberConfirmed = Convert.ToBoolean(row["PhoneNumberConfirmed"]),
				TwoFactorEnabled = Convert.ToBoolean(row["TwoFactorEnabled"]),
				LockoutEndDateUtc = row["LockoutEndDateUtc"] is DBNull ? null : (DateTime?)(Convert.ToDateTime(row["LockoutEndDateUtc"])),
				LockoutEnabled = Convert.ToBoolean(row["LockoutEnabled"]),
				AccessFailedCount = Convert.ToInt32(row["AccessFailedCount"]),
				UserName = Convert.ToString(row["UserName"])
			};
		}
	}
}
