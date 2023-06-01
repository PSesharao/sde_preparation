/*

https://practice.geeksforgeeks.org/problems/max-distance-between-same-elements/1

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
    int maxDistance(int arr[], int n){
        int max_d = 0 ; 
        unordered_map<int , int > map_idx ; 
        for(int i=0 ; i< n ; i++ ){
            if(map_idx.count(arr[i]) > 0 )
                max_d = max({max_d , i - map_idx[arr[i]]}) ; 
            else
                map_idx[arr[i]] = i ; 
        }

        return max_d ; 

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}