using IdentityDB.Model.CustomModel;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IdentityDB.DBHelper.Sql
{
	public class SqlStringHelper
	{
		/// <summary>
		/// 只生成主键的 Id=@Id
		/// </summary>
		/// <returns></returns>
		public static string MakePrimaryKeyWhere(IModel model)
		{
			Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
			string keyWhere = "";
			foreach (string name in modelInfo.Keys)
			{
				bool isKey = modelInfo[name].isKey;
				if (isKey)
				{
					keyWhere += (name + "=@" + name + " and ");
				}
			}

			return keyWhere.Remove(keyWhere.Length - 5, 5);
		}

		/// <summary>
		/// 根据 model 内所有非 null 的字段, 生成 param=@param 的查询参数
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		//public static string MakeQueryParameters(IModel model)
		//{
		//	Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
		//	string Where = "";
		//	foreach (string name in modelInfo.Keys)
		//	{
		//		Where += (name + "=@" + name + " and ");
		//	}

		//	return Where.Remove(Where.Length - 5, 5);
		//}

		/// <summary>
		/// 根据给出的 param=@param 添加对应的 SqlParameter
		/// </summary>
		/// <param name="model"></param>
		/// <param name="paramList">里面的属性将被添加进 parameter, 其余属性不添加</param>
		/// <returns></returns>
		public static SqlParameter[] MakeQueryParameters(IModel model, string where)
		{
			List<SqlParameter> parameterList = new List<SqlParameter>();
			Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
			try
			{
				foreach (KeyValuePair<string, FieldInfo> kv in modelInfo)
				{
					string name = kv.Key;//属性名称 

					// 如果该属性不需要添加进 parameter
					if (!where.Contains("@" + name))
						continue;

					SqlDbType fieldType = kv.Value.fieldType;//类型
					string val = kv.Value.fieldvalue;//属性值

					SqlParameter param = new SqlParameter("@" + name, val);
					param.SqlDbType = fieldType;
					parameterList.Add(param);
				}

				return (SqlParameter[])parameterList.ToArray();
			}
			catch (Exception e)
			{
				throw e;
			}
		}

		/// <summary>
		/// 生成 sql, 更新主键为 model.keyID 的数据
		/// </summary>
		/// <param name="model"></param>
		/// <param name="sql"></param>
		/// <returns></returns>
		public static SqlParameter[] MakeUpdateSql(IModel model, ref string sql)
		{
			string keyWhere = MakePrimaryKeyWhere(model);
			return MakeUpdateWhereSql(model, keyWhere, ref sql);
		}

		/// <summary>
		/// model 所有非 null 字段添加进 @param
		/// </summary>
		/// <param name="model"></param>
		/// <param name="where"></param>
		/// <param name="sql"></param>
		/// <returns></returns>
		public static SqlParameter[] MakeUpdateWhereSql(IModel model, string where, ref string sql)
		{
			StringBuilder strSql = new StringBuilder("update " + model.mTableName + " set ");
			List<SqlParameter> parameterList = new List<SqlParameter>();
			Dictionary<string, FieldInfo> modelInfo = model.getModelInfo();
			try
			{
				foreach (KeyValuePair<string, FieldInfo> kv in modelInfo)
				{
					string name = kv.Key;                       //属性名称 
					SqlDbType fieldType = kv.Value.fieldType;   //类型
					string val = kv.Value.fieldvalue;           //属性值
					bool isKey = kv.Value.isKey;                // 是否是主键

					if (isKey)                                  //不修改主键,只添加参数供判断条件
					{
						parameterList.Add(new SqlParameter("@" + name, val));
					}
					else
					{
						strSql.Append(name + "=@" + name + ",");
						SqlParameter param = new SqlParameter("@" + name, val);
						param.SqlDbType = fieldType;
						parameterList.Add(param);
					}
				}
				strSql.Remove(strSql.Length - 1, 1);    // 去掉之前多加的一个逗号 ','
				strSql.Append(" where " + where);
				sql = strSql.ToString();
				return (SqlParameter[])parameterList.ToArray();
			}
			catch (Exception e)
			{
				throw e;
			}
		}

		/// <summary>
		/// 生成 insert 语句和 parameter
		/// </summary>
		/// <param name="model"></param>
		/// <param name="sql"></param>
		/// <returns></returns>
		public static SqlParameter[] MakeInsertSql(IModel model, ref string sql)
		{
			StringBuilder strSql = new StringBuilder("insert into " + model.mTableName + "( ");
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
	}
}
