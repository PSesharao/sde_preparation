package Exceptions;

public class UncheckedExp {

    // Java compiler does not complain when you throw an unchecked exception
    // (also known as a runtime exception) from a method. Unchecked exceptions are
    // subclasses of RuntimeException or are themselves instances of RuntimeException

    public void validate(int age) {

        if(age > 18 )
            throw new ArithmeticException("He is not minor ") ;

        else{
            System.out.println("He is minor ");
        }

    }

    public static void main(String[] args) {
        UncheckedExp exp = new UncheckedExp() ;
        exp.validate(25);
    }
}

