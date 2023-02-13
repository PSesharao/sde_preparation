/*

https://leetcode.com/problems/pascals-triangle/

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



With out pass by reference

/*

Here in this approach we should not pass 'ans' variable by reference 
as in the function code we are not removing it at the end it keeps on adding  
the elements at the back.

*/


void printSubSeq( int index , int N , vector<int> &arr , vector<int> ans ){
    if( index == N )
    {
        for(int i=0 ; i<ans.size() ; i++ ){
            cout << ans[i] << " " ; 
        }
        cout << endl ; 
        return ; 
    }

    //not take
    printSubSeq(index+1 , N , arr , ans ) ; 
    // take
    ans.push_back(arr[index]) ; 
    printSubSeq(index+1 , N , arr , ans ) ; 

}


Pass by reference
/*

In this approach we should remove what ever the element we are adding to the ans , otherwise it keeps on adding  
the elements at the back. as we are passing by reference.


*/


void printSubSeq2( int index , int N , vector<int> &arr , vector<int> &ans ){
    if( index == N )
    {
        for(int i=0 ; i<ans.size() ; i++ ){
            cout << ans[i] << " " ; 
        }
        cout << endl ; 
        return ; 
    }


    //not take
    printSubSeq2(index+1 , N , arr , ans ) ;
    
    // take
    ans.push_back(arr[index]) ; 
    printSubSeq2(index+1 , N , arr , ans ) ; 

    
    ans.pop_back() ; 

}


void printSubSeq3( int index , int N , vector<int> &arr , vector<int> &ans ){
    if( index == N )
    {
        for(auto it : ans  ){
            cout << it << " " ; 
        }
        cout << endl ; 
        return ; 
    }


    // take
    ans.push_back(arr[index]) ; 
    printSubSeq3(index+1 , N , arr , ans ) ; 

    
    ans.pop_back() ; 

    //not take
    printSubSeq3(index+1 , N , arr , ans ) ;
    

}

int main() {
    init_code() ; 
    Solution sol ; 

    
}