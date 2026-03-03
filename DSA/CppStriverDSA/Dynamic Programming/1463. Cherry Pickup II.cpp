/*

https://leetcode.com/problems/cherry-pickup-ii/

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

    int cherryPickup( int x , int y1 , int y2 , int m , int n , vector<vector<int>>& grid ) {
        
        if( x == m-1 )
        {
            if(y1 == y2 )
                return grid[x][y1] ; 
            return grid[x][y1] + grid[x][y2] ; 
        }

        int y[] = {-1 , 0 , +1 } ; 

        int maxCherry = INT_MIN ; 

        int curr_cherry = 0 ; 
        if( y1 == y2 )
            curr_cherry = grid[x][y1] ; 
        else
            curr_cherry = grid[x][y1] + grid[x][y2] ;         

        for( int robo1=0 ; robo1< 3 ; robo1++ )
            for( int robo2=0 ; robo2< 3 ; robo2++ ){

                int r = x+1 , c1 = y1+y[robo1] , c2 = y2+y[robo2] ; 

                if( r < m and (c1 >= 0 and c1 < n ) and ( c2 >= 0 and c2 < n ) )
                    maxCherry = max(maxCherry , cherryPickup(r , c1 , c2 , m , n , grid )) ; 

            }

        return curr_cherry + maxCherry ; 

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ;  
        return cherryPickup(0 , 0 , n-1 , m , n ,  grid ) ; 
    }
};

// Memoization 
class Solution2 {

public:

    int cherryPickup( int x , int y1 , int y2 , int m , int n ,
     vector<vector<int>>& grid , vector<vector<vector<int>>> &dp ) {
        
        if( dp[x][y1][y2] != -1 ) 
            return dp[x][y1][y2] ; 

        if( x == m-1 )
        {
            if(y1 == y2 )
                return  dp[x][y1][y2] = grid[x][y1] ; 
            return  dp[x][y1][y2] = grid[x][y1] + grid[x][y2] ; 
        }

        int y[] = {-1 , 0 , +1 } ; 

        int maxCherry = INT_MIN ; 

        int curr_cherry = 0 ; 
        if( y1 == y2 )
            curr_cherry = grid[x][y1] ; 
        else
            curr_cherry = grid[x][y1] + grid[x][y2] ;         

        for( int robo1=0 ; robo1< 3 ; robo1++ )
            for( int robo2=0 ; robo2< 3 ; robo2++ ){

                int r = x+1 , c1 = y1+y[robo1] , c2 = y2+y[robo2] ; 

                if( r < m and (c1 >= 0 and c1 < n ) and ( c2 >= 0 and c2 < n ) )
                    maxCherry = max(maxCherry , cherryPickup(r , c1 , c2 , m , n , grid , dp )) ; 

            }

        return  dp[x][y1][y2] = curr_cherry + maxCherry ; 

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ;  
        vector<vector<vector<int>>> dp(m , vector<vector<int>>( n , vector<int>(n , -1 ))) ; 
        return cherryPickup(0 , 0 , n-1 , m , n ,  grid , dp ) ; 
    }


};



// Tabulation
class Solution3 {

public:

    int cherryPickup( int m , int n ,
     vector<vector<int>>& grid , vector<vector<vector<int>>> &dp ) {
        
        for( int y1=n-1 ; y1>=0 ; y1-- )
            for( int y2=n-1 ; y2>=0 ; y2-- )
            {
                if(y1 == y2 )
                    dp[m-1][y1][y2] = grid[m-1][y1] ; 
                else 
                    dp[m-1][y1][y2] = grid[m-1][y1] + grid[m-1][y2] ; 
            }


        int y[] = {-1 , 0 , +1 } ;     

        for(int x=m-2 ; x>=0 ; x-- )
         for( int y1=n-1 ; y1>=0 ; y1-- )
            for( int y2=n-1 ; y2>=0 ; y2-- ){

                int maxCherry = INT_MIN ; 

                int curr_cherry = 0 ; 
                if( y1 == y2 )
                    curr_cherry = grid[x][y1] ; 
                else
                    curr_cherry = grid[x][y1] + grid[x][y2] ;         

                for( int robo1=0 ; robo1< 3 ; robo1++ )
                    for( int robo2=0 ; robo2< 3 ; robo2++ ){

                        int r = x+1 , c1 = y1+y[robo1] , c2 = y2+y[robo2] ; 

                        if( r < m and (c1 >= 0 and c1 < n ) and ( c2 >= 0 and c2 < n ) )
                            maxCherry = max(maxCherry , dp[r][c1][c2]  ) ; // cherryPickup(r , c1 , c2 , m , n , grid , dp )) ; 

                    }

                 dp[x][y1][y2] = curr_cherry + maxCherry ; 
            }            

        

        return dp[0][0][n-1] ; 

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ;  
        vector<vector<vector<int>>> dp(m , vector<vector<int>>( n , vector<int>(n , 0 ))) ; 
        return cherryPickup( m , n ,  grid , dp ) ; 
    }

};




int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}} ; 
    cout << sol.cherryPickup(grid) ; 
    return 0 ; 
}