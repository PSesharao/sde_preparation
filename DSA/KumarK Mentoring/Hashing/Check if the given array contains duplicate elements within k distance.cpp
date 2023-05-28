/*

https://leetcode.com/problems/contains-duplicate-ii/

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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int > umap ; 

        for(int i=0 ; i< nums.size() ; i++ ){
            if(umap.count(nums[i]) > 0 ){
                int prev_pos = umap[nums[i]] ; 
                if(i - prev_pos <= k )
                    return true ; 
                else
                    umap[nums[i]] = i ; 
            }else{
                umap[nums[i]] = i ; 
            }
        }

        return false ; 
    }
};

int main() {
    init_code() ; 
    vector<int> A = {1,2,3,1} ; 
    int k = 3 ; 
    Solution sol ; 
    int m = sol.containsNearbyDuplicate(A , k ) ; 
    cout << m << endl ; 
    return 0;
}
