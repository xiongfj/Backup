using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;
using WebApplication5.SqlHelper;

namespace WebApplication5.Dal
{
    public class CommonBaseDAL
    {
        protected IHelper dbHelper;
        public CommonBaseDAL()
        {
            SqlHelper.SqlHelper sqlHelper = new SqlHelper.SqlHelper();
            dbHelper = sqlHelper.SqlHelperInstance;
        }

        #region 必须有的部分
        /// <summary>
        /// 需要进行添加的model列表
        /// </summary>
        protected ModelList modelList = new ModelList();
        /// <summary>
        /// 获取要执行的model列表
        /// </summary>
        public ModelList ModelList
        {
            get { return modelList; }
            set { modelList = value; }
        }
        #endregion

        /// <summary>
        /// √根据表名 + where 删除数据
        /// </summary>
        /// <param name="tableName"></param>
        /// <param name="where"></param>
        /// <returns>被删除的行数</returns>
        /// TransDAL 需要覆盖该函数,使用ExecuteNonQueryTrans()
        public virtual int Delete(string tableName, string where)
        {
            string sql = "delete from " + tableName + " where " + where;
            return dbHelper.ExecuteNonQuery(sql); 
        }
        /// <summary>
        /// 删除指定主键的数据
        /// </summary>
        /// <param name="tableName"></param>
        /// <param name="PrimaryKeyName">主键名</param>
        /// <param name="PrimaryKey">主键值</param>
        /// <returns>被删除的行数</returns>
        public int Delete(string tableName, string PrimaryKeyName, int PrimaryKey)
        {
            return this.Delete(tableName, PrimaryKeyName + "=" + PrimaryKey);
        }
        /// <summary>
        /// √批量删除指定主键的数据
        /// </summary>
        /// <param name="tableName"></param>
        /// <param name="PrimaryKeyName">主键名</param>
        /// <param name="PrimaryKeyList">主键值组成的字符串,每个主键用逗号分开</param>
        /// <returns>被删除的行数</returns>
        public int DeleteList(string tableName, string PrimaryKeyName, string PrimaryKeyList)
        {
            return this.Delete(tableName, PrimaryKeyName + " in ( " + PrimaryKeyList + " ) ");
        }
         
    }
    public class CommonDAL : CommonBaseDAL
    {
        /// <summary>
        /// √内部使用 DbDataAdapter 填充一个 DataTable 返回.
        /// </summary>
        /// <param name="sql"></param>
        /// <returns>返回查询结果DataTable</returns>
        public DataTable ExecuteTable(string sql)
        {
            return dbHelper.ExecuteTable(sql);
        }
        #region 通用（增、改）方法
        /// <summary>
        /// √提供一个 Model 插入一条数据,返回新插入的数据的主键或者插入的行数(1\0)
        /// </summary>
        /// <param name="model"></param>
        /// <param name="isBackIdentity"></param>
        /// <returns>true->返回主键, false->返回1或0</returns>
        public int Add(IModel.IModel model, bool isBackIdentity)
        {
            return dbHelper.Add(model, isBackIdentity);
        }
        /// <summary>
        /// 根据Model内的主键和新数据修改数据,Model内必须提供主键,返回成功修改的行数
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int Update(IModel.IModel model)
        {
            return dbHelper.Update(model);
        }
        /// <summary>
        /// 根据Model内数据修改数据库,Model中可以不提供主键
        /// </summary>
        /// <param name="model"></param>
        /// <param name="where">sql语句中的 where 条件</param>
        /// <returns>成功修改的行数</returns>
        public int Update(IModel.IModel model, string where)
        {
            return dbHelper.Update(model, where);
        }
        /// <summary>
        /// 提增,删,改的函数调用,最终执行数据库操作,返回受影响的行数
        /// </summary>
        /// <param name="sql"></param>
        /// <returns></returns>
        public int ExecuteNonQuery(string sql)
        {
            return dbHelper.ExecuteNonQuery(sql);
        }
        /// <summary>
        /// 返回结果中的第一行第一列那个字段的值,可能为 NULL(=System.DBNull.Value) 或者 null(不存在数据),需要验证
        /// </summary>
        /// <param name="sql"></param>
        /// <returns></returns>
        public object ExecuteScalar(string sql)
        {
            return dbHelper.ExecuteScalar(sql);
        }
        #endregion


