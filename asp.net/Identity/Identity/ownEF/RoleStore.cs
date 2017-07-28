using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Threading.Tasks;

namespace Identity.ownEF
{
    public class RoleStore<TRole> : IQueryableRoleStore<TRole>
        where TRole : IdentityRole
    {
        public IQueryable<TRole> Roles { set; get; }

        public Task CreateAsync(TRole role)
        {
            return Task.FromResult<object>(null);
        }

        public Task DeleteAsync(TRole role)
        {
            return Task.FromResult<object>(null);
        }

        public void Dispose()
        {
            //return Task.FromResult<object>(null);
        }

        public Task<TRole> FindByIdAsync(string roleId)
        {
            return Task.FromResult<TRole>(null);
        }

        public Task<TRole> FindByNameAsync(string roleName)
        {
            return Task.FromResult<TRole>(null);
        }

        public Task UpdateAsync(TRole role)
        {
            return Task.FromResult<object>(null);
        }
    }
}