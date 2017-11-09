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
			return Task.FromResult((IQueryable<TRole>)l.Result);
		}

		public async Task<TRole> FindByIdAsync(TKey id)
		{
			var u = await mDAL.FindByIdAsync(id);
			return (TRole)u;
		}

		public async Task<TRole> FindByNameAsync(string roleName)
		{
			var u = await mDAL.FindByNameAsync(roleName);
			return (TRole)u;
		}



		public async Task InsertAsync(TRole role)
		{
			ApplicationRole u = role as ApplicationRole;
			if (u != null)
				await mDAL.InsertAsync(u);
		}


		public async Task UpdateAsync(TRole role)
		{
			ApplicationRole u = role as ApplicationRole;
			if (u != null)
				await mDAL.UpdateAsync(u);
		}


		public async Task DeleteAsync(TRole role)
		{
			ApplicationRole u = role as ApplicationRole;
			if (u != null)
				await mDAL.DeleteAsync(u);
		}
	}
}
