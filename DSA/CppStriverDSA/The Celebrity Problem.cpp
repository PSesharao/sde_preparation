/*

https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
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

bool knows(int A, int B);

int findCelebrity(int n) {
    
    int i = 0 , j = n-1 ; 
    while(i < j ){
        if( i == j )
            continue ; 
        if(knows(i , j ))
            i++ ; // i is not celebrity 
        else
            j -- ; // if i does not know j , we'll try with j-1 
    }

    int celebrity = i ; // what ever is the 'i' index , it might be 
    // possible celebrity 

    // now to make sure every one knows 'i'

    for(int k=0 ; k<n ; k++ ){
        if(k == celebrity )
            continue ; 

        if( !knows(k , celebrity ) or knows(celebrity , k ))
            return -1 ; 
    }

    return celebrity ; 
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}