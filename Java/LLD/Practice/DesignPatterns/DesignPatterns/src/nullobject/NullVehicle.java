package nullobject;

public class NullVehicle extends Vehicle{
    @Override
    int getWheels() {
        return 0;  // defaulted or do nothing behaviour
    }
}
