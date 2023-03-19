/*

Similar Question : Bi Partite Graph 
https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

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

private : 

    bool isPossibleToFill(int node ,int color , int fill_node[], bool graph[101][101] , int N ){
        for(int k=0 ; k<N ; k++ ){
            // If any adjacent vertex k is filled by col
            if( k !=node and graph[k][node] ==1 and fill_node[k] == color )
                return false ; 
        }
        return true ; 
    }

    bool graphColoring( int node , int fill_node[] , bool graph[101][101], int M , int N  ){
        if(node == N){
            return true ; 
        }

        for(int color = 1 ; color <=M ; color++ ){

            if(isPossibleToFill(node , color , fill_node ,  graph , N )){
                fill_node[node] = color ; 
                if(graphColoring(node+1 , fill_node , graph , M , N  ))
                    return true ; // solution is found no need to check further for other ways
                fill_node[node] = 0 ; // Resetting 
            }
        }
        return false ; 
    }


public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int M, int N) {
        // your code here
        // Initially all nodes are coloured with none 0 
        int fill_node[N] = {0};
        return graphColoring(0 , fill_node , graph , M , N ) ; 
    }

};


int main() {
    init_code() ; 
    Solution sol ; 

    
}