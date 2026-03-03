/*

https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

edge case will be 

len1 = 4 , len2 = 6 
k =3 

here we can not pick all 4 from arr1 so high = min(k , len1 ) ;

len1 = 4 , len2 = 6 
k = 7 

here high can be 4 , but low cant be 0 because if we pick 0 from arr1 ,
we dont have 7 from arr2 , so the minimum we should pick should be 1 
i.e 

low = max ( 0 , k-len2 ) 

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


class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int len1, int len2, int k)
    {
        if(len1 > len2 ) return kthElement(arr2 , arr1 , len2 , len1 , k ) ; 
        
        int low = max ( 0 , k-len2 ) ; 
        //int high = len1 <= k ? len1 : k  ; 
        int high = min(k , len1 ) ; 

        int l1 , l2 , r1 , r2 ; 

        while( low <= high ) {
            int partition_len_arr1 = low + (high - low ) /2 ; 
            int partition_len_arr2 = k - partition_len_arr1 ; 
            
            l1 = (partition_len_arr1 == 0 ? INT_MIN : arr1[partition_len_arr1-1]) ; 
            l2 = (partition_len_arr2 == 0 ? INT_MIN : arr2[partition_len_arr2-1]) ; 
            r1 = (partition_len_arr1 == len1 ? INT_MAX : arr1[partition_len_arr1]) ; 
            r2 = (partition_len_arr2 == len2 ? INT_MAX : arr2[partition_len_arr2]) ; 
            // first cross condition 
            if( l1 > r2 )
                high = partition_len_arr1 - 1 ; 
            // second cross condition
            else if(l2 > r1 ) 
                low = partition_len_arr1 + 1 ; 
            else 
                break ; 
        }

        return max(l1 , l2 ) ; 
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}