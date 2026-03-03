/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Here min_val should always preceed the curr_pos element , means 
should be always likely to be subtracted , as that makes the
difference positive 


Intuition: We will linearly travel the array. We can maintain a 
minimum from the starting of the array and compare it with every 
element of the array, if it is greater than the minimum then take 
the difference and maintain it in max, otherwise update the minimum.

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



#define INF 1000000007

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0 , N = prices.size() ; 
        int min_val = INF ; 
        for(int curr_pos=0 ; curr_pos<N ; curr_pos++ ){
            if(prices[curr_pos] > min_val )
            {
                // This makes the difference positive
                max_profit = max(max_profit , prices[curr_pos]-min_val);
            }else {
                // Resetting the minimum value to further minimum 
                min_val = prices[curr_pos] ; 
            }
        }
        return max_profit ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}