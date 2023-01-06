/*

https://www.codingninjas.com/codestudio/problems/799400?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

Intuition: 
Each arrival time represents a new train 

dont think of this in terms of trains , think it in terms of time

arrival of a train is before departure. So i am sure if a train is areiving it will 
first arrive and then which ever train departs it has for sure arrived and hence is departing, 
this is the logic here.

At first we need to sort both the arrays. When the events will be sorted, 
it will be easy to track the count of trains that have arrived but not departed yet. 
Total platforms needed at one time can be found by taking the difference of arrivals 
and departures at that time and the maximum value of all times will be the final answer.


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


int calculateMinPatforms(int at[], int dt[], int n) {
    if(n == 0 )
        return 0 ; 
    sort(at , at+n ) ; 
    sort(dt , dt+n ) ; 
    int current_platform_count , min_platform_count ; 

    // We are alloting a platform to the first train always by default
    current_platform_count = min_platform_count = 1 ; 

    int current_arrival_ptr , current_depature_ptr ; 
    current_arrival_ptr = 1 ; 
    current_depature_ptr = 0 ; 

    while( (current_arrival_ptr<n) and (current_depature_ptr < n ) ) {
        // you need separate platform here for current_arrival_ptr train
        if(at[current_arrival_ptr] <= dt[current_depature_ptr] )
        {
            current_platform_count++ ; 
            min_platform_count = max(current_platform_count , min_platform_count ) ; 
            current_arrival_ptr++ ; 
        }else{  // you can vacate the current_depature_ptr from any platform
            current_platform_count -- ; 
            current_depature_ptr ++ ; 
        }
    }
    return min_platform_count ; 
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}