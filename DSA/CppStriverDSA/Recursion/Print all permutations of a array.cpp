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


class Solution
{
    private : 
    void getPermutations( int N ,  vector<int> &arr , vector<vector<int>> &ans , 
        vector<int> &map , vector<int>& ds  ){

        if(ds.size() == N )
            ans.push_back(ds) ; 

        for(int i=0 ; i<N ; i++ ){
            if( map[i] == 0 ) {
                map[i] = 1 ; 
                ds.push_back(arr[i]) ;
                getPermutations(N , arr , ans , map , ds ) ;
                map[i] = 0 ;
                ds.pop_back() ;  
            }
        }

    }

    public:
    vector<vector<int>> find_permutations(vector<int> arr ){
        vector<vector<int>> ans ; 
        vector<int> ds ; 
        int N = arr.size() ;
        vector<int> map = {0 , 0 , 0 } ;
        getPermutations(N , arr , ans  , map , ds ) ; 
        return ans ; 
    }
};


int main() {
    init_code() ; 
    vector<int> arr = { 1 , 2 , 3} ; 
    Solution sol ; 
    vector<vector<int>>  ans = sol.find_permutations( arr  ) ; 
    for(auto v : ans ){
        for(auto e : v )
            cout << e << " " ;
        cout << endl ;
    }
    return 0 ; 
}


class Solution
{
    private : 
    void getPermutations(int pos , int N , vector<int> &arr , 
        vector<vector<int>> &ans ) {

        if(pos == N-1 ){
            ans.push_back( arr ) ;
            return ;  
        }

        for(int i=pos ; i<N ; i++ ){

            swap(arr[i] , arr[pos]) ;
            getPermutations(pos+1 , N , arr , ans ) ; // since here we are keeping 
                                                     // the position constant , pass pos+1 , not i+1 
            swap(arr[i] , arr[pos]) ;

        }

    }

    public:
    vector<vector<int>> find_permutations(vector<int> arr ){
        vector<vector<int>> ans ; 
        int N = arr.size() ;
        getPermutations(0 , N , arr , ans ) ; 
        return ans ; 
    }
};
