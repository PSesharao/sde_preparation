/*

https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

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
    int getPairsCount(int arr[], int n, int k) {

        int ans = 0 ; 
        unordered_map<int , int > map_freq ; 

        for(int i=0 ; i< n ; i++ ){
            int num = arr[i] ; 
            int remaining_diff =  k - num ; 
            ans += map_freq[remaining_diff] ; 
            map_freq[num] ++ ; 
        }

        return ans ; 

    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}