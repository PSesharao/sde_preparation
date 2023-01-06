/*

https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
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


int findMinimumCoins(int amount) 
{
    int total_num_of_den = 0 ; 
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    for (int i = n - 1; i >= 0; i--) {
        int change = coins[i] ; 
        int num_of_den = amount / change ; 
        total_num_of_den += num_of_den ; 
        amount-= num_of_den*change ; 
        if(amount == 0 )
            break ; 
    }
    return total_num_of_den ; 
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}