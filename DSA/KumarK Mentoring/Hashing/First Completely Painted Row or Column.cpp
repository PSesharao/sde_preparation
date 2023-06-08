/*

https://leetcode.com/problems/first-completely-painted-row-or-column/

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


#define INF int(1e9 + 7)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int , int> index_map ; 

        for(int i=0 ; i< arr.size() ; i++ )
            index_map[arr[i]] = i ; 

        int ans = INF ; 
        for(int r=0 ; r<mat.size() ; r++ ){
            int row_max = 0 ; 
            for(int c=0 ; c<mat[0].size() ; c++ ){
                row_max = max(row_max , index_map[mat[r][c]]) ; 
            }
            ans = min(ans , row_max ) ; 
        }


        for(int c=0 ; c<mat[0].size() ; c++ ){
            int col_max = 0 ; 
            for(int r=0 ; r<mat.size() ; r++ ){
                col_max = max(col_max , index_map[mat[r][c]]) ; 
            }
            ans = min(ans , col_max ) ; 
        }

        return ans ; 

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}