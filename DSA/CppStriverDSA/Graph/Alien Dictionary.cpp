/*

https://practice.geeksforgeeks.org/problems/alien-dictionary/1

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



class Solution{

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
        return tpSort ; 
    }    

    string findOrder(string dict[], int N, int K) {

        vector<int> adj[K] ; 

        for(int i=1 ; i<N ; i++ ){
            string str1 = dict[i-1] ; 
            string str2 = dict[i] ; 

            int len = ( str1.size() < str2.size() ) ? str1.size() : str2.size() ; 

            for(int ptr =0 ; ptr < len ; ptr ++ ){
                if(str1[ptr] != str2[ptr] ){
                    adj[str1[ptr] - 'a'].push_back(str2[ptr] - 'a') ; 
                    break ; 
                }
            }
        }

        vector<int> tpSort = topoSort(K , adj ) ; 
        string ans = "" ; 

        for(auto v : tpSort )
            ans += (v+ 'a') ; 

        return ans ; 
    }
};
