using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Wrox.ProCSharp.LINQ;

namespace Where索引
{
    class Program
    {
        static void Main(string[] args)
        {
            var champions = new List<Racer>(Formula1.GetChampions());

            // index 是在原数据集的索引,而不是查询得到结果后的索引
            // index 不是从查询结果中索引
            IEnumerable<Racer> brazilChampions =
                champions.Where((r, index) => r.FirstName.StartsWith("J") && index <= 5 ).
                        Select(r => r);           

            foreach (Racer r in brazilChampions)
            {
                Console.WriteLine("{0:A}", r.FirstName);
            }
        }
    }
}
