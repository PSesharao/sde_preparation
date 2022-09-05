/*

https://leetcode.com/problems/sort-colors/

next_zero -> represents the index where the next zero should be placed 

next_two -> represents the index where the next two should be placed 

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
    void sortColors(vector<int>& nums) {
        int N = nums.size() ; 
        int next_zero = 0 , next_two =N-1 ;

        for(int curr_pos=0 ; curr_pos<=next_two ; curr_pos++ )
        {
            if(nums[curr_pos] == 0 )
            {
                swap(nums[curr_pos] , nums[next_zero]) ; 
                next_zero++ ; 
            }else if(nums[curr_pos] == 2){
                swap(nums[curr_pos] , nums[next_two]) ; 
                next_two -- ; 
                curr_pos -- ; // Since we dont know what is already there in next_two position 
                // that's why we need to re visit that curr_pos again 
            }
        }
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}