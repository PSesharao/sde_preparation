/*

https://leetcode.com/problems/implement-queue-using-stacks/

In the below approach the pop() or peek() can be O(1) or O(n)

O(1) - > when all elements are shifted to copy , we just need to delete the 
last element

O(n) - > when copy is empty need to shift all to copy 

Hence the time complexity would be amortized O(1)

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


class MyQueue {
    stack<int> stk ;
    stack<int> copy  ;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x) ; 
    }
    
    int pop() {
        if(stk.empty() and copy.empty())
            return -1 ; 

        int top ; 
        if(copy.empty()){
            while(!stk.empty()){
                copy.push(stk.top()) ; 
                stk.pop() ; 
            }
        }

        top = copy.top() ; 
        copy.pop() ; 
        return top ; 
    }
    
    int peek() {
        if(stk.empty() and copy.empty())
            return -1 ; 

        int top ; 
        if(copy.empty()){
            while(!stk.empty()){
                copy.push(stk.top()) ; 
                stk.pop() ; 
            }
        }

        top = copy.top() ; 
        return top ; 
    }
    
    bool empty() {
        return stk.empty() and copy.empty() ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}