/*

https://leetcode.com/problems/word-ladder/

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
    int ladderLength(string beginWord, string endWord, 
        vector<string>& wordList) {
        
        queue<pair<string , int >> Q ; 
        unordered_set<string> visited ; 

        for(auto str : wordList )
            visited.insert(str) ; 

        Q.push( { beginWord , 1 } ) ; 

        visited.erase(beginWord) ; // Marking the begin word as visited if it does
        // exist in the initial given list . 

        while(! Q.empty()){

            pair<string , int > curr = Q.front() ; 
            Q.pop() ; 

            string curr_word = curr.first ; 
            int steps = curr.second ; 

            if(curr_word == endWord )                      // if(curr_word.compare( endWord ) )
                return steps ; 

            for( int i=0 ; i<curr_word.size() ; i++ ){

                string transformed_word = curr_word ; 

                for(char ch='a' ; ch <='z' ; ch++){
                    transformed_word[i] = ch ; 

                    if(visited.count(transformed_word) > 0 ){
                        // This is a valid and unvisited transformation 
                        Q.push({transformed_word , steps+1 }) ; 
                        visited.erase(transformed_word) ; // marking as visited 

                    }
                }
            }

        }

        return 0 ; 


    }
};
