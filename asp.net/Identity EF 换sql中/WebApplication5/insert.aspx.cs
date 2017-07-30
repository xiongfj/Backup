using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication5.Bll;
using WebApplication5.Model;

/// <summary>
/// 模拟事务插入数据
/// </summary>

namespace WebApplication5
{
    public partial class insert : System.Web.UI.Page
    {
        CommonTransBLL tran = new CommonTransBLL();
        CommonBLL bll = new CommonBLL();
        string sql_1 = "insert into USERINFO values ('fammtho043', '640B1472')";
        string sql_2 = "select username from USERINFO where Id>3";
        string sql_3 = "select * from USERINFO where id > 3";
        string sql_4 = "insert into USERINFO values ('new_name', '0000000')";
        string sql_5 = "insert into USERINFO values ('new_user', 'aaaaaaaaaaa')";

        protected void Page_Load(object sender, EventArgs e)
        {

        } 
        protected void btn3_click(object sender, EventArgs e)
        {
            DataTable table = bll.ExecuteTable(sql_3);
            result.Text = table.Rows[0]["username"].ToString();
        }
        protected void btn4_click(object sender, EventArgs e)
        {
            USER_INFO model = new USER_INFO();
            model.username = "hello-" + new Random().Next(1000);    // 返回1000以内的随机数
            model.password = "670B1472";
            object result = bll.Add(model, false);
            Response.Write("<script>alert('" + result + "')</script>");
        }
        protected void btn5_click(object sender, EventArgs e)
        {
            USER_INFO model = new USER_INFO(13, "new_name", "670B1472");
            int result = bll.Update(model);
            Response.Write("<script>alert('" + result + "')</script>");
        }
        protected void btn6_click(object sender, EventArgs e)
        {
            USER_INFO model = new USER_INFO("new_name2", "089892089");
            int result = bll.Update(model, "username = 'hello'");
            Response.Write("<script>alert('" + result + "')</script>");
        }
        protected void btn7_click(object sender, EventArgs e)
        {
            int result = bll.ExecuteNonQuery(sql_4);
            Response.Write("<script>alert('" + result + "')</script>");
        }
        protected void btn8_click(object sender, EventArgs e)
        {
            object obj = bll.ExecuteScalar("select username from USERINFO where id > 18");
            if ( obj != null && obj != System.DBNull.Value )
                Response.Write("<script>alert('" + Convert.ToString(obj) + "')</script>");
            else
                Response.Write("<script>alert('没有查询到数据!')</script>");
        }

        //--------------- 存储过程测试 --------------------------------------------------------
        protected void produre_click_1(object sender, EventArgs e)
        {
            DataSet set = bll.RunProcedure("Procedure_1", null, "table_1");
            string username = set.Tables["table_1"].Rows[0][0].ToString();
            Response.Write("<script>alert('" + username + "')</script>");
        }
        protected void produre_click_3(object sender, EventArgs e)
        {
            SqlDataReader reader = (SqlDataReader)bll.RunSqlDataReaderProcedure("Procedure_3", null);
            if ( reader != null && reader.Read())
            {
                Response.Write("<script>alert('" + reader[0] + " - " + reader[1] + "')</script>");
            }
            reader.Close();
        }
        protected void produre_click_4(object sender, EventArgs e)
        {
            DataTable table = bll.RunSqlDataTableProcedure("Procedure_4", null);
            if ( table.Rows.Count > 0 )
                Response.Write("<script>alert('" + table.Rows[0][0] + "')</script>");
            else
                Response.Write("<script>alert('没有查询到数据!')</script>");
        }
        protected void produre_click_5(object sender, EventArgs e)
        {
            SqlParameter[] paramArray = {   new SqlParameter("@uname", SqlDbType.NVarChar, 50),
                                            new SqlParameter("@pword", SqlDbType.NVarChar, 50)};
            paramArray[0].Value = "produre_name";
            paramArray[1].Value = "j15729xiongfj";
            int rowsAffected = 0;
            int result = bll.ProcedureExecuteNonQuery("Procedure_5", paramArray, out rowsAffected);
            Response.Write("<script>alert('" + rowsAffected + " - " + result + "')</script>");
        }
        protected void produre_click_6(object sender, EventArgs e)
        {
            SqlParameter[] paramArray = { new SqlParameter("@Output_Value", SqlDbType.Int) };
            paramArray[0].Direction = ParameterDirection.Output;
            object obj = bll.ProcedureExecuteNonQuery("Procedure_6", paramArray );
            Response.Write("<script>alert('" + obj.ToString() + "')</script>");
        }

