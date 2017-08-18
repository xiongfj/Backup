#region 程序集 mscorlib, Version=4.0.0.0, Culture=neutral, */
		publicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5\mscorlib.dll
#endregion

using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Security.Principal;

/* 申明: 包含一条条用户信息的描述;
* 一个对象对应一个 User , 
* 一个对象包含多条信息集合: IEnumerable<Claim> Claims { get; }
* 一个 Claims 代表一条信息
* Claims 包含信息的详细描述
*/

namespace System.Security.Claims
{
    //
    /*
    //     表示基于声明的标识。
    [ComVisible(true)]
    */
		public class ClaimsIdentity : IIdentity
    {
        //
        /*
        //     默认颁发者;"本地颁发机构"。
        */
		public const string DefaultIssuer = "LOCAL AUTHORITY";
        //
        /*
        //     默认名称声明的类型。 System.Security.Claims.ClaimTypes.Name.
        */
		public const string DefaultNameClaimType = "http://schemas.xmlsoap.org/ws/2005/05/identity/claims/name";
        //
        /*
        //     默认角色声明类型; System.Security.Claims.ClaimTypes.Role.
        */
		public const string DefaultRoleClaimType = "http://schemas.microsoft.com/ws/2008/06/identity/claims/role";

        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 用空类声明集合。
        */
		public ClaimsIdentity();
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类使用从指定的名称和身份验证类型 System.Security.Principal.IIdentity。
        //
        // 参数:
        //   identity:
        //     从要基于新声明的标识的标识。
        */
		public ClaimsIdentity(IIdentity identity);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类使用的枚举的集合 System.Security.Claims.Claim
        //     对象。
        //
        // 参数:
        //   claims:
        //     用来填充声明的标识声明。
        */
		public ClaimsIdentity(IEnumerable<Claim> claims);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 用空类声明集合和指定的身份验证类型。
        //
        // 参数:
        //   authenticationType:
        //     使用的身份验证类型。
        */
		public ClaimsIdentity(string authenticationType);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 使用指定的声明和身份验证类型。
        //
        // 参数:
        //   claims:
        //     用来填充声明的标识声明。
        //
        //   authenticationType:
        //     使用的身份验证类型。
        */
		public ClaimsIdentity(IEnumerable<Claim> claims, string authenticationType);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类使用指定的声明和指定 System.Security.Principal.IIdentity。
        //
        // 参数:
        //   identity:
        //     从要基于新声明的标识的标识。
        //
        //   claims:
        //     用来填充声明的标识声明。
        */
		public ClaimsIdentity(IIdentity identity, IEnumerable<Claim> claims);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类具有指定的身份验证类型、 名称声明类型和角色声明类型。
        //
        // 参数:
        //   authenticationType:
        //     使用的身份验证类型。
        //
        //   nameType:
        //     要使用的名称声明的声明类型。
        //
        //   roleType:
        //     要用于角色声明的声明类型。
        */
		public ClaimsIdentity(string authenticationType, string nameType, string roleType);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类具有指定的声明、 身份验证类型、 名称声明类型和角色声明类型。
        //
        // 参数:
        //   claims:
        //     用来填充声明的标识声明。
        //
        //   authenticationType:
        //     使用的身份验证类型。
        //
        //   nameType:
        //     要使用的名称声明的声明类型。
        //
        //   roleType:
        //     要用于角色声明的声明类型。
        */
		public ClaimsIdentity(IEnumerable<Claim> claims, string authenticationType, string nameType, string roleType);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 从指定的类 System.Security.Principal.IIdentity
        //     使用指定的声明、 身份验证类型、 名称声明类型和角色声明类型。
        //
        // 参数:
        //   identity:
        //     从要基于新声明的标识的标识。
        //
        //   claims:
        //     用来填充新声明的标识声明。
        //
        //   authenticationType:
        //     使用的身份验证类型。
        //
        //   nameType:
        //     要使用的名称声明的声明类型。
        //
        //   roleType:
        //     要用于角色声明的声明类型。
        */
		public ClaimsIdentity(IIdentity identity, IEnumerable<Claim> claims, string authenticationType, string nameType, string roleType);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类序列化的流通过创建从 System.Runtime.Serialization.ISerializable。
        //
        // 参数:
        //   info:
        //     序列化数据。
        [SecurityCritical]
        */
		protected ClaimsIdentity(SerializationInfo info);
        //
        /*
        //     新实例初始化 System.Security.Claims.ClaimsIdentity 类序列化的流通过创建从 System.Runtime.Serialization.ISerializable。
        //
        // 参数:
        //   info:
        //     序列化数据。
        //
        //   context:
        //     序列化的上下文。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     info 为 null。
        [SecurityCritical]
        */
		protected ClaimsIdentity(SerializationInfo info, StreamingContext context);

