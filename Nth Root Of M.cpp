/*

https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
https://www.geeksforgeeks.org/calculating-n-th-real-root-using-binary-search/

Take eps as 1e-6, since we have to find answers to 6 decimal places.

Time Complexity:  log(M x 10^d) X N 

Let say we are find answers upto 1 decimal spaces

[1 ,1.1 ,1.2 , ...... , 26.8 , 26.9 , 27 ]
It'll be  ( M x 10 )  search space 
If it is d decimal spaces ( M x 10^d )

and also you are running multiplier N times each 

Space Complexity: O(1)

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

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double findNthRootOfM(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }

    return low ; // we can return high also
}

int main() {
    init_code() ; 
    
    cout << findNthRootOfM(6 , 46 ) ; 
    
}