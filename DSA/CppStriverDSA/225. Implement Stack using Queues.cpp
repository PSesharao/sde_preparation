/*

https://leetcode.com/problems/implement-stack-using-queues/

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

// using two stacks 
// Time Complexity: O(N)
class MyStack {

        queue<int> q;
        queue<int> copy ;
public:

    MyStack() {

    }
    
    void push(int x) {
        while(!q.empty()){
            copy.push(q.front()) ; 
            q.pop() ; 
        }

        q.push(x) ; 

        while(!copy.empty()){
            q.push(copy.front()) ;
            copy.pop() ;  
        }

    }
    
    int pop() {
        if(q.empty()) 
            return -1 ;
        int f = q.front() ; 
        q.pop() ; 
        return f ; 
    }
    
    int top() {
        if(q.empty()) 
            return -1 ;
        return q.front() ; 
    }
    
    bool empty() {
        return q.empty() ; 
    }
};

// using 1 queue 
//Use a for loop of size()-1, remove element from queue and again push back to the 
//queue, hence the most recent element becomes the most former element and vice versa.

class MyStack {
    queue<int> q; 
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) 
            return -1 ;
        int f = q.front() ; 
        q.pop() ; 
        return f ; 
    }
    
    int top() {
        if(q.empty()) 
            return -1 ;
        return q.front() ; 
    }
    
    bool empty() {
        return q.empty() ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}