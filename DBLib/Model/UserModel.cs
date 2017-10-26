using DBLib.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
	/// <summary>
	/// 双字段表
	/// </summary>
	public class UserModel : IModel
	{
		private uint? id = null;		// 主键
		private uint? groupid = null;		// 复健
		private string name = null;
		private string addr = null;

		#region 属性对应的字段
		public uint? ID
		{
			set
			{
				id = value;
			}
			get
			{
				return id;
			}
		}
		public uint? GroupID
		{
			set
			{
				groupid = value;
			}
			get
			{
				return groupid;
			}
		}
		public string Name
		{
			set
			{
				name = value;
			}
			get
			{
				return name;
			}
		}
		public string Address
		{
			set
			{
				addr = value;
			}
			get
			{
				return addr;
			}
		}
		#endregion

		public string mTableName
		{
			get
			{
				return "NetUser";		// 对应数据库中的表名
			}
		}

		/// <summary>
		/// 模拟使用双主键的情况
		/// </summary>
		/// <returns></returns>
		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			if (id != null)
				dic.Add("ID", new FieldInfo(SqlDbType.BigInt, id.ToString(), true));			// true 该字段是主键
			if (groupid != null)
				dic.Add("GroupID", new FieldInfo(SqlDbType.BigInt, groupid.ToString(), true));	// true 该字段是主键
			if (name != null)
				dic.Add("Name", new FieldInfo(SqlDbType.NVarChar, name.ToString()));
			if (addr != null)
				dic.Add("Address", new FieldInfo(SqlDbType.NVarChar, addr.ToString()));

			return dic;
		}
	}
}