        #region 执行存储过程
        /// <summary>
        /// 执行存储过程,结果在 DataSet中的表"tableName"中
        /// </summary>
        /// <param name="storedProcName">存储过程名</param>
        /// <param name="parameters">存储过程参数</param>
        /// <param name="tableName">DataSet结果中的表名</param>
        /// <returns>DataSet</returns>
        public DataSet RunProcedure(string storedProcName, IDataParameter[] parameters, string tableName)
        {
            return dbHelper.RunProcedure(storedProcName, parameters, tableName);
        }
        public DataSet RunProcedure(string storedProcName, IDataParameter[] parameters, string tableName, int Times)
        {
            return dbHelper.RunProcedure(storedProcName, parameters, tableName, Times);
        }
        /// <summary>
        /// ( 注意：调用该方法后，一定要对SqlDataReader进行Close )
        /// </summary>
        /// <param name="storedProcName"></param>
        /// <param name="parameters"></param>
        /// <returns></returns>
        public DbDataReader RunSqlDataReaderProcedure(string storedProcName, IDataParameter[] parameters)
        {
            return dbHelper.RunSqlDataReaderProcedure(storedProcName, parameters);
        }
        public DataTable RunSqlDataTableProcedure(string storedProcName, IDataParameter[] parameters)
        {
            return dbHelper.RunSqlDataTableProcedure(storedProcName, parameters);
        }
        /// <summary>
        /// 执行存储过程，返回影响的行数		
        /// </summary>
        /// <param name="storedProcName">存储过程名</param>
        /// <param name="parameters">存储过程参数</param>
        /// <param name="rowsAffected">影响的行数</param>
        /// <returns></returns>
        public int ProcedureExecuteNonQuery(string storedProcName, IDataParameter[] parameters, out int rowsAffected)
        {
            return dbHelper.ProcedureExecuteNonQuery(storedProcName, parameters, out rowsAffected);
        }
        public object ProcedureExecuteNonQuery(string storedProcName, IDataParameter[] parameters)
        {
            return dbHelper.ProcedureExecuteNonQuery(storedProcName, parameters);
        }
        #endregion
    }

    /// <summary>
    /// 提供事物处理
    /// </summary>
    public class CommonTransDAL : CommonBaseDAL
    {
        /// <summary>
        /// 开始事务，并打开链接
        /// </summary>
        public void BeginTransaction()
        {
            dbHelper.BeginTransaction();
        }
        /// <summary>
        /// 事物回滚
        /// </summary>
        public void RollBack()
        {
            dbHelper.RollBack();
        }
        /// <summary>
        /// 事务提交，并关闭链接。
        /// </summary>
        public void Commit()
        {
            dbHelper.Commit();
        }
        /// <summary>
        /// 添加一条数据
        /// </summary>
        /// <param name="model"></param>
        /// <param name="isBackIdentity">true->返回插入的数据的主键,false->返回成功添加的行数1\0</param>
        /// <returns></returns>
        public int AddTrans(IModel.IModel model, bool isBackIdentity)
        {
            return dbHelper.AddTrans(model, isBackIdentity);
        }

        /// <summary>
        /// 添加多条数据,返回最后插入的ID 或 其它
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int AddList(List<IModel.IModel> listModel, bool isBackIdentity)
        {
            int result = 0;
            for (int i = 0; i < listModel.Count; i++)
            {
                result = dbHelper.AddTrans(listModel[i], isBackIdentity);
                if (result < 1)
                {
                    break;
                }
            }
            return result;
        }

        #region 事物处理（执行多个添加修改）
        /// <summary>
        /// 内部开启事务,批量插入\更新,
        /// 需要先填充成员 modelList
        /// </summary>
        /// <param name="ModelList">model列表</param>
        public bool TransactionModel()
        {
            return dbHelper.TransactionModel(modelList);
        }
        /// <summary>
        /// 事务执行多个 sql 语句,自带事务开启
        /// </summary>
        /// <param name="ModelList">sql语句l列表</param>
        public bool TransactionSql(string[] sqlList)
        {
            return dbHelper.TransactionSql(sqlList);
        }
        #endregion

        /// <summary>
        /// 更新数据,model必须指定主键,返回更新的行数
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int Update(IModel.IModel model)
        {
            return dbHelper.UpdateTrans(model);
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="model"></param>
        /// <param name="strWhrere"></param>
        /// <returns></returns>
        public int Update(IModel.IModel model, string strWhrere)
        {
            return dbHelper.UpdateTrans(model, strWhrere);
        } 
        /// <summary>
        /// 如果 where="",删除所有数据
        /// </summary>
        /// <param name="tableName"></param>
        /// <param name="where"></param>
        /// <returns></returns>
        public override int Delete(string tableName, string where)
        {
            if (where.Trim() == "")
            {
                where = "1=1";
            }
            string sql = "delete from " + tableName + " where " + where;
            return dbHelper.ExecuteNonQueryTrans(sql);
        }
        /// <summary> 
        /// </summary>
        /// <param name="tableName"></param>
        /// <param name="where"></param>
        /// <returns></returns>
        public int ExecuteNonQueryTrans(string tableName, string where)
        {
            if (where.Trim() == "")
            {
                where = "1=1";
            }
            string sql = "update " + tableName + " set STATUS=1 where " + where;
            return dbHelper.ExecuteNonQueryTrans(sql);
        }
        /// <summary>
        /// 查询, 返回结果集中第一行第一列的值
        /// </summary>
        /// <param name="sql"></param>
        /// <returns></returns>
        public object ExecuteScalarTrans(string sql)
        {
            return dbHelper.ExecuteScalarTrans(sql);
        }
    }
}
