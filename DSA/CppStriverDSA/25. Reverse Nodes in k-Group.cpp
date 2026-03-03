/*

https://leetcode.com/problems/reverse-nodes-in-k-group/

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
class HeadTail{
    public :
    ListNode* head ;
    ListNode* tail ;
     HeadTail(ListNode* head , ListNode* tail ) {
        this->head = head ; 
        this->tail = tail ; 
     }
};

class Solution {

private : 

HeadTail reverseList(ListNode* head ) {

    ListNode* reverse_head = nullptr ; 
    ListNode* curr_ptr = head , *next_ptr ; 
    while( curr_ptr!=nullptr ){
        next_ptr = curr_ptr->next ; 
        curr_ptr->next = reverse_head ; 
        reverse_head = curr_ptr ; 
        curr_ptr = next_ptr ; 
    }

    HeadTail head_tail(reverse_head , head ) ; 
    return head_tail ; 
}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* first_node_of_k_slice , *curr_ptr ; 
        curr_ptr = head ; 
        int k_counter = 1 ; 

        first_node_of_k_slice = curr_ptr ; 

        while((curr_ptr!=nullptr) and (k_counter<k )){
            k_counter++ ; 
            curr_ptr = curr_ptr->next ; 
        }

        // Means one complete k slice is found 
        if( curr_ptr!=nullptr ){
            ListNode* next_node = curr_ptr->next ; 
            curr_ptr->next = nullptr ; 
            HeadTail head_tail_of_k_slice = reverseList( first_node_of_k_slice ) ; 
            head = head_tail_of_k_slice.head ; 
            ListNode* recursive_head = reverseKGroup(next_node , k ) ; 
            head_tail_of_k_slice.tail->next = recursive_head ; 
        }

         // Means complete k slice is not found 

        // If we need to reverse the last non k slice
        /*else{
            HeadTail head_tail_of_non_k_slice = reverseList( first_node_of_k_slice ) ; 
            head = head_tail_of_non_k_slice.head ;
        }*/

        // If we need not to reverse the last non k slice
        else{
            
            head = first_node_of_k_slice ;
        }        
        return head ; 

    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}