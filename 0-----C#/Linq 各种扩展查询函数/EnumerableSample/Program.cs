using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;

namespace Wrox.ProCSharp.LINQ
{
    public static class StringExtension
    {
        public static string FirstName(this string name)
        {
            int ix = name.LastIndexOf(' ');
            return name.Substring(0, ix);
        }
        public static string LastName(this string name)
        {
            int ix = name.LastIndexOf(' ');
            return name.Substring(ix + 1);
        }
    }

    class Program
    {
        static void Main()
        {
            // Filtering();
            // IndexFiltering();
            // TypeFiltering();
            //CompoundFrom();
            // Sorting();
            // GroupByMethod();
            // Grouping();
            //GroupingWithNestedObjects();
            // InnerJoin();
            //InnerJoinMethod();
            // LeftOuterJoin();
           // GroupJoinLinq();
             //GroupJoin2();
             // SetOperations();
              Except();
             // ZipOperation();
             // Partitioning();
             /// Aggregate();
             // Aggregate2();
             // Untyped();
             // CombineRacers();
             // SelectMany();
             //SelectMany2();
        }

        // SelectMany 交叉表查询
        private static void SelectMany()
        {
            var ferrariDrivers = Formula1.GetChampions().

                /* c 是 r.Cars 里面的 item
                 * 实现交叉表查询, 结果集合 s1 格式:
                 *    Racer    Car
                 * --------------------
                 * {Racer_1, "Ferrari"},            // 将 Racer 与其内部 Cars 的每个 Car 交叉的结果
                 * {Racer_1, "Lotus"},
                 * {Racer_2, "Cooper"},
                 * {Racer_3, "Ferrari"},
                 * {Racer_3, "Williams"}
                 * ...
                */
                SelectMany(r => r.Cars, (r, c) => new { Racer = r, Car = c }).

                /*
                 * 这里的 r 是 SelectMany(..) 的结果 s1
                 * 
                 */
                Where(r => (r.Car == "Ferrari" || r.Car == "Lotus")).
                Select(r => r.Racer.FirstName + " -- " + r.Racer.LastName + " - " + r.Car);

            foreach(var item in ferrariDrivers)
            {
                Console.WriteLine("{0}", item);
            }

            // 结果与下面的两个 from 相同
            /*
             var ferrariDrivers = from r in Formula1.GetChampions()
                                 from c in r.Cars       // 相当于交叉表一样, 如果 Cars 有多个 Ferrari, 结果就会重复出现几次
                                 where c == "Ferrari" || c == "Lotus"
                                 select r.FirstName + " -- " + r.LastName + " - " + c;
            */
        }

        // 筛选多个结果
        private static void SelectMany2()
        {
            var racers = Formula1.GetChampionships()
                .Where(r => r.Year > 2000)
              .SelectMany(cs => new List<dynamic>() {   // dynamic 是定义弱对象
                // 自定义对象的属性名
                // 然后用 cs 数据赋值; 
                  // 将原数据经过封装后, 生成匿名对象返回
                 new {
                   Year = cs.Year,
                   Position = 1,
                   Name = cs.First,
                   xx = "hello kitty"
                 }/*,
                 new {
                   Year = cs.Year,
                   Position = 2,
                   Name = cs.Second
                 }*/
               });

            foreach (var s in racers)
            {
                Console.WriteLine(s);
            }

        }


        private static void CombineRacers()
        {
            var q = from r in Formula1.GetChampions()
                    join r2 in Formula1.GetChampionships().GetRacerInfo() on
                    new
                    {
                        FirstName = r.FirstName,
                        LastName = r.LastName
                    }
                      equals
                    new
                    {
                        FirstName = r2.FirstName,
                        LastName = r2.LastName
                    }
                    into yearResults
                    select new
                    {
                        FirstName = r.FirstName,
                        LastName = r.LastName,
                        Wins = r.Wins,
                        Starts = r.Starts,
                        Results = yearResults
                    };

            foreach (var item in q)
            {
                Console.WriteLine("{0} {1}", item.FirstName, item.LastName);
                foreach (var item2 in item.Results)
                {
                    Console.WriteLine("{0} {1}", item2.Year, item2.Position);
                }
            }
        }

