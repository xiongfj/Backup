
namespace IdentityDB.Model
{
	public class IdentityUserLogin : IdentityUserLogin<string>
	{
		///public IdentityUserLogin();
	}

	public class IdentityUserLogin<TKey>
	{
		///public IdentityUserLogin();

		//
		// Summary:
		//     The login provider for the login (i.e. facebook, google)
		public virtual string LoginProvider { get; set; }
		//
		// Summary:
		//     Key representing the login for the provider
		public virtual string ProviderKey { get; set; }
		//
		// Summary:
		//     User Id for the user who owns this login
		public virtual TKey UserId { get; set; }
	}
}