/*

https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

The main idea is to observe the prefix xor of the array. , prefix xor at given index i
XOR of all elements of the original array starting 
from index 0 up to that index. In other words 
prefix_xor[i] = XOR(a[0], a[1], a[2],……,a[i])

P = xor(a[0], a[1], a[2],……, a[q], a[q+1],….., a[p])
Q = xor(a[0], a[1], a[2],……, a[q])

Therefore,
P^Q = xor(a[q+1],….., a[p]) = M   



similarly let's say that 

previos_prefix_xor ^ current_prefix_xor = k 

then 

previos_prefix_xor = current_prefix_xor ^ k 

At anygiven index if we find the count of such previos_prefix_xor , 
we can add up that count to the counter 

Let's take [4 2 2 6 4 ] , k = 6 

current_prefix_xor = xor(4 ,2 ,2 , 6) 

previous_prefix_xor = xor(4 ,2 ,2 , 6)  ^ 6 = 4 

and previous_prefix_xor = 4 

We have two counts for previous_prefix_xor i.e [{4} , {4 , 2 ,2 }]

resulting us to give two sub arrays [{4 ,2 ,2 , 6} , {2 ,2 , 6}] whose xor is 6

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


int subarraysXor(vector<int> &arr, int x)
{
    int N = arr.size() ;
    int subArrayCount = 0 ; 
    int current_prefix_xor = 0 ; 
    unordered_map<int , int> map ; 
    for(int i=0 ; i<N ; i++){
        current_prefix_xor = current_prefix_xor ^ arr[i] ; 

        if(current_prefix_xor == x)
            subArrayCount ++ ; 
        int previous_prefix_xor = current_prefix_xor ^ x ; 
        if(map.count(previous_prefix_xor)>0 ) {
            subArrayCount += map[previous_prefix_xor] ;
        }

        if(map.count(current_prefix_xor) >0 )
            map[current_prefix_xor] ++ ; 
        else
            map[current_prefix_xor] = 1 ; 
    }
    return subArrayCount ; 
}


int main() {
    init_code() ; 
   

    
}