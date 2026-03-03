/*

https://leetcode.com/problems/triangle/

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
class Solution1 {
public:
    int minimumTotal( int x , int y , int rows , vector<vector<int>>& triangle) {
        
        if(x == rows-1 )
            return triangle[x][y] ; 

        int down_sum = INT_MAX , diagonal_sum = INT_MAX ;

        // down 
        if(x+1 < rows )
            down_sum = minimumTotal(x+1 , y , rows , triangle ) ; 

        // diagonal 
        if( x+1 < rows and y+1 <= x+1 )
            diagonal_sum = minimumTotal(x+1 , y+1 , rows , triangle ) ; 

        return 0LL + triangle[x][y] + min(down_sum , diagonal_sum ) ; 

    }

    int minimumTotal( vector<vector<int>>& triangle ) {
        int rows = triangle.size() ; 
        return minimumTotal( 0 ,0 , rows , triangle ) ; 
    }
};

// Memoization 
class Solution2 {
public:
    int minimumTotal( int x , int y , int rows , vector<vector<int>>& triangle 
        , vector<vector<int>> &dp ) {

        if(dp[x][y] != -1)
            return dp[x][y] ;         
        
        if(x == rows-1 )
            return dp[x][y] = triangle[x][y] ; 

        int down_sum = INT_MAX , diagonal_sum = INT_MAX ;

        // down 
        if(x+1 < rows )
            down_sum = minimumTotal(x+1 , y , rows , triangle , dp  ) ; 

        // diagonal 
        if( x+1 < rows and y+1 <= x+1 )
            diagonal_sum = minimumTotal(x+1 , y+1 , rows , triangle , dp ) ; 

        return dp[x][y] = 0LL + triangle[x][y] + min(down_sum , diagonal_sum ) ; 

    }

    int minimumTotal( vector<vector<int>>& triangle ) {
        int rows = triangle.size() ; 
        vector<vector<int>> dp(rows , vector<int>(rows , -1 ) ) ; 
        return minimumTotal( 0 ,0 , rows , triangle , dp ) ; 
    }

};


// Tabulation
class Solution3 {
public:
    int minimumTotal( int rows , vector<vector<int>>& triangle 
        , vector<vector<int>> &dp ) {

        for(int y =0 ; y<rows ; y++ )
            dp[rows-1][y] = triangle[rows-1][y] ; 


        for(int x= rows-2 ; x>=0 ; x-- )
            for(int y=x ; y>=0 ; y-- ){

                    int down_sum = INT_MAX , diagonal_sum = INT_MAX ;

                    // down 
                    if(x+1 < rows )
                        down_sum = dp[x+1][y] ; // minimumTotal(x+1 , y , rows , triangle , dp  ) ; 

                    // diagonal 
                    if( x+1 < rows and y+1 <= x+1 )
                        diagonal_sum = dp[x+1][y+1] ;// minimumTotal(x+1 , y+1 , rows , triangle , dp ) ; 

                     dp[x][y] = 0LL + triangle[x][y] + min(down_sum , diagonal_sum ) ; 

            }

        return dp[0][0] ; 

    }

    int minimumTotal( vector<vector<int>>& triangle ) {
        int rows = triangle.size() ; 
        vector<vector<int>> dp(rows , vector<int>(rows , 0 ) ) ; 
        return minimumTotal(  rows , triangle , dp ) ; 
    }
};


int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3} }; 
    cout << sol.minimumTotal(triangle) ; 
    return 0 ; 
}