        //-------------------- 事务测试 ----------------------------------------

        protected void trans_click_1(object sender, EventArgs e)
        {
            string name = txtname.Value.Trim();

            USER_INFO user_info = new USER_INFO();
            user_info.username = name;
            user_info.password = "670B1472";
            tran.BeginTransaction();
            try
            {
                int id = tran.AddTrans(user_info, true);
                tran.Commit();
                Response.Write("<script>alert('" + id + "')</script>");
            }
            catch
            {
                tran.RollBack();
            }

        }
        protected void trans_click_2(object sender, EventArgs e)
        {
            List<IModel.IModel> list = new List<IModel.IModel>();
            list.Add(new USER_INFO("list_name_1", "125673498"));
            list.Add(new USER_INFO("list_name_2", "125673498ffsdf"));
            tran.BeginTransaction();
            try
            {
                int result = tran.AddList(list, false);
                tran.Commit();
                Response.Write("<script>alert('" + result + "')</script>");
            }
            catch(SqlException ex)
            {
                tran.RollBack();
                throw ex;
            }
        }
        protected void trans_click_3(object sender, EventArgs e)
        {
            USER_INFO model_1 = new USER_INFO("modelist_23", "123456");
            USER_INFO model_2 = new USER_INFO("modelist_2", "123456zxcv");
            tran.ModelList.Add(model_1);
            tran.ModelList.Add(model_2);

            bool resu = tran.TransactionModel();
            Response.Write("<script>alert('插入结果: " + resu + "')</script>");
        }
        protected void trans_click_4(object sender, EventArgs e)
        {
            string[] list = { sql_1, sql_4, sql_5 };
            bool result = tran.TransactionSql(list);
            Response.Write("<script>alert('插入结果: " + result + "')</script>");
        }
        protected void trans_click_5(object sender, EventArgs e)
        {
            USER_INFO model = new USER_INFO(22, "new_name", "assword000");
            tran.BeginTransaction();
            try
            {
                int result = tran.Update(model);
                tran.Commit();
                Response.Write("<script>alert('结果: " + result + "')</script>");
            }
            catch(SqlException ex)
            {
                tran.RollBack();
                Response.Write("<script>alert('更新失败!')</script>");
            }
        }
        protected void trans_click_6(object sender, EventArgs e)
        {
            tran.BeginTransaction();
            try
            {
                object obj = tran.ExecuteScalarTrans(sql_2);
                tran.Commit();
                Response.Write("<script>alert('" + obj + "')</script>");
            }catch(SqlException ex)
            {
                tran.RollBack();
                throw ex;
            }
        }
        protected void trans_click_7(object sender, EventArgs e)
        {
            USER_INFO model = new USER_INFO("new_name_xxx", "assword000");
            tran.BeginTransaction();
            try
            {
                int result = tran.Update(model, "username = 'P'");
                tran.Commit();
                Response.Write("<script>alert('更新行数: " + result + "')</script>");
            }
            catch (SqlException ex)
            {
                tran.RollBack();
                Response.Write("<script>alert('更新失败!')</script>");
            }
        }
        protected void trans_click_8(object sender, EventArgs e)
        {
            tran.BeginTransaction();
            try
            {
                int result = tran.Delete("USERINFO", "username != 'admin' AND username != 'guest' AND username != 'anglebaby'");
                Response.Write("<script>alert('删除记录数量: " + result + "')</script>");
                tran.Commit();
            }catch(SqlException ex)
            {
                tran.RollBack();
                Response.Write("<script>alert('删除失败!')</script>");
            }
        }
        protected void trans_click_9(object sender, EventArgs e)
        {
            string sql_x = "insert into USERINFO values ('new_user_1', '640B1472' ); select @@Identity;";
            tran.BeginTransaction();
            try
            {
                object obj = tran.ExecuteScalarTrans(sql_x);
                tran.Commit();
                if ( obj != null )
                    Response.Write("<script>alert('" + obj.ToString() + "')</script>");
                else
                    Response.Write("<script>alert('obj = null')</script>");
            }
            catch(SqlException ex)
            {
                tran.RollBack();
            }
        }
    }
}