using System;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web.Mvc;
using mvcTest.Models;
using System.Collections.Generic;

/*
 * 该类创建步骤:
 * 1. 在 Models 内添加一个 Movie.cs 类.
 * 2. web.config 内添加数据库连接字符串
 * 3. 右击 Controllers 添加 "框架"(scaffolded) -> .. With Views using entity framework
 *      - Model Class 选 Model(xxx)
 *      - Data Context class 选 MovieDBContext(xxx)
 *      - 勾选 Views 下的三个选项
 * 4. 确定后会自动生成相应的 View 文件
 */

namespace mvcTest.Controllers
{
    public class MoviesController : Controller
    {
        private MovieDBContext db = new MovieDBContext();

        // GET: Movies
       /* public ActionResult Index(string searchString)
        {
            var movies = from m in db.Movie
                         select m;
            if (!string.IsNullOrEmpty(searchString))
            {
                movies = movies.Where(s => s.Title.Contains(searchString));   // Lambda表达式
            }
            // return View(db.Movie.ToList());      // 返回整个数据
            return View(movies);                    // 返回查询结果
        }*/

        // 
       // [HttpPost]
        public ActionResult Index(string MovieGenre, string searchString)
        {
            var GenreList = new List<string>();
            var GenreQry = from d in db.Movie
                           orderby d.Genre
                           select d.Genre;

            GenreList.AddRange(GenreQry.Distinct());        // 获取非重复的结果

            // ViewBag.MovieGenre 必须与参数同名!! 因为 cshtml传递过来的数据是以该属性同名的!! 必须与参数对应才能正确传递
            ViewBag.MovieGenre = new SelectList(GenreList);
            var movies = from m in db.Movie
                         select m;

            if (!string.IsNullOrEmpty(searchString))
            {
                movies = movies.Where(s=>s.Title.Contains(searchString));
            }
            if (!string.IsNullOrEmpty(MovieGenre))
            {
                movies = movies.Where(x => x.Genre.Equals(MovieGenre));
            }

            return View(movies);
        }

        // GET: Movies/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Movie movie = db.Movie.Find(id);
            if (movie == null)
            {
                return HttpNotFound();
            }
            return View(movie);
        }

        // GET: 点击创建按钮时调用这个函数
        public ActionResult Create()
        {
            return View();
        }

        // POST: Movies/Create
        // 创建结束后调用这个函数, 页面数据会提交到这里
        [HttpPost]
        [ValidateAntiForgeryToken]      // 与 Create.cshtml 内的 @Html.AntiForgeryToken() 对应防止伪造跨站请求
        /*
         * 参数 Bind 是防御重复提交攻击;
         * 或者放在模型类的上面一行
         */
        public ActionResult Create([Bind(Include = "ID,Title,ReleaseDate,Genre,Price")] Movie movie)
        {
            if (ModelState.IsValid)
            {
                db.Movie.Add(movie);
                db.SaveChanges();
                return RedirectToAction("Index");
            }
           // UpdateModel(movie);
            return View(movie);
        }

        // GET: Movies/Edit/5
        /* 点击编辑按钮的时候会调用这个函数
         * 显示一个表单为 <form action='Movies/Edit/id' method='post' /> 的编辑页面
         * 该页面提交后,会提交到使用了 [HttpPost] 的 Edit(..) 方法上. 隐藏的数据是一个 Model
         */
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Movie movie = db.Movie.Find(id);
            if (movie == null)
            {
                return HttpNotFound();
            }

            return View(movie);
        }

        // POST: Movies/Edit/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Title,ReleaseDate,Genre,Price")] Movie movie)
        {
            // 模型状态, 用户输入验证失败后该值= false 
            if (ModelState.IsValid)
            {
                db.Entry(movie).State = EntityState.Modified;       // 一种更新模型数据的方式
                db.SaveChanges();                                   // 将模型内的数据更新到数据库
                return RedirectToAction("Index");
            }
            return View(movie);
        }

       /* 
        * 除了使用 Bind 参数防止重复提交攻击外, 还可以用 UpdateModel() 指定需要更新的列表
        * 即可防止多余的字段提交(防止注入多余字段提交)
        * [HttpPost]
        public ActionResult Edit(int id, FormCollection formValues)
        {
            try
            {
                Movie moive = db.Movie.FirstOrDefault(s => s.ID.Equals(id));
                UpdateModel(moive, new string[] { "Genre", "Price"});
                db.SaveChanges();

                return RedirectToAction("Index");
            }
            catch
            {
                throw;
            }
        }*/

        // GET: Movies/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Movie movie = db.Movie.Find(id);
            if (movie == null)
            {
                return HttpNotFound();
            }
            return View(movie);
        }

        // POST: Movies/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Movie movie = db.Movie.Find(id);
            db.Movie.Remove(movie);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
