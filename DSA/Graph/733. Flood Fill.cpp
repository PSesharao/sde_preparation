/*

https://leetcode.com/problems/flood-fill/

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

void floodFill(vector<vector<int>>& res , 
    int x , int y , int oldCol , int newCol , vector<vector<bool>> &visited) {
    
    res[x][y] = newCol  ;
    visited[x][y] = true ; 
    int r = res.size() ; 
    int c = res[0].size() ; 

    int R[] = {0 , -1 , +1 , 0 } ;  
    int C[] = {-1 , 0 , 0 , +1 } ;

    for(int i=0 ; i<4 ; i++ ){
        int next_x = x + R[i] ; 
        int next_y = y + C[i] ;  

        if( next_x >=0 and next_x < r and next_y >=0 and next_y < c ){

            if( !visited[next_x][next_y] and res[next_x][next_y] == oldCol  )
                floodFill(res , next_x , next_y , oldCol , newCol , visited ) ; 
        }
    }


}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
        int sr, int sc, int color) {
        
        int oldCol = image[sr][sc] ;
        vector<vector<int>> res = image ; 
        // Just inorder not to tamper with given input image
        int r = res.size() ; 
        int c = res[0].size() ;         
        vector<vector<bool>> visited(r , vector<bool>(c , false ) ) ; 
        floodFill(res , sr , sc , oldCol , color , visited ) ; 
        return res ; 
    }
    
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}