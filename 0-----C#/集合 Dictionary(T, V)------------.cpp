
0.字典需要使用 KeyValuePair 遍历

//定义
    Dictionary<string, string> openWith = new Dictionary<string, string>();
 
//添加元素
    openWith.Add("txt", "notepad.exe");
    openWith.Add("bmp", "paint.exe");
    openWith.Add("dib", "paint.exe");
    openWith.Add("rtf", "wordpad.exe");

//取值
    Console.WriteLine("For key = \"rtf\", value = {0}.", openWith["rtf"]);

//更改值
    openWith["rtf"] = "winword.exe";
    Console.WriteLine("For key = \"rtf\", value = {0}.", openWith["rtf"]);
 
//遍历key
    foreach (string key in openWith.Keys)
    {
        Console.WriteLine("Key = {0}", key);
    }
 
//遍历value
    foreach (string value in openWith.Values)
    {
        Console.WriteLine("value = {0}", value);
    }

//遍历value, Second Method
    Dictionary<string, string>.ValueCollection valueColl = openWith.Values;
    foreach (string s in valueColl)
    {
        Console.WriteLine("Second Method, Value = {0}", s);
    }
 
//遍历字典
    foreach (KeyValuePair<string, string> kvp in openWith)
    {
        Console.WriteLine("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
    }
 
//添加存在的元素
    try
    {
        openWith.Add("txt", "winword.exe");
    }
    catch (ArgumentException)
    {
        Console.WriteLine("An element with Key = \"txt\" already exists.");
    }
 
//删除元素
    openWith.Remove("doc");
    if (!openWith.ContainsKey("doc"))
    {
        Console.WriteLine("Key \"doc\" is not found.");
    }
 
//判断键存在
    if (openWith.ContainsKey("bmp")) // True 
    {
        Console.WriteLine("An element with Key = \"bmp\" exists.");
    }

//参数为其它类型 
    Dictionary<int, string[]> OtherType = new Dictionary<int, string[]>();
    OtherType.Add(1, "1,11,111".Split(','));
    OtherType.Add(2, "2,22,222".Split(','));
    Console.WriteLine(OtherType[1][2]);
 

// 参数为自定义类型

1.首先定义类

    class DouCube
    {
        public int Code { get { return _Code; } set { _Code = value; } } private int _Code;
        public string Page { get { return _Page; } set { _Page = value; } } private string _Page;
    } 
2.然后

	//声明并添加元素
    Dictionary<int, DouCube> MyType = new Dictionary<int, DouCube>();
    for (int i = 1; i <= 9; i++)
    {
        DouCube element = new DouCube();
        element.Code = i * 100;
        element.Page = "http://www.doucube.com/" + i.ToString() + ".html";
        MyType.Add(i, element);
    }
	//遍历元素
    foreach (KeyValuePair<int, DouCube> kvp in MyType)
    {
        Console.WriteLine("Index {0} Code:{1} Page:{2}", kvp.Key, kvp.Value.Code, kvp.Value.Page);
    } 
 

 

//常用属性-----------------------------------------------

    名称    	说明
    Comparer     //获取用于确定字典中的键是否相等的 IEqualityComparer<T>。
    Count        //获取包含在 Dictionary<TKey, TValue> 中的键/值对的数目。
    Item         //获取或设置与指定的键相关联的值。
    Keys         //获取包含 Dictionary<TKey, TValue> 中的键的集合。
    Values       //获取包含 Dictionary<TKey, TValue> 中的值的集合。

//常用方法
    名称    			说明
    Add                 //将指定的键和值添加到字典中。
    Clear               //从 Dictionary<TKey, TValue> 中移除所有的键和值。
    ContainsKey         //确定 Dictionary<TKey, TValue> 是否包含指定的键。
    ContainsValue       //确定 Dictionary<TKey, TValue> 是否包含特定值。
    Equals(Object)      //确定指定的 Object 是否等于当前的 Object。 （继承自 Object。）
    Finalize            //允许对象在“垃圾回收”回收之前尝试释放资源并执行其他清理操作。 （继承自 Object。）
    GetEnumerator       //返回循环访问 Dictionary<TKey, TValue> 的枚举器。
    GetHashCode         //用作特定类型的哈希函数。 （继承自 Object。）
    GetObjectData       //实现 System.Runtime.Serialization.ISerializable 接口，并返回序列化 Dictionary<TKey, TValue> 实例所需的数据。
    GetType             //获取当前实例的 Type。 （继承自 Object。）
    MemberwiseClone     //创建当前 Object 的浅表副本。 （继承自 Object。）
    OnDeserialization   //实现 System.Runtime.Serialization.ISerializable 接口，并在完成反序列化之后引发反序列化事件。
    Remove              //从 Dictionary<TKey, TValue> 中移除所指定的键的值。
    ToString            //返回表示当前对象的字符串。 （继承自 Object。）
	
    public bool TryGetValue(TKey key, out TValue value);         //获取与指定的键相关联的值。
	
	
	
	
	
	
	
	
	