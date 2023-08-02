package observer;

public class EmailAlertObserverImpl implements NotificationAlertObserver {

    String userName ;
    String emailId ;
    StocksObservable observable ;

    public EmailAlertObserverImpl(String userName , String emailId  , StocksObservable observable ){
        this.userName = userName ;
        this.emailId = emailId ;
        this.observable = observable ;
    }

    @Override
    public void update() {
        sendEmail( userName , emailId , " HurryUp ! Product is available now in the stock with quantity : " +
                observable.getStockCount() );
    }

    private void sendEmail( String userName , String emailId , String message ){
        System.out.println("Message is sent to " + userName + " and the email " + emailId + message );
    }
}
