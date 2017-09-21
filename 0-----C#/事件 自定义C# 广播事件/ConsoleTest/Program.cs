using System;

namespace ConsoleTest
{
    // 自定义封装一个类, 然后可以把这个类作为事件的参数发送出去
    // 从而实现数据的传递
    // 类里面可以封装自己想要的数据
    internal class MyEventArgs : EventArgs
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
    }

    // 发送事件
    internal class EventSender
    {
        // 自定义一个委托
        public delegate void EventHandler(object sender, MyEventArgs e);

        // 定义委托关联事件
        public static event EventHandler myEvent;
        public static event EventHandler myEvent2;

        // 测试发送事件
        public void testEvent(string msg)
        {
            // 自定义包装一个 EventArgs, 作为数据传递出去
            myEvent(this, new MyEventArgs(msg));
            myEvent2(this, new MyEventArgs("Lambda 表达式响应事件."));
        }
    }

    // 接收事件
    internal class ReceiveEvent
    {
        // 绑定事件与响应函数
        public ReceiveEvent()
        {
            EventSender.myEvent += onEvent;

			// 事件发送只能在定义这个事件的类里面发送!!!??!?
			//EventSender.myEvent(this, new MyEventArgs("Lambda 表达式响应事件."));

            // 直接指定响应函数
            EventSender.myEvent2 += (o, arg) =>
                {
                    Console.WriteLine("发送事件的类: {0} \n附带数据: {1}\n", o.GetType().Name, arg.KeyChar);
                };
        }

        // 处理接受的事件
        private void onEvent(object obj, MyEventArgs arg)
        {
            Console.WriteLine( "发送事件的类: {0} \n附带数据: {1}\n", obj.GetType().Name, arg.KeyChar);
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
