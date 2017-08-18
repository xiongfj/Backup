#region 程序集 mscorlib, Version=4.0.0.0, Culture=neutral, */
		publicKeyToken=b77a5c561934e089
// C:\Program Files\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5\mscorlib.dll
#endregion

using System.Collections.Generic;

namespace System.Security.Claims
{
    //
    /*
    //     表示声明。
    */
		public class Claim
    {
        //
        /*
        //     新实例初始化 System.Security.Claims.Claim 类具有指定的声明类型和值。
        //
        // 参数:
        //   type:
        //     声明类型。
        //
        //   value:
        //     声明值。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 或 value 为 null。
        */
		public Claim(string type, string value);
        //
        /*
        //     新实例初始化 System.Security.Claims.Claim 类，具有指定的声明类型、 值和值类型。
        //
        // 参数:
        //   type:
        //     声明类型。
        //
        //   value:
        //     声明值。
        //
        //   valueType:
        //     声明值类型。 如果此参数为 null，则使用 System.Security.Claims.ClaimValueTypes.String。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 或 value 为 null。
        */
		public Claim(string type, string value, string valueType);
        //
        /*
        //     新实例初始化 System.Security.Claims.Claim 类，具有指定的声明类型、 值、 值类型和颁发者。
        //
        // 参数:
        //   type:
        //     声明类型。
        //
        //   value:
        //     声明值。
        //
        //   valueType:
        //     声明值类型。 如果此参数为 null，则使用 System.Security.Claims.ClaimValueTypes.String。
        //
        //   issuer:
        //     声明颁发者。 如果此参数为空或为 null，则使用 System.Security.Claims.ClaimsIdentity.DefaultIssuer。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 或 value 为 null。
        */
		public Claim(string type, string value, string valueType, string issuer);
        //
        /*
        //     使用指定的声明类型、值、值类型、颁发者、原始颁发者，初始化 System.Security.Claims.Claim 类的新实例。
        //
        // 参数:
        //   type:
        //     声明类型。
        //
        //   value:
        //     声明值。
        //
        //   valueType:
        //     声明值类型。 如果此参数为 null，则使用 System.Security.Claims.ClaimValueTypes.String。
        //
        //   issuer:
        //     声明颁发者。 如果此参数为空或为 null，则使用 System.Security.Claims.ClaimsIdentity.DefaultIssuer。
        //
        //   originalIssuer:
        //     声明的原始颁发者。 如果此参数为空或 null，则将 System.Security.Claims.Claim.OriginalIssuer 属性设置为
        //     System.Security.Claims.Claim.Issuer 属性的值。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 或 value 为 null。
        */
		public Claim(string type, string value, string valueType, string issuer, string originalIssuer);
        //
        /*
        //     使用指定的声明类型、值、值类型、颁发者、原始颁发者和主题，初始化 System.Security.Claims.Claim 类的新实例。
        //
        // 参数:
        //   type:
        //     声明类型。
        //
        //   value:
        //     声明值。
        //
        //   valueType:
        //     声明值类型。 如果此参数为 null，则使用 System.Security.Claims.ClaimValueTypes.String。
        //
        //   issuer:
        //     声明颁发者。 如果此参数为空或为 null，则使用 System.Security.Claims.ClaimsIdentity.DefaultIssuer。
        //
        //   originalIssuer:
        //     声明的原始颁发者。 如果此参数为空或 null，则将 System.Security.Claims.Claim.OriginalIssuer 属性设置为
        //     System.Security.Claims.Claim.Issuer 属性的值。
        //
        //   subject:
        //     此声明说明的主题。
        //
        // 异常:
        //   T:System.ArgumentNullException:
        //     type 或 value 为 null。
        */
		public Claim(string type, string value, string valueType, string issuer, string originalIssuer, ClaimsIdentity subject);

        // 提供声明的认证方名称
		public string Issuer { get; }
        //
        /*
        //     获取声明的原始颁发者。
        //
        // 返回结果:
        //     指的是原始的声明颁发者名称。
        */
		public string OriginalIssuer { get; }
        //
        /*
        //     获取一个字典，其中包含与此声明关联的其他属性。
        //
        // 返回结果:
        //     一个字典，其中包含与声明关联的其他属性。 属性以名称 / 值对的形式表示。
        */
		public IDictionary<string, string> Properties { get; }
		
        // 声明指向的ClaimIdentity 对象
		// 当前申明所属的 ClaimsIdentity
		// Claim_1,Claim_2,Claim_3... 是属于一个 ClaimsIdentity的
		public ClaimsIdentity Subject { get; }
		
        /*   获取声明的声明类型。
		* 是一串 schemas url
		* 常用的值在类 System.Security.Claims.ClaimTypes 内;
        */
		public string Type { get; }
        //
        /*
        //     获取声明的值。
        //
        // 返回结果:
        //     声明值。
        */
		public string Value { get; }
        //
        /*
        //     获取声明的值类型。
        //
        // 返回结果:
        //     声明值类型。
        */
		public string ValueType { get; }

        //
        /*
        //     返回从此对象复制的新 System.Security.Claims.Claim 对象。 新的报销申请不具有使用者。
        //
        // 返回结果:
        //     新的声明对象。
        */
		public virtual Claim Clone();
        //
        /*
        //     返回从此对象复制的新 System.Security.Claims.Claim 对象。 新声明的主题设置为指定的 ClaimsIdentity。
        //
        // 参数:
        //   identity:
        //     新的报销申请预期使用者。
        //
        // 返回结果:
        //     新的声明对象。
        */
		public virtual Claim Clone(ClaimsIdentity identity);
        //
        /*
        //     返回此 System.Security.Claims.Claim 对象的字符串表示形式。
        //
        // 返回结果:
        //     此 System.Security.Claims.Claim 对象的字符串表示形式。
        */
		public override string ToString();
    }
}