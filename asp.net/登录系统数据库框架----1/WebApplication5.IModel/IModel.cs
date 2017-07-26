using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace WebApplication5.IModel
{
    public interface IModel
    {
        /// <summary>
        /// 表名 不可修改 事物专用
        /// </summary>		
        string Transaction_TableName { get; set; }
        string Transaction_PrimaryKey
        {
            get;
            set;
        }
        /// <summary>
        /// 类型 事物专用 1执行添加  2执行修改
        /// </summary>		
        TransactionType Transaction_type
        {
            get;
            set;
        } 

        /// <summary>
        /// 返回model类中的具体信息。
        /// </summary>
        /// <returns></returns>
        Dictionary<string, FieldInfo> getModelInfo();
    }

    public struct FieldInfo
    {
        public FieldInfo(SqlDbType fieldType, string fieldvalue)
        {
            this.fieldType = fieldType;
            this.fieldvalue = fieldvalue;
        }
        public SqlDbType fieldType;     // 必须与数据库内的字段类型一样!!
        public string fieldvalue;
    }

    public class ModelList
    {
        private List<IModel> modelList = new List<IModel>();

        public void Add(IModel model)
        {
            model.Transaction_type = TransactionType.Add;
            modelList.Add(model);
        }
        public void Update(IModel model)
        {
            model.Transaction_type = TransactionType.Update;
            modelList.Add(model);
        }
        public List<IModel> returnModelList()
        {
            return modelList;
        }
        public void Clear()
        {
            modelList.Clear();
        }
    }

    public enum TransactionType
    {
        Add = 1,
        Update = 2
    }
}
