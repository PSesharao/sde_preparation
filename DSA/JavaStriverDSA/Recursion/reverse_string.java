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

    private static void sumOfSubsets( int A[] , int cur_sum , 
        int ind , List<Integer> ans ) {

        if( ind == A.length ) {
            ans.add(cur_sum) ; 
            return ;  
        }

        ans.add( cur_sum ) ; 

        // include
        sumOfSubsets(A , cur_sum + A[ind] , ind+1 , ans ) ; 

        // exclude
        sumOfSubsets(A , cur_sum , ind+1 , ans ) ; 

    }

    private static void swap(char[] s , int l , int r ) {

        char t = s[l] ;
        s[l] = s[r] ; 
        s[r] = t ;
    }

    private static void reverse( char[] s , int l , int r  ) {
        if(l >= r )
            return ; 

        swap(s , l , r ) ; 
        reverse(s, l+1 , r-1 ) ; 
    }

    private static String reverseString( String str ) {
        char[] charArray = str.toCharArray() ; 
        int r = str.length()-1 ; 
        int l = 0 ;
        reverse( charArray , l , r ) ; 
        return new String(charArray) ; 
    }


    private static String reverseString1( String str ) {

        if( (str.length() <=1 )  || (str.isEmpty()) )
            return str ;

        return reverseString1( str.substring(1) ) + str.charAt(0) ; 
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        String str = "sesharao" ; 
        // String reverse = reverseString(str) ;
        // out.println(reverse) ; 

        String reverse1 = reverseString1(str) ;
        out.println(reverse1) ; 
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
