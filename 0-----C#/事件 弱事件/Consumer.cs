using System;
using System.Windows;

namespace Wrox.ProCSharp.Delegates
{
    public class Consumer// : IWeakEventListener
    {
        private string name;

        public Consumer(string name)
        {
            this.name = name;
        }

        public void NewCarIsHere(object sender, CarInfoEventArgs e)
        {
            Console.WriteLine("                响应事件 sender {0}: args: {1}", name, e.Car);
        }

        // 不实现这个接口也可以正常使用?!?!?
       /* bool IWeakEventListener.ReceiveWeakEvent(Type managerType, object sender, EventArgs e)
        {
            NewCarIsHere(sender, e as CarInfoEventArgs);
            return false;
        }*/


    }
}
