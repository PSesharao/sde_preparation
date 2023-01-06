/*

https://leetcode.com/problems/permutation-sequence/


Approach 1 :  

The extreme naive solution is to generate all the possible permutations of the given 
sequence.  This is achieved using recursion and every permutation generated is stored 
in some other data structure (here we have used a vector). Finally, we sort the 
data structure in which we have stored all the sequences and return 
the Kth sequence from it.

Approach 2 : 

Say we have N = 4  and K = 17. Hence the number sequence is {1,2,3,4}. 

Since this is a permutation we can assume that there are four positions that need to be 
filled using the four numbers of the sequence. First, we need to decide which number is 
to be placed at the first index. Once the number at the first index is decided we have 
three more positions and three more numbers.  Now the problem is shorter. We can repeat 
the technique that was used previously until all the positions are filled.


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

// Approach 1 

class Solution {
  public:
    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

// Approach 2
class Solution {
  public:
    string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}