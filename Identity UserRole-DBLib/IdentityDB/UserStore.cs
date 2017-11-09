using IdentityDB.BLL;
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

/*
 * UserManager 层控制一个 TUser user 局部变量.
 * user = FindUserByxxx();			// 数据库找 user
 * SetEmailAsyncxx(user, email);	// 将新 email 赋值给局部变量 user
 * UpdateAsync(user);				// 将新的 user 保存到数据库
 */
namespace IdentityDB
{
	public class UserStore<TUser> : UserStore<TUser, IdentityRole, string, IdentityUserLogin, IdentityUserRole, IdentityUserClaim>, IUserStore<TUser>, IUserStore<TUser, string>, IDisposable 
		where TUser : IdentityUser
	{
		public UserStore()
		{
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
		AspNetUser<TUser, TKey> mBll = new AspNetUser<TUser, TKey>();
		AspNetUserClaim<TUser, TKey> mClaimBLL = new AspNetUserClaim<TUser, TKey>();
		AspNetUserRole<TUser, TRole, TKey> mUserRoleBLL = new AspNetUserRole<TUser, TRole, TKey>();

		public IQueryable<TUser> Users
		{
			get
			{
				return mBll.QueryTable().Result;
			}
		}

		public UserStore()
		{
		}

		//
		// Summary:
		//     Return the claims for a user
		public virtual Task<IList<Claim>> GetClaimsAsync(TUser user)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return mClaimBLL.GetClaimsAsync(user);
		}
		//
		// Summary:
		//     Add a claim to a user
		public virtual Task AddClaimAsync(TUser user, Claim claim)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (claim == null)
			{
				throw new ArgumentNullException("claim");
			}
			return mClaimBLL.AddClaimAsync(user, claim);
		}

		//
		// Summary:
		//     Remove a claim from a user
		public virtual Task RemoveClaimAsync(TUser user, Claim claim)   // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (claim == null)
			{
				throw new ArgumentNullException("claim");
			}

			return mClaimBLL.RemoveClaimAsync(user, claim);
		}

		//
		// Summary:
		//     Add a login to the user
		public virtual Task AddLoginAsync(TUser user, UserLoginInfo login)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (login == null)
			{
				throw new ArgumentNullException("login");
			}
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
		public virtual Task AddToRoleAsync(TUser user, string roleName) // 改
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentNullException("roleName");
			}

			return mUserRoleBLL.AddToRoleAsync(user, roleName);
		}
		//
		// Summary:
		//     Insert an entity
		public virtual Task CreateAsync(TUser user)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return mBll.InsertAsync(user);
		}
		//
		// Summary:
		//     Mark an entity for deletion
		public virtual Task DeleteAsync(TUser user) // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return mBll.DeleteAsync(user);
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
		public virtual Task<TUser> FindAsync(UserLoginInfo login)
		{
			if (login == null)
			{
				throw new ArgumentNullException("login");
			}
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
		public virtual Task<TUser> FindByEmailAsync(string email)   // 改好
		{
			if (String.IsNullOrWhiteSpace(email))
			{
				throw new ArgumentNullException("email");
			}
			return mBll.FindByEmailAsync(email);
		}

		//
		public virtual Task<TUser> FindByIdAsync(TKey userId)// 已修改
		{
			if (userId == null)
			{
				throw new ArgumentNullException("userId");
			}
			return mBll.FindByIdAsync(userId);
		}
		//
		// Summary:
		//     Find a user by name
		public virtual Task<TUser> FindByNameAsync(string userName)// 已修改
		{
			if (String.IsNullOrWhiteSpace(userName))
			{
				throw new ArgumentNullException("userName");
			}
			return mBll.FindByNameAsync(userName);
		}
		//
		// Summary:
		//     Returns the current number of failed access attempts. This number usually will
		//     be reset whenever the password is verified or the account is locked out.
		public virtual Task<int> GetAccessFailedCountAsync(TUser user)// 已修改
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.AccessFailedCount);
		}

		//
		// Summary:
		//     Get the user's email
		public virtual Task<string> GetEmailAsync(TUser user)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.Email);
		}
		//
		// Summary:
		//     Returns whether the user email is confirmed
		public virtual Task<bool> GetEmailConfirmedAsync(TUser user) // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.EmailConfirmed);
		}
		//
		// Summary:
		//     Returns whether the user can be locked out.
		public virtual Task<bool> GetLockoutEnabledAsync(TUser user)	//改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.LockoutEnabled);
		}
		//
		// Summary:
		//     Returns the DateTimeOffset that represents the end of a user's lockout, any time
		//     in the past should be considered not locked out.
		public virtual Task<DateTimeOffset> GetLockoutEndDateAsync(TUser user)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return
				Task.FromResult(user.LockoutEndDateUtc.HasValue
					? new DateTimeOffset(DateTime.SpecifyKind(user.LockoutEndDateUtc.Value, DateTimeKind.Utc))
					: new DateTimeOffset());
		}
		//
		// Summary:
		//     Get the logins for a user
		public virtual async Task<IList<UserLoginInfo>> GetLoginsAsync(TUser user)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			// await EnsureLoginsLoaded(user).WithCurrentCulture(); 前提要确保有数据
			return user.Logins.Select(l => new UserLoginInfo(l.LoginProvider, l.ProviderKey)).ToList();
		}
		//
		// Summary:
		//     Get the password hash for a user
		public virtual Task<string> GetPasswordHashAsync(TUser user)// 已修改
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.PasswordHash);
		}
		//
		// Summary:
		//     Get a user's phone number
		public virtual Task<string> GetPhoneNumberAsync(TUser user) // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.PhoneNumber);
		}
		//
		// Summary:
		//     Returns whether the user phoneNumber is confirmed
		public virtual Task<bool> GetPhoneNumberConfirmedAsync(TUser user)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.PhoneNumberConfirmed);
		}
		//
		// Summary:
		//     Get the names of the roles a user is a member of
		public virtual Task<IList<string>> GetRolesAsync(TUser user)    // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return mUserRoleBLL.GetRolesAsync(user);
		}
		//
		// Summary:
		//     Get the security stamp for a user
		public virtual Task<string> GetSecurityStampAsync(TUser user)   // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.SecurityStamp);
		}
		//
		// Summary:
		//     Gets whether two factor authentication is enabled for the user
		public virtual Task<bool> GetTwoFactorEnabledAsync(TUser user)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.TwoFactorEnabled);
		}
		//
		// Summary:
		//     Returns true if the user has a password set
		public virtual Task<bool> HasPasswordAsync(TUser user)//正确
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return Task.FromResult(user.PasswordHash != null);
		}
		//
		// Summary:
		//     Used to record when an attempt to access the user has failed
		public virtual Task<int> IncrementAccessFailedCountAsync(TUser user)// 已修改
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.AccessFailedCount++;
			return Task.FromResult(user.AccessFailedCount);
		}
		//
		// Summary:
		//     Returns true if the user is in the named role
		public virtual Task<bool> IsInRoleAsync(TUser user, string roleName)    // 改
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentNullException("roleName");
			}
			return Task.FromResult(mUserRoleBLL.IsInRoleAsync(user, roleName).Result);
		}
		//
		// Summary:
		//     Remove a user from a role
		public virtual Task RemoveFromRoleAsync(TUser user, string roleName)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (String.IsNullOrWhiteSpace(roleName))
			{
				throw new ArgumentNullException("roleName");
			}
			return Task.FromResult(mUserRoleBLL.RemoveFromRoleAsync(user, roleName));
		}
		//
		// Summary:
		//     Remove a login from a user
		public virtual Task RemoveLoginAsync(TUser user, UserLoginInfo login)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			if (login == null)
			{
				throw new ArgumentNullException("login");
			}
			return Task.FromResult<object>(null);
		}
		//
		// Summary:
		//     Used to reset the account access count, typically after the account is successfully
		//     accessed
		public virtual Task ResetAccessFailedCountAsync(TUser user)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.AccessFailedCount = 0;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Set the user email
		public virtual Task SetEmailAsync(TUser user, string email) // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.Email = email;
			return Task.FromResult(0);
