using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvcIdentity.MyIdentity
{
    public class MyIdentityUser : IUser
    {
        public MyIdentityUser()
        {
            Id = Guid.NewGuid().ToString();
        }
        /// <summary>
        /// Constructor that takes user name as argument
        /// </summary>
        /// <param name="userName"></param>
        public MyIdentityUser(string userName)
            : this()
        {
            UserName = userName;
        }
        public virtual string Email { get; set; }
        public virtual bool EmailConfirmed { get; set; }
        public virtual string PasswordHash { get; set; }
        public virtual string SecurityStamp { get; set; }
        public virtual string PhoneNumber { get; set; }
        public virtual bool PhoneNumberConfirmed { get; set; }
        public virtual bool TwoFactorEnabled { get; set; }
        public virtual DateTime? LockoutEndDateUtc { get; set; }
        public virtual bool LockoutEnabled { get; set; }
        public virtual int AccessFailedCount { get; set; }
        //public virtual ICollection<TRole> Roles { get; }
        //public virtual ICollection<TClaim> Claims { get; }
        //public virtual ICollection<TLogin> Logins { get; }
        public virtual string Id { get; set; }
        public virtual string UserName { get; set; }

        //string IUser<string>.Id => throw new NotImplementedException();
    }
}