* 前端使用 angular
	$http({
		url: "api/xx/GetEditItemData/xxid",
		method: 'get',
		// query string like { userId: user.id } -> ?userId=value
		params: p,
	}).then(function(d){
		// d.data = model...
	}).catch(function(d){
		console.log(d.data);	// user data not found!
	});
	
	
	
* 后台：
public HttpResponseMessage GetEditItemData(Guid id)
{
	if (!Security.IsAuthorizedTo(Rights.AccessAdminPages))
		throw new UnauthorizedAccessException();

	Dictionary<string, object> result = new BLL.User().GetUserJoinBlogItem(id);
	if (result.Count <= 0)
		return Request.CreateResponse(HttpStatusCode.NotFound, "user data not found!");

	UserViewModel model = new UserViewModel
	{
		UserId = (Guid)result["UserId"],
		EmailAddress = result["EmailAddress"].ToString(),
		UserName = result["UserName"].ToString(),
		IsActive = (bool)result["IsActive"],
		Avatar = result["Avatar"].ToString(),
		VirtualPath = result["VirtualPath"].ToString()
	};

	return Request.CreateResponse(HttpStatusCode.OK, model);
}