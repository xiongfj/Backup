using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBLib.Model
{
	public class Url : IModel
	{
		/// <summary>
		/// 主键
		/// </summary>
		private string _urlKey = null;      // 自定义 url 的key
		/// <summary>
		/// 主键
		/// </summary>
		private string _userID = null;      // 所属的 user
		private string _urlValue = null;    // key 对应的 url

		public string UrlKey
		{
			get { return _urlKey; }
			set { _urlKey = value; }
		}
		public string UserID
		{
			get { return _userID; }
			set { _userID = value; }
		}
		public string UrlValue
		{
			get { return _urlValue; }
			set { _urlValue = value; }
		}

		public string mTableName
		{
			get
			{
				return "Urls";
			}
		}

		public Dictionary<string, FieldInfo> getModelInfo()
		{
			Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

			if (_urlKey != null)
				dic.Add("UrlKey", new FieldInfo(SqlDbType.NVarChar, _urlKey.ToString(), true));       // true 该字段是主键
			if (_userID != null)
				dic.Add("UserID", new FieldInfo(SqlDbType.NVarChar, _userID.ToString(), true));  // true 该字段是主键
			if (_urlValue != null)
				dic.Add("UrlValue", new FieldInfo(SqlDbType.NVarChar, _urlValue.ToString()));

			return dic;
		}
	}
}
