<<<<<< 模型添加验证属性标签 >>>>>>>>>>>>>>>>>>>>>>>
{
* 模型属性上面添加标签可以验证用户输入
/// 自定义验证信息: 添加参数即可 ErrorMessage="自定义错误信息,"
/** ErrorMessage="{0} Is unvalid"		// {0} 代表当前属性, 显示的时候会使用属性名代替
*
*/

/// 客户端验证://////////////////////////////////////
* [Required]		// 没有提示的验证
* [Required(ErrorMessage="自定义错误信息,")]// 自定义验证信息

* [StringLength(100)]		// 最多 100 字符
* [StringLength(100, MinimumLength=3)]		// 可以 ErrorMessage="自定义错误信息,"

* [RegularExpression(@"exp.")]		// 正则表达式验证, 可以 ErrorMessage="自定义错误信息,"

* [Range(10, 23)]		// 设置数值最大最小, int double, 可以 ErrorMessage="自定义错误信息,"
* [Range(typeof(decimal), "0.00", "45.66")]		// 重载构造函数, 可以给 Date 和 decimal 设置范围

* [Compare("propertyName")]		
/*
// 验证当前输入与指定的 propertyName 是否相同, 
// 可以 ErrorMessage="自定义错误信息,"
*/

/// 服务端验证: 例如需要验证用户名与数据库其它的不能相同
* [Remote("action", "controller")]
public string UserName{get; set;}		// 把该值发送到服务端某控制器的 action 方法

/// 使用资源文件显示错误信息, 用于国际化语言标准, 不同国家显示不同的语言
* [Required(ErrorMessageResourceType=typeof(ErrorMessages), 
	ErrorMessageResourceName="LastNameRequired")]	// 表示显示资源文件ErrorMessages.resx 内的 LastNameRequired 条目作为验证信息显示