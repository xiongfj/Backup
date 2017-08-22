using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvcIdentity.Areas.SuperAdmin.Model
{
    public class UserViewModel
    {
        public string Id { set; get; }

        public string UserName { set; get; }

        public string Email { set; get; }
    }
}