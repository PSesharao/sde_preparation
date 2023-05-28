/*

https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

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

#define INF int(1e9 + 7)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){

        vector<int> adj[N]; 

        for(auto edge : edges ){
            adj[edge[0]].push_back(edge[1]) ; 
            adj[edge[1]].push_back(edge[0]) ;
        }

        vector<int> dis(N , INF ) ; 
        dis[src] = 0 ; 

        queue<int> Q ; 
        Q.push(src) ;

        while(!Q.empty()){

            int v = Q.front() ; 
            Q.pop() ; 

            for(auto  neigh : adj[v] ){

                if(dis[v] + 1 < dis[neigh] ){
                    dis[neigh] = dis[v] + 1 ; 
                    Q.push(neigh) ; 
                }
            }

        }

        

        for(int i=0 ; i<N ; i++ ){
            if(dis[i] == INF )
                dis[i] = -1 ; 
        }

        return dis ;  


    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}