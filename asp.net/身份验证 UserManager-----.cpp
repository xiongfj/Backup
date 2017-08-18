
/*
* 创建 IdentityUser 到数据库
* 修改 IdentityUser -> UpdateAsync(IUser)
* 从数据库删除 IdentityUser 
* 获取 IndentityUser 列表: Manager.Users
* 获取某个 IdentityUser 所在的 IdentityRole
* 查找某个 IdentityUser
* 添加某个 IdentityUser 到 IdentityRole 中
* 显式验证密码: await UserManager.PasswordValidator.ValidateAsync(password);
* 显式获取 hashcode :user.PasswordHash = UserManager.PasswordHasher.HashPassword(password);
* 创建添加用户申明: ClaimsIdentity claim = UserManager.CreateIdentityAsync(AppUser, DefaultAuthenticationTypes.ApplicationCookie); claim.AddClaim(..)
* 设置密码验证(可以继承该类自定义验证, 见下面..)
	manager.PasswordValidator = new PasswordValidator
	{
		RequiredLength = 6,                 // 密码长度
		RequireNonLetterOrDigit = true,     // true-必须包含一个字符, 不能是数字或字母
		RequireDigit = true,            // true-必须包含数字
		RequireLowercase = true,        // 必须包含小写字符
		RequireUppercase = true,        //.. 
	};
* 设置用户验证
	manager.UserValidator = new UserValidator<ApplicationUser>(manager)
	{
		AllowOnlyAlphanumericUserNames = false,
		RequireUniqueEmail = true
	};
*/

-------------------------------------------------------------


// AppUser 是继承 IdentityUser 的自定义类
// AppRole 是继承 IdentityRole 的自定义类
* public class AppUserManager : UserManager<AppUser>		// 继承用户类


* AppUserManager:Users		// 获取所有用户,数据库中的?!

* AppUserManager:CreateAsync(AppUser, "密码");		// 创建用户到数据库中
/*
* 返回值类型: IdentityResult result = ...
* result.Succeeded	// 指明成功与否
* result.Errors		// 错误信息
*/

* AppUserManager:FindByName()		// 返回 AppUser 对象

* AppUserManager:GetRoles(AppUser:Id)	// 获取用户所在的所有 AppRole 

* AppUserManager:AddToRole(AppUser.Id, AppRole.Name)	// 将 User 添加进 Role


* 自定义密码验证; user验证类似
/*
public class CustomPasswordValidator : PasswordValidator
{
   public override async Task<IdentityResult> ValidateAsync(string password)
   {
	   IdentityResult result = await base.ValidateAsync(password);
	   if (password.Contains("12345"))
	   {
		   List<string> errors = result.Errors.ToList();
		   errors.Add("密码不能包含连续数字");
		   result = new IdentityResult(errors);
	   }
	   return result;
   }
}

---------------

//自定义的Password Validator
manager.PasswordValidator = new CustomPasswordValidator
{
    RequiredLength = 6,
    RequireNonLetterOrDigit = false,
    RequireDigit = false,
    RequireLowercase = true,
    RequireUppercase = true
};
*/












