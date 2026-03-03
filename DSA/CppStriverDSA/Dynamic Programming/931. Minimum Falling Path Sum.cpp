/*

https://leetcode.com/problems/minimum-falling-path-sum/

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

    int minFallingPathSum(int x , int y , int m , int n , vector<vector<int>>& matrix) {
        if(x == m-1 )
            return matrix[x][y] ; 

        int down_sum = INT_MAX , diagonal_right_sum = INT_MAX , diagonal_left_sum = INT_MAX ;
        
        // diagonal left 
        if( x+1 < m and y-1>=0 )
            diagonal_left_sum = minFallingPathSum(x+1 , y-1 , m , n , matrix ) ;

        // diagonal right
        if( x+1 < m and y+1 < n  )
            diagonal_right_sum = minFallingPathSum(x+1 , y+1 , m , n , matrix ) ;

        // down 
        if( x+1 < m ) 
            down_sum = minFallingPathSum(x+1 , y , m , n , matrix ) ;

        return 0LL + matrix[x][y] + min( {diagonal_left_sum , diagonal_right_sum , down_sum }) ; 

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size() ; 
        int n = matrix[0].size() ; 
        int minAns = INT_MAX ; 
        for(int i=0 ; i<n ; i++ ){
            int curAns = minFallingPathSum(0 , i , m , n , matrix ) ; 
            minAns = min( curAns , minAns ) ; 
        }
        return minAns ; 

    }
};


 // Memoization 
class Solution2 {
public:

    int minFallingPathSum(int x , int y , int m , int n , vector<vector<int>>& matrix 
        , vector<vector<int>> &dp ) {

        if(dp[x][y] != -1)
            return dp[x][y] ; 

        if(x == m-1 )
            return dp[x][y] = matrix[x][y] ; 

        int down_sum = INT_MAX , diagonal_right_sum = INT_MAX , diagonal_left_sum = INT_MAX ;
        
        // diagonal left 
        if( x+1 < m and y-1>=0 )
            diagonal_left_sum = minFallingPathSum(x+1 , y-1 , m , n , matrix , dp ) ;

        // diagonal right
        if( x+1 < m and y+1 < n  )
            diagonal_right_sum = minFallingPathSum(x+1 , y+1 , m , n , matrix , dp ) ;

        // down 
        if( x+1 < m ) 
            down_sum = minFallingPathSum(x+1 , y , m , n , matrix , dp ) ;

        return dp[x][y]  = 0LL + matrix[x][y] + min( {diagonal_left_sum , diagonal_right_sum , down_sum }) ; 

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size() ; 
        int n = matrix[0].size() ; 
        vector<vector<int>> dp(m , vector<int>(n , -1 ) ) ; 
        int minAns = INT_MAX ; 
        for(int i=0 ; i<n ; i++ ){
            int curAns = minFallingPathSum(0 , i , m , n , matrix , dp ) ; 
            minAns = min( curAns , minAns ) ; 
        }
        return minAns ; 

    }


};


// Tabulation
class Solution3 {
public:
    int minFallingPathSum( int m , int n , vector<vector<int>>& matrix 
        , vector<vector<int>> &dp ) {


        for(int y=n-1 ; y>=0 ; y-- )
            dp[m-1][y] = matrix[m-1][y] ; 


        for(int x= m-2 ; x>=0 ; x-- )
            for(int y=n-1 ; y>=0 ; y-- ){
                int down_sum = INT_MAX , diagonal_right_sum = INT_MAX , diagonal_left_sum = INT_MAX ;
                
                // diagonal left 
                if( x+1 < m and y-1>=0 )
                    diagonal_left_sum = dp[x+1][y-1] ; // minFallingPathSum(x+1 , y-1 , m , n , matrix , dp ) ;

                // diagonal right
                if( x+1 < m and y+1 < n  )
                    diagonal_right_sum = dp[x+1][y+1] ;// minFallingPathSum(x+1 , y+1 , m , n , matrix , dp ) ;

                // down 
                if( x+1 < m ) 
                    down_sum = dp[x+1][y] ; // minFallingPathSum(x+1 , y , m , n , matrix , dp ) ;

                 dp[x][y]  = 0LL + matrix[x][y] + min( {diagonal_left_sum , diagonal_right_sum , down_sum }) ; 
            }


            int minAns = INT_MAX ; 
            for(int i=0 ; i<n ; i++ ){
                int curAns = dp[0][i] ; // minFallingPathSum( m , n , matrix , dp ) ; 
                minAns = min( curAns , minAns ) ; 
            }
            return minAns ;             

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size() ; 
        int n = matrix[0].size() ; 
        vector<vector<int>> dp(m , vector<int>(n , 0 ) ) ; 
        return minFallingPathSum( m , n , matrix , dp ) ; 

    }
};


int main() {
    init_code() ; 
    Solution3 sol ; 
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}} ; 
    cout << sol.minFallingPathSum(matrix) ; 
    return 0 ; 
}