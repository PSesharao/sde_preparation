/*

https://leetcode.com/problems/merge-sorted-array/

Intuition : To compare two sorted arrays 

[7 , 9 , 0 , 0 , 0 ] and [1 , 2 , 8] If we compare from end

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

-----------------------------------------------------------------
Gap Method or Shell sorting method

Just assume that we are traversing the single array of length (m+n)

Approach:

Initially take the gap as (m+n)/2;
Take as a pointer1 = 0 and pointer2 = gap.
Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
After completion of the loop reduce the gap as gap=gap/2.
Repeat the process until gap>0.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int gap = ceil((float)(m + n) / 2);

        while(gap !=0 ){
            int ptr1 = 0 ; 
            int ptr2 = gap ; 

            while(ptr2 < (m+n) ){
                // when both ptr1 and ptr2 lies in nums1 only 
                if( (ptr2 <m) and (nums1[ptr2] < nums1[ptr1] ) )
                    swap(nums1[ptr1]  , nums1[ptr2] ) ;

                // when ptr1 lies in nums1 and ptr2 lies in nums2
                else if ((ptr1 <m ) and (ptr2 >=m ) and (nums2[ptr2-m] < nums1[ptr1]) )
                    swap(nums1[ptr1]  , nums2[ptr2-m] ) ;

                // when both ptr1 and ptr2 lies in nums2 only 
                else if((ptr1 >=m ) and (ptr2 >=m ) and (nums2[ptr2-m] < nums2[ptr1-m]))
                    swap(nums2[ptr1-m]  , nums2[ptr2-m] ) ;

                ptr1++ ; 
                ptr2++ ;

            }

            if(gap == 1)
                gap = 0 ; // to stop futher as ceil (1/2) will be 1 always
            else
                gap = ceil((float)(gap) / 2);

        }

        // In case if the nums1 is of size (m+n) and is expected to be return as answer

        for(int i=m ; i<(m+n) ; i++ )
            nums1[i] = nums2[i-m] ;  
    }
};




int main() {
    init_code() ; 
    Solution sol ; 
    int m = 5 , n =3 ; 
    vector<int> nums1 = {3 , 7 , 9 , 15 , 18 , 0 , 0 , 0 } ; 
    vector<int> nums2 = {4 , 8 , 17} ; 
    sol.merge(nums1 , m , nums2 , n ) ; 
    //merge(nums1 , m , nums2 , n ) ; 
    for(int i=0 ; i<m ; i++ )
        cout << nums1[i] << " "; 
    cout << endl ; 
    for(int i=0 ; i<n ; i++ )
        cout << nums2[i] << " "; 
    cout << endl ; 

    for(int i=0 ; i<m+n ; i++ )
        cout << nums1[i] << " "; 

    return 0 ; 
}