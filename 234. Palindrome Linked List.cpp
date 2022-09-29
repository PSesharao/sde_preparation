/*

https://leetcode.com/problems/palindrome-linked-list/

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

private : 
ListNode* reverseList(ListNode* head ) {
    if(head == nullptr || head->next == nullptr )
        return head ; 

    ListNode* reverse_head = reverseList(head->next ) ;
    head->next->next = head ; 
    head->next = nullptr ; 
    return reverse_head ;  
}

public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr )
            return true ; 
        ListNode* slow_ptr , *fast_ptr ;
        slow_ptr = head ; 
        fast_ptr = head->next ; 
        while(fast_ptr !=nullptr and fast_ptr->next != nullptr )  
        {
            slow_ptr = slow_ptr->next ; 
            fast_ptr = fast_ptr->next->next ; 
        }
        ListNode* second_half_head = slow_ptr->next ; 
        ListNode* second_half_reverse_head = reverseList(second_half_head ) ;
        ListNode* first_half_ptr = head ; 
        ListNode* second_half_ptr = second_half_reverse_head ; 
        while((first_half_ptr!=nullptr) and (second_half_ptr!=nullptr) ){
            if(first_half_ptr->val != second_half_ptr->val )
                return false ; 
            first_half_ptr = first_half_ptr->next ; 
            second_half_ptr = second_half_ptr->next ; 
        }
        return true ;  
    }
};

int main() {
    init_code() ; 
    Solution sol ; 
}