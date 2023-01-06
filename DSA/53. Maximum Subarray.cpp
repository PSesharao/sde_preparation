/*

https://leetcode.com/problems/maximum-subarray/

 If we have to return 0 incase all the elements are negative , 
 we should initialize max_so_far to 0 

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
    int maxSubArray(vector<int>& nums) {


           int max_so_far = nums[0];
           int curr_max = nums[0];
          
           for (int i = 1; i < nums.size(); i++)
           {
                curr_max = max(nums[i], curr_max+nums[i]);
                max_so_far = max(max_so_far, curr_max);
           }
           return max_so_far;
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    sol.generate(5) ; 
}