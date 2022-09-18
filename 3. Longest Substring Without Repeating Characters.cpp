/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approach 1

We will have two pointers left and right. Pointer ‘left’ is used for maintaining 
the starting point of substring while ‘right’ will maintain the endpoint of the 
substring.’ right’ pointer will move forward and check for the duplicate occurrence 
of the current element if found then ‘left’ pointer will be shifted ahead so as to 
delete the duplicate elements.

Time Complexity: O( 2*N ) 
(sometimes left and right both have to travel complete array)

Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

Approach 2

Approach: In this approach, we will make a map that will take care of counting 
the elements and maintaining the frequency of each and every element as a unity 
by taking the latest index of every element.

Time Complexity: O( N )

Space Complexity: O(N) where N represents the size of 
HashSet where we are storing our elements

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


// Approach 1 
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size() ; 
        int len = 0 ; 
        int l=0 , r = 0 ;
        unordered_set<char> set ; 
        while( r<N ) {

            if(set.count(s[r]) == 0)
            {
                int curr_len = r-l+1 ; 
                len = max(len , curr_len ) ; 
                set.insert(s[r]) ; 
                r++ ; 
            }else{
                do {
                    set.erase(s[l]) ;
                    l++ ; 
                }while(set.count(s[r]) > 0) ; 
                int curr_len = r-l+1 ; 
                len = max(len , curr_len ) ; 
                set.insert(s[r]) ; 
                r++ ; 
            }
        }
        return len ; 
    }
};*/

// Approach 2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size() ; 
        int len = 0 ; 
        int l =0 , r = 0 ;
        unordered_map<char , int > lastSeenIndex ; 
        while( r<N ) {

            if(lastSeenIndex.count(s[r]) == 0)
            {
                int curr_len = r-l+1 ; 
                len = max(len , curr_len ) ; 
                lastSeenIndex.insert({s[r] , r} ); 
                r++ ; 
            }else{
                // we are directly bypassing to the range in between 
                // l and r with one hop 
                // also we are just updating l only if we see
                // lastSeenIndex[s[r]] is between l and r
                l = max(lastSeenIndex[s[r]]+1 , l ) ; 
                int curr_len = r-l+1 ; 
                len = max(len , curr_len ) ; 
                lastSeenIndex[s[r]] = r ; 
                r++ ; 
            }
        }
        return len ; 
    }
};

int main() {
    init_code() ; 

}