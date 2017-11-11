using IdentityDB.BLL;
using IdentityDB;
using IdentityDB.Model;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IdentityDB.Model.CustomModel;

namespace IdentityDB.BLL
{
	public class AspNetRole<TRole, TKey> : Base
		where TRole : IRole<TKey>
		//where TKey : IEquatable<TKey>
	{
		private DAL.AspNetRole mDAL = new DAL.AspNetRole();

		//public async Task<IQueryable<TRole>> QueryRoles()
		//{
		//	var l = await mDAL.QueryRoles();
		//	return (IQueryable<TRole>)l;
		//}
		public Task<IQueryable<TRole>> QueryRoles()
		{
			var l = mDAL.QueryRoles();
			return Task.FromResult((IQueryable<TRole>)l);
		}

		public Task<TRole> FindByIdAsync(TKey id)
		{
			var u = mDAL.FindByIdAsync(id);
			return Task.FromResult((TRole)u);
		}

		public Task<TRole> FindByNameAsync(string roleName)
		{
			var u = mDAL.FindByNameAsync(roleName);
			return Task.FromResult((TRole)u);
		}



		public Task InsertAsync(TRole role)
		{
			ApplicationRole u = role as ApplicationRole;
			if (u != null)
				mDAL.InsertAsync(u);
			return Task.FromResult<object>(null);
		}


		public Task UpdateAsync(TRole role)
		{
			ApplicationRole u = role as ApplicationRole;
			if (u != null)
				mDAL.UpdateAsync(u);
			return Task.FromResult<object>(null);
		}


		public Task DeleteAsync(TRole role)
		{
			ApplicationRole u = role as ApplicationRole;
			if (u != null)
				mDAL.DeleteAsync(u);
			return Task.FromResult<object>(null);
		}
	}
}