        // 当前登录的用户名
   		public virtual string Name { get; }
        //
        /*
        //     获取或设置此声明标识的标签。
        //
        // 返回结果:
        //     标签。
        */
		public string Label { get; set; }
        //
        /*
        //     获取与关联的声明此声明标识。
        //
        // 返回结果:
        //     与关联的声明集合此声明标识。
        */
		public virtual IEnumerable<Claim> Claims { get; }
        //
        /*
        //     获取或设置用于创建令牌此声明标识。
        //
        // 返回结果:
        //     启动上下文。
        */
		public object BootstrapContext { get; set; }
        //
        /*
        //     获取或设置调用方授予委派权限的标识。
        //
        // 返回结果:
        //     调用方授予委派权限。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     尝试将该属性设置为当前实例时发生。
        */
		public ClaimsIdentity Actor { get; set; }
        //
        /*
        //     获取一个值，该值指示是否已验证身份。
        //
        // 返回结果:
        //     true 如果标识已经过身份验证;否则为 false。
        */
		public virtual bool IsAuthenticated { get; }
		
        //  获取身份验证类型。 " " 
		// DefaultAuthenticationTypes.ApplicationCookie 之类的
		public virtual string AuthenticationType { get; }
        //
        /*
        //     获取将被解释为在此声明中的.NET Framework 角色声明标识的声明类型。
        //
        // 返回结果:
        //     角色声明类型。
        */
		public string RoleClaimType { get; }
        //
        /*
        //     获取用于确定哪些声明提供的值的声明类型 System.Security.Claims.ClaimsIdentity.Name 属性的声明的身份。
        //
        // 返回结果:
        //     名称声明类型。
        */
		public string NameClaimType { get; }

        // 给用户添加申明;
		// var claimIdentity = UserManager.CreateIdentityAsync(user, DefaultAuthenticationTypes.ApplicationCookie);
		// claimIdentity.AddClaims()..
		public virtual void AddClaim(Claim claim);
		public virtual void AddClaims(IEnumerable<Claim> claims);
        //
        /*
        //     返回一个新 System.Security.Claims.ClaimsIdentity 从复制此声明标识。
        //
        // 返回结果:
        //     当前实例的副本。
        */
		public virtual ClaimsIdentity Clone();
        //
        /*
        //     检索所有具有指定的声明类型的声明。
        //
        // 参数:
        //   type:
        //     要根据其匹配声明的声明类型。
        //
        // 返回结果:
        //     匹配的声明。 列表是只读的。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 为 null。
        */
		public virtual IEnumerable<Claim> FindAll(string type);
        //
        /*
        //     检索指定的谓词匹配的所有声明。
        //
        // 参数:
        //   match:
        //     执行匹配逻辑的函数。
        //
        // 返回结果:
        //     匹配的声明。 列表是只读的。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     match 为 null。
        */
		public virtual IEnumerable<Claim> FindAll(Predicate<Claim> match);
        //
        /*
        //     检索由指定谓词匹配的第一个声明。
        //
        // 参数:
        //   match:
        //     执行匹配逻辑的函数。
        //
        // 返回结果:
        //     为第一个匹配声明，或者，如果找不到任何匹配，则为 null。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     match 为 null。
        */
		public virtual Claim FindFirst(Predicate<Claim> match);
        //
        /*
        //     使用指定的声明类型检索第一个声明。
        //
        // 参数:
        //   type:
        //     要匹配的声明类型。
        //
        // 返回结果:
        //     为第一个匹配声明，或者，如果找不到任何匹配，则为 null。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 为 null。
        */
		public virtual Claim FindFirst(string type);
		
        // 判断是否存在指定的申明 
		public virtual bool HasClaim(string type, string value);
		public virtual bool HasClaim(Predicate<Claim> match);
        //
        /*
        //     尝试删除从声明的标识声明。
        //
        // 参数:
        //   claim:
        //     若要删除声明。
        //
        // 异常:
        //   T:System.InvalidOperationException:
        //     声明不能删除。
        [SecurityCritical]
        */
		public virtual void RemoveClaim(Claim claim);
        //
        /*
        //     尝试删除从声明的标识声明。
        //
        // 参数:
        //   claim:
        //     若要删除声明。
        //
        // 返回结果:
        //     true 如果成功移除了声明;否则为 false。
        [SecurityCritical]
        */
		public virtual bool TryRemoveClaim(Claim claim);
        //
        /*
        //     填充 System.Runtime.Serialization.SerializationInfo 所需数据来序列化当前 System.Security.Claims.ClaimsIdentity
        //     对象。
        //
        // 参数:
        //   info:
        //     要填充数据的对象。
        //
        //   context:
        //     此序列化的目标。 可以为 null。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     info 为 null。
        [SecurityCritical]
        */
		protected virtual void GetObjectData(SerializationInfo info, StreamingContext context);
    }
}