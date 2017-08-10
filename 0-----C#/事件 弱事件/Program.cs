using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Wrox.ProCSharp.Delegates
{
    class Program
    {
        static void Main(string[] args)
        {
            // 内部发送事件
            var dealer = new CarDealer();

            var michael = new Consumer("1111");

            // 绑定 dealer 内的 NewCarInfo 事件到 michael.NewCarIsHere 函数
            WeakEventManager<CarDealer, CarInfoEventArgs>.AddHandler(dealer, "NewCarInfo", michael.NewCarIsHere);

            dealer.NewCar("aaaa");

            // 添加一个响应函数
            var sebastian = new Consumer("2222");
            WeakEventManager<CarDealer, CarInfoEventArgs>.AddHandler(dealer, "NewCarInfo", sebastian.NewCarIsHere);

            dealer.NewCar("bbb");

            // 取消 michael 响应函数
            WeakEventManager<CarDealer, CarInfoEventArgs>.RemoveHandler(dealer, "NewCarInfo", michael.NewCarIsHere);

            dealer.NewCar("ccccc");
        }
    }
}
