/*

https://leetcode.com/problems/rotate-image/

==========================================
Note : To reverse the matrix rows 
reverse(M.begin(), M.end());
==========================================

Intuition: By observation, we see that the 
first column of the original matrix is the reverse of the 
first row of the rotated matrix, so that’s why we transpose 
the matrix and then reverse each row, and since we are making 
changes in the matrix itself space complexity gets reduced to O(1).
Intuition: By observation, we see that the first column of the original
 matrix is the reverse of the first row of the rotated matrix, so that’s 
 why we transpose the matrix and then reverse each row, and since we are 
 making changes in the matrix itself space complexity gets reduced to O(1).

1 2 3       1 4 7        7 4 1
4 5 6  =>   2 5 8  =>    8 5 2
7 8 9       3 6 9        9 6 3

or 

  clockwise rotate
  first reverse up to down, then swap the symmetry 
  1 2 3     7 8 9     7 4 1
  4 5 6  => 4 5 6  => 8 5 2
  7 8 9     1 2 3     9 6 3




 anticlockwise rotate
 first reverse left to right, then swap the symmetry
 1 2 3     3 2 1     3 6 9
 4 5 6  => 6 5 4  => 2 5 8
 7 8 9     9 8 7     1 4 7

 


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


Naive approach : Taking the help of dummy matrix 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size() ; 
        vector<vector<int>>A(N , vector<int>(N , 0 )) ; // dummy matrix 

        // placing the col in reverse direction in place of row
        for(int r=0 ; r<N ; r++ ){
            for(int c=0 ; c<N ; c++ )
                A[r][c] = matrix[N-1-c][r] ;  
        }

        // copying back
        for(int r=0 ; r<N ; r++ ){
            for(int c=0 ; c<N ; c++ )
                matrix[r][c] = A[r][c] ;
               
        }

    }
};

int main() {
    init_code() ; 
    Solution sol ; 
    vector<vector<int>>M = {{1,2,3},{4,5,6},{7,8,9}} ; 
    cout << "Original :" << endl ; 
    for(int i=0 ; i<M.size() ; i++){
        for(int j=0 ; j<M[0].size() ; j++ )
            cout << M[i][j] << " " ; 
        cout << endl ; 
    } 
    sol.rotate(M) ; 
    cout << "Rotated :" << endl ; 
    for(int i=0 ; i<M.size() ; i++){
        for(int j=0 ; j<M[0].size() ; j++ )
            cout << M[i][j] << " " ; 
        cout << endl ; 
    } 
    return 0 ; 
}

--------------------------------------------------------------------------------

Best approach :

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size() ; 
        // Transposing 
        for(int r=0 ; r<N ; r++)
            for(int c=r+1 ; c<N ; c++ )
                swap(matrix[r][c]  ,matrix[c][r]) ;

        // Reversing each row 
        for(int r=0 ; r<N ; r++) 
            reverse(matrix[r].begin() , matrix[r].end() ) ; 
        
    }
};