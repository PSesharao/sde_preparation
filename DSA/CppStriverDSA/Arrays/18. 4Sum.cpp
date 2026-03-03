/*

https://leetcode.com/problems/4sum/

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
    vector<vector<int>> fourSum(vector<int>& num, int target) {
         vector<vector<int> > res;
        int n = num.size(); 
        if (n <= 3)
            return res;
        
        sort(num.begin(),num.end());
    
        for (int first = 0; first < n-3; first++) {
        
            for (int second = first + 1; second < n-2; second++) {
            
                ll target_2 = 0LL + target - num[first] - num[second];
            
                int third = second + 1;
                int fourth = n - 1;
            
                while(third < fourth) {
                
                    ll two_sum = 0LL + num[third] + num[fourth];
                
                    if (two_sum < target_2) third++;
                
                    else if (two_sum > target_2) fourth--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[first];
                        quadruplet[1] = num[second];
                        quadruplet[2] = num[third];
                        quadruplet[3] = num[fourth];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (third < fourth && num[third] == quadruplet[2]) ++third;
                    
                        // Processing the duplicates of number 4
                        while (third < fourth && num[fourth] == quadruplet[3]) --fourth;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(second + 1 < n-2 && num[second + 1] == num[second]) ++second;
            }
        
            // Processing the duplicates of number 1
            while (first + 1 < n-3 && num[first + 1] == num[first]) ++first;
        
        }
    
        return res;
    }
};





int main() {
    init_code() ; 
    Solution sol ; 

    
}