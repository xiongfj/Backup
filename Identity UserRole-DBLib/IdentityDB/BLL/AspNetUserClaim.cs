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

		public async Task AddClaimAsync(TUser user, Claim claim)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				await mDAL.AddClaimAsync(u, claim);
		}

		public async Task<IList<Claim>> GetClaimsAsync(TUser user)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				return await mDAL.GetClaimsAsync(u);
			return new List<Claim>();
		}

		public async Task RemoveClaimAsync(TUser user, Claim claim)
		{
			ApplicationUser u = user as ApplicationUser;
			if (u != null)
				await mDAL.RemoveClaimAsync(u, claim);
		}
	}
}
