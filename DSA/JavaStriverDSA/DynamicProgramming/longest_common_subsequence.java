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


    private static int longestCommonSubSeq(String str1 , String str2 , 
        int ind1 , int ind2) {

        if(ind1 == str1.length() || ind2 == str2.length() )
            return 0 ;

        if( str1.charAt(ind1) == str2.charAt(ind2) )
            return 1+ longestCommonSubSeq(str1 , str2 , ind1+1 , ind2+1 ) ;

        int len1 = longestCommonSubSeq(str1 , str2 , ind1+1 , ind2 ) ;
        int len2 = longestCommonSubSeq(str1 , str2 , ind1 , ind2+1 ) ;

        return Math.max(len1 , len2) ; 
    }


    private static int longestCommonSubSeq_Mem(String str1 , String str2 , 
        int ind1 , int ind2 , int dp[][] ) {

        if(dp[ind1][ind2] !=-1 )
            return dp[ind1][ind2] ; 

        if(ind1 == str1.length() || ind2 == str2.length() )
            return dp[ind1][ind2] = 0 ;

        if( str1.charAt(ind1) == str2.charAt(ind2) )
            return dp[ind1][ind2] = 1 + longestCommonSubSeq_Mem(str1 , str2 , ind1+1 , ind2+1 , dp ) ;

        int len1 = longestCommonSubSeq_Mem(str1 , str2 , ind1+1 , ind2 , dp ) ;
        int len2 = longestCommonSubSeq_Mem(str1 , str2 , ind1 , ind2+1 , dp ) ;

        return dp[ind1][ind2] = Math.max(len1 , len2) ; 
    }
 
    private static int longestCommonSubSeq_dp(String str1 , String str2 ) {

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
        return dp[0][0] ; 
    }


    public static void main( String[] args ) throws IOException {
        initialize();  
        String str1 = "bdefg" ; 
        String str2 = "bfg" ;
        int n1 = str1.length() ;
        int n2 = str2.length() ;
        int dp[][] = new int[n1+1][n2+1] ; 
        for(int i=0 ; i<n1 ; i++)
            Arrays.fill(dp[i] , -1 ) ; 
        int ans = longestCommonSubSeq_Mem(str1 , str2 , 0 , 0 , dp ) ;
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
