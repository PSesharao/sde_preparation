/*

https://leetcode.com/problems/merge-sorted-array/

Intuition : To compare two sorted arrays 

[7 , 9 , 0 , 0 , 0 ] and [1 , 2 , 8] If we compare from 

we would be able to fill up the last 0's spaces with greater
elements and at last what ever left in arr2 can be copied to 
the front of arr1


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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int num1_indx = m-1 ;
        int num2_indx = n-1 ;
        int num1_back_indx = m+n-1 ; 

        while( num1_indx>=0 && num2_indx>=0 ){

            if(nums1[num1_indx] > nums2[num2_indx] )
                nums1[num1_back_indx--] = nums1[num1_indx--] ; 
            else 
                nums1[num1_back_indx--] = nums2[num2_indx--] ;
        }

        // what ever left in arr2 can be copied to the front of arr1
        while( num2_indx>=0 )
            nums1[num1_back_indx--] = nums2[num2_indx--] ;
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}