        // 貌似是差集
        private static void Except()
        {
            var racers = Formula1.GetChampionships().SelectMany(cs => new List<RacerInfo>()
		   {
			 new RacerInfo {
			   Year = cs.Year,
			   Position = 1,
			   FirstName = cs.First.FirstName(),
			   LastName = cs.First.LastName()
			 },
			 new RacerInfo {
			   Year = cs.Year,
			   Position = 2,
			   FirstName = cs.Second.FirstName(),
			   LastName = cs.Second.LastName()
			 },
			 new RacerInfo {
			   Year = cs.Year,
			   Position = 3,
			   FirstName = cs.Third.FirstName(),
			   LastName = cs.Third.LastName()
			 }
		   });


            var nonChampions = racers.Select(r =>
              new
              {
                  FirstName = r.FirstName,
                  LastName = r.LastName
              }).Except(Formula1.GetChampions().Select(r =>
                new
                {
                    FirstName = r.FirstName,
                    LastName = r.LastName
                }));

            foreach (var r in nonChampions)
            {
                Console.WriteLine("{0} {1}", r.FirstName, r.LastName);
            }

        }

        private static void Sorting()
        {
            var racers = (from r in Formula1.GetChampions()
                          orderby r.Country, r.LastName, r.FirstName
                          select r).Take(10);

            foreach (var racer in racers)
            {
                Console.WriteLine("{0}: {1}, {2}", racer.Country, racer.LastName, racer.FirstName);
            }

        }

        // Cast 转换对象类型
        static void Untyped()
        {
            var list = new System.Collections.ArrayList(Formula1.GetChampions() as System.Collections.ICollection);

            // cast 将只能以 [index] 访问的集合转换成 .propertyName 的形式, 这样才可以用 foreach 遍历
            var query = from r in list.Cast<Racer>()
                        where r.Country == "USA"
                        orderby r.Wins descending
                        select r;
            foreach (var racer in query)
            {
                Console.WriteLine("{0:A}", racer);
            }

        }

        /*
         * 列合并, 两个集合的每一行前后收尾相接合并为一行; 生成一个新集合
         */
        static void ZipOperation()
        {
            var racerNames = from r in Formula1.GetChampions()
                             where r.Country == "Italy"
                             orderby r.Wins descending
                             select new
                             {
                                 Name = r.FirstName + " " + r.LastName
                             };

            var racerNamesAndStarts = from r in Formula1.GetChampions()
                                      where r.Country == "Italy"
                                      orderby r.Wins descending
                                      select new
                                      {
                                          LastName = r.LastName,
                                          Starts = r.Starts
                                      };

            foreach(var r in racerNames)
            {
                Console.WriteLine(r);
            }
            foreach (var r in racerNamesAndStarts)
            {
                Console.WriteLine(r);
            }

            var racers = racerNames.Zip(racerNamesAndStarts, (first, second) => first.Name + ", starts: " + second.Starts);
            foreach (var r in racers)
           { 
                Console.WriteLine(r);
            }

        }

        // 嵌套 select 语句
        static void Aggregate2()
        {
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

            foreach (var country in countries)
            {
                Console.WriteLine("{0} {1}", country.Country, country.Wins);
            }

        }

        /*
         * 在查询语句中定义变量
         */
        static void Aggregate()
        {
            var query = from r in Formula1.GetChampions()
                        let numberYears = r.Years.Count()
                        where numberYears >= 3
                        orderby numberYears descending, r.LastName
                        select new
                        {
                            Name = r.FirstName + " " + r.LastName,
                            TimesChampion = numberYears
                        };

            foreach (var r in query)
            {
                Console.WriteLine("{0} {1}", r.Name, r.TimesChampion);
            }
        }

