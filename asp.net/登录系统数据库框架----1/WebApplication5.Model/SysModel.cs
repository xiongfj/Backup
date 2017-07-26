using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;

/*** Model 实体类
 * 与数据库表或视图对应.
 * 成员数据与数据库字段对应
 */

namespace WebApplication5.Model
{
    public class SYS_LOGIN_LOG : WebApplication5.IModel.IModel
    {
        private int? _id = null;
        private string _loginip = null;
        private DateTime? _login_time = null;   // 问号 .net2.0 新语法,表示可以为 null
        private string _sys_user_id = null;
        private string _is_success = null;

        public SYS_LOGIN_LOG()
        {
            Transaction_type = TransactionType.Add;             // 事务操作默认是添加
        }

        public string LOGINIP
        {
            get { return _loginip; }
            set { _loginip = value; }
        }

        /// <summary>
        /// 登录时间
        /// </summary>		
        public DateTime? LOGIN_TIME
        {
            get { return _login_time; }
            set { _login_time = value; }
        }
        public int? ID
        {
            get { return _id; }
            set { _id = value; }
        }

        /// <summary>
        /// 登录账户
        /// </summary>		
        public string SYS_USER_ID
        {
            get { return _sys_user_id; }
            set { _sys_user_id = value; }
        }

        /// <summary>
        /// 登录是否成功
        /// </summary>	
        public string IS_SUCCESS
        {
            get { return _is_success; }
            set { _is_success = value; }
        }
        public string Transaction_TableName
        {
            set { }
            get { return "SYS_LOGIN_LOG"; }
        }

        public string Transaction_PrimaryKey
        {
            set { }
            get { return "ID"; }
        }
        public IModel.TransactionType Transaction_type { set; get; }

        public Dictionary<string, FieldInfo> getModelInfo()
        {
            Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();
            if (_id != null)
            {
                dic.Add("ID", new FieldInfo(SqlDbType.Int, _id.ToString()));
            }
            if (_loginip != null)
            {
                dic.Add("LOGINIP", new FieldInfo(SqlDbType.NVarChar, _loginip.ToString()));
            }
            if (_login_time != null)
            {
                dic.Add("LOGIN_TIME", new FieldInfo(SqlDbType.DateTime, _login_time.ToString()));
            }
            if (_sys_user_id != null)
            {
                dic.Add("SYS_USER_ID", new FieldInfo(SqlDbType.NVarChar, _sys_user_id.ToString()));
            }
            if (_is_success != null)
            {
                dic.Add("IS_SUCCESS", new FieldInfo(SqlDbType.NVarChar, _is_success.ToString()));
            }
            return dic;
        }
    }

    public class USER_INFO : WebApplication5.IModel.IModel
    {
        private int? _id = null;
        private string _username = null;
        private string _password = null;

        public USER_INFO()
        {
            Transaction_type = TransactionType.Add;
        }
        public USER_INFO(string user, string pwd)
        {
            Transaction_type = TransactionType.Add;
            _username = user;
            _password = pwd;
        }
        public USER_INFO(int? i, string user, string pwd)
        {
            Transaction_type = TransactionType.Add;
            _id = i;
            _username = user;
            _password = pwd;
        }
        
        public int? id
        {
            set { _id = value; }
            get { return _id; }
        }
        public string username {
            set { _username = value; }
            get { return _username; }
        } 
        public string password
        {
            get { return _password; }
            set { _password = value; }
        }
        public string Transaction_TableName
        {
            get { return "USERINFO"; }
            set { }
         }
        public string Transaction_PrimaryKey
        {
            get { return "ID"; }
            set { }
        }
        public IModel.TransactionType Transaction_type { get; set; }
         
        public Dictionary<string, FieldInfo> getModelInfo()
        {
            Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();
            if( _id != null )
            {
                dic.Add("ID", new FieldInfo(SqlDbType.Int, _id.ToString()));
            }
            if( _username!=null)
            {
                dic.Add("username", new FieldInfo(SqlDbType.NVarChar, _username.ToString()));
            }
            if( _password != null)
            {
                dic.Add("password", new FieldInfo(SqlDbType.NVarChar, _password.ToString()));
            }
            return dic;
        }
    }
}
