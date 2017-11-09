using IdentityDB;
using IdentityDB.Model;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB
{
	public class RoleStore<TRole> : 
		RoleStore<TRole, string, IdentityUserRole>, 
		IQueryableRoleStore<TRole>, 
		IQueryableRoleStore<TRole, string>, 
		IRoleStore<TRole, string>, 
		IDisposable 
		where TRole : IdentityRole, new()
	{
	}




	public class RoleStore<TRole, TKey, TUserRole> : 
		IQueryableRoleStore<TRole, TKey>, 
		IRoleStore<TRole, TKey>, IDisposable
		where TRole : IdentityRole<TKey, TUserRole>, new()
		where TUserRole : IdentityUserRole<TKey>, new()
	{
		BLL.AspNetRole<TRole, TKey> mRoleBLL = new BLL.AspNetRole<TRole, TKey>();

		//
		// Summary:
		//     Returns an IQueryable of users
		public IQueryable<TRole> Roles
		{
			get
			{
				return mRoleBLL.QueryRoles().Result;
			}
		}

		// Summary:
		//     Insert an entity
		public virtual Task CreateAsync(TRole role)// ok
		{
			if (role == null)
			{
				throw new ArgumentNullException("role");
			}
			return mRoleBLL.InsertAsync(role);
		}
		// Summary:
		//     Mark an entity for deletion
		public virtual Task DeleteAsync(TRole role)// ok
		{
			if (role == null)
			{
				throw new ArgumentNullException("role");
			}
			return mRoleBLL.DeleteAsync(role);
		}
		//
		// Summary:
		//     Dispose the store
		public void Dispose() { }
		//
		// Summary:
		//     Find a role by id
		public Task<TRole> FindByIdAsync(TKey roleId)//ok
		{
			if (roleId == null)
			{
				throw new ArgumentNullException("roleId");
			}
			return mRoleBLL.FindByIdAsync(roleId);
		}
		//
		// Summary:
		//     Find a role by name
		public Task<TRole> FindByNameAsync(string roleName)//ok
		{
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentNullException("roleName");
			}
			return mRoleBLL.FindByNameAsync(roleName);
		}
		//
		// Summary:
		//     Update an entity
		public virtual Task UpdateAsync(TRole role)//ok
		{
			if (role == null)
			{
				throw new ArgumentNullException("role");
			}
			return mRoleBLL.UpdateAsync(role);
		}
		//
		// Summary:
		//     If disposing, calls dispose on the Context. Always nulls out the Context
		protected virtual void Dispose(bool disposing)
		{
		}
	}
}
