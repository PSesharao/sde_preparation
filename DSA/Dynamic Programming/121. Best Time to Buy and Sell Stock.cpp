/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 

        int maxPro = 0 ; 
        int minBuyPrice = INF ; 

        for(int i=0 ; i<n ; i++ ){
            int curDaySellPrice = prices[i] ; 

            if( curDaySellPrice > minBuyPrice ) // we will be able to sell on current day
                maxPro = max(maxPro , curDaySellPrice- minBuyPrice ) ; 
            else
                minBuyPrice = curDaySellPrice ; // as the selling price on current day less than 
            // minBuyPrice already , we are updating minBuyPrice with curDaySellPrice

        }
        return maxPro ;  
    }
};