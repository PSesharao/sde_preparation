/*

https://leetcode.com/problems/target-sum/

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

    int findTargetSumWays(vector<int>& nums, int n , int S , vector<vector<int>> &dp) {

        for( int sum =0 ; sum <= S ; sum++ )
            dp[n][sum] = 0 ; 

        dp[n][0] = 1 ; 

        for(int ind = n-1 ; ind>=0 ; ind-- )
            for(int sum =0 ; sum <= S ; sum++ ) // starting from s = 0 here as we have commented the base case
            {
                int pick = 0 ; 
                // take 
                
                if( sum - nums[ind] >=0  )
                    pick = dp[ind+1][sum - nums[ind]] ; // isSubsetSum( ind+1 , n , arr , sum - arr[ind] , dp  ) ; 

                // not take 
                int notpick = dp[ind+1][sum] ; // isSubsetSum( ind+1 , n , arr , sum , dp  ) ; 
                dp[ind][sum] = (0LL + pick + notpick) ;                
            }

        return dp[0][S] ;                 
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int totalSum = 0 ; 
        for( int i=0 ; i<n ; i++ )
            totalSum += nums[i] ;

        // sum1 , sum2 should not be fractions 
        // therefore if (totalSum + target ) is odd we will return 0 
        if((totalSum + target <0 ) or (totalSum + target )%2 == 1 )
            return 0 ; 
        
        int sum1 = (totalSum + target ) / 2 ; 
        vector<vector<int>> dp( n+1 , vector<int>( sum1+1 , 0 ) ) ; 
        return findTargetSumWays(   nums , n ,  sum1 , dp ) ;           
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}