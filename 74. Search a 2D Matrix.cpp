/*

https://leetcode.com/problems/search-a-2d-matrix/

Initially have a low index as the first index of the considered 1D matrix(i.e: 0) 
and high index as the last index of the considered 1D matrix(i.e: (R*C)-1).

Get the middle index as (low+high)/2.We can get the element at middle index 
using matrix[middle/C][middle%C].

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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size() ; 
        int C = matrix[0].size() ; 

        if(R ==0 )
            return false ; 

        int low = 0 , high = R*C-1 , mid  ; 

        while(low <= high ){
            mid = low+ ((high- low)>>1 ) ;
            int r = mid/C ; 
            int c = mid%C ; 
            if(target == matrix[r][c])
                return true ; 
            else if(target < matrix[r][c] ) 
                high = mid-1 ;
            else
                low = mid+1 ; 
        }
        return false ; 
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}