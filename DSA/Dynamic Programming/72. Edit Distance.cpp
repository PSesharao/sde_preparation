/*

https://leetcode.com/problems/edit-distance/

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

class Solution {
public:

    int minDistance( int ind1 , int ind2 , int len1 , 
        int len2 , string word1, string word2 ) {
        
        if(ind1 == len1 )
            return (len2 - ind2 ) ; 

        if(ind2 == len2 )
            return (len1 - ind1 ) ; 

        if( word1[ind1] == word2[ind2] )
            return minDistance(ind1 +1 , ind2+1 , len1 , len2 , word1 , word2 ) ;

        else{

            int insertions = 1 + minDistance(ind1 , ind2+1 , len1 , len2 , word1 , word2 ) ;

            int deletions =  1 + minDistance(ind1+1 , ind2 , len1 , len2 , word1 , word2 ) ;
            
            int updations =  1 + minDistance(ind1 +1 , ind2+1 , len1 , len2 , word1 , word2 ) ;

            return min({insertions , deletions , updations }) ; 

        } 
    }

    int minDistance( string word1, string word2 ) {

        int len1 = word1.size() ; 
        int len2 = word2.size() ; 
        return minDistance(0 ,0 , len1 , len2 , word1 , word2 ) ; 

    }
};

// Memoization 

class Solution2 {
public:

    int minDistance( int ind1 , int ind2 , int len1 , 
        int len2 , string word1, string word2 , vector<vector<int>> &dp ) {

        if(dp[ind1][ind2] != -1 )
            return dp[ind1][ind2] ; 
        
        if(ind1 == len1 )
            return dp[ind1][ind2] = (len2 - ind2 ) ; 

        if(ind2 == len2 )
            return dp[ind1][ind2] = (len1 - ind1 ) ; 

        if( word1[ind1] == word2[ind2] )
            return dp[ind1][ind2] = minDistance(ind1 +1 , ind2+1 , len1 , len2 , word1 , word2 , dp  ) ;

        else{

            int insertions = 1 + minDistance(ind1 , ind2+1 , len1 , len2 , word1 , word2 , dp ) ;

            int deletions =  1 + minDistance(ind1+1 , ind2 , len1 , len2 , word1 , word2 , dp ) ;
            
            int updations =  1 + minDistance(ind1 +1 , ind2+1 , len1 , len2 , word1 , word2 , dp ) ;

            return dp[ind1][ind2] = min({insertions , deletions , updations }) ; 

        } 
    }

    int minDistance( string word1, string word2 ) {

        int len1 = word1.size() ; 
        int len2 = word2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;        
        return minDistance(0 ,0 , len1 , len2 , word1 , word2 , dp  ) ; 

    }
};


// Tabulation 
class Solution3 {
public:

    int minDistance( int len1 , 
        int len2 , string word1, string word2 , vector<vector<int>> &dp ) {

        for(int ind2=len2 ; ind2 >=0  ; ind2-- )  
              dp[len1][ind2] = (len2 - ind2 ) ; 

        for(int ind1=len1 ; ind1>=0 ; ind1-- )
              dp[ind1][len2] = (len1 - ind1 ) ; 

        for(int ind1=len1-1 ; ind1>=0 ; ind1-- )
            for(int ind2=len2-1 ; ind2 >=0  ; ind2-- ){

                if( word1[ind1] == word2[ind2] )
                     dp[ind1][ind2] =  dp[ind1 +1][ind2+1 ] ; 

                     //  minDistance(ind1 +1 , ind2+1 , len1 , len2 , word1 , word2 , dp  ) ;

                else{

                    int insertions = 1 +  dp[ind1 ][ind2+1 ] ; 

                    // minDistance(ind1 , ind2+1 , len1 , len2 , word1 , word2 , dp ) ;

                    int deletions =  1 + dp[ind1+1 ][ind2 ] ; 
                    // minDistance(ind1+1 , ind2 , len1 , len2 , word1 , word2 , dp ) ;
                    
                    int updations =  1 + dp[ind1 +1][ind2+1 ] ; 

                    // minDistance(ind1 +1 , ind2+1 , len1 , len2 , word1 , word2 , dp ) ;

                    dp[ind1][ind2] = min( { insertions , deletions , updations } ) ; 
                }

        }

        return dp[0][0] ; 

    }

    int minDistance( string word1, string word2 ) {

        int len1 = word1.size() ; 
        int len2 = word2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;        
        return minDistance( len1 , len2 , word1 , word2 , dp  ) ; 

    }
};


int main() {
    init_code() ; 
    Solution3 sol ; 
    string str1 = "horse" ; 
    string str2 = "ros" ; 
    cout << sol.minDistance(  str1 , str2  ) ; 
    return 0 ; 
}