        // 实现分页数据
        static void Partitioning()
        {
            int pageSize = 9;

            int numberPages = (int)Math.Ceiling(Formula1.GetChampions().Count() /
                  (double)pageSize);

            for (int page = 0; page < numberPages; page++)
            {
                Console.WriteLine("Page {0}", page);

                var racers =
                   (from r in Formula1.GetChampions()
                    orderby r.LastName, r.FirstName
                    select r.FirstName + " " + r.LastName).
                   Skip(page * pageSize).Take(pageSize);

                foreach (var name in racers)
                {
                    Console.WriteLine(name);
                }
                Console.WriteLine();
            }

        }

        // 去两个集合的交际 Intersect()
        static void SetOperations()
        {
            Func<string, IEnumerable<Racer>> racersByCar =
                car => from r in Formula1.GetChampions()
                       from c in r.Cars
                       where c == car
                       orderby r.LastName
                       select r;

            Console.WriteLine("World champion with Ferrari and McLaren");
            foreach (var racer in racersByCar("Ferrari").Intersect(racersByCar("McLaren")))
            {
                Console.WriteLine(racer);
            }
        }

        // 使用 Linq 函数实现 Innerjoin
        // 结果 与 InnerJoin() 相同
        static void InnerJoinMethod()
        {
            // 表内交叉
            var racers = Formula1.GetChampions().
                SelectMany( r => r.Years, (r,y) => new { reacer = r, year = y});

            // 表内交叉
            var teams = Formula1.GetContructorChampions().
                SelectMany(t => t.Years, (t, y) => new { team = t, year = y });

            // 两个结果再交叉
            var racersAndTeams = racers.Join(teams,
                r => r.year,
                t => t.year,
                (r, t) => new {
                    Year = r.year,
                    Champion = r.reacer.FirstName,
                    Constructor = t.team.Name
                }).
                OrderBy( y => y.Year ).
                Take(10);

            foreach (var item in racersAndTeams)
            {
                Console.WriteLine("{0}: {1,-20} {2}",
                   item.Year, item.Champion, item.Constructor);
            }
        }

        // 内链接, 只包含 Year 相等的两边数据
        static void InnerJoin()
        {
            // 表内交叉
            var racers = from r in Formula1.GetChampions()
                         from y in r.Years
                         select new
                         {
                             Year = y,
                             Name = r.FirstName + " " + r.LastName
                         };

            // 表内交叉
            var teams = from t in Formula1.GetContructorChampions()
                        from y in t.Years
                        select new
                        {
                            Year = y,
                            Name = t.Name
                        };

            // 两表交叉
            var racersAndTeams =
                  (from r in racers
                   join t in teams on r.Year equals t.Year
                   orderby t.Year

                   // t 表 teams, r 代表 racers
                   select new
                   {
                       Year = r.Year,
                       Champion = r.Name,
                       Constructor = t.Name
                   }).Take(10);                 // 只显示前 10 条数据

            Console.WriteLine("Year  World Champion\t   Constructor Title");
            foreach (var item in racersAndTeams)
            {
                Console.WriteLine("{0}: {1,-20} {2}",
                   item.Year, item.Champion, item.Constructor);
            }

        }

        /* 结果与 下面的 GroupJoin2() 函数相同
         */
        static void GroupJoinLinq()
        {
            var racers = from cs in Formula1.GetChampionships()
                         select new { Year = cs.Year,  Numbers = new List<string>() { cs.First, cs.Second, cs.Third } } into temp
                         from r in temp.Numbers
                         select new { Year = temp.Year, FirstName = r.FirstName(), LastName = r.LastName(), Position = temp.Numbers.IndexOf(r)+1 };

            var q = (from r in Formula1.GetChampions()      // 只有冠军
                join r2 in racers on

                // 临时匿名对象
                new
                {
                    FirstName = r.FirstName,
                    LastName = r.LastName
                }
                equals
                new
                {
                    FirstName = r2.FirstName,
                    LastName = r2.LastName
                }
                into yearResults
                select new
                {
                    FirstName = r.FirstName,
                    LastName = r.LastName,
                    Wins = r.Wins,
                    Starts = r.Starts,
                    Results = yearResults
                });

            foreach (var r in q)
            {
                Console.WriteLine("{0} {1}", r.FirstName, r.LastName);
                foreach (var results in r.Results)
                {
                    Console.WriteLine("{0} {1}", results.Year, results.Position);
                }
            }
        }

