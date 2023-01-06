/*

https://leetcode.com/problems/set-matrix-zeroes/

My idea is simple: store states of each row in the first of that row, 
and store states of each column in the first of that column. 
Because the state of row0 and the state of column0 would occupy the same cell, 
I let it be the state of row0, and use another variable "col0" for column0. 
In the first phase, use matrix elements to set states in a top-down way. 
In the second phase, use states to set matrix elements in a bottom-up way.

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
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size() ;
        int C = matrix[0].size() ;
        int col0 = 1 ; 
        for(int r=0 ; r<R ; r++)
            for(int c=0 ; c<C ; c++){
                if(matrix[r][c] == 0){
                    if(c==0)
                        col0 = 0 ;
                    else
                    {
                        matrix[r][0]=0;
                        matrix[0][c]=0;
                    }  
                }
            }
        for(int r=R-1 ; r>=0 ; r--)
            for(int c=C-1 ; c>=0 ; c--){
                if(c==0){
                    if(col0==0 || matrix[r][0]==0 )
                        matrix[r][c] = 0 ;
                }
                else{
                    if(matrix[r][0]==0 || matrix[0][c]==0 )
                        matrix[r][c] = 0 ;
                }
            }
    }
};


int main() {
    init_code() ; 
}