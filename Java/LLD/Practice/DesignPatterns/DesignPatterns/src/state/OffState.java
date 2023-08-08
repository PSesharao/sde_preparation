package state;

public class OffState extends State{

    public OffState(Phone phone ){
        super(phone);
    }

    @Override
    public void pressPowerButton() {
        phone.setState(new OnState(phone));
        phone.turnOn();
    }
}
