/*

https://leetcode.com/problems/range-sum-query-2d-immutable/description/

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


class NumMatrix {

public:
    vector<vector<int>> prefix_sum_mat ; 
    NumMatrix(vector<vector<int>>& matrix) {
        
        int R = matrix.size() ; 
        int C = matrix[0].size() ; 

        prefix_sum_mat = vector<vector<int>>(R+1,vector<int>(C+1 , 0 )); 

        // top row and left column are 0 

        for(int r=1 ; r<=R ; r++ )
            for(int c=1 ; c<=C ; c++ ){
                prefix_sum_mat[r][c] = prefix_sum_mat[r-1][c] + prefix_sum_mat[r][c-1] 
                - prefix_sum_mat[r-1][c-1] + matrix[r-1][c-1] ; 

            }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_sum_mat[row2+1][col2+1] - prefix_sum_mat[row1][col2+1] 
        - prefix_sum_mat[row2+1][col1] + prefix_sum_mat[row1][col1] ; 
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}