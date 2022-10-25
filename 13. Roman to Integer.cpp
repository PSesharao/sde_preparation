/*

https://leetcode.com/problems/roman-to-integer/
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written 
as IV. 

Intuition : Using the above property we'll first check if the current roman literal 
is less than the next roman literal , if so we'll subtract , otherwise we'll 
add . 

Time Complexity : O(n)

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
private : 

void mapRomanLiterals(unordered_map<char , int > &M ) {
    M['I']=1;
    M['V']=5;
    M['X']=10;
    M['L']=50;
    M['C']=100;
    M['D']=500;
    M['M']=1000;
}

public:
    int romanToInt(string s) {
        unordered_map<char , int > map ;  
        mapRomanLiterals(map ) ; 
        int len = s.length() ; 
        int result = 0 ; 
        for(int i=0 ; i<len ; i++ ){
            if( (i+1 < len) and (map[s[i]] < map[s[i+1]] ))
                result -= map[s[i]] ; 
            else 
                result += map[s[i]] ; 
        }
        return result ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}