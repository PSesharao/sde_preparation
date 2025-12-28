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
    
   public static int longestSubarray(int[] arr, int k) {
 
        int n = arr.length ; 
        int ans = 0 ; 
        long curr_sum = 0 ; 
        Map<Long , Integer> map = new HashMap<>() ; 
        for(int i=0 ; i<n ; i++){
 
            curr_sum += arr[i] ; 
            if(curr_sum == k )
                ans = i+1 ;
            else{
 
                if(map.containsKey( curr_sum-k ) ) {
                    int j = map.get(curr_sum-k) ; 
                    ans = Math.max(ans , i-j) ; 
                }
 
            }
            if(!map.containsKey( curr_sum))
                map.put(curr_sum , i) ; 
        }
        return ans ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int[] nums = {10, 5, 2, 7, 1, -10} ;
        int k = 15 ; 
        int ans = longestSubarray(nums , k ) ; 
        //out.println( Arrays.toString(list) ) ; 
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
