import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ;
 

class Heap {
    private static final int minVal = - (int) (1e9) ;
    private List<Integer> heapArr ;
 
    public Heap() {
        heapArr = new ArrayList<>() ;
    }
 
    private int getParentInd(int i) {
        int parentInd = (i-1)/2 ; 
        //return heapArr.get(parentInd) ; 
        return parentInd ; 
    }

    private int getLeftChildInd(int i) {
        int leftChildInd = (2*i) +1 ; 
        return leftChildInd ; 
    }

    private int getRightChildInd(int i) {
        int rightChildInd = (2*i) +2 ; 
        return rightChildInd ;
    }
 
 
    private void swap(int i , int j) {
        int temp = heapArr.get(i) ; 
        heapArr.set(i , heapArr.get(j)) ;
        heapArr.set(j , temp ) ;
    }
 
    private void shiftUp(int i) {
        while( i>0 ) {
            int parentInd = getParentInd(i) ; 
            if( heapArr.get(i) > heapArr.get(parentInd) ){
                swap(i , parentInd) ; 
                i = parentInd ; 
            }else 
                break ; 
        }
    }

    private void shiftDown(int i) {
        while( true ) {
            int largest = i ;
            int leftChildInd = getLeftChildInd(i) ; 

            if( leftChildInd < heapArr.size() ) {
                if(heapArr.get(leftChildInd) > heapArr.get(largest))
                    largest = leftChildInd ; 

                int rightChildInd = getRightChildInd(i) ; 
                if( rightChildInd < heapArr.size() ) {
                    if(heapArr.get(rightChildInd) > heapArr.get(largest))
                        largest = rightChildInd ; 
                } 

            }else
                break ; 

            if(largest == i)
                break ; 

            swap(i , largest ) ; 
            i = largest ; 
        }
    }

    public int extractMax() {
        if(heapArr.isEmpty())
            return minVal ; 

        int max = heapArr.get(0) ; 
        int last = heapArr.get(heapArr.size()-1) ; 
        heapArr.set(0 , last) ; 
        shiftDown(0) ; 
        heapArr.remove(heapArr.size()-1) ; 
        return max ; 
    }

    public void printHeap(){
        while( !heapArr.isEmpty() ) {
            System.out.print( extractMax() + " " ) ; 
        }
    }
 
    public void insert(int element) {
        heapArr.add(element) ; 
        int lastInd = heapArr.size()-1 ;
        shiftUp(lastInd) ;
    }
}

class JavaMain {
    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;
 
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int A[] = {5 , 7 , 4 , 1 , 3} ;
        Heap heap = new Heap() ; 
        for(int num : A)
            heap.insert(num) ;

        heap.printHeap(); 
        //out.println(heap.extractMax()) ;  
        close() ; 
    }

    private static void initialize() throws IOException , FileNotFoundException {
        in = new FastReader();
        out = new FastWriter();
    }
    private static void close() throws IOException  {
        in.close();
        out.close();
    }

}
 