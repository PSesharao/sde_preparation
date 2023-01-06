/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() ; 
        int i = 0 ; 
        for(int j = 1 ; j<n ; j++ ){
            if(nums[i] != nums[j] ){
                i++ ; 
                nums[i] = nums[j]  ; 
            }
            
        }
        return i+1 ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}