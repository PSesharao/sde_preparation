/*

https://leetcode.com/problems/longest-palindromic-substring/

Approach 1 : Naive 
finding all the substrings using nested for loop , then cheking whether it is a
palindrome . 

Time Complexity : O(n^3) 

Approach2 : Expand Around Center 

Time Complexity : O(n^2) 

Approach3 : Manacher's Algorithm  

Need to explore 

Time Complexity : O(n) 

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
    string longestPalindrome(string str) {
        
        int max_palin_len = -1 ; 
        int begin_index = -1 ; 
        int len = str.length() ; 
        int curr_palin_len , left , right ; 
        for(int curr= 0 ; curr<len ; curr++ ){

            // checking for odd length palindromes 
            left = curr ;
            right = curr ;

            while((left >= 0 && right < len ) && str[left] == str[right]){
                left--;
                right++;
            }

            curr_palin_len = right - left -1 ; 
            if(curr_palin_len > max_palin_len ){
                max_palin_len = curr_palin_len ; 
                begin_index = left +1 ; 
            }

            // checking for even length palindromes 
            left = curr ; 
            right = curr +1 ; 

            while((left >= 0 && right < len ) && str[left] == str[right]){
                left--;
                right++;
            }

            curr_palin_len = right - left -1 ;

            if(curr_palin_len > max_palin_len ){
                max_palin_len = curr_palin_len ; 
                begin_index = left +1 ; 
            }

        }
        return str.substr(begin_index , max_palin_len ) ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}