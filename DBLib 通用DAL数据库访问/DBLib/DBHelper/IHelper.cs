using DBLib.Model;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;

namespace IdentityDB.DBHelper
{
    public abstract class IHelper
	{
		protected DbConnection conn;
		protected DbCommand cmd;

		public abstract void OpenConnection();
		public abstract void CloseConnection();

		public abstract DbCommand CreateCommand();
		public abstract DbConnection CreateConnection(string connString);
		public abstract DbDataAdapter CreateDataAdapter();

		#region 查找
		public abstract DataTable ExecuteTable(string sql);
		public abstract DataTable ExecuteTable(IModel model);
		public abstract DataTable ExecuteTableWhere(IModel model, string where);
		public abstract bool FindPrimaryKey(IModel model);
		public abstract bool FindWhere(IModel model, string where);
		public abstract object ExecuteScalarWhere(IModel model, string where);
		public abstract object ExecuteScalarSql(string sql);
		#endregion

		#region 插入
		public abstract int Insert(IModel model);
		public abstract int InsertList(List<IModel> ml);
		#endregion

		#region 更新
		public abstract int Update(IModel model);
		public abstract int UpdateWhere(IModel model, string where);
		#endregion

		#region 删除
		public abstract void Delete(IModel model);
		public abstract void Delete(IModel model, string where);
		public abstract int DeleteList(List<IModel> ml, string where);
		public abstract void DeleteAll(string table);
		#endregion

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
