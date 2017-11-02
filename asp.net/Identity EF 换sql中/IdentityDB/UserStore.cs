using IdentityDB.Model;
using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Security.Claims;
using System.Threading.Tasks;
using WebApplication5.Bll;
using WebApplication5.Model;

namespace IdentityDB
{
	public class UserStore<TUser> : UserStore<TUser, IdentityRole, string, IdentityUserLogin, IdentityUserRole, IdentityUserClaim>, IUserStore<TUser>, IUserStore<TUser, string>, IDisposable 
		where TUser : IdentityUser
	{
		public override Task CreateAsync(TUser user)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			//userTable.Insert(user);

			UsersModel model = new UsersModel();
			model.Id = user.Id;
			model.UserName = user.UserName;
			model.Email = user.Email;
			model.EmailConfirmed = user.EmailConfirmed;
			model.TwoFactorEnabled = user.TwoFactorEnabled;
			model.LockoutEnabled = user.LockoutEnabled;
			model.AccessFailedCount = user.AccessFailedCount;
			model.PhoneNumberConfirmed = user.PhoneNumberConfirmed;
			// model.Password = ...

			CommonBLL bll = new CommonBLL();
			bll.Add(model, true);

			return base.CreateAsync(user);
		}
	}





	/* 该类实例会传递到 UserManager 内部回调 */
	public class UserStore<TUser, TRole, TKey, TUserLogin, TUserRole, TUserClaim> : 
		IUserLoginStore<TUser, TKey>,		// 外部身份验证提供程序
		IUserClaimStore<TUser, TKey>,
		IUserRoleStore<TUser, TKey>,
		IUserPasswordStore<TUser, TKey>,	// 如果使用了哈希密码,必须实现这个
		IUserSecurityStampStore<TUser, TKey>,   // 如果你的用户存储中使用了安全戳来判断用户账号信息是否改变，你就必须实现这个接口定义的方法
		IQueryableUserStore<TUser, TKey>,       // 提供一个可查询的用户存储必须实现这个接口定义的方法
		IUserEmailStore<TUser, TKey>,
		IUserPhoneNumberStore<TUser, TKey>,
		IUserTwoFactorStore<TUser, TKey>,       // 双因素认证必须实现这个接口定义的方法
		IUserLockoutStore<TUser, TKey>,     // 存储账号锁定信息必须实现这个接口定义的方法
		IUserStore<TUser, TKey>,
		IDisposable
		where TUser : IdentityUser<TKey, TUserLogin, TUserRole, TUserClaim>
		where TRole : IdentityRole<TKey, TUserRole>
		where TKey : IEquatable<TKey>
		where TUserLogin : IdentityUserLogin<TKey>, new()
		where TUserRole : IdentityUserRole<TKey>, new()
		where TUserClaim : IdentityUserClaim<TKey>, new()
	{
		// private UserTable<TUser> userTable;
		// private RoleTable roleTable;
		// private UserRolesTable userRolesTable;
		// private UserClaimsTable userClaimsTable;
		// private UserLoginsTable userLoginsTable;
		//public MySQLDatabase Database { get; private set; }
		public IQueryable<TUser> Users
		{
			get
			{
				throw new NotImplementedException();
			}
		}
		/// <summary>
		/// Default constructor that initializes a new MySQLDatabase
		/// instance using the Default Connection string
		/// </summary>
		public UserStore()
		{
			//new MyUserStore<TUser>(new MySQLDatabase());
		}
		/// <summary>
		/// Constructor that takes a MySQLDatabase as argument 
		/// </summary>
		/// <param name="database"></param>
		/*public UserStore(MySQLDatabase database)
        {
            Database = database;
            userTable = new UserTable<TUser>(database);
            roleTable = new RoleTable(database);
            userRolesTable = new UserRolesTable(database);
            userClaimsTable = new UserClaimsTable(database);
            userLoginsTable = new UserLoginsTable(database);
        }*/

		///public bool DisposeContext { get; set; }
		///public DbContext Context { get; }
		//
		// Summary:
		//     If true will call SaveChanges after Create/Update/Delete
		///public bool AutoSaveChanges { get; set; }
		//
		// Summary:
		//     Add a claim to a user
		//
		// Parameters:
		//   user:
		//
		//   claim:
		public virtual Task AddClaimAsync(TUser user, Claim claim)
		{
			// 将数据插入 AspNetUserClaims 表中
			//_userClaims.Add(new TUserClaim { UserId = user.Id, ClaimType = claim.Type, ClaimValue = claim.Value });

			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Add a login to the user
		//
		// Parameters:
		//   user:
		//
		//   login:
		public virtual Task AddLoginAsync(TUser user, UserLoginInfo login)
		{
			/* 将下面数据插入表 AspNetUserLogins
			 _logins.Add(new TUserLogin
            {
                UserId = user.Id,
                ProviderKey = login.ProviderKey,
                LoginProvider = login.LoginProvider
            });
			*/
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Add a user to a role
		//
		// Parameters:
		//   user:
		//
		//   roleName:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< AddToRoleAsync > d__3b))]
		[DebuggerStepThrough]
		public virtual Task AddToRoleAsync(TUser user, string roleName)
		{
			/*
            var ur = new TUserRole { UserId = user.Id, RoleId = AspNetRoles 表中 roleName对应的id };
            _userRoles.Add(ur);
			*/
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Insert an entity
		//
		// Parameters:
		//   user:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< CreateAsync > d__16))]
		[DebuggerStepThrough]
		public virtual Task CreateAsync(TUser user)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Mark an entity for deletion
		//
		// Parameters:
		//   user:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< DeleteAsync > d__19))]
		[DebuggerStepThrough]
		public virtual Task DeleteAsync(TUser user)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Dispose the store
		public void Dispose()
		{
		}
		//
		// Summary:
		//     Returns the user associated with this login
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< FindAsync > d__23))]
		[DebuggerStepThrough]
		public virtual Task<TUser> FindAsync(UserLoginInfo login)
		{
			/* 根据表 AspNetUserLogins 表的LoginProvider,ProviderKey 查找 UserId
			 * 再根据 UserId 查找 AspNetUsers 表里面的 TUser
			 var provider = login.LoginProvider;
            var key = login.ProviderKey;
            var userLogin =
            await _logins.FirstOrDefaultAsync(l => l.LoginProvider == provider && l.ProviderKey == key).WithCurrentCulture();
			*/

			return Task.FromResult<TUser>(null);
		}

		// 根据邮件地址查找 TUser
		public virtual Task<TUser> FindByEmailAsync(string email)
		{
			return Task.FromResult<TUser>(null);
		}

		//
		public virtual Task<TUser> FindByIdAsync(TKey userId)
		{
			return Task.FromResult<TUser>(null);
		}
		//
		// Summary:
		//     Find a user by name
		//
		// Parameters:
		//   userName:
		public virtual Task<TUser> FindByNameAsync(string userName)
		{
			return Task.FromResult<TUser>(null);
		}
		//
		// Summary:
		//     Returns the current number of failed access attempts. This number usually will
		//     be reset whenever the password is verified or the account is locked out.
		//
		// Parameters:
		//   user:
		public virtual Task<int> GetAccessFailedCountAsync(TUser user)
		{
			return Task.FromResult(user.AccessFailedCount);// 已修改
		}
		//
		// Summary:
		//     Return the claims for a user
		//
		// Parameters:
		//   user:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< GetClaimsAsync > d__2))]
		[DebuggerStepThrough]
		public virtual Task<IList<Claim>> GetClaimsAsync(TUser user)
		{
			// 前提要确保 user 内的 Claims 已经存入数据
			//return user.Claims.Select(c => new Claim(c.ClaimType, c.ClaimValue)).ToList();
			return Task.FromResult<IList<Claim>>(null);
		}
		//
		// Summary:
		//     Get the user's email
		//
		// Parameters:
		//   user:
		public virtual Task<string> GetEmailAsync(TUser user)
		{
			return Task.FromResult<string>(null);
		}
		//
		// Summary:
		//     Returns whether the user email is confirmed
		//
		// Parameters:
		//   user:
		public virtual Task<bool> GetEmailConfirmedAsync(TUser user)
		{
			return Task.FromResult<bool>(false);
		}
		//
		// Summary:
		//     Returns whether the user can be locked out.
		//
		// Parameters:
		//   user:
		public virtual Task<bool> GetLockoutEnabledAsync(TUser user)
		{
			return Task.FromResult(user.LockoutEnabled);//正确
		}
		//
		// Summary:
		//     Returns the DateTimeOffset that represents the end of a user's lockout, any time
		//     in the past should be considered not locked out.
		//
		// Parameters:
		//   user:
		public virtual Task<DateTimeOffset> GetLockoutEndDateAsync(TUser user)
		{
			return
				Task.FromResult(user.LockoutEndDateUtc.HasValue
					? new DateTimeOffset(DateTime.SpecifyKind(user.LockoutEndDateUtc.Value, DateTimeKind.Utc))
					: new DateTimeOffset());
		}
		//
		// Summary:
		//     Get the logins for a user
		//
		// Parameters:
		//   user:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< GetLoginsAsync > d__35))]
		[DebuggerStepThrough]
		public virtual async Task<IList<UserLoginInfo>> GetLoginsAsync(TUser user)
		{
			// await EnsureLoginsLoaded(user).WithCurrentCulture(); 前提要确保有数据
			return user.Logins.Select(l => new UserLoginInfo(l.LoginProvider, l.ProviderKey)).ToList();
		}
		//
		// Summary:
		//     Get the password hash for a user
		//
		// Parameters:
		//   user:
		public virtual Task<string> GetPasswordHashAsync(TUser user)
		{
			return Task.FromResult<string>(null);
		}
		//
		// Summary:
		//     Get a user's phone number
		//
		// Parameters:
		//   user:
		public virtual Task<string> GetPhoneNumberAsync(TUser user)
		{
			return Task.FromResult<string>(null);
		}
		//
		// Summary:
		//     Returns whether the user phoneNumber is confirmed
		//
		// Parameters:
		//   user:
		public virtual Task<bool> GetPhoneNumberConfirmedAsync(TUser user)
		{
			return Task.FromResult<bool>(false);
		}
		//
		// Summary:
		//     Get the names of the roles a user is a member of
		//
		// Parameters:
		//   user:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< GetRolesAsync > d__4d))]
		[DebuggerStepThrough]
		public virtual Task<IList<string>> GetRolesAsync(TUser user)
		{
			return Task.FromResult<IList<string>>(null);
		}
		//
		// Summary:
		//     Get the security stamp for a user
		//
		// Parameters:
		//   user:
		public virtual Task<string> GetSecurityStampAsync(TUser user)
		{
			return Task.FromResult<string>(null);
		}
		//
		// Summary:
		//     Gets whether two factor authentication is enabled for the user
		//
		// Parameters:
		//   user:
		public virtual Task<bool> GetTwoFactorEnabledAsync(TUser user)
		{
			return Task.FromResult<bool>(false);
		}
		//
		// Summary:
		//     Returns true if the user has a password set
		//
		// Parameters:
		//   user:
		public virtual Task<bool> HasPasswordAsync(TUser user)
		{
			return Task.FromResult(user.PasswordHash != null);//正确
		}
		//
		// Summary:
		//     Used to record when an attempt to access the user has failed
		//
		// Parameters:
		//   user:
		public virtual Task<int> IncrementAccessFailedCountAsync(TUser user)
		{
			user.AccessFailedCount++;
			return Task.FromResult(user.AccessFailedCount);
		}
		//
		// Summary:
		//     Returns true if the user is in the named role
		//
		// Parameters:
		//   user:
		//
		//   roleName:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< IsInRoleAsync > d__55))]
		[DebuggerStepThrough]
		public virtual Task<bool> IsInRoleAsync(TUser user, string roleName)
		{
			return Task.FromResult<bool>(false);
		}
		//
		// Summary:
		//     Remove a claim from a user
		//
		// Parameters:
		//   user:
		//
		//   claim:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< RemoveClaimAsync > d__c))]
		[DebuggerStepThrough]
		public virtual Task RemoveClaimAsync(TUser user, Claim claim)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Remove a user from a role
		//
		// Parameters:
		//   user:
		//
		//   roleName:
		///[AsyncStateMachine(typeof(UserStore<,,,,,>.< RemoveFromRoleAsync > d__44))]
		[DebuggerStepThrough]
		public virtual Task RemoveFromRoleAsync(TUser user, string roleName)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Remove a login from a user
		//
		// Parameters:
		//   user:
		//
		//   login:
		//[AsyncStateMachine(typeof(UserStore<,,,,,>.< RemoveLoginAsync > d__2f))]
		[DebuggerStepThrough]
		public virtual Task RemoveLoginAsync(TUser user, UserLoginInfo login)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Used to reset the account access count, typically after the account is successfully
		//     accessed
		//
		// Parameters:
		//   user:
		public virtual Task ResetAccessFailedCountAsync(TUser user)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set the user email
		//
		// Parameters:
		//   user:
		//
		//   email:
		public virtual Task SetEmailAsync(TUser user, string email)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set IsConfirmed on the user
		//
		// Parameters:
		//   user:
		//
		//   confirmed:
		public virtual Task SetEmailConfirmedAsync(TUser user, bool confirmed)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Sets whether the user can be locked out.
		//
		// Parameters:
		//   user:
		//
		//   enabled:
		public virtual Task SetLockoutEnabledAsync(TUser user, bool enabled)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Locks a user out until the specified end date (set to a past date, to unlock
		//     a user)
		//
		// Parameters:
		//   user:
		//
		//   lockoutEnd:
		public virtual Task SetLockoutEndDateAsync(TUser user, DateTimeOffset lockoutEnd)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set the password hash for a user
		//
		// Parameters:
		//   user:
		//
		//   passwordHash:
		public virtual Task SetPasswordHashAsync(TUser user, string passwordHash)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set the user's phone number
		//
		// Parameters:
		//   user:
		//
		//   phoneNumber:
		public virtual Task SetPhoneNumberAsync(TUser user, string phoneNumber)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set PhoneNumberConfirmed on the user
		//
		// Parameters:
		//   user:
		//
		//   confirmed:
		public virtual Task SetPhoneNumberConfirmedAsync(TUser user, bool confirmed)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set the security stamp for the user
		//
		// Parameters:
		//   user:
		//
		//   stamp:
		public virtual Task SetSecurityStampAsync(TUser user, string stamp)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Set whether two factor authentication is enabled for the user
		//
		// Parameters:
		//   user:
		//
		//   enabled:
		public virtual Task SetTwoFactorEnabledAsync(TUser user, bool enabled)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Update an entity
		//
		// Parameters:
		//   user:
		//[AsyncStateMachine(typeof(UserStore<,,,,,>.< UpdateAsync > d__1c))]
		[DebuggerStepThrough]
		public virtual Task UpdateAsync(TUser user)
		{
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     If disposing, calls dispose on the Context. Always nulls out the Context
		//
		// Parameters:
		//   disposing:
		protected virtual void Dispose(bool disposing)
		{
		}
		//
		// Summary:
		//     Used to attach child entities to the User aggregate, i.e. Roles, Logins, and
		//     Claims
		//
		// Parameters:
		//   filter:
		//[AsyncStateMachine(typeof(UserStore<,,,,,>.< GetUserAggregateAsync > d__6c))]
		[DebuggerStepThrough]
		protected virtual Task<TUser> GetUserAggregateAsync(Expression<Func<TUser, bool>> filter)
		{
			return Task.FromResult<TUser>(null);
		}
	}
}