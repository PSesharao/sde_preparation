/*

https://leetcode.com/problems/house-robber-ii/

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


class Solution3 {

private : 

    int findMaxSum(  vector<int> &arr, int n ) {

        vector<int> dp(n , 0 ) ; 
 
        dp[ n-1 ] = arr[n-1] ;

        for(int curr_idx = n-2 ; curr_idx >=0 ; curr_idx-- ){

                int pick_cur = arr[curr_idx] ; 
                int skip_cur = 0 ; 

                if( curr_idx +2 < n )
                    pick_cur += dp[curr_idx+2] ;  // findMaxSum2(curr_idx+2 , arr , n ,dp  ) ;

                if(curr_idx+1 < n )
                    skip_cur += dp[curr_idx+1] ; // findMaxSum2(curr_idx +1 , arr , n , dp   )  ; 

                dp[curr_idx] =  max(pick_cur , skip_cur ) ; 
        }

        return dp[0] ; 
    }


public:
    int rob(vector<int>& arr) {
        int n = arr.size()  ; 
        if(n == 0 )
            return 0 ; 
        if(n == 1 ) 
            return arr[0] ; 
        vector<int> arr1 ; 
        vector<int> arr2 ; 

        // for(int i=0 ; i<n ; i++ ){
        //     if(i == 0 ){
        //         arr1.push_back(nums[i]) ;
        //         continue ;  
        //     } if(i == n-1 ){
        //         arr2.push_back(nums[i]) ;
        //         continue ;  
        //     }
        //         arr1.push_back(nums[i]) ;
        //         arr2.push_back(nums[i]) ;
            
        // }

        for(int i=0; i<n; i++){
            
            if(i!=0) arr1.push_back(arr[i]);
            if(i!=n-1) arr2.push_back(arr[i]);
        }

        int ans1 = findMaxSum(arr1 , n-1  ) ; 
        int ans2 = findMaxSum(arr2 , n-1  ) ; 
        return max(ans1 , ans2 ) ; 
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}