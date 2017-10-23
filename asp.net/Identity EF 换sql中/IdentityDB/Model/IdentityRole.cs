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

		/// <summary>
		///     Role id
		/// </summary>
		public TKey Id { get; set; }

		/// <summary>
		///     Role name
		/// </summary>
		public string Name { get; set; }
	}
}