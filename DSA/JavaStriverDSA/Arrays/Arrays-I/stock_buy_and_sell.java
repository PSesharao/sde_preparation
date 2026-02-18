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

    public static int maxProfit(int[] prices) {
        int N = prices.length ; 
        if(N == 0 || N ==1 )
            return 0 ; 
        int ans = 0 ; 
        int min_so_far = prices[0] ;
        for(int i=1 ; i< N ; i++ ){
            int curr_tran = prices[i] - min_so_far ;
            ans = Math.max(curr_tran , ans ) ; 
            min_so_far = Math.min( min_so_far , prices[i] ) ; 
        } 
        return ans ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int A[] = {7,6,4,3,1} ; 
        int ans = maxProfit(A) ; 
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
