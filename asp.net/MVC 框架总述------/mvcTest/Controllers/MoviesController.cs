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
        public ActionResult Create([Bind(Include = "ID,Title,ReleaseDate,Genre,Price")] Movie movie)
        {
            if (ModelState.IsValid)
            {
                db.Movie.Add(movie);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(movie);
        }

        // GET: Movies/Edit/5
        // 点击编辑按钮的时候会调用这个函数
        public ActionResult Edit(int? id)
        {
            //Response.Write("<script>alert('asdas')</script>");
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
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Title,ReleaseDate,Genre,Price")] Movie movie)
        {
            if (ModelState.IsValid)
            {
                db.Entry(movie).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(movie);
        }

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
