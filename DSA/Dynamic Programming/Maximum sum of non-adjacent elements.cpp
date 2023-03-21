/*

https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

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
class Solution1{
public: 
    // calculate the maximum sum with out adjacent

    int findMaxSum1( int curr_idx , int *arr, int n) {
        if(curr_idx == n-1 )
            return arr[n-1] ;

        int pick_cur = arr[curr_idx] ; 
        int skip_cur = 0 ; 

        if(curr_idx +2 < n )
            pick_cur += findMaxSum1(curr_idx+2 , arr , n ) ;

        if(curr_idx+1 < n )
            skip_cur += findMaxSum1(curr_idx +1 , arr , n  )  ; 

        return max(pick_cur , skip_cur ) ;  
    }


    int findMaxSum1(int *arr, int n) {
        return findMaxSum1(0 , arr , n ) ; 
    }
};


// Memoization 
class Solution2{
public: 
    // calculate the maximum sum with out adjacent

    int findMaxSum2( int curr_idx , int *arr, int n , vector<int> &dp) {

        if(dp[curr_idx] != -1 )
            return dp[curr_idx] ; 

        if(curr_idx == n-1 )
            return dp[curr_idx] = arr[n-1] ;

        int pick_cur = arr[curr_idx] ; 
        int skip_cur = 0 ; 

        if(curr_idx +2 < n )
            pick_cur += findMaxSum2(curr_idx+2 , arr , n ,dp  ) ;

        if(curr_idx+1 < n )
            skip_cur += findMaxSum2(curr_idx +1 , arr , n , dp   )  ; 

        return dp[curr_idx] =  max(pick_cur , skip_cur ) ;  
    }


    int findMaxSum2(int *arr, int n) {
        vector<int> dp(n , -1 ) ; 
        return findMaxSum2(0 , arr , n , dp ) ; 
    }
};



// Tabulation

class Solution3{
public: 
    // calculate the maximum sum with out adjacent

    int findMaxSum(  int *arr, int n , vector<int> &dp) {


        dp[ n-1 ] = arr[n-1] ;

        for(int curr_idx = n-2 ; curr_idx >=0 ; curr_idx-- ){

                int pick_cur = arr[curr_idx] ; 
                int skip_cur = 0 ; 

                if( curr_idx +2 < n )
                    pick_cur += dp[curr_idx+2] ;  // findMaxSum2(curr_idx+2 , arr , n ,dp  ) ;

                if(curr_idx+1 < n )
                    skip_cur += dp[curr_idx+1] ; // findMaxSum2(curr_idx +1 , arr , n , dp   )  ; 

                dp[curr_idx] =  max(pick_cur , skip_cur ) ; 
        }

        return dp[0] ; 
    }


    int findMaxSum(int *arr, int n) {
        vector<int> dp(n , 0 ) ; 
        return findMaxSum( arr , n , dp ) ; 
    }
};
