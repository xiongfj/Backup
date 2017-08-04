using System;
using System.ComponentModel;

namespace ConsoleTest
{
    // 自定义封装一个类, 然后可以把这个类作为事件的参数发送出去
    // 从而实现数据的传递
    // 类里面可以封装自己想要的数据
    /*internal class MyEventArgs : EventArgs
    {
        private string keyWord;
        public MyEventArgs(string keyChar) : base()
        {
            this.keyWord = keyChar;
        }

        public string KeyChar
        {
            get
            {
                return keyWord;
            }
        }
    }*/

    // 以上使用系统已经定义好的 PropertyChangedEventArgs, 该参数内部只有一个 string 存储数据

    // 发送事件
    internal class EventSender
    {
        // 对应系统的委托 public delegate void EventHandler<TEventArgs>(object sender, TEventArgs e);
        public static event PropertyChangedEventHandler myEvent;
        public static event PropertyChangedEventHandler myEvent2;

        // 测试发送事件
        public void testEvent(string msg)
        {
            // 自定义包装一个 EventArgs, 作为数据传递出去
            myEvent(this, new PropertyChangedEventArgs(msg));
            myEvent2(this, new PropertyChangedEventArgs("Lambda 表达式响应事件."));
        }
    }

    // 接收事件
    internal class ReceiveEvent
    {
        // 绑定事件与响应函数
        public ReceiveEvent()
        {
            EventSender.myEvent += onEvent;

            // 直接指定响应函数
            EventSender.myEvent2 += (o, arg) =>
                {
                    Console.WriteLine("发送事件的类: {0} \n附带数据: {1}\n", o.GetType().Name, arg.PropertyName);
                };
        }

        // 处理接受的事件
        private void onEvent(object obj, PropertyChangedEventArgs arg)
        {
            Console.WriteLine( "发送事件的类: {0} \n附带数据: {1}\n", obj.GetType().Name, arg.PropertyName);
        }
    }

    //
    class Program
    {
        static void Main(string[] args)
        {
            ReceiveEvent receive = new ReceiveEvent();

            EventSender sender = new EventSender();
            sender.testEvent("hello kitty!");
        }
    }
}
