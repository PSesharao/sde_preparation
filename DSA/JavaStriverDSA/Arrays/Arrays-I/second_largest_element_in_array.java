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




    public static void main( String[] args ) throws IOException {

        initialize() ;   
        int A[] = { 7 , 9 , 5 , 4 , 11 , 11 } ; 

        int largest = -1 ; 
        int secondLargest = -1 ;

        for( int num : A ) {

            if( num > largest ){
                
                secondLargest = largest ; 
                largest = num ; 


            }else if( ( num > secondLargest ) && ( num != largest ) ){
                secondLargest = num ; 
            }
        }

        out.println(largest) ; 
        out.println(secondLargest) ; 
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
