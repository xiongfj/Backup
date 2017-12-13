using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dll.Model
{
	public interface IModel
	{
		string mTableName { get; }

		Dictionary<string, FieldInfo> getModelInfo();
	}

	public struct FieldInfo
	{
		public FieldInfo(SqlDbType fieldType, string fieldvalue, bool key = false)
		{
			this.fieldType = fieldType;
			this.fieldvalue = fieldvalue;
			this.isKey = key;
		}
		public SqlDbType fieldType;     // 必须与数据库内的字段类型一样!!
		public string fieldvalue;
		public bool isKey;              // 指示是否是主键
	}
}
