/*

https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

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


typedef long long ll;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int> > res;
        int n = nums.size() ;
        if(n <=2 )
            return res ; 
        int target = 0 ; 
        sort(nums.begin(),nums.end());
        for (int first = 0; first < n-2; first++) {
            ll target2 = 0LL + target - nums[first] ; 

            int second = first+1 ; 
            int third = n-1 ; 

            while(second < third ){
                ll two_sum = 0LL + nums[second] + nums[third] ; 

                if(two_sum < target2 )
                    second ++ ; 
                else if(two_sum > target2 )
                    third -- ; 

                else{
                    vector<int> triplet(3 , 0 ) ;
                    triplet[0] = nums[first] ;  
                    triplet[1] = nums[second] ; 
                    triplet[2] = nums[third] ;  
                    res.push_back(triplet); 

                    // Processing the duplicates of number 2
                    while(second<third && nums[second] == triplet[1] ) ++second ; 

                    // Processing the duplicates of number 3
                    while(second<third && nums[third] == triplet[2] ) --third ;

                }
            }
            // Processing the duplicates of number 1
            while(first + 1 < n-2 && nums[first + 1] == nums[first]) ++first;
        }
        return res;
    }
};





int main() {
    init_code() ; 
    Solution sol ; 

    
}