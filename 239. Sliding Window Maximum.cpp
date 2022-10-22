/*

https://leetcode.com/problems/sliding-window-maximum/

deque -> It is doubly linked list functionally 
It will support these 4 operations 

push_back() , pop_back() , push_front() , pop_front() 

front()  , back() 

We are following the similar approach to the nge , here we'll try to 
implement previous greater element pattern and maintain the deque with 
increasing order , and keeps removing elements from front if we cross 
the out of boundary k 


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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans ; 
        deque<int> dq ; // we would store the indices here 

        for(int i=0 ; i< nums.size() ; i++ ) {

            // removing out of bound index from dq , 
            // our range should be always i-k+1 to i inclusive 
            if(!dq.empty() and dq.front() == i-k )
                dq.pop_front() ; 

            // previous greater element logic
            while( !dq.empty()  and nums[dq.back()] <= nums[i] )
                dq.pop_back() ; 

            dq.push_back(i) ; 


            if(i >= k-1 )
                ans.push_back(nums[dq.front()]) ; 
        }
        return ans ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}