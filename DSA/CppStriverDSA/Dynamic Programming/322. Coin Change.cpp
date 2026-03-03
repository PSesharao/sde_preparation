/*

https://leetcode.com/problems/coin-change/

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


#define INF int(1e9 + 7)

// Memoization
class Solution2 {
public:
    int coinChange( int ind ,  int n , int amount  , vector<int>& coins
    , vector<vector<int>> &dp  ) {

        if(ind == n){
            if(amount == 0 )
                return dp[ind][amount] = 0 ; 
            return dp[ind][amount] = INF ; 
        }


        int take = INF ; 
        if( amount - coins[ind] >=0 )
            take = 1 +  coinChange( ind , n , amount - coins[ind] , coins , dp  ) ; 

        int notTake = coinChange( ind+1 , n , amount  , coins , dp  ) ; 

        return dp[ind][amount] = min(take , notTake ) ;                 
        

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ; 
        vector<vector<int>> dp ( n+1 , vector<int>( amount+1 , -1 ) ) ; 
        int ans = coinChange(0 , n , amount , coins ,dp  ) ;   
        if(ans >= INF )
            return -1 ; 
        return ans ; 
    }
}; 

// Tabulation

class Solution3 {
public:
    int coinChange( int n , int A  , vector<int>& coins
    , vector<vector<int>> &dp  ) {

        for(int amount =0 ; amount<=A ; amount++ )
            dp[n][amount] = INF ; 

        dp[n][0] = 0 ; 

        for(int ind =n-1 ; ind>= 0  ; ind-- )
            for(int amount =0 ; amount<=A ; amount++ )
            {
                int take = INF ; 
                if( amount - coins[ind] >=0 )
                    take = 1 + dp[ind][amount - coins[ind]] ; // coinChange( ind , n , amount - coins[ind] , coins , dp  ) ; 

                int notTake = dp[ind+1][amount] ; // coinChange( ind+1 , n , amount  , coins , dp  ) ; 

                dp[ind][amount] = min(take , notTake ) ;                 
            }


        return dp[0][A] ; 

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ; 
        vector<vector<int>> dp ( n+1 , vector<int>( amount+1 , -1 ) ) ; 
        int ans = coinChange(n , amount , coins ,dp  ) ;   
        if(ans >= INF )
            return -1 ; 
        return ans ; 
    }
}; 

int main() {
    init_code() ; 
    Solution2 sol ; 
    vector<int> coins  = {1,2,5} ; 
    cout << sol.coinChange( coins , 11  ) ; 
    return 0 ; 
}