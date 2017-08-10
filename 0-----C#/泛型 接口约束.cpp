using System;
using System.Collections.Generic;

namespace Wrox.ProCSharp.Generics
{
  public class DocumentManager<TDocument>
      where TDocument : IDocument		// 表示类型 TDocument 必须是继承 IDocument 的类型
	  where T : struct		// T 必须是值类型
	  where T : class		// T 必须是引用类型
	  where T : IFoo		// 必须实现接口 IFoo
	  where T : Foo			// 必须派生自基类 Foo
	  where T : new()		// T 必须有一个默认构造函数
	  where T : T2		// 类型 T 必须派生自 T2 类型
	  where T : IFoo, new()		// 可以定义多个约束
	  {
		
	  }

}
