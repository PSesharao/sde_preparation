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

Approach: Prefix xor
---------------------------
Let us say that ‘xorr’ is the running xor from the beginning (prefix xor) , let us say if it comprises of two parts the ‘k’ that we are looking for and the other part ‘y’ .
So the count is dependent on no of ‘y’ divisions at a given point of time.
For example 
Let's take [4 2 2 6 4 ] , k = 6
xorr = [4 2 2 6] currently , 
then y = xorr ^ k 
=> [4 2 2 6] ^ 6
=> 4
y =4, if we see that for the span of xorr [4 , 2 ,2 , 6 ]
there can be two possible divisions for y =4 , they are 
i)	y = 4 , k = [2 2 6]
ii)	y = [4 2 2] , k = 6 

Algorithm :
We will maintain a running xorr , and a hash map for maintaining the frequencies of every prefix xor (running xorr)

First check if xorr it self equals to k , If so increase the count by 1 , y for this case would be 0 

We will need to find y using y = xorr ^ k , check for its frequency in the map , and add it to count.

update the frequncy map for running xorr .

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


// Brute force 
We'll need to consider the xor of every possible subarray , and from there we need to count only those which can fit into our answer.

for(int i=0 ; i<n ; i++ )
		for(int j=i ; j<n ; j++)  or for(int j=0 ; j<=i ; j++)
			
		
		

int subarraysXor(vector<int> &arr, int k){
    
    int xorr = 0 ; 
    int count = 0 ;
    unordered_map<int , int > map ; 
    for(auto num : arr ){

        xorr = xorr xor num ; 

        if(xorr == k )
            count ++ ; 

        int y = xorr xor k ; 

        if(map.count(y) > 0 )
            count += map[y] ; 

        if(map.count(xorr) > 0 )
            map[xorr] ++ ; 
        else
            map[xorr] = 1 ; 

    }

    return count ;
}



int main() {
    init_code() ; 
   

    
}