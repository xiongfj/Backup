using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dll.Model
{
    public class EasyXFunc : IModel
    {
		private string _ID = null;
		private string _FuncName = null;
		private string _Description = null;

		public string ID
		{
			get { return _ID; }
			set { _ID = value; }
		}
		public string FuncName
		{
			get { return _FuncName; }
			set { _FuncName = value; }
		}
		public string Description
		{
			get { return _Description; }
			set { _Description = value; }
		}

		public string mTableName
		{
			get
			{
				return "EasyXFunc";
			}
		}

		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			if (_ID != null)
				dic.Add("ID", new FieldInfo(SqlDbType.NVarChar, _ID.ToString(), true));
			if (_FuncName != null)
				dic.Add("FuncName", new FieldInfo(SqlDbType.NVarChar, _FuncName.ToString()));
			if (_Description != null)
				dic.Add("Description", new FieldInfo(SqlDbType.NVarChar, _Description.ToString()));

			return dic;
		}
	}
}
