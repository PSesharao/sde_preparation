/*

https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

As the answer should be in lexicographical order so it’s better to 
try the directions in lexicographical order i.e (D,L,R,U)

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


class Solution{

    private : 
    void ratInAMaze(int N , vector<vector<int>> & maze , vector<vector<int>> &visited 
        , int row , int col , string path , vector<string> &ans){

            
            if(row==N-1 and col==N-1) {
                ans.push_back(path) ; 
                return ;
            }
            visited[row][col] = 1 ;

            // Down 
            if( (row+1<N) && maze[row+1][col] == 1 && visited[row+1][col] !=1)
                ratInAMaze(N , maze , visited , row+1 , col , path + 'D' , ans  ) ;

            // Left
            if( (col-1>=0 ) && maze[row][col-1] == 1 && visited[row][col-1] !=1) 
                ratInAMaze(N , maze , visited , row , col-1 , path + 'L' , ans  ) ;

            // Right
            if( (col+1 < N ) && maze[row][col+1] == 1 && visited[row][col+1] !=1) 
                ratInAMaze(N , maze , visited , row , col+1 , path + 'R' , ans ) ;

            // Up
            if( ( row-1>=0  ) && maze[row-1][col] == 1 && visited[row-1][col] !=1) 
                ratInAMaze(N , maze , visited , row-1 , col , path + 'U' , ans ) ;


            visited[row][col] = 0 ; 
    }

    public:
    vector<string> findPath(vector<vector<int>> &maze , int N ) {
        vector<string> ans;
        vector<vector<int>> visited(N , vector<int>(N , 0)) ;
        // only if source cell is enabled rat can move further 
        if(maze[0][0] == 1 ) 
            ratInAMaze(N , maze , visited , 0 , 0 , "" , ans ) ;
        return ans ;  
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}