/*

https://leetcode.com/discuss/interview-question/3114099/AMAZON-OA-(INTERN-2024)

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


int findMatchingCount(string t  , string s ){

    unordered_map<char , int > freq_t , freq_s ; 

    int count = INF ; 

    for(auto ch : t )
        freq_t[ch] ++ ; 

    for(auto ch : s )
        freq_s[ch] ++ ; 

    for(auto ch : t ){

        if(freq_s.count(ch) == 0 )
            return 0 ; 

        int f = freq_s[ch] / freq_t[ch] ; 

        count = min(count , f ) ; 
    }

    return count ; 
}

int main() {
    init_code() ; 
    string s = "mononom" ; 
    string t = "mon" ; 
    // Solution sol ; 
    int m = findMatchingCount( t  , s ) ; 
    cout << m << endl ; 
    return 0;
}