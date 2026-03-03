/*

https://leetcode.com/problems/unique-paths/

Intuition: If we observe examples there is a similarity in paths from start to end. 
Each time we are taking an exactly m+n-2 number of steps to reach the end.

Since we need an m+n-2 number of steps to reach the end among those steps 
if we choose n-1 rightward direction or m-1 downward direction and calculate 
the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

Time Complexity: The time complexity of this solution will be O(n-1) or  O(m-1) 
depending on the formula we are using.

Space Complexity: As we are not using any extra space the space complexity 
of the solution will be  O(1).

  
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

// Approach 1

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2 ;
        int R = min(m , n)-1 ;
        // Taking double bcz ant any point fraction might give
        // fractional values
        double ncr = 1 ; 
        for(int r=1; r<=R ; r++)
            ncr = ncr*(N-r+1)/r ; 
        return (int) ncr ; 
    }
};

// recursive solution 

class Solution {

private :
    int countPaths(int i,int j,int n,int m){
        if(i==(n-1)&&j==(m-1)) 
            return 1;
        int rightPath = 0 ;
        int downPath  = 0 ; 

        if(i+1< n )
            rightPath = countPaths(i+1,j,n,m) ;
        if(j+1<m )
            downPath = countPaths(i,j+1,n,m);
        
         return rightPath + downPath ; 
    }

public:
    int uniquePaths(int m, int n) {
        return countPaths( 0, 0, m , n ) ; 
    }

};

// Approach 2 dp 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m ,vector<int>(n , 0) ) ;
        matrix[m-1][n-1]  = 1 ; 

        for(int c=n-1 ; c>=0 ; c--)
            for(int r=m-1 ; r>=0 ; r--){
                if(c == n-1 and r==m-1 )
                    continue ; 
                int rightPath = 0 ; 
                if(r+1<m )
                    rightPath = matrix[r+1][c] ;
                int downPath = 0 ;
                if(c+1 < n)
                    downPath = matrix[r][c+1] ;
                matrix[r][c] = rightPath + downPath ; 
            }
        return matrix[0][0] ;    
    }
};

int main() {
    init_code() ; 
    Solution sol ; 
    cout << sol.uniquePaths(3 , 4 ) ; 
    
}



-------------------------------------------------------------------

// Recursion 
class Solution1 {
public:
    int uniquePaths(int x , int y , int m, int n) {
        if( x == m-1 and y == n-1 )
            return 1 ; 

        // down
        int down_moves = 0 , right_moves = 0 ;
        if(x+1 < m )
            down_moves += uniquePaths(x+1 , y , m , n ) ; 

        // right
        if(y+1 < n )
            right_moves += uniquePaths(x , y+1 , m , n ) ;

        return right_moves+down_moves ;  
        
    }

    int uniquePaths(int m, int n) {
        return uniquePaths(0 , 0 , m , n ) ; 
    }
};


// Memoization 

class Solution2 {
public:
    int uniquePaths(int x , int y , int m, int n , vector<vector<int>> &dp) {

        if(dp[x][y] != -1)
            return dp[x][y] ; 

        if( x == m-1 and y == n-1 )
            return dp[x][y] = 1 ; 

        // down
        int down_moves = 0 , right_moves = 0 ;
        if(x+1 < m )
            down_moves += uniquePaths(x+1 , y , m , n , dp ) ; 

        // right
        if(y+1 < n )
            right_moves += uniquePaths(x , y+1 , m , n ,dp ) ;

        return dp[x][y] = right_moves+down_moves ;          
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp( m , vector<int>(n , -1 )) ; 
        return uniquePaths(0 , 0 , m , n , dp ) ; 
    }
};


// Tabulation
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp( m , vector<int>(n , 0 )) ; 
        dp[m-1][n-1] = 1 ;

        for(int x= m-1 ; x>=0 ; x-- )
            for(int y=n-1 ; y>=0 ; y-- )
            {
                if(x == m-1 and y == n-1 )
                    continue ; 

                int down_moves = 0 , right_moves = 0 ;
                if( x+1 < m )
                    down_moves +=  dp[x+1][y] ;  // uniquePaths(x+1 , y , m , n , dp ) ; 

                // right
                if( y+1 < n )
                    right_moves += dp[x][y+1] ; // uniquePaths(x , y+1 , m , n ,dp ) ;

                 dp[x][y] = right_moves+down_moves ;                  
            }

            return dp[0][0] ; 
    }

};

int main() {
    init_code() ; 
    Solution3 sol ; 
    cout << sol.uniquePaths(3 , 2 ) ; 
    return 0 ; 
}