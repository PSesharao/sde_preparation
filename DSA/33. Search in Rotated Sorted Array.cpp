/*

https://leetcode.com/problems/search-in-rotated-sorted-array/

lets take 

0 1 2 3 4 5 6 7 and target = 0 

3 4 5 6 7 0 1 2


mid = 3 , first check if A[mid] = target 

if not we have two options left 
to search in left part [3 4 5] or the right part [7 0 1 2]

our first preference should be to check if target lies in sorted part 

if not , we have not option but to continue on other part 


Time Complexity: O(log(N))

Reason: We are performing a binary search, this turns time complexity to O(log(N)) 
where N is the size of the array.

Space Complexity: O(1)

Reason: We do not use any extra data structure, this turns space complexity to O(1).

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
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1 ; 

        while(low <= high ){
            int mid = low + (high - low) / 2 ;
            if(nums[mid] == target)
                return mid ; 
            else{

                // If left part is sorted 
                if( nums[low] <= nums[mid]  ){
                    // check if target lies in this left part
                    if(( nums[mid]>= target ) and (nums[low]<= target) ){
                        high = mid -1 ;
                    }else{
                        low = mid +1 ; 
                    }
                }else{
                    // If right part if sorted 
                    // check if target lies in this right part
                    if(( nums[high]>= target ) and (nums[mid]<= target) ){
                        low = mid + 1 ; 
                    }else{
                        high = mid - 1 ;
                    }
                } 
            }
        }
        return -1 ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}