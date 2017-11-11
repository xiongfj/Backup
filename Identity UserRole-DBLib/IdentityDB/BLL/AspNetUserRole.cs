using IdentityDB.BLL;
using IdentityDB;
using IdentityDB.Model;
using IdentityDB.Model.CustomModel;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.BLL
{
	public class AspNetUserRole<TUser, TRole, TKey> : Base
		where TUser : IUser<TKey>
		where TRole : IRole<TKey>
		where TKey : IEquatable<TKey>
	{
		private DAL.AspNetUserRole mDAL = new DAL.AspNetUserRole();

		/// <summary>
		/// 获取 user 对应的 role 名称, (user)/(role) -> 1:m
		/// </summary>
		/// <param name="user"></param>
		/// <returns></returns>
		public Task<IList<string>> GetRolesAsync(TUser user)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}

			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				return Task.FromResult(mDAL.GetRolesAsync(u));

			IList<string> ls = new List<string>();
			return Task.FromResult(ls);
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="user"></param>
		/// <param name="roleName"></param>
		/// <returns></returns>
		public Task AddToRoleAsync(TUser user, string roleName)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentException("roleName cannot be null");
			}

			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				mDAL.AddToRoleAsync(u, roleName);

			return Task.FromResult<object>(null);
		}
		
		/// <summary>
		/// 检测 user 是否属于 role
		/// </summary>
		/// <param name="user"></param>
		/// <param name="roleName"></param>
		/// <returns></returns>
		public Task<bool> IsInRoleAsync(TUser user, string roleName)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentException("roleName cannot be null");
			}

			bool result = false;
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
			{
				result = mDAL.IsInRoleAsync(u, roleName);
			}
			return Task.FromResult(result);
		}

		/// <summary>
		/// 将 user 从 role 移除
		/// </summary>
		/// <param name="user"></param>
		/// <param name="roleName"></param>
		/// <returns></returns>
		public Task RemoveFromRoleAsync(TUser user, string roleName)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentException("roleName cannot be null");
			}

			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				 mDAL.RemoveFromRoleAsync(u, roleName);

			return Task.FromResult<object>(null);
		}
	}
}
