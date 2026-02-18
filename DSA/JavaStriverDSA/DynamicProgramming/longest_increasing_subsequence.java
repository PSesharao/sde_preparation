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


    private static int longestIncreasingSubsequence(int A[]) {

        int n = A.length ;
        int lis[] = new int[n] ; // represent the longest subsequence length ending at 'i'
        Arrays.fill(lis , 1) ;   // by default at each index 
                                 // there can be atleast of 1 len subsequence
        for( int i=1 ; i<n ; i++ )
            for(int j=0 ; j<i ; j++) {
                if(( A[i] > A[j] ) && (lis[i] <= lis[j]) )  // This check is because 
                    // In [5 8 7 1 9] though 9 > 1 , we can not take a subsequence with [1 , 9 ] , as we get better if we exclude '1'
                    lis[i] = lis[j]+1 ; // 'i' can be included in lis after 'j' 
            }

        System.out.println(Arrays.toString(lis)) ; 
        int maxLen = lis[0] ; 
        for(int i=1 ; i<n ; i++)
            maxLen = Math.max( maxLen , lis[i]) ; 

        return maxLen ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int A[] = {5,8,7,1,9} ;
        int ans = longestIncreasingSubsequence(A) ;
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
