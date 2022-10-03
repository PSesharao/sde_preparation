/*

https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

The greedy method to maximize our answer will be to pick up the items with higher values. 
Since it is possible to break the items as well we should focus on picking up items 
having higher value /weight first. To achieve this, items should be sorted in decreasing 
order with respect to their value /weight. Once the items are sorted we can iterate. 
Pick up items with weight lesser than or equal to the current capacity of the knapsack. 
In the end, if the weight of an item becomes more than what we can carry, break the item 
into smaller units. 

Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) 
to iterate through all the items for calculating the answer.

Space Complexity: O(1), no additional data structure has been used.

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

struct Item {
   int value;
   int weight;
};

bool  comp(Item a, Item b) {
     double r1 = (1.0* a.value) / (1.0* a.weight);
     double r2 =  (1.0*b.value )/ (1.0 * b.weight);
     return r1 > r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            // only one item would be remaining as fraction if at all 
            int remain = W - curWeight;
            finalvalue += ((1.0*arr[i].value) / (1.0* arr[i].weight)) * (1.0* remain);
            break;
         }
      }

      return finalvalue;

   }
        
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}