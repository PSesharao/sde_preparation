package Polymorphism;

class Parent {
    public void show() {
        System.out.println("I'm Parent !!!");
    }

    public void parentMethod()
    {
        System.out.println("I'm a Parent Method !!");
    }
}

class Child extends Parent {
    public void show() {
        System.out.println("I'm Child !!!");
    }

    public void childMethod() {
        System.out.println("I'm child method !!!");
    }
}


public class RuntimePolymorphism {

    public static void main(String[] args) {

        Child ch1 = new Child();
        ch1.childMethod();
        ch1.show();
        ch1.parentMethod();


        Parent ch2 = new Child() ;
    //  ch2.childMethod(); does not work
        ((Child)ch2).childMethod(); // This works, but be cautious with type casting
        ch2.show();
        ch2.parentMethod();


    // Child ch3 = (Child) new Parent();    does not work


    }
}
