/*

https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1

The Naive String Matching algorithm slides the pattern one by one. After each slide, 
it one by one checks characters at the current shift and if all characters match 
then prints the match. 
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. 
But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the 
pattern with the hash value of current substring of text, and if the hash values 
match then only it starts matching individual characters. So Rabin Karp algorithm 
needs to calculate hash values for following strings.

1) Pattern itself. 
2) All the substrings of the text of length m. 


Since we need to efficiently calculate hash values for all the substrings of 
size m of text, we must have a hash function which has the following property. 
Hash at the next shift must be efficiently computable from the current hash value 
and next character in text


hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) - txt[s]*h ) + txt[s + m] ) mod q 
hash( txt[s .. s+m-1] ) : Hash value at shift s. 
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
d: Number of characters in the alphabet 
q: A prime number 
h: d^(m-1)



How does the above expression work? 


This is simple mathematics, we compute decimal value of current window from previous window. 
For example pattern length is 3 and string is "23456" 
You compute the value of first window (which is "234") as 234. 
How  will you compute value of next window "345"? You will do (234 - 2*100)*10 + 5 
and get 345.

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

// d is the number of characters in the input alphabet 
#define d 256 
#define q 13 
/* pat -> pattern 
    txt -> text 
    q -> A prime number 
*/
class Solution
{
    public:
    vector <int> search(string pat, string txt)
    {
        vector <int> res ; 
        int M = pat.size() ; 
        int N = txt.size(); 
        int i, j; 
        int p = 0; // hash value for pattern 
        int t = 0; // hash value for txt 
        int h = 1; 

        // The value of h would be "pow(d, M-1)%q" 

        for (i = 0; i < M - 1; i++) 
            h = (h * d) % q; 

        // Calculate the hash value of pattern and first 
        // window of text 
        for (i = 0; i < M; i++) 
        { 
            p = (d * p + pat[i]) % q; 
            t = (d * t + txt[i]) % q; 
        }

           // Slide the pattern over text one by one 
        for (i = 0; i <= N - M; i++) 
        { 

            // Check the hash values of current window of text 
            // and pattern. If the hash values match then only 
            // check for characters one by one 
            if ( p == t ) 
            {   
                /* Check for characters one by one */

                for (j = 0; j < M; j++) 
                    if (txt[i+j] != pat[j])
                      break;
                    
                // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
              
                if (j == M) 
                    res.push_back(i+1) ; 
                    
            } 

            // Calculate hash value for next window of text: Remove 
            // leading digit, add trailing digit 
            if ( i < N-M ) 
            { 
                t = (d*(t - txt[i]*h) + txt[i+M])%q; 

                // We might get negative value of t, converting it 
                // to positive 
                if (t < 0) 
                t = (t + q); 
            } 
        }  
        if(res.size() == 0 )
            return {-1} ; 
        return res ;
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}