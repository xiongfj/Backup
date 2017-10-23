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
	public class RoleStore<TRole> : RoleStore<TRole, string, IdentityUserRole>, IQueryableRoleStore<TRole>, IQueryableRoleStore<TRole, string>, IRoleStore<TRole, string>, IDisposable where TRole : IdentityRole, new()
	{
	}




	public class RoleStore<TRole, TKey, TUserRole> : IQueryableRoleStore<TRole, TKey>, IRoleStore<TRole, TKey>, IDisposable
		where TRole : IdentityRole<TKey, TUserRole>, new()
		where TUserRole : IdentityUserRole<TKey>, new()
	{
		//
		// Summary:
		//     Constructor which takes a db context and wires up the stores with default instances
		//     using the context
		//
		// Parameters:
		//   context:
		///public RoleStore(DbContext context);

		//
		// Summary:
		//     Context for the store
		///public DbContext Context { get; }
		//
		// Summary:
		//     If true will call dispose on the DbContext during Dipose
		public bool DisposeContext { get; set; }
		//
		// Summary:
		//     Returns an IQueryable of users
		public IQueryable<TRole> Roles { get; }

		//
		// Summary:
		//     Insert an entity
		//
		// Parameters:
		//   role:
		///[AsyncStateMachine(typeof(RoleStore<,,>.< CreateAsync > d__2))]
		[DebuggerStepThrough]
		public virtual Task CreateAsync(TRole role)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Mark an entity for deletion
		//
		// Parameters:
		//   role:
		///[AsyncStateMachine(typeof(RoleStore<,,>.< DeleteAsync > d__5))]
		[DebuggerStepThrough]
		public virtual Task DeleteAsync(TRole role)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Dispose the store
		public void Dispose() { }
		//
		// Summary:
		//     Find a role by id
		//
		// Parameters:
		//   roleId:
		public Task<TRole> FindByIdAsync(TKey roleId)
		{
			return Task.FromResult<TRole>(null);
		}
		//
		// Summary:
		//     Find a role by name
		//
		// Parameters:
		//   roleName:
		public Task<TRole> FindByNameAsync(string roleName)
		{
			return Task.FromResult<TRole>(null);
		}
		//
		// Summary:
		//     Update an entity
		//
		// Parameters:
		//   role:
		///[AsyncStateMachine(typeof(RoleStore<,,>.< UpdateAsync > d__8))]
		[DebuggerStepThrough]
		public virtual Task UpdateAsync(TRole role)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     If disposing, calls dispose on the Context. Always nulls out the Context
		//
		// Parameters:
		//   disposing:
		protected virtual void Dispose(bool disposing)
		{

		}
	}
}
