using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using WebApplication9.Models;

namespace WebApplication9.Controllers
{
    public class WebApiController : ApiController
	{
		public static List<Product> products = new List<Product>
		   {
			new Product { Id = 1, Name = "农夫山泉", Category = "water", Price = 2 },
			new Product { Id = 2, Name = "钢笔", Category = "study", Price = 3.75M },
			new Product { Id = 3, Name = "烤肠", Category = "food", Price = 1 },
			new Product { Id = 4, Name = "崂山矿泉水", Category = "water", Price = 1 },
			new Product { Id = 5, Name = "铅笔", Category = "study", Price = 3.75M },
			new Product { Id = 6, Name = "烤羊肉串", Category = "food", Price = 1 }
		   };


		public IEnumerable<Product> GetAllProducts()
		{
			return products;
		}

		//GET: api/WebApi/id 访问
		// 或者 api/WebApi?id=4
		public Product GetProductById(int id)
		{
			var product = products.FirstOrDefault(p => p.Id == id);
			if (product == null)
			{
				throw new HttpResponseException(HttpStatusCode.NotFound);
			}
			return product;
		}

		// GET: /api/WebApi?id=1&price=1
		public Product GetProductById(string cate, int price)
		{
			var product = products.FirstOrDefault(p => p.Category == cate && p.Price >= price);
			if (product == null)
			{
				throw new HttpResponseException(HttpStatusCode.NotFound);
			}
			return product;
		}

		//GET:  api/WebApi?cate=food 访问
		public IEnumerable<Product> GetProductsByCategory(string cate)
		{
			return products.Where(
				(p) => string.Equals(p.Category, cate,
					StringComparison.OrdinalIgnoreCase));
		}


		//POST: /api/WebApi
		public HttpResponseMessage PostProduct(Product item)
		{
			item.Id = products.Count + 1;
			products.Add(item);

			// 返回这个 response, 将会触发前端的 error: function (XMLHttpRequest, textStatus, errorThrown) { 函数
			//var response = Request.CreateResponse<Product>(HttpStatusCode.NotFound, "这里可以返回错误信息到前端");

			var response = Request.CreateResponse<Product>(HttpStatusCode.Created, item);
			string uri = Url.Link("DefaultApi", new { id = item.Id });
			response.Headers.Location = new Uri(uri);

			return response;
		}

		//PUT: /api/WebApi/id
		public void PutProduct(int id, Product product)
		{
			int index = products.FindIndex(p => p.Id == id);
			if (index >= 0)
			{
				products.RemoveAt(index);
				products.Add(product);
			}
			else
			{
				throw new HttpResponseException(HttpStatusCode.NotFound);
			}
		}

		//Delete: /api/WebApi/id
		// 根据函数名称自动决定调用哪个函数, 请求方式未 DELETE, 则调用 Delete开头的函数
		public void Deletexx(int id)
		{
			int index = products.FindIndex(p => p.Id == id);
			if (index >= 0)
			{
				products.RemoveAt(index);
			}else
			{
				throw new HttpResponseException(HttpStatusCode.NotFound);
			}
		}
		
		// /api/WebApi
		public void DeleteAll()
		{

		}
	}
}
