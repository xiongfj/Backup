
// �����к��� MVC

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

// Controller �к���

��HttpPost��
public ActionResult Test(){
	return new ASJsonResult
	{
		Data = new { Message = "messageabc", Data = object ������js������angular���� },
		JsonRequestBehavior = behavior
	};
}

// ǰ�� js ����

$.ajax({
	url: '/Test',
	success: function(result){
		console.log(result.Message);		// ��� messageabc
		console.log(result.Data);	// ���ƶ�Ӧ��ȡ��Ӧ������
	}
});