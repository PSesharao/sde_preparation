/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approach 1

We will have two pointers left and right. Pointer ‘left’ is used for maintaining 
the starting point of substring while ‘right’ will maintain the endpoint of the 
substring.’ right’ pointer will move forward and check for the duplicate occurrence 
of the current element if found then ‘left’ pointer will be shifted ahead so as to 
delete that duplicate element.

Time Complexity: O( 2*N ) 
(sometimes left and right both have to travel complete array)

Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

Approach 2

Approach: This is a slight betterment of above approach , we are directly bypassing to the range in between left and right with one hop/jump  also we are updating left only if we see the duplicate between left and right window

Let us take 

0 1 2 3 4 5 6 7
a b c a a b c d

By the time 'right' reaches index 3 , we realize that it is a duplicate(a) as it is found at index 0 already, hence we move our 'left' pointer to go pass that i.e left = 1 , 

lastSeenIndex[a] = 3

now when 'right' reaches index 4 , we found 'a' again there now we need to move past it is lastSeenIndex 

so , left = 4 

lastSeenIndex[a] = 4

now when 'right' reaches index 5 , we found 'b' whose lastSeenIndex was 1 , but we should not take our left again back to 2 which is it's next index , as we can see 2 is not in range of [left , right ] = [4 , 5]

therefore we should leave 'left' as it is.

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


// brute force 
/*
This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding different substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string str) {
          if(str.size()==0)
              return 0;
          int maxans = INT_MIN;
          for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
          {
            unordered_set < int > set;
            for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
            {

              if ( set.count(str[j]) > 0 ) // if element is found so mark it as ans and break from the loop
              { 
                maxans = max(maxans, j - i); // j - i represents the  length
                break;
              }
              set.insert(str[j]);
            }
          }
          return maxans;
    }
};

// Approach 1 
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size() == 0)
            return 0 ; 
        int max_len = 1 ;
        int left = 0 , right = 0 ; 
        int N = str.size() ; 
        unordered_set<char> set ; 
        while(right <N ){
            if(set.count(str[right])>0  ){ // means str[right] is a duplicate

                while((left < right) and (set.count(str[right])>0 ) ){
                    set.erase(str[left]) ;  // start removing from the beginning untill the 
                    left ++ ;   // duplicate is found and removed
                } 

            }

            set.insert(str[right]) ; 
            right ++ ; 
            max_len = max(max_len , right - left ) ; 
        }
        return max_len ; 
    }
};

// Approach 2
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size() == 0)
            return 0 ; 
        int max_len = 1 ;
        int left = 0 , right = 0 ; 
        int N = str.size() ; 
        unordered_map<char , int > lastSeenIndex ; 
        while(right <N ){
            if(lastSeenIndex.count(str[right])>0  ) // means str[right] is a duplicate
                left = max(left , lastSeenIndex[str[right]]+1 ) ; 
                // we are directly bypassing to the range in between 
                // left and right with one hop/jump  also we are updating left only if we see the
                // duplicate str[right] between left and right window
            
            lastSeenIndex[str[right]] = right; 
            right ++ ; 
            max_len = max(max_len , right - left ) ; 
        }
        return max_len ; 
    }
};

int main() {
    init_code() ; 

}