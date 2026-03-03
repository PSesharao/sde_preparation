/*

https://leetcode.com/problems/longest-consecutive-sequence/



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


// Brute force


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0 ; 

        int max_len = 1 ; // at worst there is no consecutive at all

        // If the question is based on sorting
        sort( nums.begin() , nums.end() ) ; 

        int curr_len = 1 , prev= nums[0] ;

        for(int i=1 ; i<nums.size() ; i++ ){

            int curr = nums[i] ; 
            if(curr == prev +1 ) // i)  prev and curr elements are consecutive
                curr_len ++ ;
            else if(curr != prev ){  // ii) prev and curr are non-consecutive and different
                max_len = max(curr_len , max_len ) ; 
                curr_len = 1 ; // re starting from 1 here
            }else if(curr == prev ) // iii) prev and curr are non-consecutive but equal.
                continue ; 

            prev = curr ; 

        }

        // To cover for the last element
        max_len = max(curr_len , max_len ) ; 
        return max_len ; 

    }
};




#define INF 1000000007
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0 ; 
        unordered_set<int> set ; 
        for(int num : nums ){
            set.insert(num) ; 
        }
        for(int num : nums ){
            // This will decide whether num is starting of the seq or not
            if(set.count(num-1)>0)
                continue ;
            else{
                int temp = num ; 
                int cur_len = 1 ;
                while(true){
                    if(set.count(temp+1)){
                        temp++ ;
                        cur_len ++ ; 
                    }else
                        break ;     
                }
                max_len = max(max_len , cur_len ) ;
            }
        }
        return max_len ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}