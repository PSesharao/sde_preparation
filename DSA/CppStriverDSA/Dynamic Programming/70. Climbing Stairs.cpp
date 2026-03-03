/*

https://leetcode.com/problems/climbing-stairs/

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
    int climbStairs(int n) {

        if(n == 0 )
            return 1 ; 

        int steps1 = 0 , steps2 = 0 ; 
        if( n>=1 )
            steps1 =  climbStairs(n-1) ;

        if( n>=2 ) 
            steps2 =  climbStairs(n-2) ; 

        return steps1 + steps2 ;  
    }
};



// Memoization 

class Solution2 {
public:
    int climbStairs(int n , vector<int> &dp  ) {

        if(dp[n] != -1 )
            return dp[n] ; 

        if(n == 0 )
            return dp[n] = 1 ; 

        int steps1 = 0 , steps2 = 0 ; 
        if( n>=1 )
            steps1 =  climbStairs(n-1 , dp ) ;

        if( n>=2 ) 
            steps2 =  climbStairs(n-2 , dp ) ; 

        return dp[n] = steps1 + steps2 ;  
    }
};


// Tabulation

class Solution3 {
public:
    int climbStairs(int N ) {

        vector<int> dp(N+1 , 0 )  ; 

        dp[0] = 1 ; 

        for(int n = 1 ; n <=N ; n++ ){
            int steps1 = 0 , steps2 = 0 ; 
            if( n>=1 )
                steps1 =  dp[n-1] ; //  climbStairs(n-1 , dp ) ;

            if( n>=2 ) 
                steps2 =  dp[n-2] ; //  climbStairs(n-2 , dp ) ; 

            dp[n] = steps1 + steps2 ;  
        }

        return dp[N] ; 

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}