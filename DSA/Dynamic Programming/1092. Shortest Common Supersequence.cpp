/*

https://leetcode.com/problems/shortest-common-supersequence/

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

    string shortestCommonSupersequence( int len1 , 
    int len2,  string &text1, string &text2 , vector<vector<int>> &dp) {

        for(int ind2=len2 ; ind2 >=0  ; ind2-- )
            dp[len1][ind2] = 0 ; 

        for(int ind1=len1 ; ind1>=0 ; ind1-- )
            dp[ind1][len2] = 0 ; 

        for(int ind1=len1-1 ; ind1>=0 ; ind1-- )
            for(int ind2=len2-1 ; ind2 >=0  ; ind2-- ){
                int option1 =0 , option2 =0 ; 

                if ( text1[ind1] == text2[ind2] )
                      dp[ind1][ind2] = 1 + dp[ind1+1][ind2+1] ; 
                    
                else{
                    option1 = dp[ind1+1 ][ ind2 ] ; 
                    
                    option2 = dp[ind1 ][ind2+1] ; 
                   

                    dp[ind1][ind2] = max({option1 , option2 }) ;   
                }
               
            }

            string scs = "" ; 
            // dp[0][0] ---> will represent the length of lcs
            int ind1 = 0 , ind2=0 ; 

            while(ind1 < len1 and ind2 < len2 ){

                if( text1[ind1] == text2[ind2] ){

                    scs.push_back( text1[ind1]  ) ; 
                    ind1 ++ ; 
                    ind2 ++ ; 

                }else{

                    int option1 , option2 ;
                    option1 = dp[ind1+1][ind2 ] ; 
                    option2 = dp[ind1 ][ind2+1] ;    

                    if( option1 > option2 ){
                        scs.push_back( text1[ind1]  ) ; 
                        ind1 ++ ;
                    }
                    else {
                        scs.push_back( text2[ind2]  ) ; 
                        ind2 ++ ;          
                    }
                }

            }

            //Adding Remaing Characters - Only one of the below two while loops will run 
            while( ind1 < len1  ){
                scs.push_back( text1[ind1]  ) ; 
                ind1 ++ ;                
            }

            while( ind2 < len2  ){
                scs.push_back( text2[ind2]  ) ; 
                ind2 ++ ;                 
            }            

            return scs ; 
        
    }


    string shortestCommonSupersequence( string str1, string str2 ) {
        int len1 = str1.size() ; 
        int len2 = str2.size() ; 
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ;
        return shortestCommonSupersequence(len1 , len2 , str1 , str2 , dp ) ;         
    }
};



int main() {
    init_code() ; 
    Solution sol ; 
    string str1 = "abac" ; 
    string str2 = "cab" ; 
    cout << sol.shortestCommonSupersequence(  str1 , str2  ) ; 
    return 0 ; 
}