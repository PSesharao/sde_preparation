/*

https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

Once we have indexes of next and previous smaller, we know that arr[i] 
is a minimum of a window of length "right[i] - left[i] - 1". 

Some entries in ans[] are 0 and yet to be filled. 
Below are few important observations to fill remaining entries

Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1]. 
If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i] 

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


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector <int> result(n+1 , 0 ) ; 
        vector <int> left_smaller(n , -1) ; 
        vector <int> right_smaller(n , n) ; 
        stack<int> stack ; 

        for(int i=0 ; i<n ; i++){
            // for prev smaller logic 
            while(!stack.empty() and arr[stack.top()] >= arr[i] )
                stack.pop() ; 

            if(!stack.empty())
                left_smaller[i] = stack.top() ; 
            else 
                left_smaller[i] = -1 ; 

            stack.push(i) ; 
        }

         // emptying the stack 
        while (!stack.empty())
            stack.pop() ;

        for(int i=n-1 ; i>=0 ; i-- ){
            // for next smaller logic 
            while(!stack.empty() and arr[stack.top()] >= arr[i] )
                stack.pop() ; 

            if(!stack.empty())
                right_smaller[i] = stack.top() ; 
            else 
                right_smaller[i] = n  ; 

            stack.push(i) ;             
        }

        for(int i=0 ; i<n ; i++ ){
            int len = right_smaller[i] - left_smaller[i] -1 ; 
        // arr[i] is a possible answer for this length 
        // 'len' interval, there can be repeated values of 'len' , 
        // hence we need to take max of all of them 
            result[len] = max(result[len] , arr[i] ) ; 
        }

    // Some entries in result[] may not be filled yet. Fill 
     // them by taking values from right side of result[]
        for (int i=n-1; i>=1; i--)
            result[i] = max(result[i], result[i+1]);

        //Note that result[0] or answer for length 0 is useless.

        return vector<int> (result.begin()+1 , result.end() )   ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}