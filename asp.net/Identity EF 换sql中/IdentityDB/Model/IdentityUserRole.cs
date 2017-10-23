
namespace IdentityDB.Model
{
	public class IdentityUserRole : IdentityUserRole<string>
	{
		///public IdentityUserRole();
	}

	public class IdentityUserRole<TKey>
	{
		///public IdentityUserRole();

		//
		// Summary:
		//     UserId for the user that is in the role
		public virtual TKey UserId { get; set; }
		//
		// Summary:
		//     RoleId for the role
		public virtual TKey RoleId { get; set; }
	}
}