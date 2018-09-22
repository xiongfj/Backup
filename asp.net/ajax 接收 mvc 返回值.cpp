
// 首先有函数 MVC

protected virtual JsonResult Json(string message, JsonRequestBehavior behavior = JsonRequestBehavior.DenyGet)
{
	return Json(message, null, behavior);
}

protected new JsonResult Json(object data, JsonRequestBehavior behavior = JsonRequestBehavior.DenyGet)
{
	return Json(string.Empty, data, behavior);
}

protected virtual JsonResult Json(string message, object data, JsonRequestBehavior behavior = JsonRequestBehavior.DenyGet)
{
	return new ASJsonResult
	{
		Data = new { Success = true, Message = message, Data = data },
		JsonRequestBehavior = behavior
	};
}

protected virtual JsonResult JsonFail(string message, JsonRequestBehavior behavior = JsonRequestBehavior.DenyGet)
{
	return new ASJsonResult
	{
		Data = new { Success = true, Message = message },
		JsonRequestBehavior = behavior
	};
}

// Controller 有函数

【HttpPost】
public ActionResult Test(){
	return new ASJsonResult
	{
		Data = new { Message = "messageabc", Data = object 可以是js变量，angular变量 },
		JsonRequestBehavior = behavior
	};
}

// 前端 js 代码

$.ajax({
	url: '/Test',
	success: function(result){
		console.log(result.Message);		// 输出 messageabc
		console.log(result.Data);	// 名称对应获取对应的数据
	}
});