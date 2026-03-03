/*

https://leetcode.com/problems/coin-change-ii/

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

    int change( int ind , int n , int amount, vector<int>& coins) {

        if(ind == n){
            if(amount == 0 )
                return 1 ; 
            return 0 ; 
        }

        int pick = 0 ; 
        if( amount - coins[ind] >=0 )
            pick = change(ind , n , amount - coins[ind] , coins ) ;

        int notPick = change(ind+1 , n , amount , coins ) ;

        return pick + notPick ; 
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size() ; 
        return change(0 , n , amount , coins ) ; 
    }
};

// Memoization
class Solution2 {
public:

    int change( int ind , int n , int amount, 
        vector<int>& coins , vector<vector<int>> &dp) {

        if(dp[ind][amount] != -1 )
            return dp[ind][amount]  ; 

        if(ind == n){
            if(amount == 0 )
                return dp[ind][amount] = 1 ; 
            return dp[ind][amount] = 0 ; 
        }

        int pick = 0 ; 
        if( amount - coins[ind] >=0 )
            pick = change(ind , n , amount - coins[ind] , coins ,dp  ) ;

        int notPick = change(ind+1 , n , amount , coins , dp  ) ;

        return dp[ind][amount] = pick + notPick ; 
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size() ; 
        vector<vector<int>> dp( n+1 , vector<int>( amount+1 , -1 ) ) ;
        return change(0 , n , amount , coins , dp  ) ; 
    }
}; 

// Tabulation

class Solution3 {
public:

    int change(  int n , int A, 
        vector<int>& coins , vector<vector<int>> &dp) {


        for(int amount =0 ; amount<=A ; amount++ )
            dp[n][amount] = 0 ;

         dp[n][0] = 1 ;


        for(int ind =n-1 ; ind>= 0  ; ind-- )
            for(int amount =0 ; amount<=A ; amount++ ){

                int pick = 0 ; 
                if( amount - coins[ind] >=0 )
                    pick = dp[ind][amount - coins[ind]]  ; // change(ind , n , amount - coins[ind] , coins ,dp  ) ;

                int notPick = dp[ind+1][amount]  ;  // change(ind+1 , n , amount , coins , dp  ) ;

                dp[ind][amount] = pick + notPick ;           

            }

        return dp[0][A] ; 

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size() ; 
        vector<vector<int>> dp( n+1 , vector<int>( amount+1 , -1 ) ) ;
        return change( n , amount , coins , dp  ) ; 
    }
}; 


int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<int> coins  = {1,2,5} ; 
    cout << sol.change(5 , coins ) ; 
    return 0 ; 
}