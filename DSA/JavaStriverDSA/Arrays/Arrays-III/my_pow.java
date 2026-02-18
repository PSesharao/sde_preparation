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

    public static double myPow(double x, int n) {
        // It is guranteed that n > 0 , when x = 0 
        double ans = 1.0 ;
        long nn = n ; // store in a temporary variable useful for certain cases like n is -ve 
        // long is taken to avoid overflow when converting large -ve int's like -2147483648 to +ve int.
        // int range is ( -2^31 to 2^31-1 )
        if(nn < 0 ) // if -ve
            nn = -nn ; // make +ve
        while(nn >0 ){
            if((nn & 1) == 1) { // odd
                ans = ans * x ; 
                nn-- ; 
            } else{ // even
                x = x*x ; 
                nn = nn >> 1 ; // half
            }
        }
 
 
        if(n < 0 )
            return 1.0/ ans ;
 
        return ans ; 
    } 
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        double x = 2.00000 ; 
        int n = 10 ;// -2147483648 ; 
        double ans = myPow(x,n) ; 
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
