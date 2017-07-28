using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Identity.ownEF
{
    public class IdentityUser : IUser<string>
    {
        public IdentityUser()
        {
            Id = Guid.NewGuid().ToString();     // 自动生成主键
        }

        public IdentityUser(string un):
            this()
        {
            UserName = un;
        }

        public string Id { get; set; }
        public string UserName { get ; set; }

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

        //string IUser<string>.Id => throw new NotImplementedException();


        ////  public virtual ICollection<TRole> Roles { get; }
        // public virtual ICollection<TClaim> Claims { get; }
        // public virtual ICollection<TLogin> Logins { get; }
    }
}