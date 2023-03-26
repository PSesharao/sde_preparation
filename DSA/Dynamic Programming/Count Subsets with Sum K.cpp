/*

https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

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

class Solution{

    public:
    int perfectSum( int arr[], int n, int S , vector<vector<int>> &dp){

        // here we should not be putting this condition as this will not cover 
        // the cases like [1 , 0 ] , sum = 1 , we will be missing {1 ,0 } pair here

       /* for( int ind = 0 ; ind<=n ; ind++ )
            dp[ind][0] =  1 ; */

        int mod = 1e9+7 ;

        for( int sum =0 ; sum <= S ; sum++ )
            dp[n][sum] = 0 ; 

        dp[n][0] = 1 ; 

        for(int ind = n-1 ; ind>=0 ; ind-- )
            for(int sum =0 ; sum <= S ; sum++ ) // starting from s = 0 here as we have commented the base case
            {
                int pick = 0 ; 
                // take 
                
                if( sum - arr[ind] >=0  )
                    pick = dp[ind+1][sum - arr[ind]] ; // isSubsetSum( ind+1 , n , arr , sum - arr[ind] , dp  ) ; 

                // not take 
                int notpick = dp[ind+1][sum] ; // isSubsetSum( ind+1 , n , arr , sum , dp  ) ; 
                dp[ind][sum] = (0LL + pick + notpick) % mod ;                 
            }

        return dp[0][S] ;         
    }

    int perfectSum(int arr[], int n, int sum){
        vector<vector<int>> dp( n+1 , vector<int>( sum+1 , 0 ) ) ; 
        return perfectSum(   arr , n ,  sum , dp ) ;         
    }
      
};


int main() {
    init_code() ; 
    Solution sol ; 
    int A[] = {2, 3, 5, 6, 8, 10} ;
    cout << sol.perfectSum(A , 6 , 10 ) ; 
    return 0 ; 
}