using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            setMethod();
        }

        // 默认值获取公有成员
        public static void getPublicMember()
        {
            Type t = typeof(RefClass);
            MemberInfo[] minfos = t.GetMembers();   // 会获取父类的成员
            foreach (MemberInfo minfo in minfos)
            {
                Console.WriteLine(minfo.Name);
            }
            Console.ReadKey();
        }

        // 获取非公有成员
        public static void getPrivateMember()
        {
            Type t = typeof(RefClass);
            MemberInfo[] minfos = t.GetMembers( BindingFlags.NonPublic 
                                                | BindingFlags.Instance         // 不知道是什么? 必须设置这个!?
                                                | BindingFlags.Static           // 显示静态成员
                                                | BindingFlags.Public 
                                                | BindingFlags.DeclaredOnly);   // 过滤掉父类成员
            foreach (MemberInfo minfo in minfos)
            {
                Console.WriteLine(minfo.Name);
            }
            Console.ReadKey();
        }

        // 辨别是方法还是属性.. 其它
        public static void getKind()
        {
            Type t = typeof(RefClass);

            // 等效与 String getType(MemberTypes){ .. }
            Func<MemberTypes, String> getType = (x) =>
            {
                switch (x)
                {
                    case MemberTypes.Field:
                        {
                            return "字段";
                        }
                    case MemberTypes.Method:
                        {
                            return "方法";
                        }
                    case MemberTypes.Property:
                        {
                            return "属性";
                        }
                    default:
                        {
                            return "未知";
                        }
                }
            };
            MemberInfo[] minfos = t.GetMembers(BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Public | BindingFlags.DeclaredOnly | BindingFlags.Static);
            foreach (MemberInfo minfo in minfos)
            {
                Console.WriteLine(minfo.Name + ";类型:" + getType(minfo.MemberType));
            }
            Console.ReadKey();
        }

        // 只获取字段
        public static void getField()
        {
            Type t = typeof(RefClass);
            FieldInfo[] finfos = t.GetFields(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            foreach (FieldInfo finfo in finfos)
            {
                Console.WriteLine("字段名称：{0}  字段类型:{1} ", finfo.Name, finfo.FieldType.ToString());
            }
            Console.ReadKey();
        }

        // 获取字段值
        public static void getFieldValue()
        {
            Type t = typeof(RefClass);

            RefClass rc = new RefClass();
            rc.id = 3;

            FieldInfo[] finfos = t.GetFields(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            foreach (FieldInfo finfo in finfos)
            {
                // 一次获取各个字段的值, 包括非公有字段
                Console.WriteLine("字段名称：{0}  字段类型:{1} rc中的值为:{2}", 
                                    finfo.Name, 
                                    finfo.FieldType.ToString(),
                                    // finfo.FieldType.Name.ToString(), 
                                    finfo.GetValue(rc));
            }
        }

        // 重新设置字段值
        public static void setValue()
        {
            Type t = typeof(RefClass);
            RefClass rc = new RefClass();
            rc.id = 3;

            FieldInfo[] finfos = t.GetFields(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            foreach (FieldInfo finfo in finfos)
            {
                // 判断字段类型赋值
                if (finfo.FieldType.Name.Equals("Int32"))
                    finfo.SetValue(rc, 100);
                else if (finfo.FieldType.Name.Equals("String"))
                    finfo.SetValue(rc, "hello world!");
                // else if ...

                Console.WriteLine("字段名称：{0}  字段类型:{1} rc中的值为:{2}",
                    finfo.Name,
                    finfo.FieldType.Name,//.ToString(),
                    finfo.GetValue(rc));
            }
        }

        // 操作 get set 属性, 获取get,set方法的各种参数,类型,返回类型等信息
        public static void setProperty()
        {
            Type t = typeof(RefClass);
            RefClass rc = new RefClass();
            rc.id = 3;

            PropertyInfo[] finfos = t.GetProperties(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            foreach (PropertyInfo finfo in finfos)
            {
                // 获取 get 方法
                MethodInfo getinfo = finfo.GetGetMethod(true);
                Console.WriteLine("get方法的名称{0}  返回值类型:{1}  参数数量:{2}  MSIL代码长度:{3} 局部变量数量:{4}", 
                    getinfo.Name,                   // 属性的方法名
                    getinfo.ReturnType.ToString(),  // 属性类型,也是方法返回类型
                    getinfo.GetParameters().Count(),        // 参数个数, get=0; set=1
                    getinfo.GetMethodBody().GetILAsByteArray().Length,  //
                    getinfo.GetMethodBody().LocalVariables.Count);      // 局部变量个数

                // 获取 set 方法
                MethodInfo setinfo = finfo.GetSetMethod(true);
                Console.WriteLine("get方法的名称{0}  返回值类型:{1}  参数数量:{2}  MSIL代码长度:{3} 局部变量数量:{4}", 
                    setinfo.Name, 
                    setinfo.ReturnType.ToString(),
                    setinfo.GetParameters().Count(),
                    setinfo.GetMethodBody().GetILAsByteArray().Length,
                    setinfo.GetMethodBody().LocalVariables.Count);

                /*if ( finfo.PropertyType.Name.Equals("Int32") || finfo.PropertyType.Name.Equals("Double"))
                    setinfo.Invoke(rc, new object[] { 123 });
                else if (finfo.PropertyType.Name.Equals("String"))
                    setinfo.Invoke(rc, new object[] { "hello world!" });*/

                // 设置属性值, 自动根据属性类型转换
                setinfo.Invoke(rc, new Object[] { Convert.ChangeType(123456, finfo.PropertyType, CultureInfo.CurrentCulture) } );

                // 获取属性值
                object obj = getinfo.Invoke(rc, null);
                Console.WriteLine("方法名:{0}  内部值:{1} \n", finfo.Name, obj);
            }
        }

        // 另一种方法设置属性值
        public static void setPropertyValue()
        {
            Type t = typeof(RefClass);
            RefClass rc = new RefClass();
            rc.id = 3;

            PropertyInfo[] finfos = t.GetProperties(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            foreach (PropertyInfo finfo in finfos)
            {
                if ( finfo.CanWrite )
                    finfo.SetValue(rc, Convert.ChangeType(12389, finfo.PropertyType, CultureInfo.CurrentCulture), null);

                Object obj = finfo.GetValue(rc);
                Console.WriteLine("{0} - {1} \n", obj, finfo.Name);
            }
        }

        //
        public static void setMethod()
        {
            Type t = typeof(RefClass);
            RefClass rc = new RefClass();
            rc.id = 3;

            // 包括 get 和 set 和 正常的方法
            MethodInfo[] finfos = t.GetMethods(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly | BindingFlags.Static);
            foreach (MethodInfo finfo in finfos)
            {
               // Console.WriteLine("{0} \n", finfo.ReturnType.Name);
                //if (finfo.GetParameters().Count() > 0 && finfo.GetParameters()[0].ParameterType == typeof(string))

                // 不能是 get 或 set 方法!!!
                if (finfo.GetParameters().Count() > 0 && finfo.ReturnType.Name.Equals("String") )
                {
                    // 传递参数到非 set 方法, 不能传递给 set 方法
                    object obj = finfo.Invoke(rc, new[] { "123" });
                 //  object obj = finfo.Invoke(rc, new Object[] { Convert.ChangeType(123456, finfo.GetParameters()[0].ParameterType, CultureInfo.CurrentCulture) });

                    MethodBody mbody = finfo.GetMethodBody();
                    Console.WriteLine("拥有参数的方法名:{0}  返回值类型:{1}  参数1类型:{2}  参数1名称:{3}  方法调用后返回的值:{4}",
                        finfo.Name,
                        finfo.ReturnType.ToString(),
                        finfo.GetParameters()[0].ParameterType.ToString(),
                        finfo.GetParameters()[0].Name,
                        obj.ToString());
                }
                else
                {
                    MethodBody mbody = finfo.GetMethodBody();
                    Console.WriteLine("没有参数的方法名:{0}  返回值类型:{1}",
                        finfo.Name,
                        finfo.ReturnType.ToString());
                }
            }
        }
    }
}
