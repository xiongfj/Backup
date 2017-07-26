using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*** 摘要:
 * 
 * 由于 SqlServerHelper_base.cs 中的 SqlServerHelper 类继承了一个抽象类 IHelper 和一个接口 ISqlStrFactory
 * SqlServerFactory.cs 中的类       SqlServerHelper 实现--> ISqlStrFactory
 * SqlServerHelper_extend.cs 中的类 SqlServerHelper 实现--> IHelper 
 * 
 * ***/

namespace WebApplication5.SqlHelper
{
    public partial class SqlServerHelper : IHelper, ISqlStrFactory
    {
        protected static string connectionString = ConfigurationManager.ConnectionStrings["sqlHelper"].ConnectionString.Trim();

        /// <summary>
        /// 实现基类函数,具体化 DbConnection为 SqlConnection 指令
        /// </summary>
        /// <param name="connString">SqlHelper.cs 中的成员传递过来</param>
        /// <returns></returns>
        public override DbConnection CreateConnection(string connString)
        {
            return new SqlConnection(connString);
        }
        /// <summary>
        /// 实现基类函数,具体化 DbCommand 为 SqlCommand 指令
        /// </summary>
        /// <returns></returns>
        public override DbCommand CreateCommand()
        {
            return new SqlCommand();
        }
        /// <summary>
        /// 实现基类函数,具体化 DbDataAdaoter 为 SqlDataAdapter
        /// </summary>
        /// <returns></returns>
        public override DbDataAdapter CreateDataAdapter()
        {
            return new SqlDataAdapter();
        }

        #region 打开连接对象
        /// <summary>
        /// 操作基类 IHelper 的 conn
        /// </summary>
        public override void OpenConnection()
        {
            if (conn.State != ConnectionState.Open) // 不可重复打开!!
                conn.Open();
        }
        #endregion

        #region 关闭连接对象
        /// <summary>
        /// 操作基类 IHelper 的 conn
        /// </summary>
        public override void CloseConnection()
        {
            if (conn != null && cmd.Transaction == null)
            {
                conn.Close();
            }
        }
        #endregion

        /// <summary>
        /// 释放连接对象
        /// </summary>
        public override void DiposeConnection()
        {
            conn.Dispose();
        }
        /// <summary>
        /// 开始事务
        /// </summary>
        public override void BeginTransaction()
        {
            if (cmd.Transaction == null)
            {
                this.OpenConnection();
                cmd.Transaction = conn.BeginTransaction();
            }
        }
        /// <summary>
        /// 回滚事务,同时关闭 connection
        /// </summary>
        public override void RollBack()
        {
            if (cmd.Transaction != null)
            {
                cmd.Transaction.Rollback(); // 回滚后 Transaction = null
            }
            this.CloseConnection();
        }
        /// <summary>
        /// 提交事务
        /// </summary>
        public override void Commit()
        {
            if (cmd.Transaction != null)
            {
                cmd.Transaction.Commit();   // 提交后 Transaction = null
            }
            this.CloseConnection();
        }

        #region ExecuteNonQuery（执行增、删、改）
        /// <summary>
        /// 执行增、删、改
        /// </summary>
        /// <param name="sql">sql语句或存储过程</param>
        /// <returns>受影响的行数</returns>
        public override int ExecuteNonQuery(string sql)
        {
            cmd.CommandText = sql;
            int result;
            try
            {
                this.OpenConnection();
                result = cmd.ExecuteNonQuery(); // 返回被更改的行数
            }
            catch (SqlException exp)
            {
                throw exp;
            }
            finally
            {
                cmd.Parameters.Clear();
                this.CloseConnection();
            }
            return result;
        }
        /// <summary>
        /// 执行增、删、改.返回被更改行数
        /// </summary>
        /// <param name="sql">sql语句或存储过程</param>
        /// <returns>受影响的行数</returns>
        public override int ExecuteNonQueryTrans(string sql)
        {
            cmd.CommandText = sql;
            int result;
            //this.BeginTransaction();
            try
            {
                result = cmd.ExecuteNonQuery();
               // this.Commit();
            }
            catch (SqlException exp)
            {
                //this.RollBack();
                throw exp;
            }
            finally
            {
                cmd.Parameters.Clear();
            }
            return result;
        }
        #endregion

        #region ExecuteTable（执行查询）
        /// <summary>
        /// 执行查询
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <returns>返回一个DataTable</returns>
        public override DataTable ExecuteTable(string sql)
        {
            DataTable result = new DataTable();
            try
            {
                cmd.CommandText = sql;
                DbDataAdapter adp = this.CreateDataAdapter();   // 由抽象类IHelper基类映射创建一个SqlDataAdapter
                adp.SelectCommand = cmd;
                adp.Fill(result);   // 如果SqlConnection是打开的,查询后保持打开,如果是关闭的,先打开查询后关闭.
            }
            catch (SqlException e)
            {
                result = null;
                throw e;
            }
            finally
            {
                cmd.Parameters.Clear();
            }
            return result;
        }
        #endregion

        #region ExecuteScalar（执行单一查询）
        /// <summary>
        /// 执行查询，并返回查询所返回的结果集中第一行的第一列。所有其他的列和行将被忽略。
        /// </summary>
        /// <param name="sql">sql语句或存储过程</param>
        /// <returns>返回结果</returns>
        public override object ExecuteScalar(string sql)
        {
            object result = null;
            try
            {
                cmd.CommandText = sql;
                this.OpenConnection();
                result = cmd.ExecuteScalar();
            }
            catch (SqlException e)
            {
                throw e;
            }
            finally
            {
                cmd.Parameters.Clear();
                this.CloseConnection();
            }
            return result;
        }
        /// <summary>
        /// 内部开启事务,返回第一行第一列的值对象
        /// </summary>
        /// <param name="sql"></param>
        /// <returns></returns>
        public override object ExecuteScalarTrans(string sql)
        {
            object result = null;
            //this.BeginTransaction();
            try
            {
                cmd.CommandText = sql;
                result = cmd.ExecuteScalar();
                //this.Commit();
            }
            catch (SqlException e)
            {
                //this.RollBack();
                throw e;
            }
            finally
            {
                cmd.Parameters.Clear();
            }
            return result;
        }
        #endregion

         
    }
}
