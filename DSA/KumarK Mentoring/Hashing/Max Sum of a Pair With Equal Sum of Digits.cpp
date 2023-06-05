/*

https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

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

private : 
    int findDigitSum(int num ){

        int digitSum = 0 ; 
        while(num !=0 ){
            int digit =num %10 ; 
            digitSum += digit ; 
            num/=10 ; 
        }
        return digitSum ; 
    }

public:
    int maximumSum(vector<int>& nums) {
        int max_sum = -1 ;
        unordered_map<int , int > digitsum_map ; 

        for(auto num : nums ){

            int digitSum = findDigitSum(num) ; 
            if(digitsum_map.count(digitSum) > 0 ){
                int prev_num = digitsum_map[digitSum] ; 
                max_sum = max({max_sum , num + prev_num }) ;

                if(num > prev_num )
                    digitsum_map[digitSum] = num ;  
            }else 
                digitsum_map[digitSum] = num ;  
        }
        return max_sum ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}