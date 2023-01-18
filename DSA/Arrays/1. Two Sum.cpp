/*

https://leetcode.com/problems/two-sum/



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
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > map ; 
        for(int i=0 ; i<nums.size() ; i++){
            int num_to_be_searched = target - nums[i] ; 
            if(map.count(num_to_be_searched) >0 ) {
                int j = map[num_to_be_searched] ; 
                if(i<j) 
                    return {i , j } ;
                else
                    return {j , i} ;
            }else{
                map[nums[i]] = i ;
            } 
        }
        return {} ;
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}