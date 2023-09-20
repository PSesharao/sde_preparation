package Concurrency;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

class C1 implements Callable<Integer> {
    @Override
    public Integer call() throws Exception {

        System.out.println("This is " + Thread.currentThread().getName());
        // Simulate some computation delay
        Thread.sleep(10000); // Sleep for 10 seconds
        return 12; // Return a result
    }
}

public class Example1 {

    public static void main(String[] args) {

        Callable<Integer> callableTask = new C1() ;
        FutureTask<Integer> futureTask = new FutureTask<>(callableTask);
        // This FutureTask is of type Runnable
        Thread t1 = new Thread( futureTask , "callable") ;
        t1.start();

        try {
            // Wait for the task to finish and get the result
            int result = futureTask.get();
            System.out.println("Result: " + result);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        System.out.println("This is " + Thread.currentThread().getName());

    }
}
