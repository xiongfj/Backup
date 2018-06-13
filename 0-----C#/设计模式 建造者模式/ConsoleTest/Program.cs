
/*
 * 指导者, 调用建造函数
 */
class Shop
{
    public void Construct(VehicleBuilder builder){
        builder.BuildFrame();
        builder.BuildEngine();
        builder.BuildWheels();
        builder.BuildDoors();
    }
}

/*
 * 需要生成的产品对象有复杂的内部结构
 * 产品对象的属性相互依赖; 指导者可以控制生成顺序
 * 
 * 使用环境:
 * 建造者模式的目的是: 需要生成 Vehicle 对象; 
 * 但是需要用到其它数据或对象才能生成该对象;
 * 此时就需要用到 VehicleBuilder 来引入其它数据或对象; 构建 Vehicle 对象
 */

public class BuilderApp
{
    public static void Main(){
        Shop shop = new Shop();
        VehicleBuilder b1 = new MotorCycleBuilder();
        VehicleBuilder b2 = new CarBuilder();

        shop.Construct(b1);
        b1.Vehicle.Show();

        shop.Construct(b2);
        b2.Vehicle.Show();
    }
}

