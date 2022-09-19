/*

https://leetcode.com/problems/reverse-linked-list/


Node *reverseList(Node * head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *curr = head , *next ,*revHead=NULL;
    while(curr){
        next = curr->next;
        curr->next = revHead;
        revHead = curr;
        curr = next;
    }
    return revHead;
}


Node *reverseListRec(Node * head)
{
    if(head == NULL || head->next == NULL)
        return head;
    // Let's take 1->2->3->4->5->N
    // recursive call is on 2->3->4->5->N
    // We'll assume 5->4->3->2-N
    Node *recHead = reverseListRec(head->next);
    // At this point we have to append 1 to 2's next
    
    Node *last = recHead;
    while(last->next)
        last = last->next;
    
    // now last is pointing to 2, make it's next as 1 , which is head
    last->next = head;
    //and we should make 1's next to null now
    head->next = NULL;
    return recHead; 

}



class Pair {
    public :
        
            Node *head;
            Node *tail;
};

Pair reverseLL_2(Node *head) {
    if(head == NULL || head -> next == NULL) {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head -> next);

    smallAns.tail -> next = head;
    head -> next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node* reverseLL_Better(Node *head) {
    return reverseLL_2(head).head;
}





Node *reverseListRec(Node * head)
{
    if(head == NULL || head->next == NULL)
        return head;
    // Let's take 1->2->3->4->5->N
    // recursive call is on 2->3->4->5->N
    // We'll assume 5->4->3->2-N
    Node *recHead = reverseListRec(head->next);
    // At this point we have to append 1 to 2's next
    head->next->next = head;

    //and we should make 1's next to null now
    head->next = NULL;
    return recHead; 

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL ) 
            return head ; 
        ListNode* reverse_head =  reverseList(head -> next ) ; 
        head->next->next = head ; 
        head->next = NULL ; 
        return reverse_head ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}