

/// 传递进来的 TUser 是一种 ApplicationUser
public async Task<TUser> FindByUserName(string username)
{
	var u = await FindByUserName(username);
	return (TUser)u;

}

/// 必须是 object 才能正确转换!!
public Task<object> FindByUserName(string username)
{
	ApplicationUser u = new ApplicationUser {
		UserName = username
	};
	return Task.Run<object>(() => {
		DataTable table = ExecuteTableWhere(u, "UserName=@UserName");
		foreach(DataRow row in table.Rows)
		{
			return TransToUser(row);
		}
		return null;
	});
}

































