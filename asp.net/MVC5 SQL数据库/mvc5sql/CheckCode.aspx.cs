using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace mvc5sql
{
    public partial class CheckCode : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // 多少个验证字符
            int length = 4;
            string strKey = CheckingCode(length);

            // out 也是引用，传递的参数可以不初始化，申明和调用都必须带out
            // ref 表示引用传递参数，原来的值会在函数内被改变，ref这里可不写
            byte[] data = CreateCheckCode(length, ref strKey);

            Response.Cache.SetNoStore();        // 不缓存该页面, 防止浏览器后退操作不刷新验证码
           // Response.Expires = 0;
            //Response.CacheControl = "no-cache";

            Response.OutputStream.Write(data, 0, data.Length);
        }
        public string CheckingCode(int length)
        {
            string strResult = "";
            // 采用的字符集，可以随即拓展，并可以控制字符出现的几率
            string strCode = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            Random rd = new Random();
            for (int i = 0; i < length; i++)
            {
                char c = strCode[rd.Next(strCode.Length)];
                // 随机获取字符
                strResult += c.ToString();
            }
            Session["CheckCode"] = strResult;
            return strResult;
        }

        public byte[] CreateCheckCode(int nLen, ref string strKey)
        {
            int nBmpWidth = 13 * nLen + 15;   // 图片宽度，能容纳完
            int nBmpHeight = 25;

            // 定义一个 Bitmap
            System.Drawing.Bitmap bmp = new System.Drawing.Bitmap(nBmpWidth, nBmpHeight);

            // 生成随机背景颜色
            int nRed, nGreen, nBlue;

            // 生成三元色[128 - 255]
            System.Random rd = new Random((int)System.DateTime.Now.Ticks);
            nRed = rd.Next(255) % 128 + 128;
            nGreen = rd.Next(255) % 128 + 128;
            nBlue = rd.Next(255) % 128 + 128;

            // 创建 Bitmap 的画布
            System.Drawing.Graphics graph = System.Drawing.Graphics.FromImage(bmp);
            graph.FillRectangle(new System.Drawing.SolidBrush(System.Drawing.Color.AliceBlue), 0, 0, nBmpWidth, nBmpHeight);

            // 绘制干扰线条，采用比背景略深一些的颜色
            int nLines = 3;
            System.Drawing.Pen pen = new System.Drawing.Pen(System.Drawing.Color.FromArgb(nRed - 17, nGreen - 17, nBlue - 17), 2);
            for (int a = 0; a < nLines; a++)
            {
                // 随机位置、随机长度的直线
                int x1 = rd.Next(nBmpWidth);
                int y1 = rd.Next(nBmpHeight);
                int x2 = rd.Next(nBmpWidth);
                int y2 = rd.Next(nBmpHeight);
                graph.DrawLine(pen, x1, y1, x2, y2);
            }
            //画图片的前景噪音点
            for (int i = 0; i < 100; i++)
            {
                int x = rd.Next(bmp.Width);
                int y = rd.Next(bmp.Height);

                bmp.SetPixel(x, y, System.Drawing.Color.FromArgb(rd.Next()));   // 像素点颜色
            }

            // 确定字体
            System.Drawing.Font font = new System.Drawing.Font("Courier New", 14 + rd.Next() % 4, System.Drawing.FontStyle.Bold);

            // 渐变画刷
            System.Drawing.Drawing2D.LinearGradientBrush brush = new System.Drawing.Drawing2D.LinearGradientBrush(
                new System.Drawing.Rectangle(0, 0, bmp.Width, bmp.Height), System.Drawing.Color.Blue, System.Drawing.Color.DarkRed, 1.2f, true);

            graph.DrawString(strKey, font, brush, 2, 2);

            // 输出字节流
            System.IO.MemoryStream stream = new System.IO.MemoryStream();
            bmp.Save(stream, System.Drawing.Imaging.ImageFormat.Jpeg);
            bmp.Dispose();
            graph.Dispose();
            byte[] byteReturn = stream.ToArray();
            stream.Close();
            return byteReturn;
        }
    }
}