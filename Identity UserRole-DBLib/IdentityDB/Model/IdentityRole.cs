using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;

namespace IdentityDB.Model
{
	public class IdentityRole : IdentityRole<string, IdentityUserRole>
	{
		/// <summary>
		///     Constructor
		/// </summary>
		public IdentityRole()
		{
			Id = Guid.NewGuid().ToString();
		}

		/// <summary>
		///     Constructor
		/// </summary>
		/// <param name="roleName"></param>
		public IdentityRole(string roleName)
			: this()
		{
			Name = roleName;
		}
	}





	public class IdentityRole<TKey, TUserRole> : IRole<TKey> where TUserRole : IdentityUserRole<TKey>
	{
		/// <summary>
		///     Constructor
		/// </summary>
		public IdentityRole()
		{
			Users = new List<TUserRole>();
		}

		/// <summary>
		///     Navigation property for users in the role
		/// </summary>
		public virtual ICollection<TUserRole> Users { get; }
		
		protected TKey _Id = default(TKey);
		protected string _Name = null;

		public TKey Id { get { return _Id; } set { _Id = value; } }
		public string Name { get { return _Name; } set { _Name = value; } }
	}
}