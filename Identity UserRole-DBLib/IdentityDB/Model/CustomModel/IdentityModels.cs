using IdentityDB.BLL;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.Model.CustomModel
{
	public class AppDBContext : DBContext //: IdentityDbContext<ApplicationUser>
	{
		private BLL.GoUrl uBll = new BLL.GoUrl();
		//public BLL.AspNetUserRole

		public AppDBContext() //: base("DefaultConnection", throwIfV1Schema: false)
		{
		}

		public static AppDBContext Create()
		{
			return new AppDBContext();
		}

		public void Update(Url u)
		{
			uBll.Update(u);
		}
		public void Delete(Url u)
		{
			uBll.Delete(u);
		}
		public void Insert(Url u)
		{
			uBll.Insert(u);
		}

		public List<Url> Urls
		{
			get
			{
				return uBll.QueryTable();
			}
		}
	}
}
