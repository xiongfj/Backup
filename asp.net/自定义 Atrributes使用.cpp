using System.Attribute


/*
* Attribute类似于标签
* 可以为类，方法，结构体，属性，委托等贴上标签
* 在以后的实际执行时候，根据不同的标签做不同的处理
*/

//* 例如:

[Serializable]
public class Animal{...}		// 说明该类可以序列化
 ------
[Serialized]
public class Boy
{
	string name;		
	
	[NonSerialized]
	int age {get; set;};	// 该类可以序列化,但是这个属性会跳过, 不将它加入序列化
}

---------------------------------------------------

// 如何自定义 Attribute

//1. 自定义一个类 XXAttribute，继承自System.Attribute.
//2. XXAttribute的名字, 一般以 Attribute 结尾. 使用的时候只需要写 XX 部分即可, [XX]
//3. Attribute类在定义的时候，可以指定这个Attribute的应用范围，
//		AttributeTargets枚举就列出了可以指定的范围，可以是class, field…… 多个值使用 | 隔开
//		例如: 
		[AttributeUsage(AttributeTargets.All)]
		public class AcronymAttribute : Attribute
		{
		}
		
---------------------------------------------------------------------
// demo

// BlockAttribute.cs
namespace AttributeDemo
{
	[AttributeUsage(AttributeTargets.Class)]//指定Attribute的使用范围，只能在class级别使用
	public class BlockAttribute : Attribute
	{
		public Level Level
		{
		  get;
		  set;
		}
	  
		//在实例化的时候，就指定Block是Yes还是No
		public BlockAttribute(Level level)
		{
		  Level = level;
		}
	}

	public enum Level
	{
		NO,
		Yes
	}
}

// GovermentSay.cs
namespace AttributeDemo
{
	[Block(Level.Yes)]	// 会调用构造函数
	public class GovermentSay : ISay
	{
		public string Say()
		{
		   return "Our country is the most democratic country";
		}
	}
}

// PeopleSay.cs
namespace AttributeDemo
{
	[Block(Level.NO)]
	public class PeopleSay : ISay
	{
		public string Say()
		{
			return "We need rights";
		}
	}
}

// 检测是那个 ISay 在说话
// 可以用于过滤言论之类的功能
public class ThePress
{
   public static void Print(ISay say)
   {
	   System.Reflection.MemberInfo info = say.GetType();
	   
	   // 使用 System.Attribute.IsDefined(..) 代替 GetCustomAttribute 比较好
	   BlockAttribute att=
			(BlockAttribute)Attribute.GetCustomAttribute(info, typeof(BlockAttribute));
			
	   if (att.Level == Level.Yes)//如果标签是Yes
		   Console.WriteLine(say.GetType().ToString() + ": " + say.Say());
		   
	   else//如果是No
		   Console.WriteLine(say.GetType().ToString() + ": " + "I Love the country!");
   }
}




















































