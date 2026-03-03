import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ;

class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;
 
 
    public static int myAtoi( String s ) {
        long num = 0 ; 
        int sign = 1 ;
        int i =0 ;
        int n = s.length() ;
        while( i<n ) {
 
            // leading spaces 
            while( (i<n) && s.charAt(i) == ' ')
                i++ ; 
            // sign check 
            if( (i<n) && ( (s.charAt(i) == '-' ) || (s.charAt(i) == '+') ) ) {
                sign = (s.charAt(i) == '-' ) ?  -1  :  1  ;  
                i++ ;
            }
 
            while( (i<n ) && ( s.charAt(i) >= '0' ) && ( s.charAt(i) <= '9' ) ) {
                num = num*10 + ( s.charAt(i)-'0' ) ;
                if(num * sign < Integer.MIN_VALUE ) return Integer.MIN_VALUE ;
                if(num * sign > Integer.MAX_VALUE ) return Integer.MAX_VALUE ;
                i++ ; 
            }
 
            break ; // non-digit encounter
        }
 
        return (int) (sign * num ) ;
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        int ans = myAtoi(" -00003400ckl") ; 
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