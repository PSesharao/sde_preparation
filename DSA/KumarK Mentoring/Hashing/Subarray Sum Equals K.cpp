/*

https://leetcode.com/problems/subarray-sum-equals-k/
https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1

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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> sum_map ; 
        int result = 0 ; 
        int cur_sum = 0 ; 
        for(int i=0 ; i<nums.size() ; i++ ){
            cur_sum += nums[i] ; 

            if(cur_sum == k )
                result ++ ; 

            int diff = cur_sum - k ; 

            if( sum_map.count(diff) > 0 )
                result += sum_map[diff] ; 

            
            sum_map[cur_sum] ++ ; 
        }
        return result ; 
    } 
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}