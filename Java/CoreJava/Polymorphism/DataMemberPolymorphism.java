package Polymorphism;


class Bike{
    int speedlimit=90;
}


class Honda extends Bike {
    int speedlimit= 150;
    int price = 1220000;
}

public class DataMemberPolymorphism {

    public static void main(String[] args) {
        Bike b = new Honda() ;
        System.out.println(b.speedlimit);

        // System.out.println(b.price) ; does not work


        System.out.println( ((Honda)b).speedlimit); // This works

    }

}
