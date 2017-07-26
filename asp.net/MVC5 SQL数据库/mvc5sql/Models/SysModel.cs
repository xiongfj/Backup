using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using mvc5sql.IModel;

namespace mvc5sql.Models
{
    public class SYS_LOGIN_LOG : mvc5sql.IModel.IModel
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
}