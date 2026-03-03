/*

https://leetcode.com/problems/01-matrix/

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


// GFG 

class Triplet{

    public : 
    int x , y , distance ; 

    Triplet(int x , int y , int distance ){
        this->x = x ; 
        this->y = y ; 
        this->distance = distance ; 
    }
}; 

class Solution 
{
    public:
    
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int r = grid.size() ; 
        int c = grid[0].size() ; 

        vector<vector<bool>> visited(r , vector<bool>(c , false ) ) ;  
        vector<vector<int>> distance(r , vector<int>(c , 0 ) ) ; 

        int xd[] = { 0 , -1 , 1 , 0 } ; 
        int yd[] = { -1 ,0 , 0 , 1 } ; 

        queue<Triplet> Q ;

        for(int i=0 ; i<r ; i++ )
            for(int j=0 ; j<c ; j++ ){
                if(grid[i][j] == 1 )
                {
                    Triplet t(i , j , 0 ) ; 
                    visited[i][j] = true ; 
                    Q.push(t) ; 
                }
            }

        while(!Q.empty()){
            Triplet t = Q.front() ; 
            Q.pop() ; 

            int x = t.x ; 
            int y = t.y ; 
            int d = t.distance ; 
            distance[x][y] = d ; 

            for(int i=0 ; i<4 ; i++ ){
                int next_x = x+ xd[i] ; 
                int next_y = y + yd[i] ; 

                if(next_x >=0 and next_x < r and next_y >=0 and next_y < c ){
                    if(!visited[next_x][next_y] )
                    {
                        Triplet next(next_x , next_y , d+1 ) ; 
                        Q.push(next) ; 
                        visited[next_x][next_y] = true ; 

                    }
                }
            }

        }
        
        return distance ; 
    }
};


// Leetcode

class Triplet{

    public : 
    int x , y , distance ; 

    Triplet(int x , int y , int distance ){
        this->x = x ; 
        this->y = y ; 
        this->distance = distance ; 
    }
}; 


class Solution 
{
    public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid){
        int r = grid.size() ; 
        int c = grid[0].size() ; 

        vector<vector<bool>> visited(r , vector<bool>(c , false ) ) ;  
        vector<vector<int>> distance(r , vector<int>(c , 0 ) ) ; 

        int xd[] = { 0 , -1 , 1 , 0 } ; 
        int yd[] = { -1 ,0 , 0 , 1 } ; 

        queue<Triplet> Q ;

        for(int i=0 ; i<r ; i++ )
            for(int j=0 ; j<c ; j++ ){
                if(grid[i][j] == 0 )
                {
                    Triplet t(i , j , 0 ) ; 
                    visited[i][j] = true ; 
                    Q.push(t) ; 
                }
            }

        while(!Q.empty()){
            Triplet t = Q.front() ; 
            Q.pop() ; 

            int x = t.x ; 
            int y = t.y ; 
            int d = t.distance ; 
            distance[x][y] = d ; 

            for(int i=0 ; i<4 ; i++ ){
                int next_x = x+ xd[i] ; 
                int next_y = y + yd[i] ; 

                if(next_x >=0 and next_x < r and next_y >=0 and next_y < c ){
                    if(!visited[next_x][next_y] )
                    {
                        Triplet next(next_x , next_y , d+1 ) ; 
                        Q.push(next) ; 
                        visited[next_x][next_y] = true ; 

                    }
                }
            }

        }
        
        return distance ; 
    }
};
