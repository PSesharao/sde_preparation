/*

https://leetcode.com/problems/max-consecutive-ones/

We start traversing from the beginning of the array. Since we can encounter either a 
1 or 0 there can be two situations:-

If  the value at the current index is equal to 1 we increase the value of count by one. 
After updating  the count variable if it becomes more than the max_count  update the max_count.
If the value at the current index is equal to zero we make the variable count as 0 since 
there are no more consecutive ones.

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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ; 
        int max_consec_count = 0 ; 
        int current_consec_count = 0 ; 

        int i , j ; 
        i = 0 ; 
        while(i< n ){
            if(nums[i] == 1 ){
                current_consec_count =1 ; 
                j = i+1 ; 
                while(j< n ){
                    if(nums[j] == 1 ){
                        current_consec_count ++ ; 
                        j++ ; 
                    }else{
                         
                        max_consec_count = max(current_consec_count , max_consec_count ) ; 
                        break ;
                    }
                }
                i = j ;
            }
            else
                i++ ; 
            max_consec_count = max(current_consec_count , max_consec_count ) ; 
        }
        return max_consec_count ;
    }
};

// Better approach similar to kadane

class Solution {
  public:
    int findMaxConsecutiveOnes(vector < int > & nums) {
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          cnt++;
        } else {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

}