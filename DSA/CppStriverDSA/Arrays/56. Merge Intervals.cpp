/*

https://leetcode.com/problems/merge-intervals/

Intuition: Since we have sorted the intervals, the intervals which will be merging 
are bound to be adjacent. We kept on merging simultaneously as we were traversing 
through the array and when the element was non-overlapping we simply inserted the 
element in our data structure.

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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ; 
        int N = intervals.size() ; 
        if( N == 0 )
            return ans ; 
        // By default the intervals will be sorted based on the first index 
        // of the inscribed arrays.i.e starting time . 
        sort(intervals.begin() , intervals.end()) ; 
        int merge_start = intervals[0][0] ; 
        int merge_end = intervals[0][1] ; 

        for(int i=1 ; i<N ; i++ )
        {
            int current_start = intervals[i][0] ;
            int current_end = intervals[i][1] ;

            // The overlapping condition 
            if(current_start <= merge_end )
                merge_end = max(merge_end , current_end) ; 

            else
            {
                vector<int> merged_interval(2) ;
                merged_interval[0] = merge_start ;
                merged_interval[1] = merge_end ;
                ans.push_back(merged_interval) ;
                merge_start = current_start ;
                merge_end = current_end ; 
            }
        }

        vector<int> merged_interval(2) ;
        merged_interval[0] = merge_start ;
        merged_interval[1] = merge_end ;
        ans.push_back(merged_interval) ;

        return ans ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}