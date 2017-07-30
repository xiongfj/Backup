using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebApplication5.Dal;

namespace WebApplication5.Bll
{
    public class CommonBLL : CommonDAL
    {
        public CommonBLL() : base()
        {

        }
    }
    /// <summary>
    /// 事务处理
    /// </summary>
    public class CommonTransBLL : CommonTransDAL
    {
        public CommonTransBLL()
            : base()
        {

        }
    }
}
