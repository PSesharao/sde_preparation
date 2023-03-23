/*

https://leetcode.com/problems/minimum-path-sum/

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

// Recursion 
class Solution1 {
public:
    int minPathSum( int x , int y , int m , int n , vector<vector<int>>& grid ) {
        if(x == m-1 and y == n-1 )
            return grid[x][y] ; 

        int down_sum = MAX , right_sum = MAX ;

        // down 
        if(x+1 < m )
            down_sum = minPathSum(x+1 , y , m , n , grid ) ; 

        // right 
        if(y+1 < n )
            right_sum = minPathSum(x , y+1 , m , n , grid ) ; 

        return grid[x][y] + min(down_sum , right_sum ) ; 
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ;         
        return minPathSum( 0 , 0 , m , n ,  grid ) ; 
    }
};


// Memoization 
class Solution2 {
public:
    int minPathSum( int x , int y , int m , int n , 
        vector<vector<int>>& grid , vector<vector<int>> &dp ) {

        if(dp[x][y] != -1)
            return dp[x][y] ; 

        if(x == m-1 and y == n-1 )
            return dp[x][y]  = grid[x][y] ; 

        int down_sum = MAX , right_sum = MAX ;

        // down 
        if(x+1 < m )
            down_sum = minPathSum(x+1 , y , m , n , grid , dp ) ; 

        // right 
        if(y+1 < n )
            right_sum = minPathSum(x , y+1 , m , n , grid , dp ) ; 

        return dp[x][y] =grid[x][y] + min(down_sum , right_sum ) ; 

    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size() ; 
        int n = grid[0].size() ;         
        vector<vector<int>> dp(m , vector<int>(n , -1 ) ) ; 
        return minPathSum( 0 , 0 , m , n ,  grid , dp ) ; 

    }
};


// Tabulation

class Solution3 {
public:
    int minPathSum(  int m , int n , 
        vector<vector<int>>& grid , vector<vector<int>> &dp ) {

        dp[ m-1 ][n-1] = grid[ m-1 ][n-1]  ; 

        for(int x= m-1 ; x>=0 ; x-- )
            for(int y=n-1 ; y>=0 ; y-- )
            {
                if(x == m-1 and y == n-1 )
                    continue ;         

                int down_sum = MAX , right_sum = MAX ;

                // down 
                if(x+1 < m )
                    down_sum = dp[x+1][y] ; // minPathSum(x+1 , y , m , n , grid , dp ) ; 

                // right 
                if(y+1 < n )
                    right_sum = dp[x][y+1] ; // minPathSum(x , y+1 , m , n , grid , dp ) ; 

                 dp[x][y] =grid[x][y] + min(down_sum , right_sum ) ; 

          }

          return dp[0][0] ; 
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size() ; 
        int n = grid[0].size() ;         
        vector<vector<int>> dp(m , vector<int>(n , 0 ) ) ; 
        return minPathSum(  m , n ,  grid , dp ) ; 

    }
};

int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}} ; 
    cout << sol.minPathSum(grid) ; 
    return 0 ; 
}