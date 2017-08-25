using System;
using System.Text;
using System.Collections;

abstract class Component
{
    protected string name;

    public Component(string name)
    {
        this.name = name;
    }

    public abstract void Display(int depth);
}

// 做树枝节点, 后面链接子节点
class Composite : Component
{
    private ArrayList children = new ArrayList();
    public Composite(string name) : base(name) { }

    public void Add(Component component)
    {
        children.Add(component);
    }

    public void Remove (Component component)
    {
        children.Remove(component);
    }

    public override void Display(int depth)
    {
        Console.WriteLine( new String('-', depth) + name);
        foreach(Component component in children)
        {
            component.Display(depth + 2);
        }
    }
}

// 做树叶节点, 该节点没有子节点
class Leaf : Component
{
    public Leaf(string name) : base(name) { }

    public override void Display(int depth)
    {
        Console.WriteLine(new String ('-', depth) + name);
    }
}

/* 定义数据结构
 * -root
 *  1.
 *  2.
 *  3.node
 *      3.1
 *      3.2
 *      ...
 *  4.
 *  5.node_5
 *      5.1
 *      5.2
 *      ..
 */

public class Client
{
    public static void Main()
    {
        Composite root = new Composite("root");
        root.Add( new Leaf("Leaf-A") );
        root.Add(new Leaf("Leaf-B"));

        Composite comp = new Composite("Composite X");
        comp.Add(new Leaf("Leaf XA"));
        comp.Add(new Leaf("Leaf XB"));
        root.Add(comp);

        root.Add(new Leaf("Leaf C"));

        Leaf l = new Leaf("Leaf D");
        root.Add(l);
        root.Remove(l);

        root.Display(1);
    }
}