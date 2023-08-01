package observer;

import java.util.ArrayList;
import java.util.List;

public class ObserverDesignPattern {

    interface StocksObservable{
        void add(NotificationAlertObserver notificationAlertObserver) ;

        void remove(NotificationAlertObserver notificationAlertObserver) ;

        void notifyAllSubscribers() ;

        void updateStockCount(int stock) ;

        int getStockCount() ;
    }

    class IphoneObservableImpl implements StocksObservable{

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

            if(stockCount + newStock >=0 ) {
                stockCount += newStock;
                notifyAllSubscribers();
            }
        }

        @Override
        public int getStockCount() {
            return stockCount ;
        }
    }


    interface NotificationAlertObserver{
        void update() ;
    }

    class EmailAlertObserverImpl implements NotificationAlertObserver{

        String emailId ;
        StocksObservable observable ;

        EmailAlertObserverImpl(String emailId  , StocksObservable observable ){
            this.emailId = emailId ;
            this.observable = observable ;
        }

        @Override
        public void update() {
            sendEmail(emailId , "HurryUp ! Product is available now in the stock with quantity : " +
                    observable.getStockCount() );
        }

        private void sendEmail(String emailId , String message ){

        }
    }

    class MobileAlertObserverimpl implements NotificationAlertObserver{

        @Override
        public void update() {

        }
    }


}
