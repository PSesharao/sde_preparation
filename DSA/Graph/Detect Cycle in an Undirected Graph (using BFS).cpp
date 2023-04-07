/*


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

    bool isCycleBfs( int start ,  int V, 
        vector<int> adj[] , vector<bool> &visited ) {

        queue<pair<int , int >> Q ; 
        
        Q.push({start , -1 }) ; 
        visited[start] = true ; 

        while(!Q.empty()){
            pair<int , int > f = Q.front() ; 
            Q.pop() ; 
            int node = f.first ; 
            int parent = f.second ; 
            

            for(int neigh : adj[node] ){
                if( !visited[neigh] ){
                    visited[neigh] = true ; 
                    Q.push({neigh , node }) ; 
                }else{

                    // The case where neighbour is not a paraent and visited
                    if( neigh != parent )
                        return true ; 
                }
                
                    
            }
        }

        return false ; 

    }    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V , false ) ;
        for(int v=0 ; v<V ; v++){
            if(!visited[v]){
                 if(isCycleBfs(v , V , adj , visited ))
                    return true ;                
            }

        }
        return false ; 
    }
};

int main() {
    init_code() ; 
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0 ; 
}
