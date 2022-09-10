/*

https://leetcode.com/problems/powx-n/

Approach: Binary Exponentiation 
Initialize ans as 1.0  and store a duplicate copy of n i.e nn 
using to avoid overflow ( when n is negative integer , that's why taking nn as long)

Check if nn is a negative number, in that case, make it a positive number.

Keep on iterating until nn is greater than zero, now if nn is an odd power 
then multiply x with ans ans reduce nn by 1. 
Else multiply x with itself and divide nn by two.

Now after the entire binary exponentiation is complete and nn becomes zero, 
check if n is a negative value we know the 
answer will be 1 by ans.

Time Complexity: O(log n)

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


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0 ; 
        long nn = n ; 
        if(nn < 0 )
            nn = -nn ; 

        while(nn >0 ) {
            // when nn is odd power 
            if(nn & 1 == 1 ){
                ans = ans * x ; 
                nn-- ; 
            }else{
                // when nn is even power 
                x =  x * x ; 
                nn = nn >> 1 ; // dividing by 2 
            }
        }

        if(n < 0 )
            return (double) 1.0 / (double) ans ; 
        return ans ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 
    cout << sol.myPow(2.50000 , -4) ; 
    
}