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
	public class AspNetUserRole: Base
	{
		private AspNetRole mRole = new AspNetRole();
		//private AspNetUserDAL<TUser, TKey> mUser = new AspNetUserDAL<TUser, TKey>();

		/// <summary>
		/// 根据参数 userid 查找 UserRoles 表, 再与Roles表交叉, 获取role.Name
		/// </summary>
		/// <param name="user"></param>
		/// <returns></returns>
		public IList<string> GetRolesAsync(ApplicationUser user)
		{
			IQueryable<ApplicationRole> roles = mRole.QueryRoles() as IQueryable<ApplicationRole>;
			IQueryable<AppUserRole> userRoles = QueryUserRoles();

			var query = from ur in userRoles
						where ur.UserId.Equals(user.Id)
						join role in roles on ur.RoleId equals role.Id
						select role.Name;
			return query.ToList();
		}

		/// <summary>
		/// 将 user 添加进 role
		/// </summary>
		/// <param name="user"></param>
		/// <param name="roleName"></param>
		/// <returns></returns>
		public void AddToRoleAsync(ApplicationUser user, string roleName)
		{
			AppUserRole ur = new AppUserRole {
				UserId = user.Id,
				RoleId = mRole.FindIdByRoleName(roleName)
			};
			Insert(ur);
		}

		/// <summary>
		/// 判断 user 是否属于某个 role
		/// </summary>
		/// <param name="user"></param>
		/// <param name="roleName"></param>
		/// <returns></returns>
		public bool IsInRoleAsync(ApplicationUser user, string roleName)
		{
			AppUserRole ur = new AppUserRole
			{
				UserId = user.Id,
				RoleId = mRole.FindIdByRoleName(roleName)
			};
			return FindPrimaryKey(ur);
		}

		/// <summary>
		/// 将 user 从 role 移除
		/// </summary>
		/// <param name="user"></param>
		/// <param name="roleName"></param>
		/// <returns></returns>
		public void RemoveFromRoleAsync(ApplicationUser user, string roleName)
		{
			AppUserRole ur = new AppUserRole
			{
				UserId = user.Id,
				RoleId = mRole.FindIdByRoleName(roleName)
			};
			Delete(ur);
		}


		/// <summary>
		/// 返回 UserRoles 列表
		/// </summary>
		/// <returns></returns>
		private IQueryable<AppUserRole> QueryUserRoles()
		{
			List<AppUserRole> list = new List<AppUserRole>();
			string sql = "select * from AspNetUserRoles";
			DataTable table = ExecuteTable(sql);

			foreach (DataRow row in table.Rows)
			{
				list.Add(TransToUser(row));
			}
			return list.AsQueryable();
		}

		/// <summary>
		/// 将表数据转换成 ApplicationUserRole 数据
		/// </summary>
		/// <param name="row"></param>
		/// <returns></returns>
		private AppUserRole TransToUser(DataRow row)
		{
			return new AppUserRole()
			{
				UserId = Convert.ToString(row["UserId"]),
				RoleId = Convert.ToString(row["RoleId"])
			};
		}
	}
}
