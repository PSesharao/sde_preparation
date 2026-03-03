/*

https://atcoder.jp/contests/dp/tasks/dp_b

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

int frogJump1( int cur_idx , int n, vector<int> &heights , int k ){

    if(cur_idx == n-1 )
        return 0 ; 

    int stepk = MAX ; 

    for(int jump=1 ; jump<=k ; jump++ ){
        if( cur_idx + jump < n  ){
            int diff = abs(heights[cur_idx + jump] - heights[cur_idx]) ; 
            stepk = min(stepk , diff + (frogJump1( cur_idx + jump , n , heights , k ) ) ) ; 
        }
    }

    return stepk ; 
}

int frogJump1(int n, vector<int> &heights , int k ){

    return frogJump1(0 , n , heights , k ) ; 
}


// Memoization 

ll frogJump2( ll cur_idx , ll n, vector<ll> &heights ,  vector<ll> &dp , ll k ){

    if (dp[cur_idx] !=-1 )
        return dp[cur_idx] ; 
    if(cur_idx == n-1 )
        return dp[cur_idx] = 0 ; 

    ll stepk = INT_MAX ; 

    for(ll jump=1 ; jump<=k ; jump++ ){
        if( cur_idx + jump < n  ){
            ll jumpStep = abs(heights[cur_idx + jump] - heights[cur_idx]) + 
            frogJump2( cur_idx + jump , n , heights , dp ,  k ) ; 
            stepk = min(stepk ,  jumpStep )  ; 
        }
    }
    return dp[cur_idx] = stepk ; 

}

ll frogJump2(ll n, vector<ll> &heights , ll k ){

    vector<ll> dp(n , -1 ) ; 
    return frogJump2(0 , n , heights , dp ,k  ) ; 
}


// Tabulation

ll frogJump3( ll n, vector<ll> &heights ,  ll k ){
    vector<ll> dp(n , 0 ) ; 
    dp[n-1] = 0 ;  
    for(ll cur_idx = n-2 ; cur_idx >=0 ; cur_idx --  ){
            ll stepk = INT_MAX ; 
            for(ll jump=1 ; jump<=k ; jump++ ){
                if( cur_idx + jump < n  ){
                    ll jumpStep = abs(heights[cur_idx + jump] - heights[cur_idx]) + 
                    dp[cur_idx + jump] ; // frogJump2( cur_idx + jump , n , heights , dp ,  k ) ; 
                    stepk = min(stepk ,  jumpStep )  ; 
                }
            }

      dp[cur_idx] = stepk ;   

    }
    return dp[0] ; 
}