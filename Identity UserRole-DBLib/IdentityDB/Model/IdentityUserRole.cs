
namespace IdentityDB.Model
{
	public class IdentityUserRole : IdentityUserRole<string>
	{
	}

	public class IdentityUserRole<TKey>
	{
		protected TKey _UserId = default(TKey);
		protected TKey _RoleId = default(TKey);

		//
		// Summary:
		//     UserId for the user that is in the role
		public virtual TKey UserId
		{
			get { return _UserId; }
			set { _UserId = value; }
		}
		//
		// Summary:
		//     RoleId for the role
		public virtual TKey RoleId
		{
			get { return _RoleId; }
			set { _RoleId = value; }
		}
	}
}