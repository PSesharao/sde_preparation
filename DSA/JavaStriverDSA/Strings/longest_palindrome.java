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

    public static String expandFromCenter(String s , int l , int r ) {
 
        while( l>=0 && r<s.length() && s.charAt(l) == s.charAt(r) ) {
            l-- ; 
            r++ ; 
        }
        return s.substring(l+1 , r ) ; 
    }
 
    public static String longestPalindrome(String s) {
 
        String maxStr = s.substring( 0 , 1 ) ;
        int len = s.length() ; 
        for( int i=0 ; i<len-1 ; i++ ) {
            String odd = expandFromCenter(s , i , i ) ; 
            String even = expandFromCenter(s , i , i+1 ) ;
 
            if( odd.length() > maxStr.length() )
                maxStr = odd ;
 
            if(even.length() > maxStr.length() )
                maxStr = even ; 
        }
 
        return maxStr ; 
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        String str = "kbaabzba" ; 
        String ans = longestPalindrome( str ) ; 
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
