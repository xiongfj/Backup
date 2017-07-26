using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/// <summary>
/// 用于给 Orcal 或 Sql 数据库自定义的类继承,
/// 成员函数使用 DbParameter[] 返回,兼容orcal和sql
/// 
/// </summary>

namespace mvc5sql.SqlHelper
{
    internal interface ISqlStrFactory
    {
        // 接口函数不能有 publi\protected 之类修饰符
        System.Data.Common.DbParameter[] SetSql_Add(IModel.IModel model, ref string sql);
        System.Data.Common.DbParameter[] SetSql_Update(IModel.IModel model, ref string sql);
        System.Data.Common.DbParameter[] SetSql_Update(IModel.IModel model, string updateWhere, ref string sql);
    }
}
