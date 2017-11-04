
from .. in ..
group .. (into) ..
where ..
orderby ..
select ..
	
***** Linq 必须以 from 开头，select 或 group 结尾。

*** 繁星集合
/**
	List<Student> stud = new List<Student>{
		new Student { name ="Mary",age =21,address ="北京"},
		new Student { name ="John",age =37,address ="北京"},
		new Student { name ="Make",age =40,address ="北京"},
		new Student { name ="Rose",age =50,address ="北京"},
		new Student { name ="Peter",age =38,address ="上海"},
		new Student { name ="Hanson",age =30,address ="上海"}
	 };
	 
	IEnumerable<string> studentQuery =
	from s in stud
	where s.address == "北京"
	orderby s.age descending
	select s.name;
	Response.Write("地址在北京的学生有：" + "<br>");
	foreach (var a in studentQuery)
	{
		Response.Write(a + "<br>");
	}
*/

*** 为指定类型的变量 var
/**

	string[] words = { "aPPLE", "BlUeBeRrY", "cHeRry", "HAryY", "lOvE" };
	int i = 0;
	var upperLowerWords =
		from w in words
		select new { Upper = w.ToUpper(), Lower = w.ToLower() };
	foreach (var ul in upperLowerWords)
	{
		Response.Write(words[i] + "单词的大写为: " + ul.Upper + "<BR>");
		Response.Write(words[i] + "单词的小写为:" + ul.Lower + "<BR>");
		i++;
	} 
*/
	 

* from a in b	// a 是范围变量item，b 是数据源， a 是 b 中的一个 itemObj
{
实现交叉表查询:
/*
* 假若有数据:  lists = {obj1, obj2, obj3}
	obj1 = {name="Jack", age=23, skills=["书法","绘画","围棋"]}
	obj2 = {name="Mack", age=23, skills=["书法","围棋"]}
	obj3 = {name="Lie",  age=23, skills=["书法"]}
	-----------------------------------
	语句:
	from r in lists
	from c in r.skills
	select new {obj=r, skill=c}
	-------------------------
	结果:
	obj1, "书法"
	obj1, "绘画"
	obj1, "围棋"
	
	obj2, "书法"
	obj2, "围棋"
	
	obj3, "书法"
*/
}

* where		// && 或 || 连接多个条件
/**
* 可以使用多个并列的 where 
where c == "Ferrari" || c == "Lotus"
**/

* orderby ... descending		//(ascending) 降序、升序
/*
 orderby name, age, salar .. 可以对多个关键词排序
*/

* join
/**
 int arry1 = {2,4,5,7,8,12,73,};
 int arry2 = {5,3,7,2,34,21,23};
 
 var query = from val_1 in arry1
	join val_2 in arry2 on val_1%6 equals val_2%9		/// val_2 是 arry2 中的一个数字
	select new {VAL1 = val_1, VAL2 = val_2 };
*/

* equals		// 等于号 =

* select 	// 多个 select
/*
var countries = (from c in
	 from r in Formula1.GetChampions()
	 group r by r.Country into c
	 select new
	 {
		 Country = c.Key,
		 Wins = (from r1 in c
				 select r1.Wins).Sum()
	 }
 orderby c.Wins descending, c.Country
 select c).Take(5);
 */
* select		// 格式化查询得到的结果; 可以嵌套多个 select 查询	
/**
* 指定结果中包含哪些数据， 
	var result = from a.. select a.age -> 结果只得到 age 集合
	var result = from a in .... select a -> 得到的是对象集合。
	
但是不能这样写： 
	IEnumerable<string> studentQuery = 
	from a in ... select a;			
	// 因为 studentQuery 已经指定的是 string 数据，
	// 必须 select a.name 或 a.address 等 string 数据
	// 也不能 select.age ，因为 age 是数值！
或者可以这样写：
	IEnumerable<Student> studentQuery = 		// Student 是数据源的类型，前提是要知道数据源是什么。..
	from a in ... select a;
	
* var result = from w in words select new { Upper = w.ToUpper(), Lower = w.ToLower() }; 
	// 使用 new 对结果处理后再得到数据。
	// foreach( var i in result )
	{
		Response.Write(i.Upper + " - " + i.Lower);
	}
	
----------------------------------------------
// select r.FirstName + " " + r.LastName; 组合
*  var ferrariDrivers = from r in Formula1.GetChampions()
 from c in r.Cars
 where c == "Ferrari"
 orderby r.LastName
 select r.FirstName + " " + r.LastName;
**/

* into		// 一般用在 group by, join .. in.. on.. 等新集合的后面, 将分组后的数据放进一个集合中,以便后面查询使用
/*
var countries = from r in Formula1.GetChampions()
	group r by r.Country into g
	orderby g.Count() descending, g.Key     // key 就是 by 后面的 r.Country
	where g.Count() >= 2            // 筛选 >= 2 的数据
	select new                      // 封装输出数据
	{
		Country = g.Key,
		Count = g.Count()
	};
*/

* group .. by ..
/**
	var studentQuery = 
	from s in stud
	group s by s.age;

	foreach (var group1 in studentQuery)
	{
		Response.Write(group1.Key + "<br>");    // Key 的值就是分组依据： age
		foreach( var val in group1)
		{
			Response.Write(val.name + " - " + val.age + "<br>" );
		}
		Response.Write("<br>-------------------------<br>");
	}
*/

* let		// 可以定义个变量简化查询语句
/*
var query = from r in Formula1.GetChampions()
	let numberYears = r.Years.Count()
	where numberYears >= 3
	orderby numberYears descending, r.LastName
	select new
	{
		Name = r.FirstName + " " + r.LastName,
		TimesChampion = numberYears
	};
*/
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	