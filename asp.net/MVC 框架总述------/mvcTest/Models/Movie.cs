using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
/*
* 
*/

namespace mvcTest.Models
{
    public class Movie
    {
        public int ID { get; set; }

       // [Required] 
        [Display(Name="电影名")]       // 页面显示的时候使用中文代替
        public string Title { get; set; }

        //[StringLength(100, MinimumLength = 3)]
        [Display(Name ="上映时间")]
        [DataType(DataType.Date)]
        public DateTime ReleaseDate { get; set; }

        [Display(Name="类型")]
        public string Genre { get; set; }

        [Display(Name ="价格")]
        public decimal Price { get; set; }
    }

    /*
     * web.config 内的 <connectionStrings> 的 name 必须与 MovieDBContext 相同
     */
    public class MovieDBContext : DbContext
    {
        /*
         Movie 名称不能改!
         */
        public DbSet<Movie> Movie { get; set; }
    }
}