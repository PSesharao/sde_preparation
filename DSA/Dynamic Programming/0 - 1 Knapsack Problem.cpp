/*

https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/#practice

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
class Solution
{

    int knapSack( int ind  , int W, int wt[], int val[], int n) { 

        if( ind == n ) {
            return 0 ; 
        }

        int take = 0 ; 
        if( ( W - wt[ind] ) >=0 )
            take = val[ind] + knapSack( ind+1 , W - wt[ind] , wt ,  val , n  ) ;  

        int notTake =  knapSack( ind+1 , W , wt ,  val , n  ) ;  

        return max(take , notTake ) ; 

    }    

    public:
    int knapSack(int W, int wt[], int val[], int n) { 
       return knapSack(0 , W , wt , val , n ) ; 
    }



};

// Memoization 
class Solution2
{

    int knapSack( int ind  , int W, int wt[], 
        int val[], int n , vector<vector<int>> &dp ) { 

        if(dp[ind][W] != -1 )
            return dp[ind][W] ; 

        if( ind == n ) {
            return dp[ind][W] = 0 ; 
        }

        int take = 0 ; 
        if( ( W - wt[ind] ) >=0 )
            take = val[ind] + knapSack( ind+1 , W - wt[ind] , wt ,  val , n ,dp  ) ;  

        int notTake =  knapSack( ind+1 , W , wt ,  val , n , dp  ) ;  

        return dp[ind][W] = max(take , notTake ) ; 

    }    

    public:
    int knapSack(int W, int wt[], int val[], int n) { 
       vector<vector<int>> dp( n+1 , vector<int>( W+1 , -1 ) ) ; 
       return knapSack(0 , W , wt , val , n , dp  ) ; 
    }

};


// Tabulation 
class Solution3
{

    int knapSack(  int Weight, int wt[], 
        int val[], int n , vector<vector<int>> &dp ) { 


        for(int W=0 ; W<= Weight ; W++ )
            dp[n][W] = 0 ; 

        for(int ind=n-1 ; ind>=0 ; ind-- )
            for(int W=0 ; W<= Weight ; W++ ){

                int take = 0 ; 
                if( ( W - wt[ind] ) >=0 )
                    take = val[ind] + dp[ind+1][W - wt[ind] ] ;  // knapSack( ind+1 , W - wt[ind] , wt ,  val , n ,dp  ) ;  

                int notTake =  dp[ind+1][W] ; // knapSack( ind+1 , W , wt ,  val , n , dp  ) ;  

                dp[ind][W] = max(take , notTake ) ; 

            }

        return dp[0][Weight] ; 

    }    

    public:
    int knapSack(int W, int wt[], int val[], int n) { 
       vector<vector<int>> dp( n+1 , vector<int>( W+1 , 0 ) ) ; 
       return knapSack( W , wt , val , n , dp  ) ; 
    }

};

int main() {
    init_code() ; 
    Solution3 sol ; 
    int wt[] = {4,5,1} ; 
    int val[] = {1,2,3} ; 
    cout << sol.knapSack( 4 , wt , val , 3  ) ; 
    return 0 ; 
}