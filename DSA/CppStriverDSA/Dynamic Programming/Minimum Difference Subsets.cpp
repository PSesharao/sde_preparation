/*

https://www.interviewbit.com/problems/minimum-difference-subsets/

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


// Recursion 
int solve2(int ind  , int* arr, int s1 , int s2 , int n ) {

    if(ind == n )
        return abs(s1 - s2 ) ; 

    // put in s1
    int diff1 = solve2(ind+1 , arr , s1+arr[ind] , s2 ,  n ) ;

    // put in s2
    int diff2 = solve2(ind+1 , arr , s1 , s2+arr[ind] , n  ) ;

    return min({diff1 , diff2 }) ; 

}

int solve2(int* arr, int n ) {
    return solve2(0 , arr , 0 , 0 , n ) ; 
}




void solve1( int* arr, int n , int S , vector<vector<int>> &dp  ) {

        for(int ind = 0 ; ind<=n ; ind++  )
            dp[ind][0] =  true ; 


        for(int sum =0 ; sum <= S ; sum++ )
            dp[n][sum] = false ; 

        dp[n][0] = true ; 

        for(int ind = n-1 ; ind>=0 ; ind--  )
            for(int sum =1 ; sum <= S ; sum++ )
            {
                bool pick = false ; 
                // take 
                
                if( sum - arr[ind] >=0  )
                    pick = dp[ind+1][sum - arr[ind]] ;  

                // not take 
                bool notpick = dp[ind+1][sum] ; 
                dp[ind][sum] = (pick or notpick) ;                 
            }
            
}

int solve1(int* arr, int n ) {
    int sum =0 ; 
    for(int i=0 ; i<n ; i++ )
        sum += arr[i] ;     
    vector<vector<int>> dp( n+1 , vector<int>( sum+1 , 0 ) ) ; 
    solve1( arr , n , sum , dp ) ; 

    int minDiff = INT_MAX ; 
    for(int s=(sum/2) ; s>=0  ; s-- ){
        if( dp[0][s] ){
            
            minDiff = min ({minDiff , abs(s - (sum - s) ) }) ; // or we can say  sum - 2*s
           
        }
    }
    return minDiff ; 
}


int main() {
    init_code() ; 
    //Solution3 sol ; 
    int A[] = {8 , 6 , 5 } ; 
    cout << solve2(A , 3 ) ; 
    return 0 ; 
}