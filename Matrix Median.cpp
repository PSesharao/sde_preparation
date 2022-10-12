/*

https://www.interviewbit.com/problems/matrix-median/

log(32) * r * log(c)
log(32) = 32 
O(32 * r * log(c)). The upper bound function will take log(c) time and is performed 
for each row. And since the numbers will be max of 32 bit, so binary search of numbers 
from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 

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

// This is upperbound(<=) function 

int findCountLessThanMid(vector<int> &row , int cols , int k  ) {
    int low = 0 , high = cols-1 ;

    while(low <= high ){
        int mid = low + ( high-low )/2 ; 
        if(row[mid] <= k )
            low = mid+1 ; 
        else
            high = mid-1 ; 
    }

    return low ; // because low will be pointing to the upperbound index
    // which represents the count 

    // Lets take [1 2 3 3 3 4 5 ] , k = 3 
    // At end low becomes point to 4 (whose index is 5 represents count of <=3 )
}

int Solution::findMedian(vector<vector<int> > &A) {
    
    int low=1  , high = 1e9  ; // given this range 
    int rows = A.size() , cols = A[0].size();  
    while(low <= high ){
        int mid = low + ( high-low )/2 ; 
        // we just need to see how many elements in matrix are less than or equal to mid 

        int count = 0  ; 
        for(int r=0 ; r<rows ; r++ ){
            count += findCountLessThanMid(A[r] , cols , mid ) ; 
        }

        // since rows * cols is odd , our median is definitely one element separating 
        // left half and right half , here also the upperbound (<=) plays crucial role  
        if(count <= ((rows * cols)/2)) 
            low = mid+1 ; 
        else 
            high = mid-1 ; 
    } 
    return low ; 
}

int main() {
    init_code() ; 
    Solution sol ; 

    
}