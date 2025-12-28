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
    
    public static long subarrayXor(int arr[], int k) {
        // code here
        int n = arr.length ; 
        long xor = 0 ; 
        int ans = 0 ; 
        Map<Long , Integer> map = new HashMap<>() ; 
        for(int i=0 ; i<n ; i++) { 
            xor = xor ^ arr[i] ; 
            if( xor == k )
                ans ++ ; 
            long y = xor ^ k ; 
            ans += map.getOrDefault(y , 0) ;
            map.put( xor , map.getOrDefault(xor,0)+1 ) ; 
        }
        return ans ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int[] nums = {4, 2, 2, 6, 4} ;
        int k = 6 ; 
        long ans = subarrayXor(nums , k ) ;  
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
