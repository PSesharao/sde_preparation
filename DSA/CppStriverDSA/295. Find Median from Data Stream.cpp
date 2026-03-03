/*

https://leetcode.com/problems/find-median-from-data-stream/

Approach : 
we can use a max heap on the left side to represent elements that are less than 
effective median, and a min-heap on the right side to represent elements that 
are greater than effective median.

lets say
[4 , 3 , 6 ]
maxheap[] , minheap[]
4 -> no elements , so place it in the maxheap 

maxheap[4] , minheap[]

3 -> effective median so far 3+4 / 2 = 3.5 and 3< 3.5 , so place it in maxheap
maxheap[4 , 3 ] , minheap[]
but , since to balance it again we need to move one to minheap

maxheap[ 3 ] , minheap[4]

6 -> effective median is 4 and 6 > 4 need to place it in minheap

maxheap[ 3 ] , minheap[4 , 6 ]

but at anypoint maxheap size >= minheap , so we need to move one to maxheap
maxheap[ 3 , 4 ] , minheap[ 6 ]

After processing an incoming element, the number of elements in heaps differs 
utmost by 1 element. When both heaps contain the same number of elements, we 
pick the average of heaps root data as effective median. When the heaps are not 
balanced, we select effective median from the root of the heap containing more 
elements. i.e maxheap here

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


class MedianFinder {

private :
    priority_queue<int> max_pq ;
    priority_queue<int , vector<int> , greater<int> > min_pq ;

    void balanceHeaps() {
        if(max_pq.size() > min_pq.size()+1){
            min_pq.push(max_pq.top()) ; 
            max_pq.pop() ; 
        }else if(min_pq.size() > max_pq.size()){
            max_pq.push(min_pq.top()) ; 
            min_pq.pop() ; 
        }
    }

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // If less than effective median place it in max_pq
        if(max_pq.empty() || num < max_pq.top() )
            max_pq.push(num) ; 
        else
            min_pq.push(num) ; 
        balanceHeaps() ; 
    }
    
    double findMedian() {
        if( min_pq.size() == max_pq.size() )
            return (min_pq.top() + max_pq.top()) / 2.0 ; 
        return max_pq.top()*1.0 ; 
    }
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}