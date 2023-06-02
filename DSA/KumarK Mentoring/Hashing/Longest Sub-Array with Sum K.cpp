/*

https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

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
    int lenOfLongSubarr(int A[],  int N, int K) { 
        unordered_map<int , int > prefix_map ; 
        int cur_sum = 0 ; 
        int max_len = 0 ; 
        for(int i=0 ; i<N ; i++ ){
            cur_sum += A[i] ; 
            if(cur_sum == K )
                max_len = i+1 ; 
            int diff = cur_sum - K ; 
            if(prefix_map.count(diff) > 0 ){
                int prev_index = prefix_map[diff] ; 
                max_len = max({max_len , i - prev_index }) ; 
            }

            // insert to map only if it does not exist before , 
            // because we need to maximze the sum.
            
            if( prefix_map.count(cur_sum) == 0  )
                prefix_map[cur_sum] = i ;
        }
        return max_len ; 
    } 

};



int main() {
    init_code() ; 
    Solution sol ; 

    
}