package abstractfactory;

public class CarFactory extends AbstractVehicleFactory{
    @Override
    public  Vehicle getVehicle(String vehicleType) {
        if(vehicleType.equals("Micro Car")) {
            return new MicroCar() ;
        } else if (vehicleType.equals("Mega Car")) {
            return new MegaCar() ;
        }else {
            return null;
        }
    }
}