        /*
         * 根据名字列表和 年份123名次, 求出每个名字在<哪年>获得<第几名>
         */
        static void GroupJoin2()
        {
            var racers = Formula1.GetChampionships()        // 年份+123名

              /* 把年份 * 1,2,3名 交叉, 
               * 
               * 将 1950   first   second  third
               * 形成如下格式:
               *  year   pos            name
               * ------------------------------------------
               * 1950     1   first(firstname, lastname)
               * 1950     2   second(firstname, lastname)
               * 1950     3   third(firstname, lastname)
               * 
               * 然后用名字列表, 即冠军列表中的名字列表与上表中的  name 作为join 的key
               */
              .SelectMany(cs => new List<RacerInfo>()
              {
                  // 封装年份 + 123名次
                 new RacerInfo {
                   Year = cs.Year,
                   Position = 1,
                   FirstName = cs.First.FirstName(),
                   LastName = cs.First.LastName()
                 },
                 new RacerInfo {
                   Year = cs.Year,
                   Position = 2,
                   FirstName = cs.Second.FirstName(),
                   LastName = cs.Second.LastName()
                 },
                 new RacerInfo {
                   Year = cs.Year,
                   Position = 3,
                   FirstName = cs.Third.FirstName(),
                   LastName = cs.Third.LastName()
                 }
             });

            var q = (from r in Formula1.GetChampions()      // 只有冠军
                     join r2 in racers on

                     // 临时匿名对象
                     new
                     {
                         FirstName = r.FirstName,
                         LastName = r.LastName
                     }
                     equals
                     new
                     {
                         FirstName = r2.FirstName,
                         LastName = r2.LastName
                     }
                     into yearResults
                     select new
                     {
                         FirstName = r.FirstName,
                         LastName = r.LastName,
                         Wins = r.Wins,
                         Starts = r.Starts,
                         Results = yearResults
                     });

            foreach (var r in q)
            {
                Console.WriteLine("{0} {1}", r.FirstName, r.LastName);
                foreach (var results in r.Results)
                {
                    Console.WriteLine("{0} {1}", results.Year, results.Position);
                }
            }

        }

        static void GroupJoin()
        {
            //  var q =
            //from c in categories
            //join p in products on c equals p.Category into ps
            //select new { Category = c, Products = ps }; 

            var racers = from r in Formula1.GetChampions()
                         from y in r.Years
                         select new
                         {
                             Year = y,
                             Name = r.FirstName + " " + r.LastName
                         };

            var teams = from t in Formula1.GetContructorChampions()
                        from y in t.Years
                        select new
                        {
                            Year = y,
                            Name = t.Name
                        };

            var racersAndTeams =
                  from r in racers
                  join t in teams on r.Year equals t.Year into ts
                  select new
                  {
                      Year = r.Year,
                      Racer = r.Name,
                      Constructor = ts
                  };

            foreach (var r in racersAndTeams)
            {
                Console.WriteLine("{0} {1}", r.Year, r.Racer);
                foreach (var t in r.Constructor)
                {
                    Console.WriteLine("\t{0}", t.Name);
                }
            }
        }

        static void CrossJoinWithGroupJoin()
        {
            //  var q =
            //from c in categories
            //join p in products on c equals p.Category into ps
            //from p in ps
            //select new { Category = c, p.ProductName }; 

        }

