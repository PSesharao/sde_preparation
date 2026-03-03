/*



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


void printSubSeqSumToK(int index , int N , vector<int> &arr , vector<int> &ans , int k ){

    if( index == N ){
        if( k == 0 )
        {
            for(auto a : ans )
                cout << a << " " ; 
            cout << endl ;
        }
         
        return ; 
    }

    // take 
    if( k - arr[index] >=0 ){
        ans.push_back(arr[index]) ; 
        printSubSeqSumToK(index +1 , N , arr , ans , k - arr[index]  );
        ans.pop_back() ; 
    }

    //not take 
    printSubSeqSumToK(index +1 , N , arr , ans , k );
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}


// To print any one of the subsequence we can use boolean function

bool printAnySubSeqSumToK(int index , int N , vector<int> &arr , vector<int> &ans , int k ){

    if( index == N ){
        if( k == 0 )
        {
            for(auto a : ans )
                cout << a << " " ; 
            cout << endl ;
            return true ; 
        }
         
        return false ; 
    }

    // take 
    if( k - arr[index] >=0 ){
        ans.push_back(arr[index]) ; 
        if (printAnySubSeqSumToK(index +1 , N , arr , ans , k - arr[index]  ))
            return true ; 
        ans.pop_back() ; 
    }

    //not take 
    if(printAnySubSeqSumToK(index +1 , N , arr , ans , k ))
        return true ; 

    return false ; 
}


// To count the subsequences whose sum is k
int countSubSeqSumToK(int index , int N , vector<int> &arr  , int k ){

    if( index == N ){
        if( k == 0 )
        
            return 1 ;
         
        return 0 ; 
    }
    
    int takeCount =0 , nonTakeCount = 0 ; 
    // take 
    if( k - arr[index] >=0 ){
       
        takeCount = countSubSeqSumToK(index +1 , N , arr  , k - arr[index]  ) ;
        
    }

    //not take 
    nonTakeCount = countSubSeqSumToK(index +1 , N , arr  , k ) ; 
        

    return takeCount + nonTakeCount  ; 
}