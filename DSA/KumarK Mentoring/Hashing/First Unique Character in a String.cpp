/*

https://leetcode.com/problems/first-unique-character-in-a-string/

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
    int firstUniqChar(string s) {
        unordered_map<char , int > map_freq ; 
        for(char ch : s )
            map_freq[ch] ++ ; 
        
        for(int i=0 ; i<s.size() ; i++ ) {
            char ch = s[i] ; 
            if(map_freq[ch] == 1 )
                return i ; 
        }
        return -1 ; 
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}