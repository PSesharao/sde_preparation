/*

https://leetcode.com/problems/find-common-characters/

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
    vector<string> commonChars(vector<string>& words) {
        vector<int> min_freq(26 , 101 ) ; // as word length <=100 

        for(auto word : words ){
            
            unordered_map<int , int > freq ; 

            for(char ch : word )
                freq[ch - 'a'] ++ ; 
            
            for(int i=0 ; i<26 ; i++ ){
                min_freq[i] = min(min_freq[i] , freq[i] ) ; 
            }
        }

        vector<string> result ; 

        for(int i=0 ; i<26 ; i++ ){
            if(min_freq[i] > 0 ){
                char ch = i + 'a' ; 
                for(int k=1 ; k<= min_freq[i] ; k++ )
                    result.push_back( string(1 , ch ) ) ;  // string of length 1 of chars
            }
        }
        return result ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}