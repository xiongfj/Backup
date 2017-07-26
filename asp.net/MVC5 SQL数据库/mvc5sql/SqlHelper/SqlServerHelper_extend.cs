using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using mvc5sql.IModel;

/*** 摘要:
 * 由于 SqlServerHelper_base.cs 中的 SqlServerHelper 类继承了一个抽象类 IHelper 和一个接口 ISqlStrFactory
 * SqlServerFactory.cs 中的类       SqlServerHelper 实现--> ISqlStrFactory
 * SqlServerHelper_extend.cs 中的类 SqlServerHelper 实现--> IHelper 
 * ***/

namespace mvc5sql.SqlHelper
{
    public partial class SqlServerHelper
    {
        public SqlServerHelper(string connString) : base(connString) { }

        /// <summary>
        /// 提供一个Model插入一条数据,返回插入的行数或插入的主键ID
        /// </summary>
        /// <param name="model"></param>
        /// <param name="isBackIdentity">ture->返回新插入的数据的主键,false->返回插入的行数</param>
        /// <returns></returns>
        public override int Add(IModel.IModel model, bool isBackIdentity)
        {
            string sql = "";
            SqlParameter[] dp = (SqlParameter[])this.SetSql_Add(model, ref sql);
            foreach (SqlParameter item in dp)
            {
                this.Parameters.Add(item);
            }
            if (isBackIdentity)
            {
                sql += ";select @@identity;";    // 返回插入数据的 ID 值
                object obj = this.ExecuteScalar(sql);
                this.Parameters.Clear();
                return Convert.ToInt32(obj);
            }
            else
            {
                int r = this.ExecuteNonQuery(sql);
                this.Parameters.Clear();
                return r;
            }
        }
        /// <summary>
        /// 内部函数开启事务,返回新插入数据的主键?或插入的行数
        /// </summary>
        /// <param name="model"></param>
        /// <param name="isBackIdentity"></param>
        /// <returns></returns>
        public override int AddTrans(IModel.IModel model, bool isBackIdentity)
        {
            string sql = "";
            SqlParameter[] dp = (SqlParameter[])this.SetSql_Add(model, ref sql);
            foreach (SqlParameter item in dp)
            {
                this.Parameters.Add(item);
            }
            if (isBackIdentity)
            {
                // 一个字符串包含两条 sql 语句, ExecuteScalar 返回 select 语句的第一行第一列的值,即ID
                sql += ";select @@identity;";       // 返回上次插入数据的 ID 值
                object obj = this.ExecuteScalarTrans(sql);
                this.Parameters.Clear();
                return Convert.ToInt32(obj);
            }
            else
            {
                int r = this.ExecuteNonQueryTrans(sql);
                this.Parameters.Clear();
                return r;
            }
        }

        /// <summary>
        /// 根据Model里面的主键和其他字段的新值修改数据
        /// </summary>
        /// <param name="model">修改的实体类</param>
        /// <returns>被修改的行数</returns>
        public override int Update(IModel.IModel model)
        {
            string sql = "";
            SqlParameter[] dp = (SqlParameter[])this.SetSql_Update(model, ref sql);
            foreach (SqlParameter item in dp)
            {
                this.Parameters.Add(item);
            }
            return this.ExecuteNonQuery(sql);
        }
        /// <summary>
        /// 根据Model和where修改数据,Model内可以不提供主键
        /// </summary>
        /// <param name="model"></param>
        /// <param name="updateWhere"></param>
        /// <returns></returns>
        public override int Update(IModel.IModel model, string updateWhere)
        {
            string sql = "";
            SqlParameter[] dp = (SqlParameter[])this.SetSql_Update(model, updateWhere, ref sql);
            foreach (SqlParameter item in dp)
            {
                this.Parameters.Add(item);
            }
            return this.ExecuteNonQuery(sql);
        }
        /// <summary>
        /// 内部函数开启事务,返回更改的行数.<model>内必须指定主键
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public override int UpdateTrans(IModel.IModel model)
        {
            string sql = "";
            SqlParameter[] dp = (SqlParameter[])this.SetSql_Update(model, ref sql);
            foreach (SqlParameter item in dp)
            {
                this.Parameters.Add(item);
            }
            return this.ExecuteNonQueryTrans(sql);
        }
        /// <summary>
        /// 内部函数开启事务,返回更改的行数.<model>内可以不指定主键?
        /// </summary>
        /// <param name="model"></param>
        /// <param name="updateWhere"></param>
        /// <returns></returns>
        public override int UpdateTrans(IModel.IModel model, string updateWhere)
        {
            string sql = "";
            SqlParameter[] dp = (SqlParameter[])this.SetSql_Update(model, updateWhere, ref sql);
            foreach (SqlParameter item in dp)
            {
                this.Parameters.Add(item);
            }
            return this.ExecuteNonQueryTrans(sql);
        }

        /// <summary>
        /// 开启事务,执行插入或修改多个Model,由Model的Transaction_type指定,返回1或者错误信息或异常信息
        /// </summary>
        /// <param name="ModelList"></param>
        public override bool TransactionModel(ModelList modelList)
        {
            string retmsg = "";
            this.BeginTransaction();
            try
            {
                foreach (IModel.IModel model in modelList.returnModelList())
                {
                    string Transaction_TableName = model.Transaction_TableName;
                    string Transaction_PrimaryKey = model.Transaction_PrimaryKey;
                    TransactionType Transaction_type = model.Transaction_type;
                    string sql = "";
                    DbParameter[] dp = null;
                    if (Transaction_type == TransactionType.Add)
                    {
                        dp = this.SetSql_Add(model, ref sql);
                    }
                    else if (Transaction_type == TransactionType.Update)
                    {
                        dp = this.SetSql_Update(model, ref sql);
                    }
                    cmd.Parameters.Clear();

                    foreach (SqlParameter item in dp)
                    {
                        cmd.Parameters.Add(item);
                    }
                    if (!string.IsNullOrEmpty(sql))
                    {
                        cmd.CommandText = sql;
                        cmd.ExecuteNonQuery();
                    }
                    else
                    {
                        return false;
                    }
                }
                this.Commit();
            }
            catch (SqlException ex)
            {
                this.RollBack();
                return false;
            }
            return true;
        }
        /// <summary>
        /// 开启事务,执行多条 sql 语句, 返回异常信息, 成功返回空:""
        /// </summary>
        /// <param name="sqlList"></param>
        public override bool TransactionSql(string[] sqlList)
        {
            this.BeginTransaction();
            try
            {
                foreach (string sql in sqlList)
                {
                    if (!string.IsNullOrEmpty(sql))
                    {
                        cmd.CommandText = sql;
                        cmd.ExecuteNonQuery();
                    }
                }
                this.Commit();
            }
            catch (SqlException e)
            {
                this.RollBack();
                return false;
            }
            return true;
        }
    }
}
