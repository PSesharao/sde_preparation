/*

https://leetcode.com/problems/middle-of-the-linked-list/

If there are two middle nodes, to return the first middle node 
initialize 
fast_ptr = head ->next ; 


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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow_ptr = head , *fast_ptr = head ;
        while(fast_ptr!= NULL && fast_ptr->next != NULL ) {
            slow_ptr = slow_ptr->next ; 
            fast_ptr = fast_ptr->next->next  ; 
        }
        return slow_ptr ;  
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}