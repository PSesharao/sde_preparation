/*

https://leetcode.com/problems/combination-sum-ii/

one of the approach is to use of bounded knapsack and remove duplicates


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

// Need to remove duplicates in this approach 
class Solution {

void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
            if (target == 0) {
            ans.push_back(ds);
        }
            return;
      }
      // pick up the element 
      if (target - arr[ind] >= 0 ) {
            ds.push_back(arr[ind]);
            findCombination(ind+1 , target - arr[ind], arr, ans, ds);
            ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};


// This is similar to 90. Subsets II leetcode question 

class Solution {
private : 
void findCombination2(int ind , int target , vector<int>& candidates , vector < int > &ds , 
    vector < vector < int >> & ans ){

    if(target == 0 ) {
        ans.push_back(ds);
        return ; 
    }

    for(int i = ind ; i<candidates.size() ; i++ ){
        if((i!=ind) and (candidates[i]==candidates[i-1])) continue ; 
        if(target - candidates[i] < 0 )
            break ; 
        ds.push_back(candidates[i] ) ;
        findCombination2(i+1 , target - candidates[i] , candidates , ds , ans )  ; 
        ds.pop_back() ; 
    }
} 

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()) ; 
        vector < vector < int >> ans;
        vector < int > ds; 
        findCombination2(0 , target , candidates ,ds , ans ) ; 
        return ans;
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}