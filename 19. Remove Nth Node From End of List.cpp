/*

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

with two pointers in hand out of which one is at the n-th node from start, 
we can just advance both of them till the end simultaneously, once the faster 
reaches the end, the slower will stand at the n-th node from the end.

Time Complexity: O(N)

Space Complexity: O(1)

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL )
            return head ;

        int node_count = 1 ; 
        ListNode* nThNode_from_begin , *nThNode_from_last , *prevNode ;
        nThNode_from_begin = nThNode_from_last = head ;
        prevNode = NULL ; 
        while(node_count <n ){
            nThNode_from_begin = nThNode_from_begin->next ;
            node_count++ ; 
        }

        while(nThNode_from_begin ->next != NULL ){
            prevNode = nThNode_from_last ; 
            nThNode_from_begin = nThNode_from_begin->next ; 
            nThNode_from_last = nThNode_from_last->next ; 
        }

        if(prevNode == NULL ){
            // We are going to delete the first node it self 
            nThNode_from_last = head ; 
            head = head->next ; 
            nThNode_from_last->next = NULL ;
            delete nThNode_from_last ; 
            return head ; 
        }else{
            prevNode->next = nThNode_from_last->next ;
            nThNode_from_last->next = NULL ; 
            delete nThNode_from_last ; 
            return head ; 
        }

    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}