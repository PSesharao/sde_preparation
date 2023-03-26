/*

https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1

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


class Solution {
  public:
    int countPartitions( vector<int>& arr , int n, int S , vector<vector<int>> &dp){

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

    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0 ; 
        for( int i=0 ; i<n ; i++ )
            totalSum += arr[i] ;

        // sum1 , sum2 should not be fractions 
        // therefore if (totalSum + d ) is odd we will return 0 
        if((totalSum + d )%2 == 1 )
            return 0 ; 
        int sum1 = (totalSum + d ) / 2 ; 
        vector<vector<int>> dp( n+1 , vector<int>( sum1+1 , 0 ) ) ; 
        return countPartitions(   arr , n ,  sum1 , dp ) ;   
        
    }
};

int main() {
    init_code() ; 
    Solution sol ; 
    vector<int> arr = { 2 ,40 ,6, 6 ,43, 44 ,10 ,32 ,12 ,12 ,26 ,31 ,48 ,14 ,38 ,42 , 25 } ; 
    cout << sol.countPartitions( 17 , 2 , arr ) ; 
    return 0 ; 
}