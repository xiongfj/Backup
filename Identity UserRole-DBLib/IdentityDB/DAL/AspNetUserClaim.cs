using IdentityDB.Model.CustomModel;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.DAL
{
	public class AspNetUserClaim : Base
	{
		public Task AddClaimAsync(ApplicationUser user, Claim claim)
		{
			return Task.Run(() => {
				AppUserClaim c = new AppUserClaim {
					UserId = user.Id,
					ClaimType = claim.Type,
					ClaimValue = claim.Value
				};
				Insert(c);
			});
		}

		public Task<IList<Claim>> GetClaimsAsync(ApplicationUser user)
		{
			return Task.Run<IList<Claim>>(() => {
				AppUserClaim c = new AppUserClaim
				{
					UserId = user.Id
				};
				DataTable table = ExecuteTableWhere(c, "UserId=@UserId");
				List<Claim> list = new List<Claim>();
				foreach ( DataRow row in table.Rows)
				{
					list.Add(TransToClaim(row));
				}

				return list;
			});
		}

		public Task RemoveClaimAsync(ApplicationUser user, Claim claim)
		{
			return Task.Run(() => {
				AppUserClaim c = new AppUserClaim
				{
					UserId = user.Id
				};
				DeleteWhere(c, "UserId=@UserId");
			});
		}

		private Claim TransToClaim(DataRow row)
		{
			return new Claim(Convert.ToString(row["ClaimType"]), Convert.ToString(row["ClaimValue"]));
		}
	}
}
