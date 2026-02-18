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

    // private static final int inf = (int) 1e9+1 ;
    
     public static int[] twoSum(int[] nums, int target) {
        Map<Integer , Integer> map = new HashMap<>() ; 
        int ans[] = new int[2] ; 
        for(int i=0 ; i<nums.length ; i++) {
            int complement = target - nums[i] ; 
            if( map.containsKey(complement) )
            {
                int ind1 = i ;
                int ind2 = map.get(complement) ; 
                ans[0] = ind2 ; 
                ans[1] = ind1 ; 
                return ans ; 
            }
            map.put(nums[i] , i ) ; 
        }
        return ans ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int[] nums = {2,7,11,15} ;
        int target = 9 ; 
        int[] ans = twoSum(nums , target ) ;  
        out.println( Arrays.toString(ans) ) ; 
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
