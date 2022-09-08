/*

https://leetcode.com/problems/find-the-duplicate-number/

Intuition: Since there is a duplicate number, we can always say that 
cycle will be formed.

The slow pointer moves by one step and the fast pointer moves by 2 steps 
and there exists a cycle so the first collision is bound to happen.

Let’s assume the distance between the first element and the first collision is a. 
So slow pointer has traveled a distance while fast(since moving 2 steps at a time) 
has traveled 2a distance. For slow and a fast pointer to collide 2a-a=a should 
be multiple of the length of cycle, Now we place a fast pointer to start. 
Assume the distance between the start and duplicate to be x. So now the 
distance between slow and duplicate shows also be x, as seen from the diagram, 
and so now fast and slow pointer both should move by one step.

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
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0] ; 
        int fast = nums[0] ; 

        // do while because we are looking for 
        // first collision should atlesat move slow and fast once . 
        do{
            slow = nums[slow] ; 
            fast = nums[nums[fast]] ; 
        }while(slow != fast ) ; 

        // After the first collision we are 
        // resetting fast to start and fast now 
        // will move at the same pace as slow 

        fast =  nums[0] ; 
        
        // while loop because it can be possible that starting node 
        // it self is the duplicate 

        while(slow != fast ){
            slow = nums[slow] ; 
            fast = nums[fast] ; 
        }

        return slow ; 

    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}