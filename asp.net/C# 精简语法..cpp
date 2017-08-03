
-----------------------------------------------------------------------

* 有如此格式化字符串操作
/*
var title="aasd";
var firstName = "sf";
var lastName = "amck";
var fullName = String.Format("{0] {1] {2]", title, firstName, lastName);
*/

* 可以写成下面更加简洁的语法
// var fullName = $"{title} {firstName} {lastName}";

--------------------------------------------------------------------------

* 假如有类的属性初始化 /*
public class Customer
{
    public int Id { get; set; }
    public ICollection<Order> Orders { get; set; }
    public DateTime DateCreated { get; set; }

    public Customer()
    {
        Orders = new List<Order>();
        DateCreated = DateTime.UtcNow;
    }
}
*/

* 可以简写成: /*
public class Customer  
{
    public int Id { get; set; }
    public ICollection<Order> Orders { get; set; } = new List<Order>();
    public DateTime DateCreated { get; set; } = DateTime.UtcNow;
}
*/

--------------------------------------------------------------------------


* 使用 lambda 表达式简化属性,方法 /*
public class SalesPerson  
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public decimal TotalSales { get; set; }
    public string FullName => $"{FirstName} {LastName}";
    public decimal CalculateCommission (decimal percentage) => TotalSales * percentage / 100; 
}
*/

---------------------------------------------------------------------------------

* 获取函数名称/*
public static string GetNameOfProperty<TSource, TProperty>(
	TSource source, 
	Expression<Func<TSource, TProperty>> lambdaOfProperty )		// lambdaOfProperty 对应 TProperty 类型
{
	var memberExpression = lambdaOfProperty.Body as MemberExpression;
	
	//in a production app we check for null as
	//the code might point to a public method
	var name = memberExpression.Member.Name;

	return name;
}
*/

* 可以简写成:/*
public void LogError(string message, [CallerMemberName]string caller = null)
{
    Logger.Error($"Error in {caller} - {message}");
    Logger.Error($"Failed to call {nameof(Save??)} due to error {message}");
}
*/


















