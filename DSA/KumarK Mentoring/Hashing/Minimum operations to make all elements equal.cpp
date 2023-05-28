/*

https://www.desiqna.in/part-6

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
    int minOperations(vector<int> &A ){
        unordered_map<int , int > f ; 
        for(auto num : A )
            f[num] ++ ; 

        int maxF = 0 ; 
        for(auto m : f ){
            maxF = max(maxF , m.second ) ; 
        }
        return A.size() - maxF ; 
    }
};

int main() {
    init_code() ; 
    vector<int> A = {1,2,2,3,4} ; 
    Solution sol ; 
    int m = sol.minOperations(A) ; 
    cout << m << endl ; 
    return 0;
}

int main() {
    init_code() ; 
    Solution sol ; 

    
}