/*

https://leetcode.com/problems/surrounded-regions/

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

    void dfs( int x , int y , vector<vector<char>>& board , vector<vector<bool>> &visited ){

        visited[x][y] = true ; 

        int rows = board.size() ; 
        int cols = board[0].size() ; 

        int R[] = {0 , -1 , +1 , 0 } ;  
        int C[] = {-1 , 0 , 0 , +1 } ;

        for(int i=0 ; i<4 ; i++ ){
            int next_x = x + R[i] ; 
            int next_y = y + C[i] ;  

            if( next_x >=0 and next_x < rows and next_y >=0 and next_y < cols ){

                if( !visited[next_x][next_y] and board[next_x][next_y] == 'O'  )
                    dfs(next_x , next_y , board , visited ) ; 
                    
            }
        }

    }

    void solve( vector<vector<char>>& board ) {
        int rows = board.size() ; 
        int cols = board[0].size() ; 
        vector<vector<bool>> visited(rows , vector<bool>(cols , false ) ) ;

        // first row
        for(int y=0 ; y<cols ; y++ )
            if( board[0][y] == 'O' and !visited[0][y] )
                dfs(0 , y , board , visited  ) ; 

        // last row
        for(int y=0 ; y<cols ; y++ )
            if( board[rows-1][y] == 'O' and !visited[rows-1][y] )
                dfs(rows-1 , y , board , visited  ) ;             

        // first col
        for(int x=0 ; x<rows ; x++ )
            if( board[x][0] == 'O' and !visited[x][0] )
                dfs(x , 0 , board , visited  ) ;             

        // last col 
        for(int x=0 ; x<rows ; x++ )
            if( board[x][cols-1] == 'O' and !visited[x][cols-1] )
                dfs(x , cols-1 , board , visited  ) ;      


        for(int x=0 ; x<rows ; x++ )
            for(int y=0 ; y<cols ; y++ )
                if(board[x][y] == 'O' and !visited[x][y] )
                    board[x][y] = 'X' ; 

    }
};