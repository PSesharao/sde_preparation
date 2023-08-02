package observer;

public class MobileAlertObserverimpl implements NotificationAlertObserver {

    String userName ;
    String mobileNumber ;
    StocksObservable observable ;

    public MobileAlertObserverimpl( String userName , String mobileNumber ,  StocksObservable observable  ){
        this.userName = userName ;
        this.mobileNumber = mobileNumber ;
        this.observable = observable ;
    }

    @Override
    public void update() {
        sendEmail( userName , mobileNumber , " HurryUp ! Product is available now in the stock with quantity : " +
                observable.getStockCount() );
    }

    private void sendEmail(String userName, String mobileNumber, String message ) {
        System.out.println("Message is sent to " + userName + " and the mobile  " + mobileNumber +  message );
    }


}
