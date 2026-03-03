/*

https://leetcode.com/problems/single-element-in-a-sorted-array/

0 1 2 3 4 5 6 7 8 9 10

1 1 2 2 3 3 4 5 5 6 6

What we observe is till 4 , ( left half )

even index  -> first occurence
odd index   -> second occurence 

after 4 ( right half )

odd index  -> first occurence
even index   -> second occurence 

We need to find this point such that , after binary search over 
when low crosses high 

high index would point to the left half end index 

low point to the unique element following which is right half 

so when mid points to this unique element we always shrink high 

Time Complexity: O(log(N))

Space Complexity: O(1)

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
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size() ; 
        int low = 0 , high = N-2 ;
        // we are taking high at N-2 to handle the case like [1 1 2 2 3]
        // where unique element is at last 
        while( low <= high ){
            int mid = low + (high - low ) /2  ; 

            if( mid % 2 == 0 ){ 
                // even index
                if( nums[mid] == nums[mid+1] ){ // It is always guaranteed that mid+1 exists
                    // becuase the size of array is odd always and we are taking high at N-2 
                    // We are currently in left part , go towards right 
                    low = mid+1 ; 
                }else{
                    // We are currently in right part , go towards left 
                    high = mid-1 ; 
                }
            }else{
                // odd 
                if(nums[mid] == nums[mid-1]){ // It is always guaranteed that mid-1 exists 
                    //becz if mid is odd there should always be 1 before it 
                    // We are currently in left part , go towards right 
                    low = mid+1 ; 
                }else{
                    // We are currently in right part , go towards left 
                    high = mid-1 ; 
                }
            }
        }
        return nums[low] ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}