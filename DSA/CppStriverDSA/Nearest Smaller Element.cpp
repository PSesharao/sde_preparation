/*

https://www.interviewbit.com/problems/nearest-smaller-element/

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


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size() ; 
    stack<int> stk ; 
    vector<int> result(n , -1 ) ; 
    for(int i=0 ; i<n ; i++ ){
        while(!stk.empty() and stk.top() >= A[i])
            stk.pop() ; 
        if(!stk.empty())
            result[i] = stk.top() ; 
        else 
            result[i] = -1 ;  
        stk.push(A[i]) ; 
    }
    return result ; 
}



int main() {
    init_code() ; 
    Solution sol ; 

    
}