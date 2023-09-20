package Java8Features;

interface Addition{
    int add(int a , int b ) ;

}

public class FunctionalInterfaceEx {

    public static void main(String[] args) {
        Addition addObj = (a , b) -> {
            return a+b ;
        };

        Addition addObj1 = (a , b) -> a+b ;

        System.out.println(addObj1.add(10 , 5 ));


    }
}
