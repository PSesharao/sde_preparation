/*

https://leetcode.com/problems/distinct-subsequences/

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
class Solution1 {
public:
    int numDistinct( int ind1 , int ind2 , int len1 , int len2 , string str1 , string str2 ) {
        
        // This condition must be written first to take priority when both ind1 == len1 and ind2 == len2 true
        if( ind2 == len2 )
            return 1 ; 

        if(ind1 == len1  )
            return 0 ; 

        if(str1[ind1] == str2[ind2])
            return numDistinct(ind1 +1 , ind2+1 , len1 , len2 , str1 , str2 ) + 
            numDistinct(ind1 +1 , ind2 , len1 , len2 , str1 , str2 ) ;  

        else 
            return numDistinct(ind1 +1 , ind2 , len1 , len2 , str1 , str2 ) ;  


    }

    int numDistinct(string str1 , string str2 ) {
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 
        // vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;
        return numDistinct(0 , 0 , len1 , len2 , str1 , str2 ) ;         
    }
};


// Memeoization 
class Solution2 {
public:
    int numDistinct( int ind1 , int ind2 , int len1 , int len2 , 
        string str1 , string str2 , vector<vector<int>> &dp) {
        
        // This condition must be written first to 
        // take priority when both ind1 == len1 and ind2 == len2 true

        if(dp[ind1][ind2] != -1 )
            return dp[ind1][ind2]  ;

        if( ind2 == len2 )
            return dp[ind1][ind2]  = 1 ; 

        if(ind1 == len1  )
            return dp[ind1][ind2]  = 0 ; 

        if(str1[ind1] == str2[ind2])
            return dp[ind1][ind2]  = numDistinct(ind1 +1 , ind2+1 , len1 , len2 , str1 , str2 , dp  ) + 
            numDistinct(ind1 +1 , ind2 , len1 , len2 , str1 , str2 , dp ) ;  

        else 
            return dp[ind1][ind2]  = numDistinct(ind1 +1 , ind2 , len1 , len2 , str1 , str2 , dp ) ;  

    }

    int numDistinct(string str1 , string str2 ) {
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;
        return numDistinct(0 , 0 , len1 , len2 , str1 , str2 , dp ) ;         
    }

};

// Tabulation 
class Solution3 {
public:
    int numDistinct( int ind1 , int ind2 , int len1 , int len2 , 
        string str1 , string str2 , vector<vector<int>> &dp) {

        for(int ind2=len2 ; ind2 >=0  ; ind2-- )
            dp[len1][ind2]  = 0 ;         
        
        for(int ind1=len1 ; ind1>=0 ; ind1-- )
            dp[ind1][len2]  = 1 ; 


        // We need to make sure  dp[len1][len2] = 1 

        for(int ind1=len1-1 ; ind1>=0 ; ind1-- )
            for(int ind2=len2-1 ; ind2 >=0  ; ind2-- ){

                if(str1[ind1] == str2[ind2])
                     dp[ind1][ind2]  = ( 0LL +  dp[ind1+1][ind2+1] + dp[ind1+1][ind2] ) ; //numDistinct(ind1 +1 , ind2+1 , len1 , len2 , str1 , str2 , dp  ) + 
                    //numDistinct(ind1 +1 , ind2 , len1 , len2 , str1 , str2 , dp ) ;  

                else 
                     dp[ind1][ind2]  = dp[ind1+1][ind2] ;
                     // numDistinct(ind1 +1 , ind2 , len1 , len2 , str1 , str2 , dp ) ;  

        }

        return dp[0][0] ; 

    }

    int numDistinct(string str1 , string str2 ) {
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;
        return numDistinct(0 , 0 , len1 , len2 , str1 , str2 , dp ) ;         
    }

};

int main() {
    init_code() ; 
    Solution3 sol ; 
    string str1 = "rabbbit" ; 
    string str2 = "rabbit" ; 
    cout << sol.numDistinct(  str1 , str2  ) ; 
    return 0 ; 
}