//			return mBll.SetEmailAsync(user, email);
		}
		//
		// Summary:
		//     Set IsConfirmed on the user
		public virtual Task SetEmailConfirmedAsync(TUser user, bool confirmed)  // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.EmailConfirmed = confirmed;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Sets whether the user can be locked out.
		public virtual Task SetLockoutEnabledAsync(TUser user, bool enabled)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.LockoutEnabled = enabled;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Locks a user out until the specified end date (set to a past date, to unlock
		//     a user)
		public virtual Task SetLockoutEndDateAsync(TUser user, DateTimeOffset lockoutEnd)// 已修改
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.LockoutEndDateUtc = lockoutEnd == DateTimeOffset.MinValue ? (DateTime?)null : lockoutEnd.UtcDateTime;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Set the password hash for a user
		public virtual Task SetPasswordHashAsync(TUser user, string passwordHash)	//(改过)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.PasswordHash = passwordHash;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Set the user's phone number
		public virtual Task SetPhoneNumberAsync(TUser user, string phoneNumber)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.PhoneNumber = phoneNumber;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Set PhoneNumberConfirmed on the user
		public virtual Task SetPhoneNumberConfirmedAsync(TUser user, bool confirmed)	// 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.PhoneNumberConfirmed = confirmed;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Set the security stamp for the user
		public virtual Task SetSecurityStampAsync(TUser user, string stamp) // 改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.SecurityStamp = stamp;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Set whether two factor authentication is enabled for the user
		public virtual Task SetTwoFactorEnabledAsync(TUser user, bool enabled)//改好
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			user.TwoFactorEnabled = enabled;
			return Task.FromResult(0);
		}
		//
		// Summary:
		//     Update an entity
		public virtual Task UpdateAsync(TUser user)
		{
			if (user == null)
			{
				throw new ArgumentNullException("user");
			}
			return mBll.UpdateAsync(user);
		}
		protected virtual void Dispose(bool disposing)
		{
		}
		protected virtual Task<TUser> GetUserAggregateAsync(Expression<Func<TUser, bool>> filter)
		{
			return Task.FromResult<TUser>(null);
		}
	}
}