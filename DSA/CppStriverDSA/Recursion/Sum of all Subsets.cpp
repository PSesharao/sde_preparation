/*

https://practice.geeksforgeeks.org/problems/subset-sums2234/1

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

/* 

	here for loop is not required as we are not doing these things 
	
	i) to check for the duplicates and skip them
	ii) not trying to reduce the recursion calls by not considering the higher values and breaking the loop in between  
	
*/
class Solution
{

private : 

void subsetSums(vector<int> &arr , int index , int N , int sum , vector<int> &ans ) {
    if(index == N ){
        ans.emplace_back( sum ) ; 
        return ; 
    }

    // including index 
    subsetSums(arr , index+1 , N , sum+arr[index] , ans ) ; 
    // excluding index
    subsetSums(arr , index+1 , N , sum , ans ) ; 
}

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans ; 
        subsetSums(arr , 0 , N , 0 , ans ) ; 
        sort(ans.begin() , ans.end() ) ; 
        return ans ; 
    }
}; 


int main() {
    init_code() ; 
    Solution sol ; 

    
}


// using a for loop
class Solution
{

private :

    void getSubSetSums( int idx , vector<int> &arr, int N , 
        int &curr_sum , vector<int> &ans){

        ans.push_back(curr_sum ) ;

        for(int i= idx ; i<N ; i++ ){

            curr_sum += arr[i] ; // adding element to current sum

            getSubSetSums(i+1 , arr , N , curr_sum , ans ) ;

            curr_sum -= arr[i] ; // remove the element from current sum 

        } 
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans ;
        int curr_sum = 0 ; 
        getSubSetSums(0 , arr, N , curr_sum , ans ) ; 
        sort(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};