/*

https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

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
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int , int > map_freq ; 

        int count = 0 ; 
        for(auto num : nums ){

            int d1 = num + k ; 
            int d2 = num - k ; 

            if(map_freq.count(d1) > 0 )
                count += map_freq[d1] ; 

            if(map_freq.count(d2) > 0 )
                count += map_freq[d2] ; 

            map_freq[num] ++ ; 

        }
        return count ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}