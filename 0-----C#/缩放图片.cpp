using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Drawing;
using System.Drawing.Imaging;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net.Mail;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
	class Program
	{
		static void Main(string[] args)
		{
			FileInfo ff = new FileInfo("F:\\temp\\katana.png");

			Image f = Image.FromFile(ff.FullName);

			int h = f.Height;
			int w = f.Width;
			Console.WriteLine(w + " - " + h);

			// 计算等比例缩放
			if (h > w)
			{
				w = 256;
				h = w * f.Height / f.Width;
			}
			else
			{
				h = 256;
				w = h * f.Width / f.Height;
			}

			Bitmap bitmap = new Bitmap(w, h);
			Graphics g = Graphics.FromImage(bitmap);
			g.DrawImage(f, 0, 0, w, h);
			bitmap.Save("F:\\temp\\sd" + ff.Extension);
			g.Dispose();
			bitmap.Dispose();
			f.Dispose();

			Console.WriteLine(w + " - " + h);
		}


		public static ImageFormat getFormat(string filePath)
		{
			ImageFormat format = ImageFormat.MemoryBmp;
			String Ext = System.IO.Path.GetExtension(filePath).ToLower();

			if (Ext.Equals(".png")) format = ImageFormat.Png;
			else if (Ext.Equals(".jpg") || Ext.Equals(".jpeg")) format = ImageFormat.Jpeg;
			else if (Ext.Equals(".bmp")) format = ImageFormat.Bmp;
			else if (Ext.Equals(".gif")) format = ImageFormat.Gif;
			else if (Ext.Equals(".ico")) format = ImageFormat.Icon;
			else if (Ext.Equals(".emf")) format = ImageFormat.Emf;
			else if (Ext.Equals(".exif")) format = ImageFormat.Exif;
			else if (Ext.Equals(".tiff")) format = ImageFormat.Tiff;
			else if (Ext.Equals(".wmf")) format = ImageFormat.Wmf;
			else if (Ext.Equals(".memorybmp")) format = ImageFormat.MemoryBmp;

			return format;
		}
	}
}
