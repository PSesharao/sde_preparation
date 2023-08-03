package abstractfactory;

public class AbstractFactoryDesignPattern {
    public static void main(String[] args) {


        Vehicle v1 = VehicleFactoryProducer.getFactory("car").getVehicle("Micro Car" );
        Vehicle v2 = VehicleFactoryProducer.getFactory("bike").getVehicle("Sports Bike" );

        v1.getInfo();
        v2.getInfo();

    }
}
