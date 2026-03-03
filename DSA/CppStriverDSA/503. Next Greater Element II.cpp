/*

https://leetcode.com/problems/next-greater-element-ii/description/

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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> result(n , -1 ) ; 
        stack<int> stk ; 
        // 2*n-1 for the case of checking circular array 
        for(int i = 2*n-1 ; i>=0 ; i-- ){
            while( !stk.empty() and stk.top() <= nums[i%n] )
                stk.pop() ; 

            if(i < n )
                if(!stk.empty())
                    result[i] = stk.top() ; 
                else 
                    result[i] = -1 ; 
            stk.push(nums[i%n]) ;  
        }

        
        return result ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}