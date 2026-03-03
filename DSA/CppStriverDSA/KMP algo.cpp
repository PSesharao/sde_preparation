/*

https://practice.geeksforgeeks.org/problems/search-pattern0205/1

let us take 

txt
----
0 1 2 3 4 5 6 7 8 9 10
a b c x a b c d a b  x  ........

pat
---
0 1 2 3 4 5 6 7
a b c d a b c y 

here the intention is not to go back in the text while iterating when there is a mismatch . 

we see that first mismatch is at x(txt[3] ) and d(pat[3]) , we see if there is a 
prefix which is also a suffix of substring 'abc' , but there is no . 

now the comparision should start from x(txt[3] ) and a(pat[0]) , as they do not match 
same pattern follows now . 

next mismatch point will be x(txt[10]) and c (pat[6]) . 

Till then before c (pat[6]) we have a b c d a b , we see "a b" is the longest
prefix which is also suffix . 

since we have matched till before 'x'(txt[10]) in text , the characters before x
must be "a b" , therefore we donot have to go back in text again to match "a b" ,
the match can be c(pat[2]) of prefix . 

This is how KMP works . 



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


class Solution
{

private : 


void getLPS(vector<int> &lps , string pat ) {
    lps[0] = 0 ; // always 0 

    int j = 0 , i = 1 ; 
    while(i < pat.length() ){

        if(pat[i] == pat[j] ){
            
            lps[i] = j+1 ; 

// let us take txt = a b c d a x ..... , pat =a b c d a b c a  , when i = 4 , j should be at 0 
// since there is no match sofar in pat itself ( always j < i )
// the first mismatch would be at i= 5 x(txt[5]) and b(pat[5]) , now where to start matching 
// again would be determined by the i-1 index of lps , 

// therfore when i=4 there since there is match at i , j indices in pat , lps[i] should be j+1 

// Note : at anypoint lps[i] determines where to start searching if there is mismatch at i+1 , 
// index in pat . 


            i++ ; 
            j++ ; 
        }
        else{
            if(j != 0 )
                j = lps[j -1 ] ;  // explained above . 
            else{
                lps[i] =0 ; 
                i++ ; 
            }

        }
    }
}

public:
// This is very similar to above one    
vector <int> search(string pat, string txt)
{
    vector<int> lps( pat.size() ) ;  
    vector<int> ans ; 
    getLPS(lps , pat ) ; 
    int text_len = txt.length() ; 
    int pat_len = pat.length() ; 
    int j=0 , i=0 ; // i is txt iterator and j is pat iterator
    while(i < text_len and j < pat_len ){
        if(txt[i] == pat[j]){
            i++ ; 
            j++ ;
        }else{
            if(j!=0)
                j = lps[j-1] ; 
            else{
                i++ ; 
            }
        }

        if( j == pat_len ){
            ans.push_back(i-j+1) ; // 1 based indexing
            j = lps[j-1] ; // for the cases like txt = aaaaaa and pat = aa to include all interleaving answers 
        }
    }
    return ans ; 
}

};

int main() {
    init_code() ; 
    Solution sol ; 

    
}