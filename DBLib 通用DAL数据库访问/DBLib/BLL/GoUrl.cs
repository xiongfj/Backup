using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBLib.BLL
{
	public class GoUrl : Base
	{
		private DAL.GoUrl mDAL = new DAL.GoUrl();

		public string FindUrlByKey(string key)
		{
			return mDAL.FindUrlByKey(key);
		}
	}
}
