/*

https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

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
    int longestPalindrome(vector<string>& words) {

        int len = 0 ; 
        unordered_map<string , int > freq ;
        bool is_odd_appeared = false ; 

        for(auto str : words )
            freq[str] ++ ; 
        
        for(auto word : words ){

            if(word[0] != word[1] ){      //  distinct characters like "ab"

                string rev = "" ;
                rev+= word[1] ; 
                rev+= word[0] ;
                int f = freq[word] ; 
                int fr = freq[rev] ; 

                if( fr > 0  ) 
                    len += min({f , fr }) * 4 ; 

                
                freq.erase(word) ;
                freq.erase(rev) ; 


            }else{   // same characters "aa"

                int f = freq[word] ; 

                if( f%2 == 0 ){  // even
                    len += f*2 ; 
                }else{  // odd 

                    if(!is_odd_appeared){
                        len += f*2 ; 
                        is_odd_appeared = true ; 
                    }else{
                        len += (f-1)*2 ;
                    }
                }
            }
            freq.erase(word) ;
        }

        return len ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}