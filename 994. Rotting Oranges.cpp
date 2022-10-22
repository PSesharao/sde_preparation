/*

https://leetcode.com/problems/rotting-oranges/

Time Complexity: O ( n x n ) x 4    

Reason: Worst-case – We will be making each fresh orange rotten in the grid 
and for each rotten orange will check in 4 directions

Space Complexity: O ( n x n )

Reason: worst-case –  If all oranges are Rotten, we will end up pushing all 
rotten oranges into the Queue data structure

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
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) 
            return 0 ;
    
        int R = grid.size() ;
        int C = grid[0].size() ;
    
        int totalOranges=0 , days=0 , rottenOranges=0  ;
    
        queue<pair<int , int>> rotten ;
    
        for(int r=0 ; r<R ; r++)
            for(int c=0 ; c<C ; c++)
            {
                if(grid[r][c] == 1)
                    totalOranges++ ;
                else if(grid[r][c] == 2){
                    totalOranges++ ;
                    rotten.push({r , c}) ;
                }
            }
    
    
        while(!rotten.empty()){
            int currentRottenOranges = rotten.size() ;
            rottenOranges+=currentRottenOranges ;
    
            while(currentRottenOranges--){
                pair<int , int> frontRotten = rotten.front() ;
                rotten.pop() ;
                int x=frontRotten.first ;
                int y= frontRotten.second ;
    
                //top 
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    grid[x-1][y] = 2 ;
                    rotten.push({x-1 , y}) ;
                }
    
                //down
                if(x+1<R && grid[x+1][y]==1)
                {
                    grid[x+1][y] = 2 ;
                    rotten.push({x+1 , y}) ;
                }
    
                //left 
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    grid[x][y-1] = 2 ;
                    rotten.push({x, y-1}) ;
                }
    
                //right 
                if(y+1<C && grid[x][y+1]==1)
                {
                    grid[x][y+1] = 2 ;
                    rotten.push({x, y+1}) ;
                }
    
            }
    
            // this means some oranges are newly rotten
            //from previous rotten oranges , it'll take 1 unit of time to rot these oranges 
            // in the next pass 
            if(!rotten.empty())
                days ++ ;
        }
        // at the end we are checking if all the oranges are rotten or not 
        return (totalOranges == rottenOranges ? days : -1 );
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}