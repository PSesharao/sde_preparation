/*

https://www.codechef.com/START66B/problems/GOODBINSTR

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


int goodString(string s)
{
    int n = s.length();
    if(s[0] != s[n-1])
    {
        return 2;
    }
    else{
        return n-2;
    }
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}