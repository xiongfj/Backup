
namespace IdentityDB.Model
{
	public class IdentityUserClaim : IdentityUserClaim<string>
	{
		///public IdentityUserClaim();
	}

	public class IdentityUserClaim<TKey>
	{
		///public IdentityUserClaim();

		//
		// Summary:
		//     Primary key
		public virtual int Id { get; set; }
		//
		// Summary:
		//     User Id for the user who owns this login
		public virtual TKey UserId { get; set; }
		//
		// Summary:
		//     Claim type
		public virtual string ClaimType { get; set; }
		//
		// Summary:
		//     Claim value
		public virtual string ClaimValue { get; set; }
	}
}