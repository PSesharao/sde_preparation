/*

https://leetcode.com/problems/reverse-words-in-a-string/

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


// using stack 
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
};



class Solution {

private : 
void reverse(string &s , int left , int right ) {
    while(left < right ) {
        char temp = s[left]  ; 
        s[left] = s[right] ; 
        s[right] = temp ; 
    }
}

public:
    string reverseWords(string str ) {
        int last = 0, curr = 0;
        // string will be functionally exactly char[] , last char is '\0' 

        while(str[curr] ){
            // skipping all the trailing and extra in between spaces 
            while(str[curr] == ' ')
                curr ++ ; 

            last = curr ; // represents the last non space , character 


            while(str[curr] and str[curr] != ' ' ) 
                curr ++ ; 

            // the block last to curr-1 represents the only non space chars
            reverse(str , last , curr-1 ) ; 

        }

        // reversing the whole string 
        reverse(str , 0 , curr-1 ) ;  

        // now at this stage we have got our words reversed but , we need 
        //to cleanup the spaces 

        last = 0 ; 
        curr = 0 ; 
        while( str[curr] ){
            // either if curr is not a blank 
            // or if it curr is blank and last-1 is not blank 
            if(( str[curr]!=' ' and str[curr] ) or (last !=0 and str[last-1] != str[curr ]))
                str[last++] = str[curr] ; 
            curr ++ ; 
        }

        // this happens in case string has trailing spaces and when reversed those will come to back 
        if(last !=0 and str[last-1] == ' ' )
            str[last-1] = '\0' ; 
        else
            str[last] = '\0' ; // ending the string right there

        return str ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    string s = "hello world" ; 
    int i=0 ; 
    while(s[i])
        cout << s[i] ; 
    
}