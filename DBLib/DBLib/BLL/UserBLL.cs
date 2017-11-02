using DBLib.DAL;
using DBLib.BLL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DBLib.Model;
using System.Data;

namespace DBLib.BLL
{
	/// <summary>
	/// 一些具体的操作: 插入什么条件的数据, 查找什么样的数据
	/// 例如: 选择vip用户, 选择一般用户, 选择授权用户 ...
	/// 删除黑名单用户, 删除超龄用户, 删除不良信誉用户..
	/// 添加某个数据
	/// </summary>
	public class UserBLL : BaseBLL
	{
		private UserDAL mDAL = new UserDAL();

		public void Update(IModel model)
		{
			mDAL.Update(model);
		}

		public void UpdateAddress(IModel model)
		{
			string where = "ID=@ID and GroupID=@GroupID";
			mDAL.UpdateWhere(model, where);
		}

		public void Insert(IModel model)
		{
			mDAL.Insert(model);
		}

		public void Delete(IModel model)
		{
			mDAL.Delete(model);
		}

		public List<UserModel> QueryTable()
		{
			return mDAL.QueryUser();
		}
	}
}
