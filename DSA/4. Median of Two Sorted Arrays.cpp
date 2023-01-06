/*

https://leetcode.com/problems/median-of-two-sorted-arrays/

We should always have len1 < len2 here , becuase 
lets take len1 = 7 , len2 = 1 

half_len = 4 
low =0 and high = 4 
part1 = 2 
part2 = 4-2 (but there is only 1 element in arr2 ) 



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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int len1 = nums1.size() , len2 = nums2.size() ; 
        if(len1 > len2 ) return findMedianSortedArrays(nums2 , nums1 ) ; 
        int len_of_half = ( len1 + len2 +1 )/2 ; // This would work for both even and odd cases 

        int low = 0 ; // min partition length of array1
        int high = len1  ; // max partition length of array1
        // high = ( len1 <= len_of_half  ? len1 : len_of_half ) ; -- not necessary as len1 should be always 
        //less than len_of_half
        
        int l1 , l2 , r1 , r2 ; 

        while( low <= high ) {
            int partition_len_arr1 = low + (high - low ) /2 ; 
            int partition_len_arr2 = len_of_half - partition_len_arr1 ; 
            
            l1 = (partition_len_arr1 == 0 ? INT_MIN : nums1[partition_len_arr1-1]) ; 
            l2 = (partition_len_arr2 == 0 ? INT_MIN : nums2[partition_len_arr2-1]) ; 
            r1 = (partition_len_arr1 == len1 ? INT_MAX : nums1[partition_len_arr1]) ; 
            r2 = (partition_len_arr2 == len2 ? INT_MAX : nums2[partition_len_arr2]) ; 
            // first cross condition 
            if( l1 > r2 )
                high = partition_len_arr1 - 1 ; 
            // second cross condition
            else if(l2 > r1 ) 
                low = partition_len_arr1 + 1 ; 
            else 
                break ; 
        }

        if( (len1 + len2) % 2 == 0  )
            return (1.0 * ( max(l1 , l2 ) + min (r1 , r2) ))/2.0 ; 
        return 1.0 * max(l1 , l2 ) ; 

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}