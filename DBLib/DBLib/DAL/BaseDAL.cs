using DBLib.Model;
using DBLib.DBHelper;
using System.Collections.Generic;
using System.Data;
using DBLib.DBHelper.Sql;

namespace DBLib.DAL
{
	public class BaseDAL
	{
		//static private SqlHelper mSqlHelper = new SqlHelper();
		protected IHelper mDBHelper;

		public BaseDAL()
		{
			mDBHelper = new SqlHelper().SqlHelperInstance;
		}

		#region 查找操作

		public DataTable ExecuteTable(string sql)
		{
			return mDBHelper.ExecuteTable(sql);
		}

		public DataTable ExecuteTableWhere(IModel model, string where)
		{
			return mDBHelper.ExecuteTableWhere(model, where);
		}

		/// <summary>
		/// 检测是否存在制定的主键
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public bool FindPrimaryKey(IModel model)
		{
			return mDBHelper.FindPrimaryKey(model);
		}

		/// <summary>
		/// 查询满足 where 条件的数据是否存在
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public bool FindWhere(IModel model, string where)
		{
			return mDBHelper.FindWhere(model, where);
		}
		#endregion

		#region 插入操作
		/// <summary>
		/// 将 model 内数据插入数据库
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public int Insert(IModel model)
		{
			return mDBHelper.Insert(model);
		}

		/// <summary>
		/// 批量插入,过滤已经存在的记录
		/// </summary>
		/// <param name="modelList"></param>
		/// <returns></returns>
		public int InsertList(List<IModel> ml)
		{
			return mDBHelper.InsertList(ml);
		}
		#endregion

		#region 修改操作
		/// <summary>
		/// 根据 Model 内主键修改数据
		/// </summary>
		/// <param name="model"></param>
		/// <returns></returns>
		public int Update(IModel model)
		{
			return mDBHelper.Update(model);
		}

		/// <summary>
		/// 根据 where 修改数据
		/// </summary>
		/// <param name="model"></param>
		public void UpdateWhere(IModel model, string where)
		{
			mDBHelper.UpdateWhere(model, where);
		}
		#endregion

		#region 删除操作

		/// <summary>
		/// 根据 Model 内主键删除数据
		/// </summary>
		/// <param name="model"></param>
		public void Delete(IModel model)
		{
			mDBHelper.Delete(model);
		}

		/// <summary>
		/// 根据 where 删除数据
		/// </summary>
		/// <param name="model"></param>
		/// <param name="where"></param>
		public void Delete(IModel model, string where)
		{
			mDBHelper.Delete(model, where);
		}

		public int DeleteList(List<IModel> ml, string where)
		{
			return mDBHelper.DeleteList(ml, where);
		}

		public void DeleteAll(string table)
		{
			mDBHelper.DeleteAll(table);
		}
		#endregion
	}
}
