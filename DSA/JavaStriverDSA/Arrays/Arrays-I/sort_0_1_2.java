import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class Solution {

}


class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;

    private static void swap(int[] nums , int i , int j ){
        int temp = nums[i] ; 
        nums[i] = nums[j] ; 
        nums[j] = temp ; 
    } 
    public static void sortColors( int[] nums ) {
        int N = nums.length ;
        int curr_pos = 0 ; 
        int zero_pos = 0 ; 
        int two_pos = N-1 ; 
        while( curr_pos <= two_pos ) {  // we are not going till N , as there might already 
            // be some 2 placed and we dont want to swap them again to front
            if( nums[curr_pos] == 0 ){
                swap(nums , curr_pos , zero_pos) ;
                zero_pos++ ;  
                curr_pos++ ; 
            }else if(nums[curr_pos] == 2) {
                swap(nums , curr_pos , two_pos) ;
                two_pos-- ; 
                // do not increment current position as we need to revisit 
            } else {
                // when nums[curr_pos] == 1
                curr_pos ++ ; 
            }
        }
    }
 

    public static void main( String[] args ) throws IOException {
        initialize();  
        int A[] = {1,2,0} ; 
        sortColors(A) ; 
        out.println(Arrays.toString(A)) ; 
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
