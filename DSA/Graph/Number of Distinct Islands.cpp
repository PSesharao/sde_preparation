/*

https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

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


struct PairHash {
  size_t operator()(const pair<int, int>& p) const {
    return hash<int>()(p.first) ^ hash<int>()(p.second);
  }
};

struct VectorHash {
  size_t operator()(const vector<std::pair<int, int>>& v) const {
    size_t seed = v.size();
    for (const auto& p : v) {
      seed ^= PairHash()(p) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

class Solution {
  public:

    void bfs(int x , int y , vector<vector<int>>& grid ,
     vector<vector<bool>> &visited , 
     vector<pair<int , int >> &connectedIsland  ){

        int base_x = x ; 
        int base_y = y ; 

        queue<pair<int , int >> Q ; 
        Q.push({x , y }) ; 
        connectedIsland.push_back({x- base_x , y - base_y }) ; 
        visited[x][y] = true ; 

        int rows = grid.size() ; 
        int cols = grid[0].size() ;      

        int R[] = {0 , 1 , 0 , -1 } ;  
        int C[] = {1 , 0 , -1 , 0 } ;   

        while(!Q.empty()){

           pair<int , int > p = Q.front() ; 
           Q.pop() ; 

           int cur_x = p.first ; 
           int cur_y = p.second ; 

           for(int i=0 ; i<4 ; i++ ){
                int next_x = cur_x + R[i] ; 
                int next_y = cur_y + C[i] ; 

                if(next_x >=0 and next_x <rows and next_y>=0 and next_y < cols )
                {
                    if(!visited[next_x][next_y] and grid[next_x][next_y] == 1 ){
                        visited[next_x][next_y] = true ; 
                        Q.push( {next_x , next_y }) ; 
                        connectedIsland.push_back({next_x- base_x , next_y - base_y }) ; 
                    }

                }
                    
           }

        }

    }


    int countDistinctIslands(vector<vector<int>>& grid) {
 
        int rows = grid.size() ; 
        int cols = grid[0].size() ; 
        vector<vector<bool>> visited(rows , vector<bool>(cols , false ) ) ;
        unordered_set<vector<pair<int, int>>, VectorHash> distinctIslands;
    
        for(int x=0 ; x< rows ; x++ ){
            for(int y=0 ; y<cols ; y++ ){
                if(!visited[x][y] and grid[x][y] == 1){
                    vector<pair<int , int >> connectedIsland ;  
                    bfs( x , y , grid , visited , connectedIsland ) ; 
                    distinctIslands.insert(connectedIsland) ; 
                }
            }
        }

        return distinctIslands.size() ; 

    }
};

int main() {
    init_code() ; 

      vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
            
  Solution obj;
  cout << obj.countDistinctIslands(grid) << endl;
    return 0;
}


