using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace Wrox.ProCSharp.Arrays
{
  public class GameMoves
  {
    private IEnumerator cross;
    private IEnumerator circle;

    public GameMoves()
    {
        cross = Cross();      // 是一种函数指针之类的概念
      circle = Circle();    // 不会调用 Circle?!?!
    }

    private int move = 0;
    const int MaxMoves = 9;

    public IEnumerator Cross()
    {
      while (true)
      {
        Console.WriteLine("Cross, move {0}", move);
        if (++move >= MaxMoves)
          yield break;
        yield return circle;        // 会跳出 while, 返回 circle ,下次就会进入 Circle
      }
    }

    public IEnumerator Circle()
    {
      while (true)
      {
        Console.WriteLine("Circle, move {0}", move);
        if (++move >= MaxMoves)
          yield break;
        yield return cross;
      }
    }
  }

}
