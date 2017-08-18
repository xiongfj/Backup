using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 抽象构建者, 提供构建步骤
abstract class VehicleBuilder
{
    protected Vehicle vehicle;// 产品
    public Vehicle Vehicle
    {
        get { return vehicle; }
    }
    abstract public void BuildEngine();
    abstract public void BuildFrame();
    abstract public void BuildWheels();
    abstract public void BuildDoors();
}


class MotorCycleBuilder : VehicleBuilder
{
    public override void BuildFrame()
    {
        vehicle = new Vehicle("MotorCycle");
        vehicle["frame"] = "0";
    }

    public override void BuildDoors()
    {
        vehicle["doors"] = "0";
    }

    public override void BuildEngine()
    {
        vehicle["engine"] = "500 CC";
    }

    public override void BuildWheels()
    {
        vehicle["wheels"] = "2";
    }
}

class CarBuilder : VehicleBuilder
{
    public override void BuildDoors()
    {
        vehicle["doors"] = "4";
    }

    public override void BuildEngine()
    {
        vehicle["engine"] = "2500 cc";
    }

    public override void BuildFrame()
    {
        vehicle = new Vehicle("Car");
        vehicle["frame"] = "Car Frame";
    }

    public override void BuildWheels()
    {
        vehicle["wheels"] = "4";
    }
}
