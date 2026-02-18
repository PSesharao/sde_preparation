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
 
    private static String longestCommonSubSeq_dp(String str1 , String str2 ) {

        int n1 = str1.length() ;
        int n2 = str2.length() ;
        int dp[][] = new int[n1+1][n2+1] ; 

        for( int ind1 = 0 ; ind1<=n1 ; ind1++ )
            dp[ind1][n2] = 0 ;

        for( int ind2 = 0 ; ind2<=n2 ; ind2++ )
            dp[n1][ind2] = 0 ; 

        for( int ind1 = n1-1 ; ind1>=0 ; ind1-- )
            for( int ind2 = n2-1 ; ind2>=0 ; ind2-- ){

                if( str1.charAt(ind1) == str2.charAt(ind2) )
                     dp[ind1][ind2] = 1 + dp[ind1+1][ind2+1] ;

                 else {
                    int len1 = dp[ind1+1][ind2] ;
                    int len2 = dp[ind1][ind2+1] ;
                    dp[ind1][ind2] = Math.max(len1 , len2) ; 
                 }

            }       
        
        String lcs = "" ; 

        int ind1 = 0 , ind2 =0 ; 
        while( ind1 <n1 && ind2<n2 ){

            if( str1.charAt(ind1) == str2.charAt(ind2) ){
                lcs+= str1.charAt(ind1) ;
                ind1++ ; 
                ind2++ ; 
            }else if(dp[ind1+1][ind2] > dp[ind1][ind2+1] )
                ind1++ ; 
            else 
                ind2++ ; 

        }

        return lcs ; 
    }


    public static void main( String[] args ) throws IOException {
        initialize();  
        String str1 = "bdefg" ; 
        String str2 = "blmekkfog" ;
        String ans = longestCommonSubSeq_dp(str1 , str2 ) ;
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
