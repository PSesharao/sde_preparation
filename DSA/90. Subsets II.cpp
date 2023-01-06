/*

https://leetcode.com/problems/subsets-ii/

Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in 
another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. 
Auxiliary space is O(n)  if n is the depth of the recursion tree.


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

// Method 1 to gererate all the subsets

// class Solution {

// private :

// void subsets(int index , int N , vector<int>& nums , 
//     vector<int>& subset , vector<vector<int>> & ans ){

//     if(index == N )
//     {
//         ans.emplace_back(subset ) ;
//         return ;  
//     }

//     subsets(index +1 , N , nums , subset , ans ) ;
//     subset.emplace_back(nums[index]) ;
//     subsets(index +1 , N , nums , subset , ans ) ;   
// }

// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int N = nums.size() ; 
//         vector<vector<int>>  ans ;
//         vector<int> subset ; 
//         subsets(0 , N , nums , subset , ans ) ;
//         for(int i=0 ; i<ans.size() ; i++ ){
//             for(int j=0 ; j<ans[i].size() ; j++ )
//                 cout << ans[i][j] << " " ; 
//             cout << endl ; 
//         }
//     }
// };


// Method 2 to generate all subsets 

/*
    passing the subset array by reference 
    For each index you can generate all possible 
    subsets involving that 

    here at each level , we can have subsets of increasing by level of recursion 

class Solution {

private :

void subsets(int index , int N , vector<int>& nums , 
    vector<int>& subset , vector<vector<int>> & ans ){

    ans.emplace_back(subset ) ;

    for(int i = index ; i<N ; i++ ){
        // It will generate all subsets that starts with index
        subset.emplace_back(nums[i] ) ;  
        subsets( i+1 , N , nums , subset , ans ) ; // It should be i + 1 not index +1 
        // We are removing this to start generating all subsets that starts with next index 
        // in the loop 
        subset.pop_back() ;  
    }

}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int N = nums.size() ; 
        vector<vector<int>>  ans ;
        vector<int> subset ; 
        subsets(0 , N , nums , subset , ans ) ;
        for(int i=0 ; i<ans.size() ; i++ ){
            for(int j=0 ; j<ans[i].size() ; j++ )
                cout << ans[i][j] << " " ; 
            cout << endl ; 
        }
    }
};

*/

class Solution {
   private:
      void findSubsets(int ind, vector < int > & nums, vector < int > & subset, vector < vector < int >> & ans) {
         // This would take O(n) since this is a deep copy and we are 
         // inserting an vector into another vector . 
         ans.push_back(subset);
         for (int i = ind; i < nums.size(); i++) {
            // to pass the duplicates since array is sorted 
            if (i != ind && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            findSubsets(i + 1, nums, subset, ans);
            subset.pop_back();
         }
      }
   public:
      vector < vector < int >> subsetsWithDup(vector < int > & nums) {
         vector < vector < int >> ans;
         vector < int > subset;
         sort(nums.begin(), nums.end());
         findSubsets(0, nums, subset, ans);
         return ans;
      }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}