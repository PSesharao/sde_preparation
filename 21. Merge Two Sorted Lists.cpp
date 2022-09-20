/*

https://leetcode.com/problems/merge-two-sorted-lists/

// Iteration approach 
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
   if (head1 == NULL || head2 == NULL)
    {
        if(head1 == NULL)
            return head2;
        else 
            return head1;
    }
    Node *finalHead = NULL, *finalTail = NULL,*node;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (finalTail == NULL)
            {
                finalHead = head1;
                finalTail = head1;
                head1 = head1->next;
            }
            else
            {  
                finalTail->next = head1;
                finalTail = finalTail->next;
                head1 = head1->next;
            }
        }
        else
        {
            if (finalTail == NULL)
            {
                finalHead = head2;
                finalTail = head2;
                head2 = head2->next;
            }
            else
            {
                finalTail->next = head2;
                finalTail = finalTail->next;
                head2 = head2->next;
            }
        }
    }
    while(head1){
        finalTail->next = head1;
        finalTail = finalTail->next;
        head1 = head1->next;
    }
    while(head2){
         finalTail->next = head2;
         finalTail = finalTail->next;
         head2 = head2->next;
    }
    return finalHead;
}


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