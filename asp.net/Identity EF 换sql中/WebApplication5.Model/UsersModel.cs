using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.IModel;

namespace WebApplication5.Model
{
    public class UsersModel : WebApplication5.IModel.IModel
    {
        private string _id = null;
        private string _password = null;
        private string _email = null;
        private bool? _emailConfirmed = null;
        private string _passwordHash = null;
        private string _securityStamp = null;
        private string _phoneNumber = null;
        private bool? _phoneNumberConfirmed = null;
        private bool? _twoFactorEnabled = null;
        private DateTime? _lockoutEndDateUtc = null;
        private bool? _lockoutEnabled = null;
        private int? _accessFailedCount = null;
        private string _userName = null;

        public string   Id                      { set { _id = value; }                  get { return _id; } }
        public string   Password                { set { _password = value; }            get { return _password; } }
        public string   Email                   { set { _email = value; }               get { return _email; } }
        public bool?    EmailConfirmed          { set { _emailConfirmed = value; }      get { return _emailConfirmed; } }
        public string   PasswordHash            { set { _passwordHash = value; }        get { return _passwordHash; } }
        public string   SecurityStamp           { set { _securityStamp = value; }       get { return _securityStamp; } }
        public string   PhoneNumber             { set { _phoneNumber = value; }         get { return _phoneNumber; } }
        public bool?    PhoneNumberConfirmed    { set { _phoneNumberConfirmed = value;} get { return _phoneNumberConfirmed; } }
        public bool?    TwoFactorEnabled        { set { _twoFactorEnabled = value; }    get { return _twoFactorEnabled; } }
        public DateTime? LockoutEndDateUtc      { set { _lockoutEndDateUtc = value; }   get { return _lockoutEndDateUtc; } }
        public bool?    LockoutEnabled          { set { _lockoutEnabled = value; }      get { return _lockoutEnabled; } }
        public int?     AccessFailedCount       { set { _accessFailedCount = value; }   get { return _accessFailedCount; } }
        public string   UserName                { set { _userName = value; }            get { return _userName; } }

        public UsersModel() { }

        public string Transaction_TableName
        {
            set { }
            get { return "AspNetUsers"; }
        }
        public string Transaction_PrimaryKey
        {
            set { }
            get { return "Id"; }
        }
        public TransactionType Transaction_type { set; get; }

        public Dictionary<string, FieldInfo> getModelInfo()
        {
            Dictionary<string, FieldInfo> dic = new Dictionary<string, FieldInfo>();
            if (_id != null)
            {
                dic.Add("Id", new FieldInfo(SqlDbType.NVarChar, _id.ToString()));
            }
            if (_password != null)
            {
                dic.Add("Password", new FieldInfo(SqlDbType.NVarChar, _password.ToString()));
            }
            if (_email != null)
            {
                dic.Add("Email", new FieldInfo(SqlDbType.NVarChar, _email.ToString()));
            }
            if (_emailConfirmed != null)
            {
                dic.Add("EmailConfirmed", new FieldInfo(SqlDbType.Bit, _emailConfirmed.ToString()));
            }
            if (_passwordHash != null)
            {
                dic.Add("PasswordHash", new FieldInfo(SqlDbType.NVarChar, _passwordHash.ToString()));
            }
            if (_securityStamp != null)
            {
                dic.Add("SecurityStamp", new FieldInfo(SqlDbType.NVarChar, _securityStamp.ToString()));
            }
            if (_phoneNumber != null)
            {
                dic.Add("PhoneNumber", new FieldInfo(SqlDbType.NVarChar, _phoneNumber.ToString()));
            }
            if (_phoneNumberConfirmed != null)
            {
                dic.Add("PhoneNumberConfirmed", new FieldInfo(SqlDbType.Bit, _phoneNumberConfirmed.ToString()));
            }
            if (_twoFactorEnabled != null)
            {
                dic.Add("TwoFactorEnabled", new FieldInfo(SqlDbType.Bit, _twoFactorEnabled.ToString()));
            }
            if (_lockoutEndDateUtc != null)
            {
                dic.Add("LockoutEndDateUtc", new FieldInfo(SqlDbType.DateTime, _lockoutEndDateUtc.ToString()));
            }
            if (_lockoutEnabled != null)
            {
                dic.Add("LockoutEnabled", new FieldInfo(SqlDbType.Bit, _lockoutEnabled.ToString()));
            }
            if (_accessFailedCount != null)
            {
                dic.Add("AccessFailedCount", new FieldInfo(SqlDbType.BigInt, _accessFailedCount.ToString()));
            }
            if (_userName != null)
            {
                dic.Add("UserName", new FieldInfo(SqlDbType.NVarChar, _userName.ToString()));
            }
            return dic;
        }
    }
}
