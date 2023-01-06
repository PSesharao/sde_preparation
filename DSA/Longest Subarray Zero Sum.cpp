/*

https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Now let’s say we know that the sum of subarray(i, j) = S, and we also know that sum of 
subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.

Let us understand the above statement clearly


So in this problem, we’ll store the prefix sum of every element, and if we observe 
that 2 elements have same prefix sum, we can conclude that the 2nd part of this 
subarray sums to zero

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

int LongestSubsetWithZeroSum(vector <int> arr) {
    int N = arr.size() ; 
    int max_len = 0 ; 
    if(N == 0 )
        return 0 ; 
    int prefix_sum = 0 ; 
    unordered_map<int , int > prefix_sum_map ; 
    for(int i=0 ; i<N ; i++ ){
        prefix_sum += arr[i] ; 
        if(prefix_sum == 0)
            max_len = max(max_len , i+1) ; 
        else if(prefix_sum_map.count(prefix_sum)>0){
            int k = prefix_sum_map[prefix_sum] ; 
            max_len = max(max_len , i-k) ; 
        }else{
            prefix_sum_map[prefix_sum] = i ; 
        }
    }
    return max_len ; 
}

int main() {
    init_code() ; 
    

    
}