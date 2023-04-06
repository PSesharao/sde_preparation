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
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> visited(V , false) ; 
        vector<int> bfs ;
        queue<int> pendingNodes ;
        
        visited[0] = true ;
        pendingNodes.push(0) ;
    
        while(!pendingNodes.empty()){
            int frontNode = pendingNodes.front() ;
            pendingNodes.pop() ; 
            bfs.push_back(frontNode) ;
            for( auto neigh : adj[frontNode] ){
                if(!visited[neigh])
                {
                    visited[neigh] = true ;
                    pendingNodes.push(neigh) ;
    
                }
                
            }
        }
    
        return bfs ;

    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}