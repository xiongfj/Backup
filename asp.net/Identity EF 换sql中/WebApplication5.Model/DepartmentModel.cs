using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;

namespace WebApplication5.Model
{
    class DepartmentModel : WebApplication5.IModel.IModel
    {
        private int? _id = null;
        private string _name = null;

        public int? Id { set { _id = value; } get { return _id; } }
        public string Name { set { _name = value; } get { return _name; } }

        public string Transaction_TableName
        {
            set { }
            get { return "Departments"; }
        }
        public string Transaction_PrimaryKey
        {
            set { }
            get { return "Id"; }
        }
        public TransactionType Transaction_type
        {
            set;get;
        }

        public Dictionary<string, FieldInfo> getModelInfo()
        {
            Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();

            if ( _id != null )
                dic.Add("Id", new FieldInfo(SqlDbType.Int, _id.ToString()) );
            if (_name != null)
                dic.Add("Name", new FieldInfo(SqlDbType.NVarChar, _name.ToString()) );

            return dic;
        }
    }
}
