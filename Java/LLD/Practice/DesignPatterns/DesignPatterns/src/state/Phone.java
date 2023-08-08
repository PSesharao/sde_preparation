package state;

public class Phone {
    private State state ;

    public Phone(){
        state = new OffState(this) ;
    }

    public State getState(){
        return this.state ;
    }

    public void setState(State state ){
        this.state = state ;
    }

    public void turnOn(){
        System.out.println("Turning On");
    }

    public void turnOff(){
        System.out.println("Turning Off");
    }
}
