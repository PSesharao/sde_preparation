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
 
    private static int findmCn(int m , int n ) {
        if( n == 0 || n == m )
            return 1 ; 
        // symmetry property mCn = mC(m-n)
        if(n > m/2 )
            n = m-n ; 
        // Taking double to comply with fractional calculations
        double ans = 1 ; 
        for(int i=1 ; i<=n ;i++ )
            ans = ans * (m-i+1)/i  ; 
        return (int)ans ; 
    }
 
    private static int uniquePaths_combinatrics( int m, int n ) {
        int M = m + n -2 ; 
        int N = Math.min(m,n) - 1 ; 
        return findmCn(M , N ) ; 
    }
 
    private static int uniquePaths_mem(int r , int c , int m, int n , int dp[][] ) {
 
        if((r >=m) || (c>= n) )
            return 0 ;
 
        if( dp[r][c] != -1 )
            return dp[r][c] ;
 
        if((r== m-1) && (c == n-1))
            return dp[r][c] = 1 ;
 
        int right = uniquePaths_mem( r , c+1 , m , n , dp ) ;
        int bottom = uniquePaths_mem( r+1 , c , m , n , dp ) ;
 
        return dp[r][c] = right + bottom ; 
    }
 
    private static int uniquePaths(int r , int c , int m, int n) {
 
        if((r >=m) || (c>= n) )
            return 0 ; 
        if((r== m-1) && (c == n-1))
            return 1 ;
 
        int right = uniquePaths(r , c+1 , m , n ) ;
        int bottom = uniquePaths(r+1 , c , m , n ) ;
 
        return right + bottom ; 
    }
 
    public static int uniquePaths(int m, int n) {
        // int dp[][] = new int[m][n] ;
        // Arrays.stream(dp).forEach( row -> Arrays.fill(row , -1) ) ; 
        // return uniquePaths_mem(0 , 0 , m , n , dp  ) ; 
        return uniquePaths_combinatrics(m , n ) ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int m = 3 , n = 7 ;
        int ans = uniquePaths(m , n ) ;  
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
