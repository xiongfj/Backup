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
		public void AddClaimAsync(ApplicationUser user, Claim claim)
		{
			AppUserClaim c = new AppUserClaim {
				UserId = user.Id,
				ClaimType = claim.Type,
				ClaimValue = claim.Value
			};
			Insert(c);
		}

		public IList<Claim> GetClaimsAsync(ApplicationUser user)
		{
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
		}

		public void RemoveClaimAsync(ApplicationUser user, Claim claim)
		{
			AppUserClaim c = new AppUserClaim
			{
				UserId = user.Id
			};
			DeleteWhere(c, "UserId=@UserId");
		}

		private Claim TransToClaim(DataRow row)
		{
			return new Claim(Convert.ToString(row["ClaimType"]), Convert.ToString(row["ClaimValue"]));
		}
	}
}
