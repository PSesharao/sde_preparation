/*

https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

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

void sortedInsert(stack<int> & stack , int element) {

    // If the element to be inserted is already greater than the 
    // sorted top of the stack , then just push it into it 
    if(stack.empty() || element >= stack.top() ){
        stack.push(element ) ;
        return ;  
    }

    // otherwise remove the current top element
    int current_top_element = stack.top() ; 
    stack.pop() ; 
    // now try to insert element one step below top after removing current top 
    sortedInsert(stack , element) ;

    // finally push current top to the top of stack 
    stack.push(current_top_element) ; 
}

void sortStack(stack<int> &stack)
{
    if(stack.empty()) 
        return ;
    // first remove the top element 
    int top_element = stack.top() ; 
    stack.pop() ; 
    // sort the remaining stack 
    sortStack(stack) ; 

    // insert the top element into this sorted stack 

    sortedInsert(stack , top_element ) ; 
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}