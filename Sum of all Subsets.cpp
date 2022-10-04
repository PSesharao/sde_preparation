/*

https://practice.geeksforgeeks.org/problems/subset-sums2234/1

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


class Solution
{

private : 

void subsetSums(vector<int> &arr , int index , int N , int sum , vector<int> &ans ) {
    if(index == N ){
        ans.emplace_back( sum ) ; 
        return ; 
    }

    // including index 
    subsetSums(arr , index+1 , N , sum+arr[index] , ans ) ; 
    // excluding index
    subsetSums(arr , index+1 , N , sum , ans ) ; 
}

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans ; 
        subsetSums(arr , 0 , N , 0 , ans ) ; 
        sort(ans.begin() , ans.end() ) ; 
        return ans ; 
    }
}; 


int main() {
    init_code() ; 
    Solution sol ; 

    
}