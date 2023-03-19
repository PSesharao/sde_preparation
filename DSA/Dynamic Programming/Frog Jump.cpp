/*

https://atcoder.jp/contests/dp/tasks/dp_a

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

int frogJump1( int cur_idx , int n, vector<int> &heights){

    if(cur_idx == n-1 )
        return 0 ; 

    int step1 = MAX , step2 = MAX ; 

    if(cur_idx + 1 < n ){
        int diff = abs(heights[cur_idx+1] - heights[cur_idx]) ; 
        step1 = diff + frogJump1(cur_idx+1 , n , heights ); 
    }

    if(cur_idx + 2 < n ){
        int diff = abs(heights[cur_idx+2] - heights[cur_idx]) ; 
        step2 = diff + frogJump1(cur_idx+2 , n , heights ); 
    }

    return min(step1 , step2 ) ; 
}

int frogJump1(int n, vector<int> &heights){

    return frogJump1(0 , n , heights ) ; 
}



// Memozation 

int frogJump2( int cur_idx , int n, vector<int> &heights ,  vector<int> &dp){

    if (dp[cur_idx] !=-1 )
        return dp[cur_idx] ; 
    if(cur_idx == n-1 )
        return dp[cur_idx] = 0 ; 

    int step1 = MAX , step2 = MAX ; 

    if(cur_idx + 1 < n ){
        int diff = abs(heights[cur_idx+1] - heights[cur_idx]) ; 
        step1 = diff + frogJump2(cur_idx+1 , n , heights , dp ); 
    }

    if(cur_idx + 2 < n ){
        int diff = abs(heights[cur_idx+2] - heights[cur_idx]) ; 
        step2 = diff + frogJump2(cur_idx+2 , n , heights , dp ); 
    }

    return dp[cur_idx] = min(step1 , step2 ) ; 
}

int frogJump2(int n, vector<int> &heights){

    vector<int> dp(n , -1 ) ; 
    return frogJump2(0 , n , heights , dp ) ; 
}




// Tabulation

int frogJump3( int cur_idx , int n, vector<int> &heights ){

    vector<int> dp(n , 0 ) ; 

    dp[n-1] = 0 ; 
	
	// we are taking the loop in the reverse order as we see that , initial indices depend on 
	// the later indices in the recursion , so we need to calculate for the higher indices first and the ans will be available at dp[0] 
    for(int cur_idx = n-2 ; cur_idx>=0 ; cur_idx --  ){
        int step1 = MAX , step2 = MAX ; 

        if(cur_idx + 1 < n ){
            int diff = abs(heights[cur_idx+1] - heights[cur_idx]) ; 
            step1 = diff + dp[cur_idx+1] ; // frogJump2(cur_idx+1 , n , heights , dp ); 
        }

        if(cur_idx + 2 < n ){
            int diff = abs(heights[cur_idx+2] - heights[cur_idx]) ; 
            step2 = diff + dp[cur_idx+2] ;  // frogJump2(cur_idx+2 , n , heights , dp ); 
        }

        dp[cur_idx] = min(step1 , step2 ) ; 

    }

    return dp[0] ; 

}


int frogJump3(int n, vector<int> &heights){

    return frogJump3(0 , n , heights ) ; 
}



int main() {
    init_code() ; 
    Solution sol ; 
}