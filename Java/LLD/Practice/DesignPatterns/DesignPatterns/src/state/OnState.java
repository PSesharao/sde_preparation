package state;

public class OnState extends State{

    public OnState(Phone phone ){
        super(phone);
    }

    @Override
    public void pressPowerButton() {

        phone.setState(new OffState(phone));
        phone.turnOff();
    }
}
