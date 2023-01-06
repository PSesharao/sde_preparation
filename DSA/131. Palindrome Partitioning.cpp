/*

https://leetcode.com/problems/palindrome-partitioning/

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

private : 

bool isPalindrome(int start , int end , string s ) {

    while(start <= end ){
        if(s[start++] != s[end--])
            return false ; 
    }
    return true ; 
}

void partition(int ind  , string str , vector<string> &curr_partition , vector<vector<string>> &ans  ) {

    if( ind == str.size() ){
        ans.push_back(curr_partition) ; 
        return ; 
    }
    for(int p = ind ; p<str.size() ; p++ ) {
        if(isPalindrome(ind , p , str )){
            curr_partition.push_back(str.substr(ind , p-ind +1 )) ;
            partition(p+1 , str , curr_partition , ans ) ; 
            curr_partition.pop_back() ; 
        }
    }
}

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans  ; 
        vector<string> curr_partition ; 
        partition(0 , s , curr_partition , ans ) ; 
        return ans ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}