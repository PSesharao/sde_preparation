/*

https://leetcode.com/problems/longest-palindromic-subsequence/

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




// Appraoch 1
int LPS(string S, int left, int right){
        if (left > right) {
            return 0;
        } 
        if(left == right){
            return 1;
        }   
        if (S[left] == S[right])
        {
            return 2 + LPS(S,left+1,right-1);
        }
  
  
     return max(LPS(S, left, right - 1), LPS(S, left + 1, right));
}





class Solution3 {
public:


    int longestCommonSubsequence( int len1 , 
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

        return dp[0][0] ; 
    }    

    int longestPalindromeSubseq(string text1 ) {
        string text2 = text1 ; 
        reverse(text2.begin(),text2.end());
        int len1 = text1.size() , len2 = text2.size() ;
        vector<vector<int>> dp(len1+1 , vector<int>(len2+1 , -1 ) ) ; 
        return longestCommonSubsequence(len1 , len2 , text1 , text2 , dp ) ; 
    }
};

int main() {
    init_code() ; 
    Solution3 sol ; 
    string text1 = "bbabcbcab" ; 
    
    cout << sol.longestPalindromeSubseq(  text1 ) ; 
    return 0 ; 
}