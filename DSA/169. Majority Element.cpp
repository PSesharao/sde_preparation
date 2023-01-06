/*

https://leetcode.com/problems/majority-element/


Moore’s Voting Algorithm

Intuition: The question clearly states that the nums array has a majority element. 
Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.

Now, we can say that count of minority elements and majority elements are 
equal up to a certain point of time in the array. So when we traverse through 
the array we try to keep track of the count of elements and which element we are 
tracking. Since the majority element appears more than N/2 times, we can say that 
at some point in array traversal we find the majority element. 



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
    int majorityElement(vector<int>& nums) {
        int N = nums.size() ; 
        int count =0 ; 
        int element ; 
        for(int i=0 ; i<N ; i++){
            if(count == 0 )
                element = nums[i] ; 
            if(nums[i] == element )
                count++ ; 
            else
                count-- ; 
        }
        return element ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}