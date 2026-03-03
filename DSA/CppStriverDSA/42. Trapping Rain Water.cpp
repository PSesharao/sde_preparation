/*

https://leetcode.com/problems/trapping-rain-water/

If we observe carefully the amount the water stored at a particular index 
is the minimum of maximum elevation to the left and right of the index minus 
the elevation at that index.

Intuition: We need a minimum of leftMax and rightMax.So if we take the 
case when height[l]<=height[r] we increase l++, so we can surely say that 
there is a block with a height more than height[l] to the right of l. 
And for the same reason when height[r]<=height[l] we can surely say that 
there is a block to the left of r which is at least of height[r]. 
So by traversing these cases and using two pointers approach the time complexity 
can be decreased without using extra space.


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
    int trap(vector<int>& height) {
    // two pointer appraoch based on the extreme boundaries
    // does not care about in between values
        int left = 0 , right = height.size()-1 ;
        int max_left_height = 0 , max_right_height = 0 ; 
        ll water_trapped = 0 ; 
        while(left <= right ){
            // first check which end is shorter 
            // becz , shorter end only can store / trap the water 

            if(height[left] < height[right] ) {
            // this means left end is shorter 

            // now let's check if it's shorter than Max left boundary so far 

                // if shorter it can trap that difference
                // means against that boundary , take that difference 

                if(height[left] < max_left_height )
                    water_trapped+= max_left_height- height[left] ; 
                 // else make that at taller left
                else
                    max_left_height = height[left] ; 
                left ++ ; 
            }else{

                if(height[right] < max_right_height )
                    water_trapped += max_right_height- height[right] ; 
                else
                    max_right_height = height[right] ; 
                right-- ; 
            }
        }

        return water_trapped ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}