package abstractfactory;

public class NormalBike implements Vehicle{
    @Override
    public void getInfo() {
        System.out.println("I am a Normal Bike! ");
    }
}
