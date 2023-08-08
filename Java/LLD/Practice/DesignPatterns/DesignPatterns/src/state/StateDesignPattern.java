package state;

public class StateDesignPattern {

    public static void main(String[] args) {

        Phone phone = new Phone() ; // By default it is in Off state
        phone.getState().pressPowerButton(); //  It will go to On state
        phone.getState().pressPowerButton(); // //  It will go to Off state again
    }
}
