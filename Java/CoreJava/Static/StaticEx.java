package Static;

public class StaticEx {

    // Static is executed before the main method at the time of classloading ,
    // So, we can execute a program with-out main method
    static {
        System.out.println("static block is invoked");
    }

    public static void main(String[] args) {

        String str ;
        System.out.println("Hello World ");
    }
}
