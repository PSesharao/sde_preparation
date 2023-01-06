/*

https://leetcode.com/problems/linked-list-cycle-ii/


Approach:


Initially take two pointers, fast and slow. The fast pointer takes two steps ahead 
while the slow pointer will take a single step ahead for each iteration.
We know that if a cycle exists, fast and slow pointers will collide.
If the cycle does not exist, the fast pointer will move to NULL
Else, when both slow and fast pointer collides, it detects a cycle exists.
Take another pointer, say entry. Point to the very first of the linked list.
Move the slow and the entry pointer ahead by single steps until they collide. 
Once they collide we get the starting node of the linked list.
But why use another pointer, or xentry?

Let’s say a slow pointer covers the L2 distance from the starting node of the cycle 
until it collides with a fast pointer. L1 is the distance traveled by the entry pointer 
to the starting node of the cycle. So, in total, the slow pointer covers the L1+L2 distance. 
We know that a fast pointer covers some steps more than a slow pointer. Therefore, we can 
say that a fast pointer will surely cover the L1+L2 distance. Plus, a fast pointer will 
cover more steps which will accumulate to nC length where C is the length of the cycle 
and n is the number of turns. Thus, the fast pointer covers the total length of L1+L2+nC. 

We know that the fast pointer travels twice the slow pointer. So this makes the equation to

2(L1+L2) = L1+L2+nC. This makes the equation to

L1+L2 = nC. Moving L2 to the right side

L1 = nC-L2 and this shows why the entry pointer and the slow pointer would collide.

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

private :
ListNode * getTheCollisionPoint(ListNode *head){
    if(head == nullptr || head->next == nullptr )
        return nullptr ; 

    ListNode *slow_ptr = head , *fast_ptr = head ; 
    while(fast_ptr and fast_ptr->next ){
        slow_ptr = slow_ptr->next ; 
        fast_ptr = fast_ptr->next->next ; 
        if(fast_ptr == slow_ptr )
            return slow_ptr ; 
    }

    return nullptr ; 
}

public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * collision_point = getTheCollisionPoint(head) ;
        if(collision_point == nullptr )
            return nullptr ; 
        ListNode * entry_point = head ; 
        
        while(collision_point!=entry_point){
            collision_point = collision_point->next ; 
            entry_point = entry_point->next ; 
           
        }
        return collision_point ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}