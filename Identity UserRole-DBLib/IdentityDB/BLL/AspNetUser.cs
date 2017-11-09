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
	public class AspNetUser<TUser, TKey> : Base
		where TUser : IUser<TKey>
		where TKey : IEquatable<TKey>
	{
		private DAL.AspNetUser mDAL = new DAL.AspNetUser();

		//public async Task<IQueryable<TUser>> QueryTable()
		//{
		//	var result = await mDAL.QueryUsers();
		//	return (IQueryable<TUser>)result;
		//}
		// 不能使用 async 异步查询?!! 会卡住页面??!
		public Task<IQueryable<TUser>> QueryTable()
		{
			var result = mDAL.QueryUsers();
			return Task.FromResult((IQueryable<TUser>)result.Result);
		}

		public async Task<TUser> FindByIdAsync(TKey id)
		{
			var u = await mDAL.FindByIdAsync(id);
			return (TUser)u;
		}

		public async Task<TUser> FindByNameAsync(string username)
		{
			var u = await mDAL.FindByNameAsync(username);
			return (TUser)u;
		}

		public async Task<TUser> FindByEmailAsync(string email)
		{
			return (TUser)await mDAL.FindByEmailAsync(email);
		}


		public async Task UpdateAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null )
				await mDAL.UpdateAsync(u);
		}


		public async Task InsertAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				await mDAL.InsertAsync(u);
		}

		
		public async Task DeleteAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				await mDAL.DeleteAsync(u);
		}
	}
}
