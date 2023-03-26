/*

https://leetcode.com/problems/partition-equal-subset-sum/

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

// Tabulation
class Solution3{   
public:

    bool canPartition( int n , vector<int> &arr , int S 
        ,  vector<vector<int>> &dp  ){


        for(int ind = 0 ; ind<=n ; ind++  )
            dp[ind][0] =  true ; 


        for(int sum =0 ; sum <= S ; sum++ )
            dp[n][sum] = false ; 

        dp[n][0] = true ; 

        for(int ind = n-1 ; ind>=0 ; ind--  )
            for(int sum =1 ; sum <= S ; sum++ )
            {
                bool pick = false ; 
                // take 
                
                if( sum - arr[ind] >=0  )
                    pick = dp[ind+1][sum - arr[ind]] ; // isSubsetSum( ind+1 , n , arr , sum - arr[ind] , dp  ) ; 

                // not take 
                bool notpick = dp[ind+1][sum] ; // isSubsetSum( ind+1 , n , arr , sum , dp  ) ; 
                dp[ind][sum] = (pick or notpick) ;                 
            }
        return dp[0][S] ; 
        
    }
    

    bool canPartition(vector<int>arr){
        int s = 0 ; 
        int n = arr.size() ; 
        for(int i=0 ; i<n ; i++ )
            s += arr[i] ; 
        if(s %2 == 1 )
            return false ; 
        int sum = s/2 ; 
        vector<vector<int>> dp( n+1 , vector<int>( sum+1 , 0 ) ) ; 
        return canPartition(  n , arr , sum , dp ) ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}