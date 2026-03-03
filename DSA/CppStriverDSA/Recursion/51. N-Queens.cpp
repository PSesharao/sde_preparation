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
bool isPossibleToPlace(int row , int col , vector<string> &board , int N ){

    // left top diagonal

    for(int r=row-1 , c=col-1 ; (r>=0 and c>=0 ); r-- , c-- )
        if(board[r][c] == 'Q')
            return false ; 

    // right top diagonal

    for(int r=row-1 , c=col+1 ; (r>=0 and c<N ); r-- , c++ )
        if(board[r][c] == 'Q')
            return false ; 

    // top
    for(int r=row-1 ; (r>=0  ); r--  )
        if(board[r][col] == 'Q')
            return false ; 

    return true ; 
    
}

private : 
bool isPossibleToPlace2( int row , int col , int N , vector<int> &top , 
    vector<int> &left_diagonal , vector<int> &right_diagonal){

    return top[col] == 0 and left_diagonal[row+col] == 0 and right_diagonal[N-1 + row - col ] == 0 ; 

}

private : 

void nQueens(int row , vector<string> &board , int N , 
    vector<vector<string>> &ans , vector<int> &top , 
    vector<int> &left_diagonal , vector<int> &right_diagonal){

    if(row == N ){
        ans.push_back(board) ; 
        return ; 
    }

    for(int col =0 ; col < N ; col++ ){

        if(isPossibleToPlace2(row , col , N , top , left_diagonal , right_diagonal )){
            board[row][col] = 'Q' ;
            top[col] = 1 ;
            left_diagonal[row+col] = 1 ;
            right_diagonal[N-1 + row - col ] = 1 ; 

            nQueens(row+1 , board , N , ans , top , left_diagonal , right_diagonal ) ;

            board[row][col] = '.' ;
            top[col] = 0 ;
            left_diagonal[row+col] = 0 ;
            right_diagonal[N-1 + row - col ] = 0 ; 

        }
    }

}

public:
    vector<vector<string>> solveNQueens(int n) {
        int N = 4 ; 
        string str (N , '.' ) ; 
        vector<string> board(N , str ) ; 
        vector<vector<string>> ans ; 
        vector<int> top(n , 0 ) ; 
        vector<int> left_diagonal(2*n-1 , 0 ) ;  // for n =8 max it can go till 14  , we store row + col
        vector<int> right_diagonal(2*n-1) ;   // for n =8 max it can go till 14 , 
        //we store n-1 + (col - row ) or n-1 + (row - col ) , here n-1 is for avoiding the negative values.
        nQueens(0 ,board , N , ans , top , left_diagonal , right_diagonal  ) ;
        return ans ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 
    int n = 4 ; 
    vector<vector<string>> nQueenSol = sol.solveNQueens(n) ; 
    for(auto board : nQueenSol ){
        for(auto row : board )
            cout << row << endl ; 
        cout << endl ; 
    }
    return 0 ; 
}