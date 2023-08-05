package nullobject;

public class NullObjectPattern {
    public static void main(String[] args) {

        Vehicle vehicle = VehicleFactory.getVehicle("something else") ;
        // This will return the NullVehicle Instance

        System.out.println(vehicle.getWheels());
    }
}
