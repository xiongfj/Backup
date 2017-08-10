

Func<string, string> lambda = param =>		// 单个参数可以不加括号
{
	param += "sdasd";
	return param;
};


Func<double, double, double> two = (x, y) => x * y;	// 如果只有一条语句才可以不使用 return 语句
Func<double, double, double> two = (double x, double y) => x * y;	// 如果只有一条语句才可以不使用 return 语句
/* 等效于
* 多条语句必须用大括号和 return 语句
Func<double, double, double> two = (x, y) =>
{
	return x * y;
};
*/















