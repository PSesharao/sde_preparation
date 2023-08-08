package state;

public abstract class State {
    protected Phone phone ;

    public State(Phone phone){
        this.phone = phone ;
    }

    public abstract void pressPowerButton() ;


}
