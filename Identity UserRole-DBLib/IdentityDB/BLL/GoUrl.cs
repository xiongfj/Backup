using IdentityDB;
using IdentityDB.Model.CustomModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.BLL
{
	public class GoUrl : Base
	{
		private DAL.GoUrl mDAL = new DAL.GoUrl();

		public List<Url> QueryTable()
		{
			return mDAL.QueryTable();
		}

		public int Update(Url u)
		{
			return mDAL.Update(u);
		}
		public void Insert(Url u)
		{
			mDAL.Insert(u);
		}
		public void Delete(Url u)
		{
			mDAL.Delete(u);
		}
	}
}
