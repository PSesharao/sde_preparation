/*

https://leetcode.com/problems/valid-parentheses/

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
    bool isValid(string x) {
        char currBrace , topOfStack ;
        stack<char> braceStack ;
        for(int i=0 ;i<x.size() ;i++){

            currBrace = x[i] ;
            if(currBrace == '(' or currBrace == '{' or currBrace == '[')
                braceStack.push(currBrace) ;
            else if(braceStack.empty())
                return false ;
            else {
                topOfStack = braceStack.top() ;
                braceStack.pop() ;
                if(topOfStack == '(' and currBrace !=')' || 

                topOfStack == '{' and currBrace !='}' || 

                topOfStack == '[' and currBrace !=']'
                ) return false ;

            }
        }
        
        return braceStack.empty() ;
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}