/*

https://leetcode.com/problems/majority-element-ii/

Extended Boyer Moore’s Voting Algorithm

We are sure that there will be a max of 2 elements which occurs > N/3 times 

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
#define MAX (int) 1e9+7

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
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size() ; 
        int maj1 , maj2 , count1 , count2 ; 
        maj1 = maj2 = MAX ; 
        count1 = count2 = 0 ; 
        for(int num : nums ){
			//  we should use else if only 
                // as at a time we should either initialize maj1 or maj2
            if(num == maj1 )
                count1++ ; 
            else if(num == maj2 )
                count2++ ;
            else if(count1 == 0 )
            {
                maj1 = num ; 
                count1 = 1 ;
            }else if (count2 == 0)
            {
                maj2 = num ; 
                count2 = 1 ;
            }else{
				// If it is minority element , just decrementing 
                // to cancel the counts
                count1 -- ; 
                count2 -- ; 
            }
        }
		
		
        // since there may or may not the majority elements
		
        int freq1 =0 , freq2 = 0 ; 
        for(int num : nums ){
            if(num == maj1 )
                freq1++ ;
            else if(num == maj2 )
                freq2++ ;
        }

        if((freq1 > N/3) and (freq2 > N/3) ) {
            return {maj1 , maj2 } ; 
        }else if((freq1 > N/3)){
            return {maj1 } ; 
        }else if((freq2 > N/3)){
            return {maj2 } ; 
        }else
            return {} ; 
        
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}