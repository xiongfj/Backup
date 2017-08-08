 
 
* $scope.cache = $cacheFactory(cacheId, [options]);	// 返回一个 object 对象，
/*
* 参数：
	cacheId:	string，新创建的 cache 的 id 或者 name
	[options]	object, Options object that specifies the cache behavior. Properties: {number=} capacity — turns the cache into LRU cache.
*/

**--------------------- 返回值对象可以调用下面的函数：

object cache.info()	// 获取所有创建的 cache 的信息。Returns id, size, and options of cache
/*
* 返回一个 key-value 的 hashMap，
*/

{{*}} get(string key);	// 获取指定的 value

{{*}} cache.put(string key, {{*}} value)		// 添加一个键值，并返回它

void remove( string key )		// 移除某个 key-value

void removeAll()		// 移除所有 cache values

void destroy()		// 




















