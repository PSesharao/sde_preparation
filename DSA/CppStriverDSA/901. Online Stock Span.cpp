/*

https://leetcode.com/problems/online-stock-span/
https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

If they had given the whole array at once we could solve using the approach 
of previous greater element , otherwise the monolothic building stack approach
(build the stack in the decreasing order at this time )

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


class StockSpanner {
public:
    stack<pair<int , int> > stack ; 
    StockSpanner() {
        
    }
    
    int next(int price) {
        // when there is no lesser value on the left 
        int cur_res = 1 ; 
        // the previous greater logic
        while(!stack.empty() and stack.top().first <= price )
        {
            // adding up the prev res values
            cur_res +=  stack.top().second ; 
            stack.pop() ; 
        }
        stack.push({price , cur_res }) ; 
        return cur_res ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}