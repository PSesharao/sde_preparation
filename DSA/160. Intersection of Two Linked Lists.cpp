/*

https://leetcode.com/problems/intersection-of-two-linked-lists/

Intuition : 

If both lists are of same length and intersecting , 
the intersection point is equidistant from the both heads

// Another approach

Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. If anyone becomes null, point them to the head of the 
opposite lists and continue iterating until they collide.

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

private :
int length(ListNode *head ) {
    int len = 0 ; 
    for(ListNode* cur_ptr = head ; cur_ptr!=nullptr ; cur_ptr = cur_ptr->next  )
        len++ ;
    
    return len ;
}

ListNode * skip(ListNode *head , int k ){
    for(int i=1 ; i<=k ; i++ )
        head = head->next ; 
    return head ; 
}

// here both h1 and h2 will be of same length 
ListNode * getIntersectionPoint(ListNode * h1 , ListNode * h2 ) {

    if(h1 == nullptr || h2== nullptr )
        return nullptr ; 

    if( h1 == h2 )
        return h1 ; 

    return getIntersectionPoint(h1->next , h2->next ) ;

}

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * intersecting_node = nullptr ; 

        int length1 = length(headA ) ; 
        int length2 = length(headB ) ; 

        if(length1 == length2 )
            intersecting_node = getIntersectionPoint(headA , headB ) ; 
        else if(length1 > length2 ){
            int skip_nodes = length1 - length2 ; 
            ListNode *skipped_headA = skip(headA , skip_nodes ) ; 
            intersecting_node = getIntersectionPoint(skipped_headA , headB ) ; 
        }else{
            int skip_nodes = length2 - length1 ; 
            ListNode *skipped_headB = skip(headB , skip_nodes ) ; 
            intersecting_node = getIntersectionPoint(headA ,skipped_headB  ) ; 
        }
        return intersecting_node ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}