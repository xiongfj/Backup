using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;

namespace WebApplication5.Model
{
    public class PermissionModel : WebApplication5.IModel.IModel
    {
        private string _id = null;
        private string _controller = null;
        private string _action = null;
        private string _params = null;
        private string _description = null;

        public string Id
        {
            set { _id = value; }
            get { return _id; }
        }
        public string Controller
        {
            set { _controller = value; }
            get { return _controller; }
        }
        public string Action
        {
            set { _action = value; }
            get { return _action; }
        }
        public string Params
        {
            set { _params = value; }
            get { return _params; }
        }
        public string Description
        {
            set { _description = value; }
            get { return _description; }
        }

        public string Transaction_TableName
        {
            set { }
            get { return "ApplicationPermissions"; }
        }

        public string Transaction_PrimaryKey
        {
            set { }
            get { return "Id"; }
        }

        public TransactionType Transaction_type { set; get; }

        public PermissionModel()
        {
            Id = Guid.NewGuid().ToString();
        }

        public Dictionary<string, FieldInfo> getModelInfo()
        {
            Dictionary<string, FieldInfo > dic = new Dictionary<string, FieldInfo>();
            if (_id != null)
                dic.Add("Id", new FieldInfo(SqlDbType.NVarChar, _id.ToString()) );
            if (_id != null)
                dic.Add("Controller", new FieldInfo(SqlDbType.NVarChar, _controller.ToString()));
            if (_id != null)
                dic.Add("Action", new FieldInfo(SqlDbType.NVarChar, _action.ToString()));
            if (_id != null)
                dic.Add("Params", new FieldInfo(SqlDbType.NVarChar, _params.ToString()));
            if (_id != null)
                dic.Add("Description", new FieldInfo(SqlDbType.NVarChar, _description.ToString()));
            return dic;
        }
    }
}
