/*

https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Time Complexity : O(len1 X len2 ) at the worst case 

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
    int strStr(string haystack, string needle) {
        
        //bool occured = false ; 
        int len1 = haystack.size() ; 
        int len2 = needle.size() ; 

        for(int i=0 ; i<=len1-len2 ; i++ ){
            if( needle[0] == haystack[i] ){
                int j ; 
                for(j =0 ; j<len2 ; j++ )
                    if( haystack[i+j] != needle[j] )
                        break ; 
                //occured = true ; 
                if( j == len2 ) 
                    return i ; 
            }
        }

        return -1 ; 

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}