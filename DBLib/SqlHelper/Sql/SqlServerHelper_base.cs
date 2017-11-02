using DBLib.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Common;

namespace DBLib.DBHelper.Sql
{
	public class SqlServerHelper : IHelper
	{
		private static object m_lock = new object();

		public SqlServerHelper(string connString) : base(connString) { }

		public override void OpenConnection()
		{
			lock (m_lock)
			{
				if (conn.State != ConnectionState.Open)
					conn.Open();
			}
		}
		public override void CloseConnection()
		{
			lock (m_lock)
			{
				if (conn != null && cmd.Transaction == null)
					conn.Close();
			}
		}

		#region 查询
		/// <summary>
		/// 查询数据
		/// </summary>
		/// <param name="sql"></param>
		/// <returns></returns>
		public override DataTable ExecuteTable(string sql)
		{
			lock (m_lock)
			{
				DataTable table = new DataTable();
				DbDataAdapter adapter = this.CreateDataAdapter();

				cmd.CommandText = sql;
				adapter.SelectCommand = cmd;

				try
				{
					adapter.Fill(table);
				}
				catch (SqlException e)
				{
					throw e;
				}

				return table;
			}
		}

		/// <summary>
		/// model 提供内 @param 值, where 提供 @param 查询数据
		/// </summary>
		/// <param name="model"></param>
		/// <param name="where"></param>
		/// <returns></returns>
		public override DataTable ExecuteTableWhere(IModel model, string where)
		{
			lock (m_lock)
			{
				DataTable table = new DataTable();

				string sql = "select * from " + model.mTableName + " where " + where;
				SqlParameter[] list = SqlStringHelper.MakeQueryParameters(model, where);
				cmd.Parameters.Clear();
				foreach (SqlParameter item in list)
					cmd.Parameters.Add(item);

				cmd.CommandText = sql;
				DbDataAdapter adapter = this.CreateDataAdapter();
				adapter.SelectCommand = cmd;

				try
				{
					adapter.Fill(table);
				}
				catch (SqlException e)
				{
					throw e;
				}

				return table;
			}
		}

		/// <summary>
		/// 根据主键查找数据
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public override bool FindPrimaryKey(IModel model)
		{
			lock (m_lock)
			{
				string keyWhere = SqlStringHelper.MakePrimaryKeyWhere(model);
				return FindWhere(model, keyWhere);
			}
		}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="model"></param>
		/// <param name="where"></param>
		/// <param name="paramList"></param>
		/// <returns></returns>
		public override bool FindWhere(IModel model, string where)
		{
			lock (m_lock)
			{
				object result = null;
				string sql = "select * from " + model.mTableName + " where " + where;

				SqlParameter[] list = SqlStringHelper.MakeQueryParameters(model, where);
				cmd.Parameters.Clear();
				foreach (SqlParameter item in list)
					cmd.Parameters.Add(item);
				cmd.CommandText = sql;

				try
				{
					OpenConnection();
					result = cmd.ExecuteScalar();
				}
				catch (SqlException e)
				{
					throw e;
				}
				finally
				{
					CloseConnection();
				}

				if (result != null)
					return true;

				return false;
			}
		}
		#endregion

		#region 插入
		/// <summary>
		/// 插入数据, 返回插入的行数
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public override int Insert(IModel model)
		{
			lock (m_lock)
			{
				int result = 0;
				string sql = "";
				SqlParameter[] dp = (SqlParameter[])SqlStringHelper.MakeInsertSql(model, ref sql);
				cmd.Parameters.Clear();
				foreach (SqlParameter item in dp)
				{
					cmd.Parameters.Add(item);
				}
				cmd.CommandText = sql;

				try
				{
					OpenConnection();
					result = cmd.ExecuteNonQuery();
				}
				catch (SqlException e)
				{
					throw e;
				}
				finally
				{
					CloseConnection();
				}

				return result;
			}
		}

