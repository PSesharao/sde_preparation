/*

https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

*/


#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define MAX 200010

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// Recursion 

class Solution1 {
public:

    int knapSack( int ind  , int n, int W , int val[], int wt[] ) { 

        if( ind == n ) {
            return 0 ; 
        }

        int take = 0 ; 
        if( ( W - wt[ind] ) >=0 )
            take = val[ind] + knapSack( ind , n , W - wt[ind] ,  val , wt  ) ;  

        int notTake =  knapSack( ind+1 , n , W  ,  val , wt  ) ;  

        return max(take , notTake ) ; 

    }  


    int knapSack(int n, int W, int val[], int wt[]){
        return knapSack(0 , n , W , val , wt ) ; 
    }
};


// Memoization 

class Solution2 {
public:

    int knapSack( int ind  , int n, int W , 
        int val[], int wt[] , vector<vector<int>> &dp ) { 

        if(dp[ind][W] != -1 )
            return dp[ind][W] ; 

        if( ind == n ) {
            return dp[ind][W] = 0 ; 
        }

        int take = 0 ; 
        if( ( W - wt[ind] ) >=0 )
            take = val[ind] + knapSack( ind , n , W - wt[ind] ,  val , wt  , dp ) ;  

        int notTake =  knapSack( ind+1 , n , W  ,  val , wt  , dp ) ;  

        return dp[ind][W] = max(take , notTake ) ; 

    }  


    int knapSack(int n, int W, int val[], int wt[]){
        vector<vector<int>> dp( n+1 , vector<int>( W+1 , -1 ) ) ; 
        return knapSack(0 , n , W , val , wt , dp ) ; 
    }
};



// Tabulation

class Solution3 {
public:

    int knapSack( int ind  , int n, int Weight , 
        int val[], int wt[] , vector<vector<int>> &dp ) { 

        for(int W=0 ; W<= Weight ; W++ )
            dp[n][W] = 0 ; 


        for(int ind=n-1 ; ind>=0 ; ind-- )
            for(int W=0 ; W<= Weight ; W++ ){

                int take = 0 ; 
                if( ( W - wt[ind] ) >=0 )
                    take = val[ind] + dp[ind][W - wt[ind]] ; // knapSack( ind , n , W - wt[ind] ,  val , wt  , dp ) ;  

                int notTake =  dp[ind+1 ][W] ; // knapSack( ind+1 , n , W  ,  val , wt  , dp ) ; 
                dp[ind][W] = max(take , notTake ) ;       

            }


        return dp[0][Weight] ; 
         

    }  


    int knapSack(int n, int W, int val[], int wt[]){
        vector<vector<int>> dp( n+1 , vector<int>( W+1 , -1 ) ) ; 
        return knapSack(0 , n , W , val , wt , dp ) ; 
    }
};


int main() {
    init_code() ; 
    Solution3 sol ; 
    int wt[] = {1, 3, 4, 5} ; 
    int val[] = {1, 4, 5, 7} ; 
    cout << sol.knapSack( 4 ,  8 , val ,  wt ) ; 
    return 0 ; 
}
