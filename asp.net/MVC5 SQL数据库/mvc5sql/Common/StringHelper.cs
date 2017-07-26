using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Web;

namespace mvc5sql.Common
{
    public class StringHelper
    {
        #region 加密和解密

        const string KEY_64 = "VavicApp";//注意了，是8个字符，64位    
        const string IV_64 = "VavicApp";
        //默认密码hebccc安此种方法加密后的字符串为【uxpK0FuHjTY=】
        #region DEC加密的方法

        /// <summary>
        /// 加密的方法
        /// </summary>
        /// <param name="inputStr"></param>
        /// <returns></returns>
        public string Encode(string inputStr)
        {
            string key_64 = ToMD5(KEY_64);
            string iv_64 = ToMD5(IV_64);
            byte[] byKey = System.Text.ASCIIEncoding.ASCII.GetBytes(key_64);
            byte[] byIV = System.Text.ASCIIEncoding.ASCII.GetBytes(iv_64);

            DESCryptoServiceProvider cryptoProvider = new DESCryptoServiceProvider();
            int i = cryptoProvider.KeySize;
            MemoryStream ms = new MemoryStream();
            CryptoStream cst = new CryptoStream(ms, cryptoProvider.CreateEncryptor(byKey, byIV), CryptoStreamMode.Write);

            StreamWriter sw = new StreamWriter(cst);
            sw.Write(inputStr);
            sw.Flush();
            cst.FlushFinalBlock();
            sw.Flush();
            return Convert.ToBase64String(ms.GetBuffer(), 0, (int)ms.Length);

        }
        /// <summary>
        /// 解密的方法
        /// </summary>
        /// <param name="inputStr"></param>
        /// <returns></returns>
        public string Decode(string inputStr)
        {
            string key_64 = ToMD5(KEY_64);
            string iv_64 = ToMD5(IV_64);
            byte[] byKey = System.Text.ASCIIEncoding.ASCII.GetBytes(key_64);
            byte[] byIV = System.Text.ASCIIEncoding.ASCII.GetBytes(iv_64);

            byte[] byEnc;
            try
            {
                byEnc = Convert.FromBase64String(inputStr);
            }
            catch
            {
                return null;
            }

            DESCryptoServiceProvider cryptoProvider = new DESCryptoServiceProvider();
            MemoryStream ms = new MemoryStream(byEnc);
            CryptoStream cst = new CryptoStream(ms, cryptoProvider.CreateDecryptor(byKey, byIV), CryptoStreamMode.Read);
            StreamReader sr = new StreamReader(cst);
            return sr.ReadToEnd();
        }
        #endregion

        #region MD5加密

        public string ToMD5(string inputStr)
        {
            byte[] result = Encoding.Default.GetBytes(inputStr);
            MD5 md5 = new MD5CryptoServiceProvider();
            byte[] output = md5.ComputeHash(result);

            string outStr = BitConverter.ToString(output).Replace("-", "").Substring(0, 8);
            return outStr;

        }
        #endregion

        #endregion

        #region 将数据库中的数据类型转换成C#
        /// <summary>
        /// 将数据库中的数据类型转换成C#
        /// 对应的类型
        /// </summary>
        /// <param name="dbString">数据库中的字段类型</param>
        /// <returns>返回C#对应的类型</returns>
        public string ConvertDBTypeToDotNetType(string dbString)
        {
            switch (dbString.ToLower())
            {
                case "bigint": return "Int64";
                case "binary": return "Byte[]";
                case "bit": return "Boolean";
                case "char": return "String";
                case "date": return "String";
                case "datetime": return "DateTime";
                case "datetime2": return "String";
                case "datetimeoffset": return "String";
                case "decimal": return "Decimal";
                case "float": return "Double";
                case "geography": return "Byte[]";
                case "geometry": return "Byte[]";
                case "hierarchyid": return "Byte[]";
                case "image": return "Byte[]";
                case "int": return "Int32";
                case "money": return "Decimal";
                case "nchar": return "String";
                case "ntext": return "String";
                case "numeric": return "Decimal";
                case "nvarchar": return "String";
                case "real": return "Single";
                case "smalldatetime": return "DateTime";
                case "smallint": return "Int16";
                case "smallmoney": return "Decimal";
                case "sql_variant": return "Object";
                case "text": return "String";
                case "time": return "String";
                case "timestamp": return "Byte[]";
                case "tinyint": return "Byte";
                case "uniqueidentifier": return "Guid";
                case "varbinary": return "Byte[]";
                case "varchar": return "String";
                case "xml": return "String";
                default: return "Object";
            }
        }
        #endregion

        #region 根据输入的汉子“字符串”获取每一个汉子的首个字母
        /// <summary>
        /// 根据汉子返回一个英文字母
        /// </summary>
        /// <param name="c">一个汉子</param>
        /// <returns></returns>
        private string GetHzPy(string c)
        {
            byte[] array = new byte[2];
            array = System.Text.Encoding.Default.GetBytes(c);
            int i = (short)(array[0] - '\0') * 256 + ((short)(array[1] - '\0'));

            if (i < 0xB0A1) return "*";
            if (i < 0xB0C5) return "A";
            if (i < 0xB2C1) return "B";
            if (i < 0xB4EE) return "C";
            if (i < 0xB6EA) return "D";
            if (i < 0xB7A2) return "E";
            if (i < 0xB8C1) return "F";
            if (i < 0xB9FE) return "G";
            if (i < 0xBBF7) return "H";
            if (i < 0xBFA6) return "J";
            if (i < 0xC0AC) return "K";
            if (i < 0xC2E8) return "L";
            if (i < 0xC4C3) return "M";
            if (i < 0xC5B6) return "N";
            if (i < 0xC5BE) return "O";
            if (i < 0xC6DA) return "P";
            if (i < 0xC8BB) return "Q";
            if (i < 0xC8F6) return "R";
            if (i < 0xCBFA) return "S";
            if (i < 0xCDDA) return "T";
            if (i < 0xCEF4) return "W";
            if (i < 0xD1B9) return "X";
            if (i < 0xD4D1) return "Y";
            if (i < 0xD7FA) return "Z";

            return "*";
        }
        /// <summary>
        /// 根据输入的汉子“字符串”获取每一个汉子的首个字母
        /// </summary>
        /// <param name="text">汉子“字符串”</param>
        /// <returns>每一个汉子的首个字母</returns>
        public string GetPinYinByHanZi(string text)
        {
            string pinyin = string.Empty;
            for (int i = 0; i < text.Length; i++)
            {
                pinyin += GetHzPy(text.Substring(i, 1));
            }
            return pinyin;
        }
        #endregion

        #region 过长截取字符串

        public static string SubLongString(string lStr, int subLength = 40)
        {
            if (lStr.Length > subLength)
            {
                lStr = lStr.Substring(0, subLength) + "...";
            }
            return lStr;
        }
        #endregion
    }
}