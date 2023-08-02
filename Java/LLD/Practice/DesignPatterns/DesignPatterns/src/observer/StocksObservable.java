package observer;

public interface StocksObservable{
    public void add(NotificationAlertObserver notificationAlertObserver) ;

    public void remove(NotificationAlertObserver notificationAlertObserver) ;

    public void notifyAllSubscribers() ;

    public void updateStockCount(int stock) ;

    public int getStockCount() ;
}
