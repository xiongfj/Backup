using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Wrox.ProCSharp.LINQ;

namespace Select
{
    class Program
    {
        static void Main(string[] args)
        {
            var champions = new List<Racer>(Formula1.GetChampions());

            IEnumerable<string> brazilChampions =
                champions.Where(r => r.Country == "Brazil").
                        OrderByDescending(r => r.Wins).
                        Select(r => r.LastName);            // 可以是 r.LastName 是string, 所以必须 IEnumerable<string> 也是 string

            foreach (string r in brazilChampions)
            {
                Console.WriteLine("{0:A}", r);
            }
        }
    }
}
