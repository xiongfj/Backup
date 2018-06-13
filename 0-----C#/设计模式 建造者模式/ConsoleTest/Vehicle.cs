using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/* 最终目的是生成该类对象
 * 作为 VehicleBuilder 成员数据; 被 VehicleBuilder 构建; 
 * 
 * VehicleBuilder 可以引用一些其它对象构建产品
 */
public class Vehicle
{
    private string type;
    private Hashtable parts = new Hashtable();

    public Vehicle(string type){
        this.type = type;
    }
    public object this[string key] {
        get { return parts[key]; }
        set { parts[key] = value; }
    }

    public void Show(){
        Console.WriteLine("Vehicle type: " + type);
        Console.WriteLine("Frame: " + parts["frame"]);
        Console.WriteLine("Engine: " + parts["engine"]);
        Console.WriteLine("#Wheels: " + parts["wheels"]);
        Console.WriteLine("Doors: " + parts["doors"]);
    }
}
