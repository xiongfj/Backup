using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;

/**
 * 存储 DbConnection 和 DbCommand
 * **/

namespace WebApplication5.SqlHelper
{
    public abstract class IHelper
    {
        protected System.Data.Common.DbCommand cmd;
        protected System.Data.Common.DbConnection conn;

        public abstract object Add(IModel.IModel model, bool isBackIdentity);
        public abstract int AddTrans(IModel.IModel model, bool isBackIdentity);
        public abstract void OpenConnection();
        public abstract void CloseConnection();
        public abstract void DiposeConnection();
        public abstract void BeginTransaction();
        public abstract void RollBack();
        public abstract void Commit();

        //public abstract IList<WebApplication5.IModel.IModel> ExecuteTable_List(string sql);
        public abstract System.Data.DataTable ExecuteTable(string sql);
        public abstract System.Data.DataTable ExecuteTable(string sql, DbParameter param);
        public abstract System.Data.DataTable ExecuteTable(string sql, DbParameter[] list);

        public abstract System.Data.Common.DbCommand CreateCommand();
        public abstract System.Data.Common.DbConnection CreateConnection(string connString);
        public abstract System.Data.Common.DbDataAdapter CreateDataAdapter();

        public abstract int ExecuteNonQuery(string sql);
        public abstract int ExecuteNonQueryTrans(string sql);
        public abstract object ExecuteScalar(string sql);
        public abstract object ExecuteScalarTrans(string sql);

        /// <summary>
        /// 内部开启事务
        /// </summary>
        /// <param name="modelList"></param>
        /// <returns></returns>
        public abstract bool TransactionModel(ModelList modelList);
        /// <summary>
        /// 内部开启事务
        /// </summary>
        /// <param name="sqlList"></param>
        /// <returns></returns>
        public abstract bool TransactionSql(string[] sqlList);

        public abstract DataSet RunProcedure(string storedProcName, IDataParameter[] parameters, string tableName);
        public abstract DataSet RunProcedure(string storedProcName, IDataParameter[] parameters, string tableName, int Times);
        public abstract DbDataReader RunSqlDataReaderProcedure(string storedProcName, IDataParameter[] parameters);
        public abstract DataTable RunSqlDataTableProcedure(string storedProcName, IDataParameter[] parameters);
        public abstract int ProcedureExecuteNonQuery(string storedProcName, IDataParameter[] parameters, out int rowsAffected);
        public abstract object ProcedureExecuteNonQuery(string storedProcName, IDataParameter[] paramenters);
        public abstract int Update(IModel.IModel model);
        public abstract int Update(IModel.IModel model, string updateWhere);
        public abstract int UpdateTrans(IModel.IModel model);
        public abstract int UpdateTrans(IModel.IModel model, string updateWhere);
        public IHelper(string connString)
        {
            // this 是某个实现了 IHelper 的类的对象,访问的是那个类中的 CreateConnection(..),
            conn = this.CreateConnection(connString);//创建连接对象
            cmd = this.CreateCommand();//创建操作对象
            cmd.Connection = conn;
            cmd.CommandType = System.Data.CommandType.Text;//默认执行的是Sql语句
        }

        public System.Data.Common.DbParameterCollection Parameters
        {
            get { return cmd.Parameters; }
            set
            {
                cmd.Parameters.Clear();
                if (value != null)
                {
                    foreach (System.Data.Common.DbParameter p in value)
                    {
                        cmd.Parameters.Add(p);
                    }
                }
            }
        }
    }
}
