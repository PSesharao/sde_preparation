package Threads;


class Resource1 implements Runnable {

    public static int counter = 0; // Shared resource for all the instances

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            incrementCounter() ; // Increment the counter
        }
    }

    private synchronized static void incrementCounter() {
        counter++;
    }
}

public class ExampleSynchronization {
    public static void main(String[] args) {

        Thread thread1 = new Thread(new Resource1());
        Thread thread2 = new Thread(new Resource1());

        thread1.start();
        thread2.start();

        // Below 2 statements are added
        // for the purpose of blocking main thread from printing the counter before executing these threads
        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Final Counter Value: " + Resource1.counter);
    }
}
