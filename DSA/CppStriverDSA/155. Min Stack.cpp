/*

https://leetcode.com/problems/min-stack/

Solution 1: Using pairs to store the value and minimum element till now. 

Approach: The first element in the pair will store the value and the 
second element will store the minimum element till now.

Time Complexity: O(1)

Space Complexity: O(2N)

Solution 2: 

Approach: 

Let’s take a variable that stores the minimum number. So whenever a push 
operation comes in just take that number put it in the stack and update the 
variable to the number.

Push operation:
------------------
Now if there is a push operation just check whether that number is less than the 
min number. If it is smaller than min we will push a modified value which is a 
push(2 * Val – min) into the stack and will update min to the value of the original 
number. If it’s not then we will just push it as it is.

here this modified value is always less than the value 

val < min 

val - min < 0 

val+val - min < val 

2*val - min < val 

modified_value < val 

getMin() operation:
------------
We will just return the value of min.

Top operation:
----------------
While returning the top value we know that it there may be a modified value. We will check 
if the top value is lesser than min, If it is then we will return the min as the top value.

Pop operation:
-----------------

While making pop we will check if the top value is lesser than min, 
If it is then we must update our min to its previous value. In order to do 
that min = (2 * min) – (modified value) and we will pop the element.

2 * min - (2*val - prev_min )  

val is nothing but the current min why ? 

let's take 

6 7 5 ,

while pushing 6 stack is empty , so push and make min = 6 

[6]

while pushing 7 stack 7 > min=6 , hence just push 

[ 6 7 ]

while pushing 5 , 5 < min = 6 

push 2xval - min i.e 2x5 - 6 = 4 

[6 7 4 ]
and now set min = 5 

to retrieve top here 

check top = 4 < min = 5

hence return 5 , as it is the original val that should be in place  

top do pop here , check top = 4 < min = 5 

hence we need to set min=5 back it's immediate prev min = 6 

so 2*min - top 

2*min - (2*val - prev_min ) 
2*5 - (2*5 - prev_min ) = prev_min

2*5 - 4 = 10-4 = 6 = prev_min

val was 5 as per the above flow 


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

class MinStack {
public:
    // because they've mentioned -2^31 <= val <= 2^31 - 1
    long long min_element ;
    stack<long long > stack ;
    MinStack() {
        min_element = INT_MAX ; 
    }
    
    void push(int val) {
        
        if(stack.empty())
        {
            min_element = val ; 
            stack.push(val) ; 
        }else {
            if(val < min_element ){
                // to have long long as buffer intermediate 
                stack.push(1LL*2*val - min_element ) ;
                min_element = val ; 
            }else{
                stack.push(val) ; 
            }
        }

    }
    
    void pop() {
        if(stack.empty())
            return ; 

        long long top = stack.top() ; 
        stack.pop() ; 
        if(top < min_element ){
            // means top is modified value 
            min_element = 1LL*2*min_element - top ; 
        }
    }
    
    int top() {
        if(stack.empty())
            return -1; 
        long long top = stack.top() ;  
        if(top < min_element ){
            // means top is modified value 
            return min_element ; 
        }
        return top ; 

    }
    
    int getMin() {
        return min_element ; 
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
    init_code() ; 
    Solution sol ; 

    
}