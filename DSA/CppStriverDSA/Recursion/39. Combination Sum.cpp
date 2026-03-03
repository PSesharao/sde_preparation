/*

https://leetcode.com/problems/combination-sum/

Similar case of unbounded knapsack

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

// If the question asked is like only one number can be picked only once,we shall go for the bounded knapsack approach.
// Bounded knapsack 

class Solution {
  public:
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
        findCombination(ind + 1 , target - arr[ind], arr, ans, ds);  // ind +1 makes it bounded 
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

}
public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};


int main() {
    init_code() ; 
    vector<int> arr = {1 , 3 ,2 , 4   } ; 
    Solution sol ; 
    vector < vector < int >>  ans = sol.combinationSum(arr , 5 ) ;  
    for(auto v : ans ){
        for(auto e : v )
            cout << e << " " ;
        cout << endl ; 
    }
    return 0 ; 
}

// We can solve the same question using a for loop also , 
// i.e for each element while iterating we will be giving 2 options put it in the solution or ignore 

class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, 
        vector < vector < int >> & ans, vector < int > & ds) {


        if(target == 0 ){
            ans.push_back(ds) ; 
            return ; // as the target is already reached , 
            // we can return from here as there is no need to check further
        }


        for( int i=ind ; i<arr.size() ; i++  ){
			
			// since the array is sorted instead of this , we can use 
			/*
				if( target-arr[i] < 0 )
					break ; 
			*/
			// This will avoid the further checks also in the loop for greater elements
            if( target-arr[i] >= 0 ){
                ds.push_back( arr[i] ) ;  // pick
                findCombination( i+1 , target-arr[i] , arr , ans , ds ) ; 
                /* The important thing here is that , we have pass 'i+1' , not 'ind+1'
                   because it work only till the left most recursion tree calls
				   If the input array does not contain duplicates, we can simplify the algorithm by removing the idx parameter and the check for duplicates , In that case, we can simply use i+1 as the starting index for each recursive call.
				   
					for (; i < candidates.size() && candidates[i] <= target; i++) {
						cur.push_back(candidates[i]);
						backtrack(res, cur, candidates, target - candidates[i], i+1); 
						cur.pop_back(); 
					}
				   
				*/
				
				
                ds.pop_back() ;   // not pick 
            }

        }

}


public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      sort(candidates.begin() , candidates.end()) ; 
      /* 
      
            If the input array does not contain duplicates, sorting the array is not 
            strictly necessary for the solution to work correctly. However, 
            sorting the array can improve the efficiency of the algorithm.

            The reason for this is that sorting the array allows us to stop iterating 
            over candidates earlier if their value exceeds the remaining target sum, s
            ince we know that all subsequent candidates will have an even greater value. 
            This can save a lot of unnecessary recursive calls and reduce the overall 
            runtime of the algorithm.

            In addition, sorting the array ensures that the resulting combinations are in 
            non-descending order, which can be a desirable property depending on the problem 
            requirements.

      */
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};




// Unbounded knapsack 

class Solution {
  public:
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
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);
}


public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};

// using for loop 

class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, 
        vector < vector < int >> & ans, vector < int > & ds) {


        if(target == 0 ){
            ans.push_back(ds) ; 
            return ; 
            
        }


        for( int i=ind ; i<arr.size() ; i++  ){

            if( target-arr[i] >= 0 ){
                ds.push_back( arr[i] ) ;  // pick
                findCombination( i , target-arr[i] , arr , ans , ds ) ; // unbounded case
               
                ds.pop_back() ;   // not pick 
            }

        }

}


public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      sort(candidates.begin() , candidates.end()) ; 
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};

int main() {
    init_code() ; 
    Solution sol ; 
	
}