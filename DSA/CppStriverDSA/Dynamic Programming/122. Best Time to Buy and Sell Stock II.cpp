/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalMat  ; 
        for(int r=0 ; r<numRows ; r++ ){
            vector<int> currentRow(r+1,0) ; 
            currentRow[0] = currentRow[r] = 1 ; 
            for(int c=1 ; c<=r-1 ; c++ ){
                currentRow[c] = pascalMat[r-1][c-1] + pascalMat[r-1][c] ; 
            }
            pascalMat.push_back(currentRow) ;  
        }

        return pascalMat ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}