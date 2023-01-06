/*

https://leetcode.com/problems/delete-node-in-a-linked-list/

It is basically deleting the immediate next node after 
we got the value in it copied back to the node given to us .

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
    void deleteNode(ListNode* node) {
        ListNode* next_node = node->next ; 
        node->val = next_node->val ; 
        node->next = next_node->next ; 
        next_node->next = nullptr ; 
        delete next_node ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}