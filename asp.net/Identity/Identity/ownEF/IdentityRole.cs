using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Identity.ownEF
{
    public class IdentityRole : IRole<string>
    {
        public IdentityRole()
        {
            Id = Guid.NewGuid().ToString();
        }
        public IdentityRole(string user)
            :this()
        {
            Name = user;
        }

        public string Id { set; get; }

        public string Name { get; set; }
    }
}