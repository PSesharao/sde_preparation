/*

https://leetcode.com/problems/top-k-frequent-elements/

Time complexity is N log(k)

we are using min heap to build and the size not exceeding k 

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

class Pair{
    public :
    int freq ; 
    int value ; 
    Pair(int freq  , int value ){
        this-> freq = freq ; 
        this-> value = value ; 
    }
} ; 

class Comp {
    public : 
    bool operator() (Pair &p1, Pair &p2) {
        return p1.freq > p2.freq ; // Min heap property 
    }
} ; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        priority_queue<Pair , vector<Pair> , Comp > min_pq ; 
        vector<int> res ; 
        // we are building heap with size not more than k 
        for(auto it = map.begin(); it != map.end(); it++ ){
            Pair p(it->second , it->first ) ;
            min_pq.push(p) ; 
            if(min_pq.size() > k )
                min_pq.pop() ;  
        }

        for(int i=k-1 ; i>=0 ; i-- ){
            res[i] = min_pq.top().value ; 
            min_pq.pop() ; 
        }
        return res ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}