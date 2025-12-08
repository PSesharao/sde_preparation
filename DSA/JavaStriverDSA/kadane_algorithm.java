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

    public static int maxSubArray(int[] nums) {
        int curr_sum =nums[0] ;
        int max_so_far = nums[0] ; // initialize to 0 in case to avoid -ve sum 
        for(int i=1 ; i<nums.length ; i++ ){
            curr_sum = Math.max(curr_sum + nums[i] , nums[i] ) ; 
            max_so_far = Math.max(max_so_far, curr_sum ) ; 
        }
        return max_so_far ; 
    }
 

    public static void main( String[] args ) throws IOException {
        initialize();  
        int A[] = {-2,1,-3,4,-1,2,1,-5,4} ; 
        int ans = maxSubArray(A) ; 
        out.println(ans) ; 
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
