/*

https://leetcode.com/problems/course-schedule-ii/

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

    vector<int> topoSort(int V, vector<int> adj[]) {

        
        vector<int> indegree(V , 0 ) ;
        vector<int> tpSort ; 

        for(int v=0 ; v<V ; v++ )
            for(int neigh : adj[v] )
                indegree[neigh]++ ; 

        queue<int> Q;

        for(int v=0 ; v<V ; v++ )
            if(indegree[v] == 0 )
                Q.push(v) ;

        while(!Q.empty()){
            int v = Q.front() ; 
            Q.pop() ; 

            tpSort.push_back(v) ;

            for(int neigh : adj[v] )
            {
                indegree[neigh]-- ; 
                if(indegree[neigh] == 0 )
                    Q.push(neigh) ; 
            }

        }

        if (tpSort.size() == V) return tpSort;
        return {};
        

    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // as they have given dependencies in reverse
        }

        return topoSort(numCourses , adj ) ; 
               
    }



};


int main() {
    init_code() ; 
    Solution sol ; 

    
}