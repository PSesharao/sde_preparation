package observer;

import java.util.ArrayList;
import java.util.List;

public class ObserverDesignPattern {

    public static void main(String[] args) {

        StocksObservable iphoneStocksObservable = new IphoneObservableImpl() ;

        NotificationAlertObserver observer1 = new EmailAlertObserverImpl("Sesh" , "pari@gmail.com" , iphoneStocksObservable ) ;

        NotificationAlertObserver observer2 = new EmailAlertObserverImpl("Sesh" , "sesh@gmail.com" , iphoneStocksObservable ) ;

        NotificationAlertObserver observer3 = new MobileAlertObserverimpl("Sesh" , "1234567890" , iphoneStocksObservable ) ;

        iphoneStocksObservable.add(observer1);
        iphoneStocksObservable.add(observer2);
        iphoneStocksObservable.add(observer3);

        iphoneStocksObservable.updateStockCount(10);

        iphoneStocksObservable.updateStockCount(-10);

        iphoneStocksObservable.updateStockCount(1);

        iphoneStocksObservable.updateStockCount(-10);

    }
}
