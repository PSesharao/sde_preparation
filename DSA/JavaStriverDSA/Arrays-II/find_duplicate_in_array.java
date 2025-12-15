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

    public static int findDuplicate(int[] nums) {
        // We are basically starting from the 
        // first number of the array itself for 
        // constructing the LL
 
        // usually we follow index -> val -> index pattern for constructing the LL
 
        int slow_ptr = nums[0]; 
        int fast_ptr = nums[0];
 
        // For First collision needs sp , fp to be moved at least once , 
        // as we have initialized them to be the same with first element.
        do{
            slow_ptr = nums[slow_ptr] ; 
            fast_ptr = nums[nums[fast_ptr]] ; 
        }while(slow_ptr != fast_ptr ) ;
 
        // Now first collision would have happened at slow_ptr / fast_ptr
        // Let's reset fast_ptr to start.
        fast_ptr = nums[0] ;
 
        // while loop because , the slow and fast pointer could possibly collide at the start of 
        // the loop it self.
 
        while(slow_ptr != fast_ptr ) {
            slow_ptr = nums[slow_ptr] ; 
            fast_ptr = nums[fast_ptr] ; 
        }
 
        // either slow / fast ptr will have this.
        return slow_ptr ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int[] nums =  {2,1,4,2,3} ; // {3,4,1,4,2} ;  // {1,3,4,2,2} ; 
        int ans = findDuplicate(nums) ; 
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
