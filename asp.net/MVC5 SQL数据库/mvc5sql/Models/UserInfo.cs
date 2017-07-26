using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using mvc5sql.IModel;
using System.ComponentModel.DataAnnotations;

namespace mvc5sql.Models
{
    public class UserInfo : mvc5sql.IModel.IModel
    {
        private int? _id = null;
        private string _username = null;
        private string _password = null;

        public UserInfo()
        {
            Transaction_type = TransactionType.Add;
        }
        public UserInfo(string user, string pwd)
        {
            Transaction_type = TransactionType.Add;
            _username = user;
            _password = pwd;
        }
        public UserInfo(int? i, string user, string pwd)
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
        public string username
        {
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
            if (_id != null)
            {
                dic.Add("ID", new FieldInfo(SqlDbType.Int, _id.ToString()));
            }
            if (_username != null)
            {
                dic.Add("username", new FieldInfo(SqlDbType.NVarChar, _username.ToString()));
            }
            if (_password != null)
            {
                dic.Add("password", new FieldInfo(SqlDbType.NVarChar, _password.ToString()));
            }
            return dic;
        }
    }

    /*视图模型, 介于数据库实体与用户之间过滤*/
    public class LoginViewModel
    {
        [Required]
        [StringLength(20)]
        [Display(Name = "用户名")]
        public string username { set; get; }

        [Required]
        [Display(Name = "密码")]
        public string password { get; set; }

        [Required(ErrorMessage = "*")]
        [Display(Name = "验证码")]
        public string code { get; set; }
    }
}