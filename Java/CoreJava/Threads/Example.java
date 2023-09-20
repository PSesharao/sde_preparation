package Threads;

class T1 extends Thread{

    public void run() {

        for (int i = 0; i < 150; i++) {
            System.out.println(Thread.currentThread().getName());
            //System.out.println(Thread.currentThread().getId() + " Value " + i);
        }
    }
}

class T2 implements Runnable{

    @Override
    public void run() {
        for (int i = 0; i < 150; i++) {
            System.out.println(Thread.currentThread().getName());
            //System.out.println(Thread.currentThread().getId() + " Value " + i);
        }
    }
}

public class Example {

    public static void main(String[] args)  {

        Thread thread1 = new T1() ;
        thread1.start();
        //System.out.println("This is main thread");
        System.out.println(Thread.currentThread().getName());
        Thread thread2 = new Thread( new T2()) ;
        thread2.start();
    }

}
