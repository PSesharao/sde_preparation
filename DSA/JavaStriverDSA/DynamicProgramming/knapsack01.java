import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


// The Greedy Trap 
// In a Greedy approach, you would likely sort items by their Value-to-Weight Ratio  and pick the "best" ones first.
// Let's look at a scenario where this fails :

// * Knapsack Capacity: 10 kg
// * Item 1: Value: 60, Weight: 7 kg ( Ratio: 8.57 )
// * Item 2: Value: 40, Weight: 5 kg ( Ratio: 8.0 )
// * Item 3: Value: 40, Weight: 5 kg ( Ratio: 8.0 )

// If you use the Greedy (Sorting) approach:
// 1. You pick Item 1 because it has the highest ratio ( 8.57 ).
// 2. Your remaining capacity is 10 - 7 = 3 kg.
// 3. You can't fit Item 2 or Item 3.
// 4. Total Value: 60.

// The Optimal approach (Recursive/DP):
// 1. You realize that if you skip Item 1, you can fit Item 2 AND Item 3.
// 2. Total weight is 5 + 5 = 10 kg (exactly the limit).
// 3. Total Value: 40 + 40 = 80.


class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;


    private static int knapsack01_dp(int val[] , int wt[] , 
        int W ) {

        int n = val.length ; 
        int dp[][] = new int[n+1][W+1] ;  

        for( int w =0 ; w<=W ; w++ )
            dp[0][w] = 0 ; // when the size of val , wt arrays zero.

        for(int ind =0 ; ind<=n ; ind++ )
            dp[ind][0] = 0 ; // when W is zero.
 
        for(int ind =1 ; ind<=n ; ind++ )
            for( int w =1 ; w<=W ; w++ ){
                int include = 0 ; 
                if( w - wt[ind-1] >=0 )
                    include = val[ind-1] + dp[ind-1][w - wt[ind-1]] ; 
                int exclude = dp[ind-1][w] ; 
                dp[ind][w] = Math.max( include , exclude ) ; 
            }

       return dp[n][W] ; 

    } 


    private static int knapsack01_rec(int val[] , int wt[] , 
        int W , int ind ) {

        // if( ind == 0 )
        //     if(W - wt[ind] >=0 )
        //         return val[ind] ; 
        //     else 
        //         return 0 ; 

        if(ind < 0 )
            return 0 ; 

        int include = 0 ; 
        if( W - wt[ind] >=0 ) 
            include = val[ind] + knapsack01_rec(val , wt , W-wt[ind] , ind-1 ) ;
        
        int exclude = knapsack01_rec(val , wt , W , ind-1 ) ;

        return Math.max( include , exclude ) ; 

    } 


    public static void main( String[] args ) throws IOException {
        initialize();  
        int val[] = {10, 40, 30, 50} ;
        int wt[] = {5, 4, 6, 3};
        int n = 4 ;
        int W = 10 ;
        // int ans = knapsack01_rec(val , wt , W , n-1 ) ;
        int ans = knapsack01_dp(val , wt , W ) ;
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