		/// <summary>
		/// 批量插入数据
		/// </summary>
		/// <param name="modelList"></param>
		/// <returns></returns>
		public override int InsertList(List<IModel> ml)
		{
			lock (m_lock)
			{
				int result = 0;
				OpenConnection();
				//cmd.Transaction = conn.BeginTransaction();

				foreach (IModel model in ml)
				{
					string sql = "";
					SqlParameter[] dp = (SqlParameter[])SqlStringHelper.MakeInsertSql(model, ref sql);
					cmd.Parameters.Clear();
					foreach (SqlParameter item in dp)
					{
						cmd.Parameters.Add(item);
					}
					cmd.CommandText = sql;

					try
					{
						result += cmd.ExecuteNonQuery();
					}
					catch (SqlException e)
					{
						//cmd.Transaction.Rollback();
						//CloseConnection();
						//return 0;
					}
				}
				//cmd.Transaction.Commit();
				CloseConnection();
				return result;
			}
		}
		#endregion

		#region 修改
		/// <summary>
		/// 根据主键修改数据
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public override int Update(IModel model)
		{
			lock (m_lock)
			{
				string keyWhere = SqlStringHelper.MakePrimaryKeyWhere(model);
				return UpdateWhere(model, keyWhere);
			}
		}
		/// <summary>
		/// 自定义 where 的update查询
		/// </summary>
		/// <param name="model"></param>
		/// <param name="where"></param>
		/// <param name="param"></param>
		/// <returns></returns>
		public override int UpdateWhere(IModel model, string where)
		{
			lock (m_lock)
			{
				int result = 0;
				string sql = "";
				SqlParameter[] dp = (SqlParameter[])SqlStringHelper.MakeUpdateWhereSql(model, where, ref sql);
				cmd.Parameters.Clear();
				foreach (SqlParameter item in dp)
				{
					cmd.Parameters.Add(item);
				}
				cmd.CommandText = sql;

				try
				{
					OpenConnection();
					result = cmd.ExecuteNonQuery();
				}
				catch (SqlException e)
				{
					throw e;
				}
				finally
				{
					CloseConnection();
				}

				return result;
			}
		}
		#endregion

		#region 删除
		/// <summary>
		/// 根据 model 内主键删除数据
		/// </summary>
		/// <param name="model"></param>
		public override void Delete(IModel model)
		{
			lock (m_lock)
			{
				string keyWhere = SqlStringHelper.MakePrimaryKeyWhere(model);
				Delete(model, keyWhere);
			}
		}

		/// <summary>
		/// 自定义 where 和查询参数
		/// </summary>
		/// <param name="model"></param>
		/// <param name="where"></param>
		/// <param name="paramList">需要添加为 @param 的字段名称数组</param>
		public override void Delete(IModel model, string where)
		{
			lock (m_lock)
			{
				SqlParameter[] list = SqlStringHelper.MakeQueryParameters(model, where);
				cmd.Parameters.Clear();
				foreach (SqlParameter item in list)
					cmd.Parameters.Add(item);
				cmd.CommandText = "delete from " + model.mTableName + " where " + where;

				try
				{
					OpenConnection();
					cmd.ExecuteNonQuery();
				}
				catch (SqlException e)
				{
					throw e;
				}
				finally
				{
					CloseConnection();
				}
			}
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="ml"></param>
		/// <param name="where"></param>
		public override int DeleteList(List<IModel> ml, string where)
		{
			lock (m_lock)
			{
				int result = 0;
				OpenConnection();
				foreach (IModel model in ml)
				{
					SqlParameter[] list = SqlStringHelper.MakeQueryParameters(model, where);
					cmd.Parameters.Clear();
					foreach (SqlParameter item in list)
						cmd.Parameters.Add(item);
					cmd.CommandText = "delete from " + model.mTableName + " where " + where;

					try
					{
						result += cmd.ExecuteNonQuery();
					}
					catch (SqlException e)
					{
						throw e;
					}
				}
				CloseConnection();
				return result;
			}
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="tableName"></param>
		public override void DeleteAll(string table)
		{
			lock (m_lock)
			{
				//SqlCeParameter param = new SqlCeParameter("@table", table);
				//param.SqlDbType = SqlDbType.NVarChar;

				cmd.CommandText = "delete from " + table;

				try
				{
					OpenConnection();
					cmd.ExecuteNonQuery();
				}
				catch (SqlException e)
				{
					throw e;
				}
				finally
				{
					CloseConnection();
				}
			}
		}

		public override DbCommand CreateCommand()
		{
			return new SqlCommand();
		}

		public override DbConnection CreateConnection(string connString)
		{
			return new SqlConnection(connString);
		}

		public override DbDataAdapter CreateDataAdapter()
		{
			return new SqlDataAdapter();
		}
		#endregion
	}
}
