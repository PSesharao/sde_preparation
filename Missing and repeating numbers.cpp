/*

https://www.interviewbit.com/problems/repeat-and-missing-number-array/

https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

here the cyclic method does not work in finding the
duplicate number because , it is possible that
N = 6 and at sametime 6 also present in the array , 
if we had to look for nums[6] would throw array out of bound

Let x and y be the desired output elements.

Calculate the XOR of all the array elements.

xor1 = arr[0]^arr[1]^arr[2]…..arr[n-1]

XOR the result with all numbers from 1 to n

xor1 = xor1^1^2^…..^n

xor1 will have the result as (x^y), as others would get canceled. Since we are doing XOR, 
we know xor of 1 and 0, is only 1, so all the set bits in xor1, mean that the index bit is only set at x or y.

So we can take any set bit, in code we have taken the rightmost set bit, iterate over it, 
and divide the numbers into two hypothetical buckets.

If we check for numbers with that particular index bit set, we will get a set of numbers 
that belongs to the first bucket, also we will get another set of numbers belonging to the second bucket. 
The first bucket will be containing either x or y, similarly, the second bucket will also be containing 
either x or y. XOR of all elements in the first bucket will give X or Y, and XOR of all elements of the 
second bucket will give either X or Y since there will be double instances of every number in each bucket 
except the X or Y.

We just need to iterate again to check which one is X, and which one is y. Can be simply checked by 
linear iterations. 


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


pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
     
     int xor_res = 0 ; 
     // xor of all elements in array 
     for(int i=0 ; i<n ; i++)
        xor_res = xor_res^arr[i] ; 

     // xor of all the numbers in [1 , n ]
     for(int i=1 ; i<=n ; i++)
        xor_res = xor_res^i ;

     int set_bit_nums = 0 , unset_bit_nums = 0 ; 
     
     int right_most_set_bit_num = xor_res & (-xor_res) ;

     // all elements in array
     for(int i=0 ; i<n ; i++)
        if(right_most_set_bit_num & arr[i])
            set_bit_nums = set_bit_nums^arr[i] ;
        else 
            unset_bit_nums = unset_bit_nums^arr[i] ; 

     // all the numbers in [1 , n ]
     for(int i=1 ; i<=n ; i++)
        if(right_most_set_bit_num & i )
            set_bit_nums = set_bit_nums^i ;
        else 
            unset_bit_nums = unset_bit_nums^i ; 
     
     bool duplicate_check_set_nums = false ;
     for(int i=0 ; i<n; i++)
        if(set_bit_nums == arr[i])
        {
            duplicate_check_set_nums = true ; 
            break ; 
        }

     if(!duplicate_check_set_nums)
        return {set_bit_nums , unset_bit_nums } ;
     return {unset_bit_nums , set_bit_nums } ;    
}


int main() {
    init_code() ; 
   

}