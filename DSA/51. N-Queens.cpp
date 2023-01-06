/*

https://leetcode.com/problems/n-queens/

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
bool isPossibleToPlace(vector<string>  & board , int row , int col , int N ) {
    
    // checking for the above rows (up) 

    for(int r=row-1 ; r>=0 ; r--)
        if(board[r][col] == 'Q')
            return false ;

    // checking for left diagonal 

    for(int r=row-1 , c = col-1 ; r>=0 && c>=0 ; r-- , c--  )
        if(board[r][c] == 'Q')
            return false ;

    // checking for right diagonal

    for(int r=row-1 , c=col+1 ; r>=0 && c<N ; r-- , c++ )
        if(board[r][c] == 'Q')
            return false ;

    return true ;

}

void nQueens(int N , vector<string> & board , 
    int row , vector<vector<string>> &ans ){

    if(row == N) {
        ans.push_back(board) ; 
        for(int r=0 ; r<N ; r++)
            for(int c=0 ; c<N ; c++)
                cout << board[r][c] << " " ;
        cout << endl ;
        return ;
    }

    // here for every column we are exploring options 
    // this will only end when last column in first row is explored .
    for(int col=0 ; col<N ; col++)
    {
        if(isPossibleToPlace(board , row , col , N)){
            board[row][col] = 'Q' ;

            nQueens(N , board , row+1) ;
            // this is backtracking step 
            // we are exploring all the cases , so here we should do this for next cases
            board[row][col] = '.' ;
        }
    }

}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(N , "....") ; 
        vector<vector<string>> ans ; 
        nQueens(N ,board , 0 , ans ) ;
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}