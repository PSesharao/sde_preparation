/*

https://leetcode.com/problems/linked-list-cycle/

Approach1:

We need to keep track of all the nodes we have visited till now so that once 
we visit the same node again we can say that a cycle is detected. The process 
is as follows:

Use a hash table for storing nodes. 
Start iterating through the lists.
If the current node is present in the hash table already, this indicates the 
cycle is present in the linked list and returns true.
Else move insert the node in the hash table and move ahead.
If we reach the end of the list, which is NULL, then we can say that the given 
list does not have a cycle in it and hence we return false

Time Complexity: O(N)

Reason: Entire list is iterated once.

Space Complexity: O(N)

Reason: All nodes present in the list are stored in a hash table.

Approach2 : 

We will use two pointers with different steps forward. The process is as follows:-

We will take two pointers, namely fast and slow. Fast pointer takes 2 steps ahead 
and slow pointer takes 2 points ahead.
Iterate through the list until the fast pointer is equal to NULL. This is 
because NULL indicates that there is no cycle present in the given list.
Cycle can be detected when fast and slow pointers collide.

Time Complexity: O(N)

Reason: In the worst case, all the nodes of the list are visited.

Space Complexity: O(1)

Reason: No extra data structure is used.


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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr )
            return false ; 

        ListNode *slow_ptr = head , *fast_ptr = head ; 
        while(fast_ptr and fast_ptr->next ){
            slow_ptr = slow_ptr->next ; 
            fast_ptr = fast_ptr->next->next ; 
            if(fast_ptr == slow_ptr )
                return true ; 
        }

        return false ;  
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}