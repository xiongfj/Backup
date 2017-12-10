
** 例如：
	(\(\d{3}\)|\d{3}-)?\d{8}		// (123)12345678  123-12345678

------------ 非打印字符 --------------

\n		匹配换行
\r	回车
\f	换页
\t	制表
\v	垂直制表符
\s 	匹配任何空白字符，包括空格、制表符、换页符 .. 等。
\S	匹配任何非空白字符
\w	任何单词字符，包括字母和下划线
\W	任何非单词字符
\b	单词边界，指单词与空格间的位置
\B	单词开头
\d	数字字符，等价于[0-9]
\D	匹配任何一个非数字字符
\\	匹配 \

------------ 特殊字符 ---------------

^	匹配输入字符串的开始位置，除非在方括号表达式中使用，此时它表示不接受该字符集合。
{
/*
	"//[^:]+"  -->  // df:aaaaa 得到结果: "// df"
*/
}

$	匹配输入字符串的结尾位置
*	匹配前面的子表达式 0 次或多次
+	匹配前面的子表达式一次或多次		// 例如： \w+  表示至少出现 1 个以上字符
.	匹配除换行符 \n 之外的任何单字符
?	匹配 0 个或 1 个前面的字符			// 例如：  \d? 表示可以出现一个数字、或者不出现数字	
{	标记限定符表达式的开始
|	指明两者之间的一个选择

----- 如果要匹配上面的特殊字符，需要转移， \^   \*  之类的

{n}		n 是一个非负整数，匹配确定的 n 次	// 例如 \d{3} 表示这里要出现 3 个数字
{n,}	匹配至少出现 n 次前面的字符			// \d{3} 表示必须出现是 3 个或 3+ 个数字
{m,n}	匹配至少 m 个，至多 n 个前面的字符
[xyz]	表示一个字符集和，匹配括号中所包含的任意一个字符
[^xyz]	表示一个否定的字符集合，匹配不在此括号中的任意一个字符
[^m-n]	表示某个范围之外的字符，匹配不在指定范围内的字符
[a-z]	表示一个字符范围，匹配指定范围内的任意字符


------------ 操作符的优先等级 ------------
1、		\
2、		() (?:) (?=) []
3、		* + ？ {n} {n,} {n,m}
4、		^ $ \任何元素、字母
5、		|

--------------------------------------------------
*? 
/*                                                	
重复任意次，但尽可能少重复。
如 "acbacb"  正则  "a.*?b" 只会取到第一个"acb" 原本可以全部取到但加了限定符后，只会匹配尽可能少的字符 ，而"acbacb"最少字符的结果就是"acb" 。
*/
+?	//重复1次或更多次，但尽可能少重复。与上面一样，只是至少要重复1次。

??	
/*
重复0次或1次，但尽可能少重复。
如 "aaacb" 正则 "a.??b" 只会取到最后的三个字符"acb"。*/

{n,m}?	
/*
重复n到m次，但尽可能少重复。
如 "aaaaaaaa"  正则 "a{0,m}" 因为最少是0次所以取到结果为空。*/

{n,}?	
/*
重复n次以上，但尽可能少重复。
如 "aaaaaaa"  正则 "a{1,}" 最少是1次所以取到结果为 "a"。*/

-----------------------------------------------------------------

(exp)    		// 匹配exp,并捕获文本到自动命名的组里。
(?<name>exp)	// 匹配exp,并捕获文本到名称为name的组里。
(?:exp)			// 匹配exp,不捕获匹配的文本，也不给此分组分配组号以下为零宽断言。
(?=exp)	
/*
匹配exp前面的位置。
如 "How are you doing" 正则"(?<txt>.+(?=ing))" 这里取ing前所有的字符，
并定义了一个捕获分组名字为 "txt" 而"txt"这个组里的值为"How are you do";
*/

(?<=exp)	
/*
匹配exp后面的位置。
如 "How are you doing" 正则"(?<txt>(?<=How).+)" 这里取"How"之后所有的字符，
并定义了一个捕获分组名字为 "txt" 而"txt"这个组里的值为" are you doing";
*/

(?!exp)	
/*
匹配后面跟的不是exp的位置。
如 "123abc" 正则 "\d{3}(?!\d)"匹配3位数字后非数字的结果
*/

(?<!exp)	
/*
匹配前面不是exp的位置。
如 "abc123 " 正则 "(?<![0-9])123" 匹配"123"前面是非数字的结果也可写成"(?!<\d)123"
*/

例如:
/*
	static int Main()
	{
		WebClient client = new WebClient();
		string page = Encoding.UTF8.GetString(client.DownloadData("http://www.easyx.cn/help/?line"));
		//Regex r = new Regex(@"(?<=</h3>((.*?)|(\n.*?))<p class=""segp"">).*?(?=</p>)");
		Regex r = new Regex(@"(?<=<p class=""segp"">)(\n|.)*?(?=</p>)");
		MatchCollection mc = r.Matches(page);                       // >

		foreach(Match m in mc)
		{
			string result = Regex.Replace(m.Value, @"<(\n|.)*?>", "");
			string result2 = Regex.Replace(result, @"\n$", "");
			Console.WriteLine(result2);
		}

		Console.WriteLine(page);

		return 0;
	}
*/

------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------

* 验证是否是中文字符：
	using System.Text.RegularExpressions;
	Regex.IsMatch(str,"^[\u4E00-\u9FA5]{0,}$");
	
-------------------------------------------------------------------------------
匹配组:
--------------
// FTP(s) 地址描述格式：ftps://username:password@192.168.1.110:21/asdf/qwer

// 正则匹配组：1.s, 2.username:password@, 3.username, 4.:password, 5.password, 6.192.168.1.110:21, 7.192.168.1.110, 8.:21, 9.21, 10./asdf/qwer
Match m = Regex.Match(ftpaddress, @"^ftp([s]?)://(([^:]+)(:([^@]*))?@)?(([^:/]+)(:(\d+))?)(\S*)", RegexOptions.IgnoreCase);

//从左到右,一个 () 对应一个组,
((1),(2)) 得到三个组 ((1),(2)), (1), (2)









