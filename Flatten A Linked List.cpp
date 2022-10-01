/*

https://www.codingninjas.com/codestudio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

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

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/

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
                head1 = head1->child;
            }
            else
            {  
                finalTail->child = head1;
                finalTail = finalTail->child;
                head1 = head1->child;
            }
        }
        else
        {
            if (finalTail == NULL)
            {
                finalHead = head2;
                finalTail = head2;
                head2 = head2->child;
            }
            else
            {
                finalTail->child = head2;
                finalTail = finalTail->child;
                head2 = head2->child;
            }
        }
    }
    while(head1){
        finalTail->child = head1;
        finalTail = finalTail->child;
        head1 = head1->child;
    }
    while(head2){
         finalTail->child = head2;
         finalTail = finalTail->child;
         head2 = head2->child;
    }
    return finalHead;
}

Node* mergeLists(Node* node1 , Node* node2){

    if(node1 == nullptr )
        return node2 ; 
    if(node2 == nullptr )
        return node1 ; 

    if(node1->data < node2->data )
    {
        node1->child = mergeLists(node1->child , node2 ) ;
        return node1 ;  
    }else{
        node2->child = mergeLists(node1 , node2->child ) ;
        return node2 ;  
    }
}

Node* flattenLinkedList(Node* head) 
{
    Node* flat_list = nullptr ; 
    // for(Node* curr_node = head ; curr_node!=nullptr ; curr_node=curr_node->next ){
    //     flat_list = mergeLists(flat_list , curr_node ) ; 
    // }
    Node* curr_node = head ;
    Node* next_node ; 
    while(curr_node!=nullptr ){
        next_node = curr_node->next  ; 
        curr_node->next  = nullptr ; 
        //flat_list = mergeLists(flat_list , curr_node ) ; 
        flat_list = mergeTwoSortedLinkedLists(flat_list , curr_node ) ;
        curr_node = next_node ; 
    }
    return flat_list ; 
}

// ANother solution 

Node *merge(Node *a,Node *b)
{
   if(a==NULL)
   {
       return b;
   }
   if(b==NULL)
   {
       return a;
   }
   Node *result;
   if(a->data < b->data)
   {
       result=a;
       result->child=merge(a->child,b);
   }
   else
   {
       result=b;
       result->child=merge(a,b->child);
   }
   result->next=NULL;
   return result;
}
Node* flattenLinkedList(Node* head) 
{
   // Write your code here
   if (head==NULL or head->next==NULL)
   {
       return head;
   }
   head->next=flattenLinkedList(head->next);
   Node *ans=merge(head,head->next);
   return ans;
   
}

int main() {
    init_code() ; 
    Solution sol ; 

    
}