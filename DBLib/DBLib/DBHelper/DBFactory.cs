using DBLib.DBHelper.Sql;
using IdentityDB.DBHelper;
using IdentityDB.DBHelper.Sql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBLib.DBHelper
{
	/*
	 * 单例模式: 构建 Orcal 或 SqlServer 对象
	 * SqlHelper 内调用或 OracleHelper 内调用
	 */
	public class DBFactory
	{
		protected static volatile DBFactory singleFactory = null;
		private static readonly object obj = new object();

		/// <summary>
		/// 构造函数
		/// </summary>
		private DBFactory()
		{ }

		/// <summary>
		/// 获得DBFactory类的单例
		/// </summary>
		/// <returns>DBFactory类实例</returns>
		public static DBFactory NewDBFactory()
		{
			if (singleFactory == null)
			{
				lock (obj)
				{
					if (singleFactory == null)
					{
						singleFactory = new DBFactory();
					}
				}
			}
			return singleFactory;
		}
		public IHelper CreateHelper(string dbType, string connString)
		{
			IHelper hp = null;
			switch (dbType)
			{
				case "oracle":
					//  hp = new OracleHelper(connString);
					break;
				case "sql":
					hp = new SqlServerHelper(connString);
					break;
			}
			return hp;
		}
	}
}
