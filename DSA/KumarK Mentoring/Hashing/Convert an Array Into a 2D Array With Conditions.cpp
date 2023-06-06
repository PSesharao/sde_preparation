/*

https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int , int > freq_map ; 
        for(int num : nums )
            freq_map[num] ++ ; 

        vector<vector<int>> result ; 

        while(true) {
            vector<int> row ; 
            for(auto el : freq_map ){
                int num = el.first ; 
                int freq = el.second ; 

                if(freq  >= 1){
                    row.push_back(num) ; 
                    freq_map[num] -- ;
                }

                 
            }

            if(row.size() > 0 )
                result.push_back(row) ; 
            else 
                break ; 
        }

        return result ; 

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}