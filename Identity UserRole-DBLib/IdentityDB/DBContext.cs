using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB
{
	public class DBContext : IDisposable
	{
		////protected AspNetUserBLL mUserBLL = new AspNetUserBLL();

		//// 从数据库读取用户表所有数据
		//public List<AspNetUser> Users
		//{
		//	get
		//	{
		//		//List<AspNetUser> us = mUserBLL.QueryTable();
		//		//List<Applica>
		//		//foreach(AspNetUser u in us)
		//		//{

		//		//}
		//		return mUserBLL.QueryTable();
		//	}
		//}

		public void Dispose()
		{
		}
	}
}
