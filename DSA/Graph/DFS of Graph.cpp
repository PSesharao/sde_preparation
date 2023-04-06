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
   
    void dfsOfGraph(int v , vector<int> adj[] , 
        vector<bool> &visited , vector<int> &dfs  ){

        visited[v] = true ; 
        dfs.push_back(v) ; 

        for( auto neigh : adj[v] ){
            if(!visited[neigh])
                dfsOfGraph(neigh , adj , visited , dfs ) ; 
        }

    } 

    vector<int> dfsOfGraph(int V, vector<int> adj[] ) {
        vector<int> dfs ; 
        vector<bool> visited(V , false ) ; 
        dfsOfGraph(0 , adj , visited , dfs ) ; 
        return dfs ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}