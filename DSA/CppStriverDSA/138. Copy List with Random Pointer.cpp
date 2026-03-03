/*

https://leetcode.com/problems/copy-list-with-random-pointer/


Approach 1 (Using Extra Space): The idea to solve this problem is: 

First create a single linked list with only the 'next' pointer and 
use a mapping to map the new nodes to their corresponding nodes in 
the given linked list. Now use this mapping to point the arbitrary 
node from any node in the newly created list. 



Approach 2 (Using Constant Extra Space):  The idea to solve is using constant 
extra space is:

Create duplicate of a node and insert it in between that node and the node just 
next to it. 

Now for a node X its duplicate will be X->next and the arbitrary pointer of the 
duplicate will point to X->arbit->next [as that is the duplicate of X->arbit]

Follow the steps mentioned below to implement the idea:

Create the copy of node 1 and insert it between node 1 and node 2 in the original 
Linked List, create the copy of node 2 and insert it between 2nd and 3rd node and so on. 
Add the copy of N after the Nth node 
Now copy the arbitrary link in this fashion:
original->next->arbitrary = original->arbitrary->next 

Now restore the original and copy linked lists in this fashion in a single loop. 
original->next = original->next->next;
copy->next = copy->next->next;

Make sure that the last element of original->next is NULL. 

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


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr )
            return head ; 
        Node * curr_node = head ; 

        // Inserting copynodes b/w original nodes
        while(curr_node!= nullptr ){
            Node * next_node = curr_node->next ; 
            Node * copy_node = new Node(curr_node->val ) ; 
            curr_node->next = copy_node ; 
            copy_node->next = next_node ; 
            curr_node = next_node ; 
        }

        // Pointing the random pointers
        Node * orginal_node = head ; 
        while(orginal_node != nullptr ){
            Node * copy_node = orginal_node-> next ; 
            // for a node X its duplicate will be X->next and the arbitrary pointer of the 
            // duplicate will point to X->arbit->next [as that is the duplicate of X->arbit]
            copy_node->random = orginal_node->random ? 
            orginal_node->random->next : orginal_node->random ; 
            orginal_node = orginal_node->next->next ; 
        }

        // restoring and dividing cloned and original lists
        orginal_node = head ; 
        Node *clone = head->next , *copy_node ; 
        copy_node = clone ; 
        while(orginal_node != nullptr ){
            
            orginal_node-> next = orginal_node->next->next ; 
            // because the last of copy next will be null 
            copy_node->next = copy_node->next ? 
            copy_node->next->next : copy_node->next ; 
            orginal_node = orginal_node->next ; 
            copy_node = copy_node->next ; 
        }

        return clone ; 
    }
};



int main() {
    init_code() ; 
    Solution sol ; 

    
}