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