/*

https://leetcode.com/problems/longest-common-prefix/

Time Complexity : O( len_of_short_word x no_of_words )

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
    string longestCommonPrefix(vector<string>& strs) {
        string short_word = strs[0] ; 
        int len_of_short = short_word.size() ; 
        int no_of_words = strs.size() ; 
        for(int i= 1 ; i<no_of_words ; i++ ){
            if(strs[i].size() < len_of_short ){
                len_of_short = strs[i].size() ; 
                short_word = strs[i] ;  
            }
        }

        for(int i=0 ; i<len_of_short ; i++ ){
            int j ;
            for(j =1 ; j<no_of_words ; j++ ){
                if(short_word[i] != strs[j][i] )
                    break ; 
            }
            if( j < no_of_words )
                return short_word.substr(0 , i ) ; 
        }

        return short_word ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}