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


    public static int search( int[] nums, int target ) {
        
        int l = 0 , h = nums.length-1 ; 
        int m ;

        while( l <= h ) {
            m = l + ( (h - l)/2 ) ;

            if( nums[m] == target )
                return m ; 

            else if( nums[l] <= nums[m] ){
                // left part is sorted 
                if( ( nums[l] <= target ) && ( target <= nums[m] ) ){
                    h = m-1 ;
                } else {
                    l = m+1 ; 
                }

            }else{
                // right part is sorted
                if( ( nums[m] <= target ) && ( target <= nums[h] ) ){
                    l = m+1 ; 
                }else{
                    h = m-1 ;
                }
            }
        }

        return -1 ;  
    }

    public static void main( String[] args ) throws IOException {

        initialize() ;   
        int A[] = { 6,7,8,1,2,3,4,5 } ; 
        int target = 8 ; 

        int ind = search(A, target) ; 
        out.println(ind);
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
