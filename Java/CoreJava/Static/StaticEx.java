package Static;

public class StaticEx {

    // Static is executed before the main method at the time of classloading ,
    // So, we can execute a program with-out main method

    static int count ;
    int id ;
    String name ;

    public static void main(String[] args) {
        new StaticEx().init() ;
        System.out.println("Hello World ");
    }

    void init(){
        count = 1 ;
        id =1 ;
        name = "Sesha" ;
    }


}
