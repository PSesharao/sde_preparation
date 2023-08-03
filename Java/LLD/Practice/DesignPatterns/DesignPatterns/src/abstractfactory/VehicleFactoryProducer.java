package abstractfactory;

public class VehicleFactoryProducer {
    public static AbstractVehicleFactory getFactory(String factory ){
        if(factory.equals("car")) {
            return new CarFactory() ;
        } else if (factory.equals("bike")) {
            return new BikeFactory() ;
        }else {
            return null;
        }
    }
}
