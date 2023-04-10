/*

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

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
        vector<int> adj[] , vector<bool> &visited , vector<bool> &onpath ){

        visited[v] = true ; 
        onpath[v] = true ; 

        for(int neigh : adj[v] ){
            if( !visited[neigh] ){
                if(isCycleDfs(neigh , adj , visited , onpath  ))
                    return true ;  
            }else{

                // The case where there is a backedge from neigh to the v
                if( onpath[neigh] )
                    return true ; 
            }
                
        }

        onpath[v] = false ; 
        return false ;         
    }  
    
    bool isCyclic(int V, vector<int> adj[]) {

        vector<bool> visited(V , false ) ;
        vector<bool> onpath(V , false ) ;

        for(int v=0 ; v<V ; v++){
            if(!visited[v]){
                 if(isCycleDfs(v ,  adj , visited , onpath  ))
                    return true ;                
            }

        }
        return false ;         
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}