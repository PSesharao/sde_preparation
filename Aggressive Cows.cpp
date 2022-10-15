/*

https://practice.geeksforgeeks.org/problems/aggressive-cows/1

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

bool isPossible(int N, int no_of_cows, vector<int> &stall , int distance ){
    int cows_count = 1 ; // always assume to tie first cow at 0 index

    int last_placed_cow = 0  ; 

    int curr_stall =1 ; 
    while(curr_stall < N ){

        if(stall[curr_stall] - stall[last_placed_cow] >= distance ){
            // you can tie the cow at current stall 
            cows_count ++ ; 
            last_placed_cow = curr_stall ; 
            curr_stall ++ ; 
        }else
            curr_stall ++ ; 

        if(cows_count >= no_of_cows )
            return true ; 
    }
    return false ;  
}

class Solution {
public:
    int solve(int N, int no_of_cows, vector<int> &stall) {
    // sorting to enable the binary search
    sort(stall.begin() , stall.end()) ;

    int low =1 ; // the lowest possible when cows tied consecutively 
    int high = stall[N-1] - stall[0] ; // maximum separation when cows tied to the ends

    while(low <= high ){
        int mid = low + (high - low ) /2 ; 
        if(isPossible(N , no_of_cows , stall , mid ))
            low = mid+1 ; 
        else
            high = mid-1 ; 
    }

    // by the time low crosses over high , the last value for low should have answer , or simply high also does

    return low-1 ; 
    // return high ; 
    }
} ; 

int main() {
    init_code() ; 
    Solution sol ; 

    
}