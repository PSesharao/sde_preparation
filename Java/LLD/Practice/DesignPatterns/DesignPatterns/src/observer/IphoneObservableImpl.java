package observer;

import java.util.ArrayList;
import java.util.List;

public class IphoneObservableImpl implements StocksObservable {

    List<NotificationAlertObserver> observerList = new ArrayList<>();
    int stockCount = 0 ;

    @Override
    public void add(NotificationAlertObserver notificationAlertObserver) {
        observerList.add(notificationAlertObserver) ;
    }

    @Override
    public void remove(NotificationAlertObserver notificationAlertObserver) {
        observerList.remove(notificationAlertObserver) ;
    }

    @Override
    public void notifyAllSubscribers() {
        for(NotificationAlertObserver observer : observerList ){
            observer.update();
        }
    }

    @Override
    public void updateStockCount(int newStock) {

        if(stockCount + newStock >= 0 ) {
            stockCount += newStock ;

            if(stockCount > 0 ){
                notifyAllSubscribers();
            }
        }

    }

    @Override
    public int getStockCount() {
        return stockCount ;
    }
}
