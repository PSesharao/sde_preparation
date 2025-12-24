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

    public static List<Integer> majorityElement(int[] nums) {
 
        List<Integer> list = new ArrayList<>() ; 
        int inf = (int) 1e9+1 ; // because -109 <= nums[i] <= 109
        // so strictly taking it outside the range
        int maj1 = inf ; 
        int maj2 = inf ; 
        int count1 = 0 ; // to track maj1
        int count2 = 0 ; // to track maj2
        for( int i=0 ; i<nums.length ; i++ ){
 
            if(count1 == 0 && nums[i] != maj2 ){
                maj1 = nums[i] ; 
                count1 = 1 ; // we have to reset here only 
                // as in one pass we are either looking at maj1 or maj2 or others (minority elements)
                // in conditional if else if blocks.
            }else if(count2 == 0 && nums[i] != maj1 ){
                maj2 = nums[i] ; 
                count2 = 1 ; 
            }else if(nums[i] == maj1)
                count1 ++ ; 
            else if(nums[i] == maj2)
                count2 ++ ; 
            else {
                // Any other elements ( minority ) have the equal possibility on reducing 
                // presently considered majority elements.
                count1 -- ; 
                count2 -- ; 
            }
 
        }
 
        // since majority elements may or may not exist we must check their frequency before 
        // returning.
        count1 = 0 ; 
        count2 = 0 ; 
        for( int i=0 ; i<nums.length ; i++ ){
            if(nums[i] == maj1 )
                count1 ++ ; 
            else if(nums[i] == maj2 )
                count2 ++ ; 
        }
 
        int threshold = (int) (nums.length/3) ; 
        if(count1 > threshold )
            list.add(maj1 ) ;
        if(count2 > threshold )
            list.add(maj2) ;
 
        return list ;   
 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int nums[] = {3,2,3} ;
        List<Integer> ans = majorityElement( nums ) ; 
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
