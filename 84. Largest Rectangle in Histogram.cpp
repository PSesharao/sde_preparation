/*

https://leetcode.com/problems/largest-rectangle-in-histogram/

Intuition: The intuition behind the approach is taking different bars 
and finding the maximum width possible using the bar.

Approach:

The approach is to find the right smaller and left smaller element and 
find the largest Rectangle area in Histogram.

why ? 

Input: N =7 , heights[] = {2,1,5,6,2,3 , 1 }

  0  1  2  3  4  5   6
[ 2, 1, 5, 6, 2, 3 , 1 ]


for 2 at index 4 , to find maximum area possible around it width wise 
we need to consider all the values that are >=2 , because that particular
block will help us covering the maximum area possible around 2

the block will be [5 , 6 , 2 , 3 ] and width is 4 so 4*2 = 8 area covered here 

Inother way find right smaller and left smaller element indices 

right smaller index = 6 (block end will be 6-1 = 5 )
left smaller index = 1 (block start will be 1+1 = 2 )

total width = 5 - 2 + 1 = 4 

Optimised Approach 1

Intuition: The intuition behind the approach is the same as finding the 
smaller element on both sides but in an optimized way using the concept 
of the next greater element and the next smaller element.

Time Complexity: O( 3N )

Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array

because for above we are using 3 passes 

Optimised Approach 2

This approach is a single pass approach instead of a two-pass approach. When we traverse 
the array for finding the previous smaller element , we found that some elements were inserted 
into the stack which signifies that after them the smallest element is themselves


here the idea is to take advantage of the building stack until condition is violated 
histo[st.top()] >= histo[i] 



4 7 8 5 


till 5 it would build the stack [4 7 8  ] and at 5  histo[st.top()] >= histo[i] is true

at this point we need to process each element in the stack one by one 

for 8 , 5 is right smaller and 7 is left smaller 

from here we would follow the similar approach to Optimised Approach 1 left smaller 

Time Complexity: O( N ) + O (N) 

Space Complexity: O(N)

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
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0 ; 
        int n = heights.size() ; 
        stack<int> stack ; 
        vector<int> left_smaller(n , 0 ) ; 
        vector<int> right_smaller(n , n-1 ) ; 
        // for filling left smaller array
        for(int i=0 ; i<n ; i++ )
        {
            while(!stack.empty() and heights[stack.top()] >= heights[i] )
                stack.pop() ; 

            if(stack.empty())
                left_smaller[i] = 0 ; 
                // left extream if there are no smaller elements than heights[i]
            else 
                left_smaller[i] = stack.top() + 1 ; 
                // the starting block 
            stack.push(i) ; 
        }

        // emptying the stack and to use it again for right smaller array 
        while(!stack.empty())
            stack.pop() ; 

        for( int i=n-1 ; i>=0 ; i-- ){
            while( !stack.empty() and heights[stack.top()] >= heights[i] )
                stack.pop() ; 

            if(stack.empty())
                right_smaller[i] = n-1 ; 
            // right extream if there are no smaller elements than heights[i]

            else 
                right_smaller[i] = stack.top() - 1 ; 
            // the end block 

            stack.push(i) ; 
        }

        for(int i=0 ; i<n ; i++)
            max_area = max(max_area , (right_smaller[i] - left_smaller[i] +1 )*heights[i] ) ;

        return max_area ; 
    }
};

// Optimised Approach 2 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0 ; 
        int n = heights.size() ; 
        stack<int> stack ; 

        for(int i=0 ; i<=n ; i++ ){
            while(!stack.empty() and ( i==n or heights[stack.top()] >= heights[i] ) ){

                // we need to process the building stack elements one by one 

                int curr_bar = heights[stack.top()] ;
                stack.pop() ; 

                
                int right_end_block_index = i-1 ; // since right_smaller_index = i for curr_bar 
                int left_end_block_index ; 

                if(stack.empty())
                    left_end_block_index = 0 ; 
                else 
                    left_end_block_index = stack.top() + 1 ; // the immediate before to current bar 

                // +1 becuase left_smaller_index = stack.top() 

                max_area = max(max_area , (right_end_block_index - left_end_block_index + 1)* curr_bar  ) ; 
            }

            stack.push(i) ; 
        }

        return max_area ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}