public class Test {
    public static void main(String[] args) {
        System.out.println("Java Program started ") ;
        printSystemProperties() ;
    }

    private static void printSystemProperties() {
        System.out.println("Printing system properties :");
        System.out.print(System.getProperties());
    }
}
