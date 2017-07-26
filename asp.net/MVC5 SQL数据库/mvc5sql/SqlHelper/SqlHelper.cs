using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mvc5sql.SqlHelper
{
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

        #region 其余构造函数,使用各种不同参数方法获取 dbType 和 connString 而已.
        /***** 下面都是构造函数,使用各种不同参数方法获取 dbType 和 connString 而已.
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="connStr"></param>
        public SqlHelper(string connStr, bool isSql)
        {
            dbType = ConfigurationManager.AppSettings["dbType"].ToLower().Trim();
            connString = connStr;
            this.OnLoad();//初始化各字段
        }
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="connectionStringsName">配置文件中，数据库连接字符串connectionStrings对应的name</param>
        public SqlHelper(string connectionStringsName)
        {
            dbType = ConfigurationManager.AppSettings["dbType"].ToLower().Trim();
            connString = ConfigurationManager.ConnectionStrings[connectionStringsName].ConnectionString.Trim();
            this.OnLoad();//初始化各字段
        }

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="appSettingsKey_dbType">配置文件中，数据库类型AppSettings对应的key值</param>
        /// <param name="connectionStringsName">配置文件中，数据库连接字符串connectionStrings对应的name</param>
        public SqlHelper(string appSettingsKey_dbType, string connectionStringsName)
        {
            dbType = ConfigurationManager.AppSettings[appSettingsKey_dbType].ToLower().Trim();
            connString = ConfigurationManager.ConnectionStrings[connectionStringsName].ConnectionString.Trim();
            this.OnLoad();//初始化各字段
        }
        */
        #endregion
    }
}
