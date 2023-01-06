/*

https://leetcode.com/problems/rotate-list/description/

head = [1,2,3,4,5] k = 2000000000

If we see a brute force approach, it will take O(5*2000000000) which is not a good 
time complexity when we can optimize it.

We can see that for every k which is multiple of the length of the list, we get back 
the original list. Try to operate brute force on any linked list for k as multiple of 
the length of the list.

This gives us a hint that for k greater than the length of the list, we have to rotate 
the list for k%length of the list. This reduces our time complexity.

Steps to the algorithm:-

Calculate the length of the list.
Connect the last node to the first node, converting it to a circular linked list.
Iterate to cut the link of the last node and start a node of k%length of the list rotated 
list.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr||head->next == nullptr||k == 0) 
            return head; 

        ListNode* curr_node = head , *prev_node = nullptr ; 
        int length = 0 ; 

        while(curr_node != nullptr ){
            length ++ ; 
            prev_node = curr_node ; 
            curr_node = curr_node->next ; 
        }

        // Making it a circular linked list 
        prev_node->next = head ; 
        k = k%length; //when k is more than length of list
        int end  = length-k; //to get end of the list

        curr_node = head ; 
        

        int i = 0 ; 
        while(i < end ){
            i++ ; 
            curr_node = curr_node->next ;  
        }

        head = curr_node->next ; 
        curr_node->next = nullptr ; 

        return head ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}