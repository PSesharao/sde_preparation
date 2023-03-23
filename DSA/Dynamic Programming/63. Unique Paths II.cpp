/*

https://leetcode.com/problems/pascals-triangle/

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
    int uniquePathsWithObstacles(int x , int y , int m , int n  , vector<vector<int>>& obstacleGrid) {

        if( x == m-1 and y == n-1 )
            return 1 ; 


        // down
        int down_moves = 0 , right_moves = 0 ;
        if(x+1 < m and obstacleGrid[x+1][y] !=1 )
            down_moves = down_moves + 0LL + uniquePathsWithObstacles(x+1 , y , m , n , obstacleGrid ) ; 

        // right
        if(y+1 < n and obstacleGrid[x][y+1] !=1 )
            right_moves = right_moves+ 0LL + uniquePathsWithObstacles(x , y+1 , m , n , obstacleGrid ) ;

        return 0LL + right_moves+down_moves ;  
                
        
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() ; 
        int n = obstacleGrid[0].size() ; 

        if(obstacleGrid[0][0] == 1 )
            return 0 ; 

        return uniquePathsWithObstacles(0 , 0 , m , n , obstacleGrid ) ; 
        
    }
};


// Memoization 

class Solution2 {
public:
    int uniquePathsWithObstacles(int x , int y , int m , int n  ,
     vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp ) {

        if(dp[x][y] != -1)
            return dp[x][y] ; 

        if( x == m-1 and y == n-1 )
            return dp[x][y] = 1 ; 


        // down
        int down_moves = 0 , right_moves = 0 ;
        if(x+1 < m and obstacleGrid[x+1][y] !=1 )
            down_moves = down_moves + 0LL + uniquePathsWithObstacles(x+1 , y , m , n , obstacleGrid , dp ) ; 

        // right
        if(y+1 < n and obstacleGrid[x][y+1] !=1 )
            right_moves = right_moves+ 0LL + uniquePathsWithObstacles(x , y+1 , m , n , obstacleGrid , dp ) ;

        return dp[x][y] = 0LL + right_moves+down_moves ;  
                
        
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() ; 
        int n = obstacleGrid[0].size() ; 

        if(obstacleGrid[0][0] == 1 )
            return 0 ; 

        vector<vector<int>> dp(m , vector<int>(n , -1 ) ) ; 

        return uniquePathsWithObstacles(0 , 0 , m , n , obstacleGrid , dp ) ; 
        
    }
};


// Tabulation
class Solution3 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() ; 
        int n = obstacleGrid[0].size() ; 

        if(obstacleGrid[0][0] == 1 )
            return 0 ; 

        vector<vector<int>> dp( m , vector<int>(n , 0 )) ; 
        dp[m-1][n-1] = 1 ;


        for(int x= m-1 ; x>=0 ; x-- )
            for(int y=n-1 ; y>=0 ; y-- )
            {
                if(x == m-1 and y == n-1 )
                    continue ; 
                
                int down_moves = 0 , right_moves = 0 ;
                // down
                if(x+1 < m and obstacleGrid[x+1][y] !=1 )
                    down_moves = down_moves + 0LL + dp[x+1][y] ; // uniquePathsWithObstacles(x+1 , y , m , n , obstacleGrid , dp ) ; 

                // right
                if(y+1 < n and obstacleGrid[x][y+1] !=1 )
                    right_moves = right_moves+ 0LL + dp[x][y+1] ; // uniquePathsWithObstacles(x , y+1 , m , n , obstacleGrid , dp ) ;

                 dp[x][y] = 0LL + right_moves+down_moves ;  
               
            }

            return dp[0][0] ; 

    }
};


int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}} ; 
    cout << sol.uniquePathsWithObstacles( obstacleGrid ) ; 
    return 0 ; 
}