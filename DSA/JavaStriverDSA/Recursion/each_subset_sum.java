import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;


    private static void subSetSum(int A[] , int idx , int sum , List<Integer> list) {

        if(idx == A.length ) {
            list.add(sum) ;
            return ; 
        }

        subSetSum(A , idx+1 , sum+A[idx] , list ) ;
        subSetSum(A , idx+1 , sum , list ) ;
    }
 


    public static void main( String[] args ) throws IOException {
        initialize();  
        List<Integer> list = new ArrayList<>() ; 
        int A[] = {5,2,1} ;
        subSetSum(A , 0 , 0 , list) ;
        out.println(list);
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
