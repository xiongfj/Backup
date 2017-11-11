using IdentityDB;
using IdentityDB.Model.CustomModel;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.BLL
{
	public class AspNetUserClaim<TUser, TKey> : Base
	where TUser : IUser<TKey>
	where TKey : IEquatable<TKey>
	{
		DAL.AspNetUserClaim mDAL = new DAL.AspNetUserClaim();

		public Task AddClaimAsync(TUser user, Claim claim)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				mDAL.AddClaimAsync(u, claim);
			return Task.FromResult<object>(null);
		}

		public Task<IList<Claim>> GetClaimsAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				return Task.FromResult(mDAL.GetClaimsAsync(u));

			IList<Claim> ls = new List<Claim>();
			return Task.FromResult(ls);
		}

		public Task RemoveClaimAsync(TUser user, Claim claim)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				mDAL.RemoveClaimAsync(u, claim);
			return Task.FromResult<object>(null);
		}
	}
}
