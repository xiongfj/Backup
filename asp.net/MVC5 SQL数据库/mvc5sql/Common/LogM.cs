using mvc5sql.Dal;
using mvc5sql.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvc5sql.Common
{
    public class LogM
    {
        #region 登录日志
        /// <summary>
        /// 写登录日志
        /// </summary>
        public static void SaveLoginLog(SYS_LOGIN_LOG log)
        {
            CommonDAL commonbll = new CommonDAL();
            //写数据库
            SYS_LOGIN_LOG loginfo = new SYS_LOGIN_LOG();
            commonbll.Add(log, false);
            //写登陆日志
            //string path = System.Configuration.ConfigurationManager.AppSettings["LoginLogPath"].ToString();
            //string file = Path.Combine(path, string.Format("{0:yyyy-MM-dd}", DateTime.Now) + ".txt");
            //if (!Directory.Exists(path))
            //{
            //    DirectoryInfo d = Directory.CreateDirectory(path);
            //}
            //if (!File.Exists(file))
            //{
            //    FileStream stream = File.Create(file);
            //    stream.Close();
            //}
            //FileInfo fi = new FileInfo(file);
            //using (StreamWriter sw = fi.AppendText())
            //{
            //    string str = "IP地址为XXX的XXX用户在" + DateTime.Now.ToShortTimeString() + "登录" + log.IsOK;
            //    sw.WriteLine(str);
            //    sw.Flush();
            //}
        }
        #endregion
    }
}