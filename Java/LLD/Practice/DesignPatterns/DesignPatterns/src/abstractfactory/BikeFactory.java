package abstractfactory;

public class BikeFactory extends AbstractVehicleFactory{

    @Override
    public Vehicle getVehicle(String vehicleType) {
        if(vehicleType.equals("Normal Bike")) {
            return new NormalBike() ;
        } else if (vehicleType.equals("Sports Bike")) {
            return new SportsBike() ;
        }else {
            return null;
        }
    }
}
