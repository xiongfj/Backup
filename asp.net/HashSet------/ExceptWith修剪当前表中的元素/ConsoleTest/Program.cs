using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

/* 有两种类型的集合，SortedSet和HastSet
这个类代表一组值。
这个类提供了高性能的操作。
这是一组不包含重复元素的集合，并且其中存储的元素没有特定的顺序。
在.NET Framework 4.6版本中，HashSet 实现IReadOnlyCollection 界面连同ISet 接口。
哈希集类对其中存储的元素数量没有任何最大容量。随着元素数量的增加，这种容量不断增加。

* 常用方法:
Add()	        如果某元素不在集合中，Add()方法就把该元素添加到集合中。在其返回值Boolean中，返回元素是否添加的信息
Clear()	        方法Clear()删除集合中的所有元素
Remove()	    Remove()方法删除指定的元素
RemoveWhere()	RemoveWhere()方法需要一个Predicate<T>委托作为参数。删除满足谓词条件的所有元素
CopyTo()  	    CopyTo()把集合中的元素复制到一个数组中
ExceptWith()	ExceptWith()方法把一个集合作为参数，从集中删除该集合中的所有元素
IntersectWith()	IntersectWith()修改了集，仅包含所传送的集合和集中都有的元素
b.UnionWith(a) 	// 将a中元素拷贝进b中, 排除重复的元素

Contains()	    如果所传送的元素在集合中，方法Contains()就返回true
IsSubsetOf()	如果参数传送的集合是集的一个子集，方法IsSubsetOf()就返回true
IsSupersetOf()	如果参数传送的集合是集的一个超集，方法IsSupersetOf()就返回true
Overlaps()	    如果参数传送的集合中至少有一个元素与集中的元素相同，Overlaps()就返回true
SetEquals()	    如果参数传送的集合和集包含完全相同的元素，方法SetEquals()就返回true
*/
namespace ConsoleTest
{
    //
    class Program
    {
        static void Main(string[] args)
        {
            // hash_1
            string[] names1 = new string[] {
                "mahesh","sabnis","manish","sharma","saket","karnik"
            };
            //HashSet<string> hSetN1 = new HashSet<string>(names1);

            // hash_2
            string[] names2 = new string[] {
                "suprotim","agarwal","vikram","pendse","mahesh","mitkari"   // 与 hash_1 有一个重复值
            };
            HashSet<string> hSetN2 = new HashSet<string>(names2);
            HashSet<string> hSetN3 = new HashSet<string>(names1);

            // 删除 hSetN3 中与 hSetN2 某个值相同的元素
            hSetN3.ExceptWith(hSetN2);
            foreach (var n in hSetN3)
                Console.WriteLine(n);
        }
    }
}