        // 左外链接, 包括左表的所有数据
        static void LeftOuterJoin()
        {
            var racers = from r in Formula1.GetChampions()
                         from y in r.Years
                         select new
                         {
                             Year = y,
                             Name = r.FirstName + " " + r.LastName
                         };

            var teams = from t in Formula1.GetContructorChampions()
                        from y in t.Years
                        select new
                        {
                            Year = y,
                            Name = t.Name
                        };

            var racersAndTeams =
              (from r in racers
               join t in teams on r.Year equals t.Year into rt
               from t in rt.DefaultIfEmpty()        // 该操作就是 左链接
               orderby r.Year
               select new
               {
                   Year = r.Year,
                   Champion = r.Name,
                   Constructor = t == null ? "no constructor championship" : t.Name
               }).Take(10);

            Console.WriteLine("Year  Champion\t\t   Constructor Title");
            foreach (var item in racersAndTeams)
            {
                Console.WriteLine("{0}: {1,-20} {2}",
                   item.Year, item.Champion, item.Constructor);
            }
        }

        // group by 显示 group 内部数据
        static void GroupingWithNestedObjects()
        {
            var countries = from r in Formula1.GetChampions()
                            group r by r.Country into g
                            orderby g.Count() descending, g.Key
                            where g.Count() >= 2
                            select new
                            {
                                Country = g.Key,
                                Count = g.Count(),

                                // 获取分组内部的详细信息
                                Racers = from r1 in g
                                         orderby r1.LastName
                                         select r1.FirstName + " " + r1.LastName
                            };
            foreach (var item in countries)
            {
                Console.WriteLine("{0, -10} {1}", item.Country, item.Count);
                foreach (var name in item.Racers)
                {
                    Console.WriteLine("{0}; ", name);
                }
                Console.WriteLine("--------------------------------");
            }
        }

        // 函数 GroupByd 结果与下 Grouping() 相同
        static void GroupByMethod()
        {
            var countries = Formula1.GetChampions().
                GroupBy(r => r.Country).        // 返回 IEnumerable<IGrouping<TKey, TSource>>
                OrderByDescending(g => g.Count()).  // g 代表每个 IGrouping<TKey, TSource>
                ThenBy(g => g.Key).                 // g.Key 就是 r.COuntry
                Where(g => g.Count() >= 2).
                Select( g => 
                    new {
                        Country = g.Key,
                        Count = g.Count()
                });
            foreach (var item in countries)
            {
               // foreach (var str in item )
                    Console.WriteLine(item);
                Console.WriteLine("-----------------------");
            }
        }

        // group by 
        static void Grouping()
        {
            var countries = from r in Formula1.GetChampions()
                            group r by r.Country into g
                            orderby g.Count() descending, g.Key     // key 就是 by 后面的 r.Country
                            where g.Count() >= 2            // 筛选 >= 2 的数据
                            select new                      // 封装输出数据
                            {
                                Country = g.Key,
                                Count = g.Count()
                            };

            foreach (var item in countries)
            {
                Console.WriteLine("{0, -10} {1}", item.Country, item.Count);
            }

        }

        // 多个 from 子句实现交叉表查询
        // 如果筛选结果里面有集合, 就可以使用 from 进一步筛选
        static void CompoundFrom()
        {
            var ferrariDrivers = from r in Formula1.GetChampions()
                                 from c in r.Cars       // 相当于交叉表一样, 如果 Cars 有多个 Ferrari, 结果就会重复出现几次
                                 where c == "Ferrari" || c == "Lotus"
                                // orderby r.LastName
                                 select r.FirstName + " " + r.LastName + " - " + c;

            foreach (var racer in ferrariDrivers)
            {
                Console.WriteLine(racer);
            }

        }

        static void TypeFiltering()
        {
            object[] data = { "one", 2, 3, "four", "five", 6 };
            var query = data.OfType<string>();
            foreach (var s in query)
            {
                Console.WriteLine(s);
            }

        }

        static void IndexFiltering()
        {
            var racers = Formula1.GetChampions().
                    Where((r, index) => r.LastName.StartsWith("A") && index % 2 != 0);
            foreach (var r in racers)
            {
                Console.WriteLine("{0:A}", r);
            }

        }


        static void Filtering()
        {
            var racers = from r in Formula1.GetChampions()
                         where r.Wins > 15 && (r.Country == "Brazil" || r.Country == "Austria")
                         select r;

            foreach (var r in racers)
            {
                Console.WriteLine("{0:A}", r);
            }

        }
    }
}
