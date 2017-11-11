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
			return Task.FromResult((IQueryable<TUser>)result);
		}

		public Task<TUser> FindByIdAsync(TKey id)
		{
			var u = mDAL.FindByIdAsync(id);
			return Task.FromResult((TUser)u);
		}

		public Task<TUser> FindByNameAsync(string username)
		{
			var u = mDAL.FindByNameAsync(username);
			return Task.FromResult((TUser)u);
		}

		public Task<TUser> FindByEmailAsync(string email)
		{
			return Task.FromResult((TUser)mDAL.FindByEmailAsync(email));
		}


		public Task UpdateAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null )
				mDAL.UpdateAsync(u);
			return Task.FromResult<object>(null);
		}


		public Task InsertAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				mDAL.InsertAsync(u);
			return Task.FromResult<object>(null);
		}

		
		public Task DeleteAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				mDAL.DeleteAsync(u);
			return Task.FromResult<object>(null);
		}
	}
}
