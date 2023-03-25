/*

https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

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

// Recursion 
class Solution1{  

public:

    bool isSubsetSum( int ind , int n , vector<int> &arr , int sum){

        if(sum == 0 )
            return true ; 

        if( ind == n ){
            if( sum == 0 )
                return true ; 
            return false ; 
        }

        bool pick = false ; 
        // take 

        if( sum - arr[ind] >=0  )
            pick = isSubsetSum( ind+1 , n , arr , sum - arr[ind] ) ; 

        // not take 
        bool notpick = isSubsetSum( ind+1 , n , arr , sum  ) ; 

        return (pick or notpick) ; 
    }
    

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size() ; 
        return isSubsetSum(0 , n , arr , sum ) ; 
    }
};

// Memoization 
class Solution2{   
public:

    bool isSubsetSum( int ind , int n , vector<int> &arr , int sum
        ,  vector<vector<int>> &dp  ){

        if( dp[ind][sum] != -1  )
            return dp[ind][sum] ;  

        if(sum == 0 )
            return dp[ind][sum] = true ; 

        if( ind == n ){
            if( sum == 0 )
                return dp[ind][sum] = true ; 
            return dp[ind][sum] = false ; 
        }

        bool pick = false ; 
        // take 
        
        if( sum - arr[ind] >=0  )
            pick = isSubsetSum( ind+1 , n , arr , sum - arr[ind] , dp  ) ; 

        // not take 
        bool notpick = isSubsetSum( ind+1 , n , arr , sum , dp  ) ; 

        return dp[ind][sum] = (pick or notpick) ; 
    }
    

    bool isSubsetSum(vector<int>arr, int sum){

        int n = arr.size() ; 
        vector<vector<int>> dp( n+1 , vector<int>( sum+1 , -1 ) ) ; 
        return isSubsetSum( 0 , n , arr , sum , dp ) ; 
    }
};


// Tabulation
class Solution3{   
public:

    bool isSubsetSum( int n , vector<int> &arr , int S 
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
    

    bool isSubsetSum(vector<int>arr, int sum){

        int n = arr.size() ; 
        vector<vector<int>> dp( n+1 , vector<int>( sum+1 , 0 ) ) ; 
        return isSubsetSum(  n , arr , sum , dp ) ; 
    }
};




int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<int> arr = {3, 34, 4, 12, 5, 2} ; 
    cout << sol.isSubsetSum( arr , 9 ) ; 
    return 0 ; 
}