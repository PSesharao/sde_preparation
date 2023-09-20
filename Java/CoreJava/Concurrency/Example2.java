package Concurrency;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class WorkerThread implements Runnable {

    private int taskNumber ;

    public WorkerThread(int taskNumber){
        this.taskNumber = taskNumber ;
    }

    @Override
    public void run() {
        System.out.println("Task " + taskNumber + " is being executed by thread: " + Thread.currentThread().getName());
    }
}


public class Example2 {

    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(5);
        //creating a pool of 5 threads

        for (int i = 0; i < 10; i++) { // let's say there are 10 tasks are there
            Runnable worker = new WorkerThread(i);
            executorService.execute(worker); // This will only accept type of Runnable , i.e FutureTask also incase of callable
            //calling execute method of ExecutorService
        }

        executorService.shutdown(); // We should do this , otherwise program does not stop
        while (!executorService.isTerminated()) {   }

        System.out.println("Finished all threads");
    }
}
