/*

https://leetcode.com/problems/wildcard-matching/

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

    bool isAllStar(int ind , string str , int len1 ){
        for(int i=ind ; i< len1 ; i++ )
            if(str[i] != '*' )
                return false ; 
            return true ; 
    }

    bool isMatch( int ind1 , int ind2  , int len1 , int len2 , 
     string str1, string str2 ) {
        
        if(ind1 == len1 )  {

            if(ind2 == len2 )
                return true ; 

            else
                return false ; 

        }

        if( ind2 == len2 )
            return isAllStar(ind1 , str1 , len1 ) ; 

        
        if( str1[ind1] == str2[ind2 ] )
            return isMatch(ind1+1 , ind2+1 , len1 , len2 , str1 , str2 ) ; 
        else{

            if(str1[ind1] == '?' )
                return isMatch(ind1+1 , ind2+1 , len1 , len2 , str1 , str2 ) ; 

            else if(str1[ind1] == '*'){

                bool skip = isMatch(ind1+1 , ind2 , len1 , len2 , str1 , str2 ) ; 
                bool match = isMatch(ind1 , ind2+1 , len1 , len2 , str1 , str2 ) ; 

                return (skip or match ) ; 

            }else 
                return false ; 
        }

    }

    bool isMatch(string str1, string str2) {
 
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 

        return isMatch( 0 , 0 , len1 , len2 , str1 , str2 ) ; 

    }
};


// Memoization 

class Solution2 {
public:

    bool isAllStar(int ind , string str , int len1 ){
        for(int i=ind ; i< len1 ; i++ )
            if(str[i] != '*' )
                return false ; 
            return true ; 
    }

    bool isMatch( int ind1 , int ind2  , int len1 , int len2 , 
     string str1, string str2 , vector<vector<int>> &dp) {
        
        if(dp[ind1][ind2] != -1 )
            return dp[ind1][ind2]  ;

        if(ind1 == len1 )  {

            if(ind2 == len2 )
                return dp[ind1][ind2] = true ; 

            else
                return dp[ind1][ind2] = false ; 

        }

        if( ind2 == len2 )
            return dp[ind1][ind2] = isAllStar(ind1 , str1 , len1 ) ; 

        
        if( str1[ind1] == str2[ind2 ] )
            return dp[ind1][ind2] = isMatch(ind1+1 , ind2+1 , len1 , len2 , str1 , str2 , dp  ) ; 
        else{

            if(str1[ind1] == '?' )
                return dp[ind1][ind2] = isMatch(ind1+1 , ind2+1 , len1 , len2 , str1 , str2 , dp ) ; 

            else if(str1[ind1] == '*'){

                bool skip = isMatch(ind1+1 , ind2 , len1 , len2 , str1 , str2 , dp ) ; 
                bool match = isMatch(ind1 , ind2+1 , len1 , len2 , str1 , str2 , dp ) ; 

                return dp[ind1][ind2] = (skip or match ) ; 

            }else 
                return dp[ind1][ind2] = false ; 
        }

    }

    bool isMatch(string str1, string str2) {
 
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;
        return isMatch( 0 , 0 , len1 , len2 , str1 , str2 , dp  ) ; 

    }
};



// Tabulation 
class Solution3 {
public:

    bool isAllStar(int ind , string str , int len1 ){
        for(int i=ind ; i< len1 ; i++ )
            if(str[i] != '*' )
                return false ; 
            return true ; 
    }

    bool isMatch(  int len1 , int len2 , 
     string str1, string str2 , vector<vector<int>> &dp) {
        

        for(int ind2=len2 ; ind2 >=0  ; ind2-- ){
            if(ind2 == len2 )
                 dp[len1][ind2] = true ; 

            else
                 dp[len1][ind2] = false ;             
        }


        for(int ind1=len1-1 ; ind1>=0 ; ind1-- ) // ind1 == len1 taken care in above case
            dp[ind1][len2] = isAllStar(ind1 , str1 , len1 ) ; 



        for(int ind1=len1-1 ; ind1>=0 ; ind1-- )
            for(int ind2=len2-1 ; ind2 >=0  ; ind2-- ){

                if( str1[ind1] == str2[ind2 ] )
                     dp[ind1][ind2] = dp[ind1+1 ][ ind2+1 ] ; 

                     // isMatch(ind1+1 , ind2+1 , len1 , len2 , str1 , str2 , dp  ) ; 
                else{

                    if(str1[ind1] == '?' )
                         dp[ind1][ind2] = dp[ind1+1 ][ ind2+1 ] ; 
                        // isMatch(ind1+1 , ind2+1 , len1 , len2 , str1 , str2 , dp ) ; 

                    else if(str1[ind1] == '*'){

                        bool skip = dp[ind1+1 ][ ind2 ] ; 
                        //isMatch(ind1+1 , ind2 , len1 , len2 , str1 , str2 , dp ) ; 
                        bool match =  dp[ind1 ][ ind2+1 ] ; 

                        // isMatch(ind1 , ind2+1 , len1 , len2 , str1 , str2 , dp ) ; 

                        dp[ind1][ind2] = (skip or match ) ; 

                    }else 
                        dp[ind1][ind2] = false ; 
                }                
            }
        

        return dp[0][0] ; 

    }

    bool isMatch(string str1, string str2) {
        
        swap(str1 , str2 ) ; // As the algorithm is written in reverse
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;
        return isMatch( len1 , len2 , str1 , str2 , dp  ) ; 

    }
};



int main() {
    init_code() ; 
    Solution3 sol ; 
    string str1 = "ab*cd" ; 
    string str2 = "abdfkhgcd" ; 
    cout << sol.isMatch(  str1 , str2  ) ; 
    return 0 ; 
}