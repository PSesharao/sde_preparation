/*

https://leetcode.com/problems/number-of-provinces/

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

    void findCircleNum( int v  , vector<vector<int>>& isConnected , 
        int V , vector<bool> &visited ) {

        visited[v] = true ; 

        for(int neigh = 0 ; neigh < V ; neigh ++ ){

            if(neigh != v and !visited[neigh] and (isConnected[v][neigh] == 1 ) )
                findCircleNum(neigh , isConnected , V , visited ) ; 
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size() ; 
        vector<bool> visited(V , false ) ; 
        int noOfProvinces =0 ; 

        for(int v=0 ; v< V ; v++ ){

            if(!visited[v]){
                findCircleNum(v , isConnected , V , visited ) ; 
                noOfProvinces ++ ; 
            }
        }
        return noOfProvinces ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}