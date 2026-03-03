/*

https://leetcode.com/problems/pascals-triangle/

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

    bool bfsIsBipartite(int v , vector<vector<int>>& graph , vector<int> &colour )
    {

        queue<int> Q ; 
        Q.push(v) ; 

        colour[v] = 0 ; // initial color

        while(!Q.empty()){

            int cur_node = Q.front() ; 
            Q.pop() ; 
            
            for(auto neigh : graph[cur_node]){

                if(colour[neigh] == -1 )
                {
                    colour[neigh] = 1 - colour[cur_node] ;  
                    Q.push(neigh) ; 
                    // color the neighbor with the opposite color

                }else{
                    if(colour[neigh] == colour[cur_node] )
                       // found a conflict, the graph is not bipartite
                        return false ; 
                }
            }

        }

        return true ; 
    }

    bool isBipartite(  vector<vector<int>>& graph  ) {
        
        // The given graph it self is in a adjacency list format
        int V = graph.size() ; 

        vector<int> colour(V , -1 ) ; 

        // -1 --> unvisited
        // 0 --> one of the color
        // 1 --> other color 

        for(int v=0 ; v<V ; v++  )
        {
            if(colour[v] == -1 )
                if(!bfsIsBipartite(v , graph , colour ))
                    return false ; 
        }

        return true ; 

    }
};



class Solution1 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1); // -1: not colored yet, 0: color 1, 1: color 2
        
        for (int i = 0; i < n; i++) {
            if (colors[i] != -1) continue; // already colored
            
            queue<int> q;
            q.push(i);
            colors[i] = 0; // color 1
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : graph[curr]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[curr]; // color the neighbor with the opposite color
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[curr]) {
                        return false; // found a conflict, the graph is not bipartite
                    }
                }
            }
        }
        
        return true; // no conflicts found, the graph is bipartite
    }
};

int main() {
    init_code() ; 
    Solution sol ; 
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}}; 
    cout << sol.isBipartite(graph) ; 
    return 0;
}
