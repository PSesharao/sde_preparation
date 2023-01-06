/*

https://leetcode.com/problems/rotate-image/


Intuition: By observation, we see that the 
first column of the original matrix is the reverse of the 
first row of the rotated matrix, so that’s why we transpose 
the matrix and then reverse each row, and since we are making 
changes in the matrix itself space complexity gets reduced to O(1).
Intuition: By observation, we see that the first column of the original
 matrix is the reverse of the first row of the rotated matrix, so that’s 
 why we transpose the matrix and then reverse each row, and since we are 
 making changes in the matrix itself space complexity gets reduced to O(1).

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