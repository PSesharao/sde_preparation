package strategy;


interface PaymentStrategy {
    public void pay(int amount);
}

class CreditCardStrategy implements PaymentStrategy {

    private String name;
    private String cardNumber;
    private String cvv;
    private String dateOfExpiry;

    public CreditCardStrategy(String nm, String ccNum, String cvv, String expiryDate){
        this.name=nm;
        this.cardNumber=ccNum;
        this.cvv=cvv;
        this.dateOfExpiry=expiryDate;
    }
    @Override
    public void pay(int amount) {
        System.out.println(amount +" paid with credit/debit card");
    }

}

class PaypalStrategy implements PaymentStrategy {

    private String emailId;
    private String password;

    public PaypalStrategy(String email, String pwd){
        this.emailId=email;
        this.password=pwd;
    }

    @Override
    public void pay(int amount) {
        System.out.println(amount + " paid using Paypal.");
    }

}

class PaymentContext {
    private PaymentStrategy paymentStrategy ;

    PaymentContext(PaymentStrategy paymentStrategy){
        this.paymentStrategy = paymentStrategy ;
    }

    void makePayment( int amount ){
        paymentStrategy.pay(amount);
    }
}

public class StrategyDesignPattern {
    public static void main(String[] args) {
        PaymentStrategy paypalStrategy = new PaypalStrategy("paypal_email@gmail.com" , "paypal_pwd" ) ;


        PaymentStrategy creditCardStrategy =
                new CreditCardStrategy("Pankaj Kumar", "1234567890123456", "786", "12/15") ;

        PaymentContext paymentContext = new PaymentContext(paypalStrategy) ;

        paymentContext.makePayment(120);

        paymentContext = new PaymentContext(creditCardStrategy) ;

        paymentContext.makePayment(150);
    }
}
