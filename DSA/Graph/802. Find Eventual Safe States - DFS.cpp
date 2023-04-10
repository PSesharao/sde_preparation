/*

https://leetcode.com/problems/find-eventual-safe-states/

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

    bool isCycleDfs(int v , 
        vector<vector<int>>& graph , vector<bool> &visited , 
        vector<bool> &onpath , vector<bool> &safeNodesCheck  ){

        visited[v] = true ; 
        onpath[v] = true ; 

        for(int neigh : graph[v] ){
            if( !visited[neigh] ){
                if(isCycleDfs(neigh , graph , visited , onpath , safeNodesCheck  ))
                    return true ;  
            }else{

                // The case where there is a backedge from neigh to the v
                if( onpath[neigh] )
                    return true ; 
            }
                
        }

        onpath[v] = false ; 
        safeNodesCheck[v] = true ; 
        return false ;         
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph ) {
        
        int V = graph.size() ; 
        vector<bool> visited(V , false ) ;
        vector<bool> onpath(V , false ) ;
        vector<bool> safeNodesCheck(V , false ) ;

        vector<int> safeNodes; 
        for(int v=0 ; v<V ; v++){
            if(!visited[v])
                 isCycleDfs(v ,  graph , visited , onpath  , safeNodesCheck  ) ;              

        }

        for(int v=0 ; v< V ; v++ )
            if(safeNodesCheck[v])
                safeNodes.push_back(v) ; 

        return safeNodes ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}