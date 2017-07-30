



1.AutoMapper.Mapper.Map		// 实现不同对象内部相同数据的转换
/*
using AutoMapper;
obj1 = Mapper.Map(obj2)

* 一般在 Global.asax 内初始化:
	//AutoMapper配置
	AutoMapperConfig.Configure();
	
------------- 同时 App_Start 自己定一个文件,内部写下面这个类
[Description("AutoMapper配置")]
    public class AutoMapperProfile : AutoMapper.Profile
    {
        protected override void Configure()
        {
            CreateMap<ApplicationPermission, PermissionViewModel>();
            CreateMap<RoleViewModel, ApplicationRole>()
                .ForMember(
                            dest => dest.Id,
                            sour =>
                            {
                                sour.MapFrom(s => s.Id ?? System.Guid.NewGuid().ToString());
                            });
		.....
        }
    }

    [Description("AutoMapper匹配")]
    public class AutoMapperConfig
    {
        public static void Configure()
        {
            AutoMapper.Mapper.Initialize(cfg =>
            {
                cfg.AddProfile<AutoMapperProfile>();
            });
        }
    }
*/

2.MVC return Views() 分页
/* 该方法是 ebdiyer.WebControls.Mvc.PageLinqExtensions 内对IEnumberable<T> 和 IQueryable<T> 的扩展方法
	views 是一个 IList<xxModel> 或继承自 IEnumberable<T> 或 IQueryable<T> 的类对象
	//分页
	return View(views.ToPagedList(index, 10));
*/ 

3.List<T> 排序
/*
var list = new List<xxModel>();
list.Add(..);
..
list.Sort(new TCompare());
其中:
public class TCompare : IComparer<xxModel>
{
	public int Compare(xxModel x, xxModel y)
	{
		// 返回 0 , 相等
		...这里还可以比较其他属性
		return string.Compare(x.property, y.property, true) 	// 比较各自属性
	}
}
*/

4.AutoMapper.EnumerableExtensions.Each<T>		// 遍历并转换
/* Each<T>(this IEnumerable<T> items, Action<T> action); 是 IEnumerable<T> 扩展方法
	list_1 是一个存有数据的 List<Model_1>
	var list_2 = new List<Model_2>();
	
	// 遍历每一个 Model_1 同时实现转换
	list_1.Each(t =>
	{
		var view = Mapper.Map<Model_2>(t);
		list_2.Add(view);
	});
*/

5.获取M,V,C信息:
/*
var types = Assembly.Load("AspNetIdentity2Permission.Mvc").GetTypes();	//取得所有在这个命名空间下的类
//取控制器
foreach (var type in types)
{
	if (type.BaseType == typeof(BaseController))//如果是BaseController                
	{
		//反射控制器
		var controller = new ReflectedControllerDescriptor(type);
		//取控制器的Action,共有实例方法
		var actions = controller.GetCanonicalActions();
		//构建权限
		foreach (var action in actions)
		{
			//创建权限
			var ap = new ApplicationPermission()
			{
				Action = action.ActionName,
				Controller = controller.ControllerName,
				//Params = FormatParams(action),
				Description = GetDescription(action)
			};
			result.Add(ap);
		}
	}
}
*/

6.IEnumerable 取差运算
/* System.Linq.Enumerable
public static IEnumerable<TSource> Except<TSource>(this IEnumerable<TSource> first, 		// 是一个扩展方法
															IEnumerable<TSource> second, 
															IEqualityComparer<TSource> comparer);
    
------------------------
	var allModels = new List<Model>();
	addlModels.Add(..):
	...
	
	var someModels = func();		// func() 自定义函数, 返回一个 List<Model> 或其他 IEnumerable<Model>
	
	// 此时假设是 comeModels 是 allModels 的子集
	// 获得差集
	var subModels = allModels.Except(someModels, new Comparer());
	
------- Comparer 类
public class Comparer : IEqualityComparer<ApplicationPermission>
{
	public bool Equals(Model x, Model y)
	{
		if(string.compare(x.name, y.name, true)==0)
			return true;	// 相等
		...
		
		return false; // 不相等
	}
	
	public int GetHashCode(Model obj)
	{
		var str = string.Format("{0}-{1}-{2}", obj.property_1, obj.property_2, obj_...);
		return str.GetHashCode();		// 不知道有什么用
	}
}
*/




































