

//https://leetcode.com/problems/merge-two-sorted-lists/

// Iteration approach 

/* 

This solution uses a dummy node as the initial head of the merged list, and a pointer called "curr" to keep track of the current node. The while loop iterates through both input lists and compares the values of the current nodes. The smaller value is added to the merged list and the pointer is moved to the next node. When one of the input lists becomes empty, the remaining elements of the other list are added to the merged list. Finally, the dummy node is skipped and the actual head of the merged list is returned.

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy->next;
    }
};


// Without using the dummy node.

/*
This version uses a different approach to initialize the head of the merged list, by comparing the first elements of the input lists and choosing the one with the smaller value. Then it proceeds with the same logic as before
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* curr = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return head;
    }
};




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
    // Recursion approach
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL )
            return list2 ; 
        if(list2 == NULL )
            return list1 ; 

        if(list1->val < list2->val ){
            ListNode* mergedList_head = mergeTwoLists(list1->next , list2 ) ;
            list1->next = mergedList_head ; 
            return list1 ;  
        }else{
            ListNode* mergedList_head = mergeTwoLists(list1 , list2->next ) ;
            list2->next = mergedList_head ;
            return list2 ; 
        }
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}