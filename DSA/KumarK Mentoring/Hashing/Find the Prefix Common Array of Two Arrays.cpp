/*

https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size() ; 
        vector<int> C(n) ; 
        int count = 0 ; 
        unordered_set<int> common_set ; 
        for(int i=0; i<n ; i++ ){

            if(A[i] == B[i])
                count ++ ;
            else {
                if(common_set.count(A[i]) > 0 )
                    count ++ ; 
                if(common_set.count(B[i]) >0 )
                    count ++ ; 
            }

          common_set.insert(A[i]) ;
          common_set.insert(B[i]) ;   
          C[i] = count ; 
        }

        return C ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}