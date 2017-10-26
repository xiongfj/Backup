using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBLib.SqlHelper
{
	/*
	 * BaseDAL 构造函数内调用, 生成单例对象
	 */
	public class SqlHelper
	{
		#region 字段
		protected DBFactory dbFactory = DBFactory.NewDBFactory();//数据工厂
		private IHelper sqlHelper;
		protected string dbType;//数据库类型
		protected static string connString;//连接数据库字符串
		#endregion

		public IHelper SqlHelperInstance
		{
			get { return sqlHelper; }
			set { sqlHelper = value; }
		}

		private void OnLoad()
		{
			sqlHelper = dbFactory.CreateHelper(dbType, connString);
		}

		#region 构造函数
		/// <summary>
		/// 构造函数
		/// </summary>
		public SqlHelper()
		{
			dbType = ConfigurationManager.AppSettings["dbType"].ToLower().Trim();
			connString = ConfigurationManager.ConnectionStrings["sqlHelper"].ConnectionString.Trim();
			this.OnLoad();//初始化各字段
		}
		#endregion
	}
}
