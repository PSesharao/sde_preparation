/*

https://leetcode.com/problems/sudoku-solver/

Time Complexity: O(9^(n ^ 2)), in the worst case, 
for each cell in the n^2 board, we have 9 possible numbers.

Space Complexity: O(1), since we are refilling the given board itself, 
there is no extra space required, so constant space complexity.


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

private : 
bool isPossibleToPlace(int k , vector<vector<int>> &sudoku 
, int row , int col  ) {

    k += '0' ; 
	// This represents the top left corner of the any given box 
    int box_x_corner = 3*(row/3) ; 
    int box_y_corner = 3*(col/3) ; 

    for(int i=0 ; i<9 ; i++ ){

        // checking row wise 
        if(sudoku[row][i] == k )
            return false ; 

        // checking column wise

        if(sudoku[i][col] == k )
            return false ;  

        // checking within the 3 X 3 box 

        if(sudoku[box_x_corner + (i/3) ][box_y_corner + (i%3) ] == k )
            return false ; 

    }

    return true ;
}

bool solveSudoku_helper(vector<vector<char>> &sudoku) {
    for(int i=0 ; i<9 ; i++)
        for(int j=0 ; j<9 ; j++ )
        {
            if(sudoku[i][j] == '.') {
                for(int k=1 ; k<=9 ; k++) {
                    if(isPossibleToPlace(k , sudoku , i , j ))
                    {
                        sudoku[i][j] = '0'+k ;
                        bool filled = solveSudoku_helper( sudoku ) ;
                        if(filled)
                        // We are returning as soon as first solution found     
                            return true ;
                        // marking empty again to try for 
                        // another option when current option does not
                        // fit
                        sudoku[i][j] = '.' ;
                    }
                }
                // if not able to place any of digit 
                // from 1 to 9 
                return false ;
            }
        }

    //  if no empty cell found-> all are validly filled  
    return true ;
}

public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku_helper(board ) ; 
        return board ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}