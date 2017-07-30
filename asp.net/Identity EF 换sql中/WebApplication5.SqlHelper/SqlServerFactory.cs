using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;
/*** 摘要:
 * 由于 SqlServerHelper_base.cs 中的 SqlServerHelper 类继承了一个抽象类 IHelper 和一个接口 ISqlStrFactory
 * SqlServerFactory.cs 中的类       SqlServerHelper 实现--> ISqlStrFactory
 * SqlServerHelper_extend.cs 中的类 SqlServerHelper 实现--> IHelper 
 * ***/

namespace WebApplication5.SqlHelper
{
    public partial class SqlServerHelper
    {
        /*
        private void addSqlVal(StringBuilder strVal, string fieldType, string name)
        {
            strVal.Append("@" + name + ",");
        }
        private void UpdateSqlVal(StringBuilder strVal, string fieldType, string name)
        {
            strVal.Append(name + "=@" + name + ",");
        }
        */

        /// <summary>
        /// 根据Model数据,插入一条新数据,Model内可指定主键或不指定
        /// </summary>
        /// <param name="model">需要添加的实体类</param>
        /// <param name="sql">返回添加sql语句</param>
        /// <returns>参数列表</returns>
        public DbParameter[] SetSql_Add(IModel.IModel model, ref string sql)
        {
            StringBuilder strSql = new StringBuilder("insert into " + model.Transaction_TableName + "( ");
            StringBuilder strVal = new StringBuilder(" values(");
            Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
            List<SqlParameter> parameterList = new List<SqlParameter>();
            try
            {
                foreach (KeyValuePair<string, FieldInfo> kv in modelInfo)
                {
                    string name = kv.Key;//属性名称 
                    SqlDbType fieldType = kv.Value.fieldType;//类型
                    string val = kv.Value.fieldvalue;//属性值

                    strVal.Append("@" + name + ",");
                    strSql.Append(name + ",");
                    SqlParameter param = new SqlParameter("@" + name, val);
                    param.SqlDbType = fieldType;
                    parameterList.Add(param);
                }
                strSql.Remove(strSql.Length - 1, 1);
                strVal.Remove(strVal.Length - 1, 1);
                strSql.Append(")" + strVal.ToString() + ")");
                sql = strSql.ToString();
                return (SqlParameter[])parameterList.ToArray();
            }
            catch (Exception e)
            {
                throw e;
            }
        }
        /// <summary>
        /// 根据Model内的主键修改数据,Model内必须指定主键
        /// </summary>
        /// <param name="model">需要修改的实体类</param>
        /// <param name="sql">返回修改sql语句</param>
        /// <returns>参数列表</returns>

        public DbParameter[] SetSql_Update(IModel.IModel model, ref string sql)
        {
            StringBuilder strSql = new StringBuilder("update " + model.Transaction_TableName + " set ");
            List<SqlParameter> parameterList = new List<SqlParameter>();
            Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
            try
            {
                foreach (KeyValuePair<string, FieldInfo> kv in modelInfo)
                {
                    string name = kv.Key;//属性名称 
                    SqlDbType fieldType = kv.Value.fieldType;//类型
                    string val = kv.Value.fieldvalue;//属性值

                    if (name.ToLower().Equals(model.Transaction_PrimaryKey.ToLower()))//不修改主键
                    {
                        parameterList.Add(new SqlParameter("@" + model.Transaction_PrimaryKey, val));
                    }
                    else
                    {
                        //UpdateSqlVal(strSql, fieldType, name);
                        strSql.Append(name + "=@" + name + ",");
                        SqlParameter param = new SqlParameter("@" + name, val);
                        param.SqlDbType = fieldType;
                        parameterList.Add(param);
                    }
                }
                strSql.Remove(strSql.Length - 1, 1);    // 去掉之前多加的一个逗号 ','
                strSql.Append(" where " + model.Transaction_PrimaryKey + "=@" + model.Transaction_PrimaryKey);
                sql = strSql.ToString();
                return (SqlParameter[])parameterList.ToArray();
            }
            catch (Exception e)
            {
                throw e;
            }
        }
        /// <summary>
        /// 返回sql语句和参数化数组,Model内可以不提供主键
        /// </summary>
        /// <param name="model">需要修改的实体类</param>
        /// <param name="updateWhere">修改条件</param>
        /// <param name="sql">返回修改sql语句</param>
        /// <returns>参数列表</returns>
        /// 实现 SqlServerHelper_base 中继承的接口函数,
        public DbParameter[] SetSql_Update(IModel.IModel model, string updateWhere, ref string sql)
        {
            StringBuilder strSql = new StringBuilder("update " + model.Transaction_TableName + " set ");
            List<SqlParameter> parameterList = new List<SqlParameter>();
            Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
            try
            {
                foreach (KeyValuePair<string, FieldInfo> kv in modelInfo)
                {
                    string name = kv.Key;//属性名称 
                    object val = kv.Value.fieldvalue;//属性值
                    SqlDbType fieldType = kv.Value.fieldType;//类型
                    if (name.ToLower().Equals(model.Transaction_PrimaryKey.ToLower()))//不修改主键
                    {
                        // 多余的添加?? 用不到主键
                        parameterList.Add(new SqlParameter("@" + model.Transaction_PrimaryKey, val));
                        continue;
                    }
                    else
                    {
                        strSql.Append(name + "=@" + name + ",");
                        SqlParameter param = new SqlParameter("@" + name, val);
                        param.SqlDbType = fieldType;
                        parameterList.Add(param);
                    }
                }
                strSql.Remove(strSql.Length - 1, 1);
                strSql.Append(" where " + updateWhere);
                sql = strSql.ToString();
                return (SqlParameter[])parameterList.ToArray();
            }
            catch (Exception e)
            {
                throw e;
            }
        } 
    }
}
