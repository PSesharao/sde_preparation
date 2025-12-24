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

    public static int majorityElement(int[] nums) {
        int count = 1 ; 
        int element = nums[0] ; // becuase 1 <= nums.length <= 5 * 104
        // or else we can set count to 0 and iterate from 0th element as well
        for(int i=1 ; i<nums.length ; i++ ){
            if(count == 0 )
                element = nums[i] ; // reset
 
            if(element == nums[i])
                count ++ ; 
            else 
                count -- ; 
        } 
        return element ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int nums[] = {2,2,1,1,1,2,2} ;
        int ans = majorityElement( nums ) ; 
        out.println( ans ) ; 
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
