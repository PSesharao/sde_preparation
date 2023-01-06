/*

https://leetcode.com/problems/next-permutation/

Let's take 1 3 5 4 2


1 3 2 4 5

1 3 2 5 4

1 3 4 2 5

1 3 4 5 2

1 3 5 2 4 

1 3 5 4 2

1 4 2 3 5

For any dictionary order , it will be always
increasing from the back (atleast 1 element should follow this pattern Ex in 1 2 3 ) 

-> First step would to find the breakpoint where this pattern breaks 

i.e bp = A[i]<A[i+1]

1 3 5 4 2

A[bp] = 3 (bp = 1 )

-> Second step we need to swap this breakpoint with element which is 
just greater than this in the other half 

A[sw] > A[bp] 

1 3 5 4 2
A[sw] = 4 (sw = 3 )

1 4 5 3 2

-> Third step would be to reverse the second half {5 3 2}
since the second half would be already in increasing order from back , to get the 
lower rank in next permutation , we should reverse it 

hence our final answer would be 

1 4 2 3 5 


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
    void nextPermutation(vector<int>& nums) {
        int N= nums.size() ; 
        int bp = -1 , sw =-1 ; 
        for(int i=N-2 ; i>=0 ; i-- )
            if(nums[i]<nums[i+1])
            {
                bp = i ; 
                break ;
            }

        if(bp == -1){
            reverse(nums.begin()+bp+1 , nums.end()) ; 
            return ; 
        }

        for(int i=N-1 ; i>=0 ; i-- )
            if(nums[i]> nums[bp]){
                sw = i ; 
                break ; 
            }
        swap(nums[bp] , nums[sw]);
        reverse(nums.begin()+bp+1 , nums.end()) ; 
    }
};


int main() {
    init_code() ; 
}