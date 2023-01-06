/*

https://leetcode.com/problems/add-two-numbers/

If lists are given straightly , we need to perform reverse 
operation first , then the addition and finally consider
reversing the result

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
ListNode* reverseList(ListNode* list ) {
    if(list == nullptr || list->next == nullptr )
        return list ; 
    ListNode* rev_list = reverseList(list->next ) ;
    list->next->next = list ; 
    list->next = nullptr ; 
    return rev_list ; 
}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr ) 
            return l2 ;
        if(l2 == nullptr )
            return l1 ; 
        ListNode* sum_head , *sum_tail , *num1_ptr , *num2_ptr ; 
        sum_head = sum_tail = nullptr ; 
        num1_ptr = l1 ; //reverseList(l1) ; 
        num2_ptr = l2 ; //reverseList(l2) ; 
        int sum , digit , carry =0 ; 
        while(num1_ptr!=nullptr and num2_ptr!=nullptr ){
            sum = num1_ptr->val + num2_ptr->val + carry ; 

            // when single digited
            if(sum <10 ){
                digit = sum ; 
                carry = 0 ;
            }else{
                digit = sum%10 ; // taking unit's place (for 12 it is 2 )
                carry = sum/10 ; // taking other than unit's place (for 1 it is 2 )
            }

            ListNode * new_digit = new ListNode(digit ) ;
            if(sum_tail == nullptr ){
                sum_head = sum_tail = new_digit ; 
            }else{
                sum_tail->next = new_digit ; 
                sum_tail = new_digit ; 
            }

            num1_ptr = num1_ptr->next ; 
            num2_ptr = num2_ptr->next ;  
        }

        if( num1_ptr!=nullptr ){
            while(num1_ptr!=nullptr ){
                sum = num1_ptr->val + carry ; 
                if(sum <10 ){
                    digit = sum ; 
                    carry = 0 ;
                }else{
                    digit = sum%10 ; 
                    carry = sum/10 ; 
                }

                ListNode * new_digit = new ListNode(digit ) ;
                if(sum_tail == nullptr ){
                    sum_head = sum_tail = new_digit ; 
                }else{
                    sum_tail->next = new_digit ; 
                    sum_tail = new_digit ; 
                }

                num1_ptr = num1_ptr->next ; 
            }
        }

        if( num2_ptr!=nullptr ){
            while(num2_ptr!=nullptr ){
                sum = num2_ptr->val + carry ; 
                if(sum <10 ){
                    digit = sum ; 
                    carry = 0 ;
                }else{
                    digit = sum%10 ; 
                    carry = sum/10 ; 
                }

                ListNode * new_digit = new ListNode(digit ) ;
                if(sum_tail == nullptr ){
                    sum_head = sum_tail = new_digit ; 
                }else{
                    sum_tail->next = new_digit ; 
                    sum_tail = new_digit ; 
                }
                
                num2_ptr = num2_ptr->next ; 
            }
        }

        if( carry>0 ){
            ListNode * new_digit = new ListNode(carry ) ;
            if(sum_tail == nullptr ){
                sum_head = sum_tail = new_digit ; 
            }else{
                sum_tail->next = new_digit ; 
                sum_tail = new_digit ; 
            }
        }

        //sum_head = reverseList(sum_head) ; 
        //l1 = reverseList(l1) ; 
        //l2 = reverseList(l2) ; 
        return sum_head ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}